/*
 * Milkymist SoC (Software)
 * Copyright (C) 2007, 2008, 2009 Sebastien Bourdeauducq
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <uart.h>
#include <console.h>
#include <stdio.h>
#include <stdarg.h>
#include <irq.h>
#include <hw/interrupts.h>

static console_write_hook write_hook;
static console_read_hook read_hook;
static console_read_nonblock_hook read_nonblock_hook;

#define BUFF_SIZE 256

//#define DEBUG_ON
char buffer[BUFF_SIZE];
int ndex = 0;

static void delay(void)
{
    volatile int i;
    for(i=0;i<1000;i++);
}

void console_set_write_hook(console_write_hook h)
{
	write_hook = h;
}

void console_set_read_hook(console_read_hook r, console_read_nonblock_hook rn)
{
	read_hook = r;
	read_nonblock_hook = rn;
}

static void writechar(char c)
{
	uart_write(c);
	if(write_hook != NULL)
		write_hook(c);
}

char readchar(void)
{
	while(1) {
		if(uart_read_nonblock())
			return uart_read();
		if((read_nonblock_hook != NULL) && read_nonblock_hook())
			return read_hook();
        /* When hook is not set, avoids infinite loop that may prevent the CPU
         * to catch interruptions.
         */
        delay();
	}
}

int readchar_nonblock(void)
{
	return (uart_read_nonblock()
		|| ((read_nonblock_hook != NULL) && read_nonblock_hook()));
}

int puts(const char *s)
{
	unsigned int oldmask;

	oldmask = irq_getmask();
	irq_setmask(IRQ_UART); // HACK: prevent UART data loss

	while(*s) {
		writechar(*s);
		s++;
	}
	writechar('\n');
	
	irq_setmask(oldmask);
	return 1;
}

void putsnonl(const char *s)
{
	unsigned int oldmask;

	oldmask = irq_getmask();
	irq_setmask(IRQ_UART); // HACK: prevent UART data loss
	
	while(*s) {
		writechar(*s);
		s++;
	}
	
	irq_setmask(oldmask);
}

/*int printf(const char *fmt, ...)
{
	va_list args;
	int len;
	char outbuf[256];

	va_start(args, fmt);
	len = vscnprintf(outbuf, sizeof(outbuf), fmt, args);
	va_end(args);
	outbuf[len] = 0;
	putsnonl(outbuf);

	return len;
}*/


static void printchar(char c)
{
	buffer[ndex] = c;
	ndex++;
}

#define PAD_RIGHT 1
#define PAD_ZERO 2

static int prints(const char *string, int width, int pad)
{
	register int pc = 0, padchar = ' ';

	if (width > 0) {
		register int len = 0;
		register const char *ptr;
		for (ptr = string; *ptr; ++ptr) ++len;
		if (len >= width) width = 0;
		else width -= len;
		if (pad & PAD_ZERO) padchar = '0';
	}
	if (!(pad & PAD_RIGHT)) {
		for ( ; width > 0; --width) {
			printchar (padchar);
			++pc;
		}
	}
	for ( ; *string ; ++string) {
		printchar (*string);
		++pc;
	}
	for ( ; width > 0; --width) {
		printchar (padchar);
		++pc;
	}

	return pc;
}

/* the following should be enough for 32 bit int */
#define PRINT_BUF_LEN 12

static int printi(int i, int b, int sg, int width, int pad, int letbase)
{
	char print_buf[PRINT_BUF_LEN];
	register char *s;
	register int t, neg = 0, pc = 0;
	register unsigned int u = i;

	if (i == 0) {
		print_buf[0] = '0';
		print_buf[1] = '\0';
		return prints (print_buf, width, pad);
	}

	if (sg && b == 10 && i < 0) {
		neg = 1;
		u = -i;
	}

	s = print_buf + PRINT_BUF_LEN-1;
	*s = '\0';

	while (u) {
		t = u % b;
		if( t >= 10 )
			t += letbase - '0' - 10;
		*--s = t + '0';
		u /= b;
	}

	if (neg) {
		if( width && (pad & PAD_ZERO) ) {
			printchar ('-');
			++pc;
			--width;
		}
		else {
			*--s = '-';
		}
	}

	return pc + prints (s, width, pad);
}

static int print(const char *format, va_list args )
{
	register int width, pad;
	register int pc = 0;
	char scr[2];
	for (; *format != 0; ++format) {
		if (*format == '%') {
			++format;
			width = pad = 0;
			if (*format == '\0') break;
			if (*format == '%') goto dehors;
			if (*format == '-') {
				++format;
				pad = PAD_RIGHT;
			}
			while (*format == '0') {
				++format;
				pad |= PAD_ZERO;
			}
			for ( ; *format >= '0' && *format <= '9'; ++format) {
				width *= 10;
				width += *format - '0';
			}
			if( *format == 's' ) {
				register char *s = (char *)va_arg( args, int );
				pc += prints (s?s:"(null)", width, pad);
				continue;
			}
			if( *format == 'd' ) {
				pc += printi (va_arg( args, int ), 10, 1, width, pad, 'a');
				continue;
			}
			if( *format == 'x' ) {
				pc += printi (va_arg( args, int ), 16, 0, width, pad, 'a');
				continue;
			}
			if( *format == 'X' ) {
				pc += printi (va_arg( args, int ), 16, 0, width, pad, 'A');
				continue;
			}
			if( *format == 'u' ) {
				pc += printi (va_arg( args, int ), 10, 0, width, pad, 'a');
				continue;
			}
			if( *format == 'c' ) {
				/* char are converted to int then pushed on the stack */
				scr[0] = (char)va_arg( args, int );
				scr[1] = '\0';
				pc += prints (scr, width, pad);
				continue;
			}
		}
		else {

		dehors:
			printchar (*format);
			++pc;
		}
	}
	buffer[ndex] = '\0';
	va_end( args );
	return pc;
}

int printf ( const char * format, ... )
{
   va_list args;
   
#ifdef DEBUG_ON
   {
      int i;
      for (i = 0; i < BUFF_SIZE; i++) buffer[i] = 'a';
      buffer[BUFF_SIZE-1] = '\0'; 
   }
#endif
   ndex = 0;
   va_start( args, format );
   print(format, args );
   putsnonl(buffer);
   
   return ndex;
}

int printfln(const char *format, ...)
{
   va_list args;
   
#ifdef DEBUG_ON
   {
      int i;
      for (i = 0; i < BUFF_SIZE; i++) buffer[i] = 'a';
      buffer[BUFF_SIZE-1] = '\0'; 
   }
#endif
   ndex = 0;
   va_start( args, format );
   print(format, args );
   buffer[ndex++] = '\n';
   putsnonl(buffer);  
   
   return ndex;
}
