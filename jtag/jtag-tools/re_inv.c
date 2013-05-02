/*
 * Milkymist SoC (Software)
 * Copyright (C) 2007, 2008, 2009, 2010, 2011 Sebastien Bourdeauducq
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

#include <stdio.h>
#include <console.h>
#include <string.h>
#include <uart.h>
#include <blockdev.h>
#include <fatfs.h>
#include <crc.h>
#include <system.h>
#include <board.h>
#include <irq.h>
#include <version.h>
#include <net/mdio.h>
#include <hw/fmlbrg.h>
#include <hw/sysctl.h>
#include <hw/gpio.h>
#include <hw/flash.h>
#include <hw/minimac.h>

#include <hal/vga.h>
#include <hal/tmu.h>
#include <hal/brd.h>
#include <hal/usb.h>
#include <hal/ukb.h>

#include "boot.h"
#include "splash.h"

enum {
	CSR_IE = 1, CSR_IM, CSR_IP, CSR_ICC, CSR_DCC, CSR_CC, CSR_CFG, CSR_EBA,
	CSR_DC, CSR_DEBA, CSR_JTX, CSR_JRX, CSR_BP0, CSR_BP1, CSR_BP2, CSR_BP3,
	CSR_WP0, CSR_WP1, CSR_WP2, CSR_WP3,
};

/* General address space functions */

#ifdef FIXME
#define NUMBER_OF_BYTES_ON_A_LINE 16
static void dump_bytes(unsigned int *ptr, int count, unsigned addr)
{
	char *data = (char *)ptr;
	int line_bytes = 0, i = 0;

	putsnonl("Memory dump:");
	while(count > 0){
		line_bytes =
			(count > NUMBER_OF_BYTES_ON_A_LINE)?
				NUMBER_OF_BYTES_ON_A_LINE : count;

		printf("\n0x%08x  ", addr);
		for(i=0;i<line_bytes;i++)
			printf("%02x ", *(unsigned char *)(data+i));

		for(;i<NUMBER_OF_BYTES_ON_A_LINE;i++)
			printf("   ");

		printf(" ");

		for(i=0;i<line_bytes;i++) {
			if((*(data+i) < 0x20) || (*(data+i) > 0x7e))
				printf(".");
			else
				printf("%c", *(data+i));
		}

		for(;i<NUMBER_OF_BYTES_ON_A_LINE;i++)
			printf(" ");

		data += (char)line_bytes;
		count -= line_bytes;
		addr += line_bytes;
	}
	printf("\n");
}


static void mr(char *startaddr, char *len)
{
	char *c;
	unsigned int *addr;
	unsigned int length;

	if(*startaddr == 0) {
		printf("mr <address> [length]\n");
		return;
	}
	addr = (unsigned *)strtoul(startaddr, &c, 0);
	if(*c != 0) {
		printf("incorrect address\n");
		return;
	}
	if(*len == 0) {
		length = 1;
	} else {
		length = strtoul(len, &c, 0);
		if(*c != 0) {
			printf("incorrect length\n");
			return;
		}
	}

	dump_bytes(addr, length, (unsigned)addr);
}

static void mw(char *addr, char *value, char *count)
{
	char *c;
	unsigned int *addr2;
	unsigned int value2;
	unsigned int count2;
	unsigned int i;

	if((*addr == 0) || (*value == 0)) {
		printf("mw <address> <value> [count]\n");
		return;
	}
	addr2 = (unsigned int *)strtoul(addr, &c, 0);
	if(*c != 0) {
		printf("incorrect address\n");
		return;
	}
	value2 = strtoul(value, &c, 0);
	if(*c != 0) {
		printf("incorrect value\n");
		return;
	}
	if(*count == 0) {
		count2 = 1;
	} else {
		count2 = strtoul(count, &c, 0);
		if(*c != 0) {
			printf("incorrect count\n");
			return;
		}
	}
	for (i=0;i<count2;i++) *addr2++ = value2;
}

static void mc(char *dstaddr, char *srcaddr, char *count)
{
	char *c;
	unsigned int *dstaddr2;
	unsigned int *srcaddr2;
	unsigned int count2;
	unsigned int i;

	if((*dstaddr == 0) || (*srcaddr == 0)) {
		printf("mc <dst> <src> [count]\n");
		return;
	}
	dstaddr2 = (unsigned int *)strtoul(dstaddr, &c, 0);
	if(*c != 0) {
		printf("incorrect destination address\n");
		return;
	}
	srcaddr2 = (unsigned int *)strtoul(srcaddr, &c, 0);
	if(*c != 0) {
		printf("incorrect source address\n");
		return;
	}
	if(*count == 0) {
		count2 = 1;
	} else {
		count2 = strtoul(count, &c, 0);
		if(*c != 0) {
			printf("incorrect count\n");
			return;
		}
	}
	for (i=0;i<count2;i++) *dstaddr2++ = *srcaddr2++;
}

static void crc(char *startaddr, char *len)
{
	char *c;
	char *addr;
	unsigned int length;

	if((*startaddr == 0)||(*len == 0)) {
		printf("crc <address> <length>\n");
		return;
	}
	addr = (char *)strtoul(startaddr, &c, 0);
	if(*c != 0) {
		printf("incorrect address\n");
		return;
	}
	length = strtoul(len, &c, 0);
	if(*c != 0) {
		printf("incorrect length\n");
		return;
	}

	printf("CRC32: %08x\n", crc32((unsigned char *)addr, length));
}

/* processor registers */
static int parse_csr(const char *csr)
{
	if(!strcmp(csr, "ie"))   return CSR_IE;
	if(!strcmp(csr, "im"))   return CSR_IM;
	if(!strcmp(csr, "ip"))   return CSR_IP;
	if(!strcmp(csr, "icc"))  return CSR_ICC;
	if(!strcmp(csr, "dcc"))  return CSR_DCC;
	if(!strcmp(csr, "cc"))   return CSR_CC;
	if(!strcmp(csr, "cfg"))  return CSR_CFG;
	if(!strcmp(csr, "eba"))  return CSR_EBA;
	if(!strcmp(csr, "dc"))   return CSR_DC;
	if(!strcmp(csr, "deba")) return CSR_DEBA;
	if(!strcmp(csr, "jtx"))  return CSR_JTX;
	if(!strcmp(csr, "jrx"))  return CSR_JRX;
	if(!strcmp(csr, "bp0"))  return CSR_BP0;
	if(!strcmp(csr, "bp1"))  return CSR_BP1;
	if(!strcmp(csr, "bp2"))  return CSR_BP2;
	if(!strcmp(csr, "bp3"))  return CSR_BP3;
	if(!strcmp(csr, "wp0"))  return CSR_WP0;
	if(!strcmp(csr, "wp1"))  return CSR_WP1;
	if(!strcmp(csr, "wp2"))  return CSR_WP2;
	if(!strcmp(csr, "wp3"))  return CSR_WP3;

	return 0;
}

static void rcsr(char *csr)
{
	unsigned int csr2;
	register unsigned int value;

	if(*csr == 0) {
		printf("rcsr <csr>\n");
		return;
	}

	csr2 = parse_csr(csr);
	if(csr2 == 0) {
		printf("incorrect csr\n");
		return;
	}

	switch(csr2) {
		case CSR_IE:   asm volatile ("rcsr %0,ie":"=r"(value)); break;
		case CSR_IM:   asm volatile ("rcsr %0,im":"=r"(value)); break;
		case CSR_IP:   asm volatile ("rcsr %0,ip":"=r"(value)); break;
		case CSR_CC:   asm volatile ("rcsr %0,cc":"=r"(value)); break;
		case CSR_CFG:  asm volatile ("rcsr %0,cfg":"=r"(value)); break;
		case CSR_EBA:  asm volatile ("rcsr %0,eba":"=r"(value)); break;
		case CSR_DEBA: asm volatile ("rcsr %0,deba":"=r"(value)); break;
		case CSR_JTX:  asm volatile ("rcsr %0,jtx":"=r"(value)); break;
		case CSR_JRX:  asm volatile ("rcsr %0,jrx":"=r"(value)); break;
		default: printf("csr write only\n"); return;
	}

	printf("%08x\n", value);
}

static void wcsr(char *csr, char *value)
{
	char *c;
	unsigned int csr2;
	register unsigned int value2;

	if((*csr == 0) || (*value == 0)) {
		printf("wcsr <csr> <address>\n");
		return;
	}

	csr2 = parse_csr(csr);
	if(csr2 == 0) {
		printf("incorrect csr\n");
		return;
	}
	value2 = strtoul(value, &c, 0);
	if(*c != 0) {
		printf("incorrect value\n");
		return;
	}

	switch(csr2) {
		case CSR_IE:   asm volatile ("wcsr ie,%0"::"r"(value2)); break;
		case CSR_IM:   asm volatile ("wcsr im,%0"::"r"(value2)); break;
		case CSR_ICC:  asm volatile ("wcsr icc,%0"::"r"(value2)); break;
		case CSR_DCC:  asm volatile ("wcsr dcc,%0"::"r"(value2)); break;
		case CSR_EBA:  asm volatile ("wcsr eba,%0"::"r"(value2)); break;
		case CSR_DC:   asm volatile ("wcsr dcc,%0"::"r"(value2)); break;
		case CSR_DEBA: asm volatile ("wcsr deba,%0"::"r"(value2)); break;
		case CSR_JTX:  asm volatile ("wcsr jtx,%0"::"r"(value2)); break;
		case CSR_JRX:  asm volatile ("wcsr jrx,%0"::"r"(value2)); break;
		case CSR_BP0:  asm volatile ("wcsr bp0,%0"::"r"(value2)); break;
		case CSR_BP1:  asm volatile ("wcsr bp1,%0"::"r"(value2)); break;
		case CSR_BP2:  asm volatile ("wcsr bp2,%0"::"r"(value2)); break;
		case CSR_BP3:  asm volatile ("wcsr bp3,%0"::"r"(value2)); break;
		case CSR_WP0:  asm volatile ("wcsr wp0,%0"::"r"(value2)); break;
		case CSR_WP1:  asm volatile ("wcsr wp1,%0"::"r"(value2)); break;
		case CSR_WP2:  asm volatile ("wcsr wp2,%0"::"r"(value2)); break;
		case CSR_WP3:  asm volatile ("wcsr wp3,%0"::"r"(value2)); break;
		default: printf("csr read only\n"); return;
	}
}


/* CF filesystem functions */

static int lscb(const char *filename, const char *longname, void *param)
{
	printf("%12s [%s]\n", filename, longname);
	return 1;
}

static void ls(char *dev)
{
	if(!fatfs_init(BLOCKDEV_MEMORY_CARD)) return;
	fatfs_list_files(lscb, NULL);
	fatfs_done();
}

static void load(char *filename, char *addr, char *dev)
{
	char *c;
	unsigned int *addr2;

	if((*filename == 0) || (*addr == 0)) {
		printf("load <filename> <address>\n");
		return;
	}
	addr2 = (unsigned *)strtoul(addr, &c, 0);
	if(*c != 0) {
		printf("incorrect address\n");
		return;
	}
	if(!fatfs_init(BLOCKDEV_MEMORY_CARD)) return;
	fatfs_load(filename, (char *)addr2, 16*1024*1024, NULL);
	fatfs_done();
}

static void mdior(char *reg)
{
	char *c;
	int reg2;

	if(*reg == 0) {
		printf("mdior <register>\n");
		return;
	}
	reg2 = strtoul(reg, &c, 0);
	if(*c != 0) {
		printf("incorrect register\n");
		return;
	}

	printf("%04x\n", mdio_read(brd_desc->ethernet_phyadr, reg2));
}

static void mdiow(char *reg, char *value)
{
	char *c;
	int reg2;
	int value2;

	if((*reg == 0) || (*value == 0)) {
		printf("mdiow <register> <value>\n");
		return;
	}
	reg2 = strtoul(reg, &c, 0);
	if(*c != 0) {
		printf("incorrect address\n");
		return;
	}
	value2 = strtoul(value, &c, 0);
	if(*c != 0) {
		printf("incorrect value\n");
		return;
	}

	mdio_write(brd_desc->ethernet_phyadr, reg2, value2);
}
#endif
/* Init + command line */
#ifdef FIXME
static void help(void)
{
	puts("Milkymist(tm) BIOS (bootloader)");
	puts("Don't know what to do? Try 'flashboot'.\n");
	puts("Available commands:");
	puts("cons       - switch console mode");
	puts("flush      - flush FML bridge cache");
	puts("mr         - read address space");
	puts("mw         - write address space");
	puts("mc         - copy address space");
	puts("crc        - compute CRC32 of a part of the address space");
	puts("rcsr       - read processor CSR");
	puts("wcsr       - write processor CSR");
	puts("ls         - list files on the filesystem");
	puts("load       - load a file from the filesystem");
	puts("netboot    - boot via TFTP");
	puts("serialboot - boot via SFL");
	puts("fsboot     - boot from the filesystem");
	puts("flashboot  - boot from flash");
	puts("mdior      - read MDIO register");
	puts("mdiow      - write MDIO register");
	puts("version    - display version");
	puts("reboot     - system reset");
	puts("reconf     - reload FPGA configuration");
}


static char *get_token(char **str)
{
	char *c, *d;

	c = (char *)strchr(*str, ' ');
	if(c == NULL) {
		d = *str;
		*str = *str+strlen(*str);
		return d;
	}
	*c = 0;
	d = *str;
	*str = c+1;
	return d;
}

static void do_command(char *c)
{
	char *token;

	token = get_token(&c);


	if(strcmp(token, "cons") == 0) vga_set_console(!vga_get_console());
	else if(strcmp(token, "flush") == 0) flush_bridge_cache();
	else if(strcmp(token, "mr") == 0) mr(get_token(&c), get_token(&c));
	else if(strcmp(token, "mw") == 0) mw(get_token(&c), get_token(&c), get_token(&c));
	else if(strcmp(token, "mc") == 0) mc(get_token(&c), get_token(&c), get_token(&c));
	else if(strcmp(token, "crc") == 0) crc(get_token(&c), get_token(&c));

	else if(strcmp(token, "ls") == 0) ls(get_token(&c));
	else if(strcmp(token, "load") == 0) load(get_token(&c), get_token(&c), get_token(&c));

	else if(strcmp(token, "netboot") == 0) netboot();
	else if(strcmp(token, "serialboot") == 0) serialboot();
	else if(strcmp(token, "fsboot") == 0) fsboot(BLOCKDEV_MEMORY_CARD);
	else if(strcmp(token, "flashboot") == 0) flashboot();

	else if(strcmp(token, "mdior") == 0) mdior(get_token(&c));
	else if(strcmp(token, "mdiow") == 0) mdiow(get_token(&c), get_token(&c));

	else if(strcmp(token, "version") == 0) puts(VERSION);
	else if(strcmp(token, "reboot") == 0) reboot();
	else if(strcmp(token, "reconf") == 0) reconf();

	else if(strcmp(token, "help") == 0) help();

	else if(strcmp(token, "rcsr") == 0) rcsr(get_token(&c));
	else if(strcmp(token, "wcsr") == 0) wcsr(get_token(&c), get_token(&c));

	else if(strcmp(token, "") != 0)

    if(strcmp(token, "help") == 0) help();
    //else if(strcmp(token, "special") == 0) specialBoot();
    else printf("Command not found\n");
		
}
#endif 
#ifdef FIXME
static int test_user_abort(void)
{
	char c;

	puts("I: Press Q or ESC to abort boot");
	CSR_TIMER0_COUNTER = 0;
	CSR_TIMER0_COMPARE = 2*CSR_FREQUENCY;
	CSR_TIMER0_CONTROL = TIMER_ENABLE;
	while(CSR_TIMER0_CONTROL & TIMER_ENABLE) {
		if(readchar_nonblock()) {
			c = readchar();
			if((c == 'Q')||(c == '\e')) {
				puts("I: Aborted boot on user request");
				return 0;
			}
			if(c == 0x07) {
				vga_unblank();
				vga_set_console(1);
				netboot();
				return 0;
			}
		}
	}
	return 1;
}
#endif

int rescue;

extern unsigned int _edata;

#ifdef FIXME
static void crcbios(void)
{
	unsigned int offset_bios;
	unsigned int length;
	unsigned int expected_crc;
	unsigned int actual_crc;

	/*
	 * _edata is located right after the end of the flat
	 * binary image. The CRC tool writes the 32-bit CRC here.
	 * We also use the address of _edata to know the length
	 * of our code.
	 */
	offset_bios = rescue ? FLASH_OFFSET_RESCUE_BIOS : FLASH_OFFSET_REGULAR_BIOS;
	expected_crc = _edata;
	length = (unsigned int)&_edata - offset_bios;
	actual_crc = crc32((unsigned char *)offset_bios, length);
	if(expected_crc == actual_crc)
		printf("I: BIOS CRC passed (%08x)\n", actual_crc);
	else {
		printf("W: BIOS CRC failed (expected %08x, got %08x)\n", expected_crc, actual_crc);
		printf("W: The system will continue, but expect problems.\n");
	}
}

static void print_mac(void)
{
	unsigned char *macadr = (unsigned char *)FLASH_OFFSET_MAC_ADDRESS;

	printf("I: MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n", macadr[0], macadr[1], macadr[2], macadr[3], macadr[4], macadr[5]);
}
#endif

static const char banner[] = "Coucou\n\n";/*
	"\nMILKYMIST(tm) v"VERSION" BIOS   http://www.milkymist.org\n"
	"(c) Copyright 2007, 2008, 2009, 2010, 2011 Sebastien Bourdeauducq\n\n"
	"This program is free software: you can redistribute it and/or modify\n"
	"it under the terms of the GNU General Public License as published by\n"
	"the Free Software Foundation, version 3 of the License.\n\n";*/

#ifdef FIXME
static void boot_sequence(void)
{
	if(test_user_abort()) {
		if(rescue) {
			netboot();
			serialboot();
			fsboot(BLOCKDEV_MEMORY_CARD);
			flashboot();
		} else {
			fsboot(BLOCKDEV_MEMORY_CARD);
			flashboot();
			netboot();
			serialboot();
		}
		printf("E: No boot medium found\n");
	}
}
#endif
#ifdef FIXME
static void readstr(char *s, int size)
{
	char c[2];
	int ptr;

	c[1] = 0;
	ptr = 0;
	while(1) {
		c[0] = readchar();
		switch(c[0]) {
			case 0x7f:
			case 0x08:
				if(ptr > 0) {
					ptr--;
					putsnonl("\x08 \x08");
				}
				break;
			case '\e':
#endif
#ifdef FIXME
				vga_set_console(!vga_get_console());
#endif
#ifdef FIXME
				break;
			case 0x07:
				break;
			case '\r':
			case '\n':
				s[ptr] = 0x00;
				putsnonl("\n");
				return;
			default:
				putsnonl(c);
				s[ptr] = c[0];
				ptr++;
				break;
		}
	}
}
#endif
#ifdef FIXME
static void ethreset_delay(void)
{
	CSR_TIMER0_COUNTER = 0;
	CSR_TIMER0_COMPARE = CSR_FREQUENCY >> 2;
	CSR_TIMER0_CONTROL = TIMER_ENABLE;
	while(CSR_TIMER0_CONTROL & TIMER_ENABLE);
}

static void ethreset(void)
{
	CSR_MINIMAC_SETUP = MINIMAC_SETUP_PHYRST;
	ethreset_delay();
	CSR_MINIMAC_SETUP = 0;
	ethreset_delay();
}
#endif

int main(int i, char **c)
{
	//char buffer[64];

#ifdef FIXME
	/* lock gdbstub ROM */
	CSR_DBG_CTRL = DBG_CTRL_GDB_ROM_LOCK;

	/* enable bus errors */
	CSR_DBG_CTRL = DBG_CTRL_BUS_ERR_EN;
#endif

	CSR_GPIO_OUT = GPIO_LED1;
	rescue = !((unsigned int)main > FLASH_OFFSET_REGULAR_BIOS);

	irq_setmask(0);
	irq_enable(1);
	uart_init();
#ifdef FIXME
	vga_init(!(rescue || (CSR_GPIO_IN & GPIO_BTN2)));
#endif
	putsnonl(banner);

#ifdef FIXME
	crcbios();
	brd_init();
	tmu_init(); /* < for hardware-accelerated scrolling */
	usb_init();
	ukb_init();

	if(rescue)
		printf("I: Booting in rescue mode\n");

	splash_display();
	ethreset(); /* < that pesky ethernet PHY needs two resets at times... */
	print_mac();
	boot_sequence();
	vga_unblank();
	vga_set_console(1);
#endif
    specialBoot();
	/*while(1) {
		putsnonl("\e[1mBIOS>\e[0m ");
		readstr(buffer, 64);
		do_command(buffer);
	}*/
	return 0;
}
ÿ4¥ <¥ 4B ´%( (¥  P… ¸   Q¢ÿøãÿÿÙ7œÿğ[‹ [Œ [ [ x@'ø 2ó9Œ`T4 D  4 5kÿÿ=d X  X ôµ„  (ƒ  ("¸L 	eàŒC  ´% Xd (cØE` 5kÿÿ=d ´C µ„  (ƒ  L 	eàŒC  ´% Xd (cØ]`ÿõø 2×\+ÿäûÿÿ¤+ +‹ +Œ + 7œ Ã   X  4 ãÿÿã7œÿø[‹ [ x@(8BK˜(B  ¸ X x@(Yb Y` 8!L(!  Ya ø)ÿYa 4 Y` ,Y` 0Ya 4+ +‹ 7œ Ã   7œÿğ[‹ [Œ [ ¸ ` x@(8!ô¹€ 4  7„ ø 2³+… 4  D  (¦Ø(¥ 4! ¹€ 4  7„ ÈÅ8 P¦ µgX ø 2¦+… \ ÿõ¹` + +‹ +Œ 7œ Ã   7œÿü[ 4  ûÿÿİ+ 7œ Ã   x@$8„Ô(ˆ  4 4 4¥ÿÿ¤à<g 4Æÿÿ´$  (‰Ø´G8 E  Xä (‰Ì4c È‰  „ ˆˆ  Xä \Àÿñ¸` Ã   7œÿè[‹ [Œ [ [ [ [ (,ô4-À4  ¹  ¸ x ûÿÿİ¸  5 H  x@(8!0¹  ûÿÿÖ¸  L x@(4  9Î0E` 5k I‹ÿş4c ¸<c µãx Yà Yà + +‹ +Œ + + + 7œ Ã   ¹À ¹  ûÿÿ¾¸  ãÿÿí7œÿø[‹ [ ¸ X D  ("ô\@ x@(9k0¹` ûÿÿÈx@'8B`h4 x@'x@'x@'8¥`t8„`|8c`„XA 4  Y`ÀX@  X@ XE XE XD XD XC XC  + +‹ 7œ Ã   ûÿÿ¯Y`Àãÿÿâx@4$  8cddXƒ X‚ ($  4 ¼b 8„@ X$  Lb ¸  4 (e  X` 0Xa <8¥€ Xe  4„ 4c  \‚ÿùÃ   7œÿì[‹ [Œ [ [ [ (F  (g  x@( Æ  ç Æàçà8¥0´Å0 ´å( ¸ X \Å /4  Pb + +‹ +Œ + + 7œ Ã   < 4ÿ€4  4 (E D¦ 
4B  Pbÿı+ +‹ +Œ + + 7œ Ã   (E (G (I ª ,4H Y' µÊP Xé  µj8 (é $4ê $Y( XI XJ ½¥H Xè $½…( XD ´I ´% Pbÿáãÿÿäx@#x@$x@ 8!Ô08Bˆ4¢8„iŒøux@#8!Ô\øts7œÿü[ x@(8„Lô(‡  4ü (&ĞÈG( ¥  ¤( <¨ ¸`  ´è8 4¨ÿTÅ ¸à (#Ô4  ´Ã0 Q 4ãàûÿÿ ¸ ( ¸  + 7œ Ã   4 ¼b Lb 4 X$ 04c 4!  \bÿıÃ   (&L4„ <„ 4 ½@ ´$  4Æ  §  („  ÈÈ0 Dà  g ´ã8 ç Èg  ¥ D  e  ¥ ´£( ¥ Èe ´d( 4  L¦ 4 L 
(% Lc 4  ÈÅ( Le 4„ c HD 4 ¸€ Ã   (& x4! ,¼Ä0 È¦( Le ãÿÿõ4  ¸€ Ã   (' (&LDà PÇ (&L4 4„ ¼â@ <„ Èè8 ´$   ¨  („  ´æ0 E   g ´ã8 ç Èg  ¥ D  e  ¥ ´£( ¥ Èe ´d( 4  L¦ 4 L 
(% Lc 4  ÈÅ( Le 4„ c HD 4 ¸€ Ã   (& x4! ,¼Ä0 È¦( Le ãÿÿõ4  ¸€ Ã   7œÿÄ[‹ [Œ [ [ [ [ƒ ([„ ,[… 0[† 4[‡ 8[ˆ < , ¸ X ¸@h E€ + +‹ +Œ + + 7œ <Ã   x@'x@ 8!`¤8BiT[ƒ øŠÀ+ƒ D,ÿòx x@(¡a 4 9Î¨\  )Á  4  ("  B  B \L (!  (, !ŒeŒ  )Á  x@$8„p(" (   A \  !b \A 4ÿş¡` \` )Á  ¹  ¹`  ("  x@$8! 4B¨øtKøs¢¹€ ø­ãÿÿÊx@$7„ ,[ƒ 7‚ 7ƒ $8!˜[„ $[ƒ  øt>ãÿÿë $   % 8‚ @\  x  # \e 8‚ P4ÿ¿ D \`  !  \# x@(8!¨(!  (#  d \€ x@$8¥p(¤   d \` ($  („  „ Dƒ 8B  A  ! Ã   x@(8c¨(c  4 c(e  (¥ LÅ x  # ãÿÿá($  („  „ D€ÿæ8B ãÿÿî(!  !  ! \$ÿé A  ! Ã   x@$8Æp(e (Ã   £ \`ÿë8‚ Pãÿÿé7œÿü[ 4 ûÿıô+ 7œ Ã    # 4  D` 
 A x@'<! 8c`H´# (a  €"  ! ! Ã   7œşğ[‹ ˜[Œ ”[ [ Œ[ ˆ[ „[‘ €[’ |[“ x[” t[• p[– l[— h[˜ d[™ `[› \[ X¸ ° ø 0¸ X D  !x@$x@$x@'"Î 9ŒØ9ïè9­`Hà  )bÜøsÊ)e 4  ¹à (£ (¤ (¥  øsÃ¹` ø 0q¸ X D  )bØD@ÿû¹€ EÀÿğ)¢   B \@ÿí¹` ø 0f¸ X \ ÿöx@(x@(x@(x@(x@(x@(x@(x@(x@(x@(x@(x@(x@(x@(x@(x@(x
@(x	@(:sL4:RL8:1LL:L9ïL<9ÎL@9ŒLh9kLD9JLP9)Lx8BL8cL8„L`8¥L8ÆL8çLd9L 9­L,(B  (c  („  (¥  (Æ  (ç  )  *u  *T  *3  *  )ñ  )Ğ  )¯  )  )l  )K  )*  x	@$¹  8![‹ ([Š ,[• [” [“ [’ [‘ [ [ [  [Œ $øsoø 0¸ X D   x@$x@$x@$x@$x@%x@$x@'"Ï :sÔ9Œ :Rä9­tÄ:1:|Ì9Î`H)iØE  ‹¹€ ]à Ú)cL)gT)hP)j\)tX)u`)w )x¤)yd)bt=) =J [‚ Ä)dx? ?9 [„ œ)el>µ >÷ […  )f¨)e >” [† ¤){|<c <¥ [› Ì)}€<ç = [ Ğ)bˆ)d„[„ Ô)fŒ[† Ø){)fD[› Ü)}¸<[ )bÜ[ à)dœ{ 
[„ ä[† È[‰ ¼+‰ Ä)}  [Š ¨=) +Š œ?¤ [‰ Ä)} +‰ ¤=J ?¦ =) +  [Š œ+Š Ì[‰ ¤+‰ Ğ?½ =J [  [Š Ì== +Š Ô+‰ Ø[˜ ¸[™ À=8 =Y +‰ à+Š Ü[• °[— ´=5 =W )i  +Š ä[” ¬=T º`P E  º P +‰ ¨[› 8+› È[‰ +‰ ¬[ 4[™ <[‰ +‰ °[˜ @[— D[‰ +‰ ´[• H[” L[‰ +‰ ¸[› P[‰ +‰ ¼[‰ +‰ À[‰ +‰ Ä[‰  +‰ œ[‰ $+‰  [‰ (+‰ ¤[‰ ,+‰ Ì[‰ 0[Š TørÛº@ ørÙ)b ¹  ørÖ)b ¹  ørÓº  ørÑ¹` ø /¸ X \ ÿqø /w¸ X D  2x@$x@$x@$x@'"Í :ø7’ è4 9ï 4 9Î9Œ`H)bØD@  ]  D)bÜº  ør¸ ( Ğ   4  ¹`  º@° º@ 4  (‡ L4„ ,¼ã0 XG  4c ¶¦¨ 4B \qÿùĞ  4  *Â  ¾t ¹à 6” ør¢6Ö ^‘ÿú>¢ ¹À ør¹` ø /K¸ X \ ÿÜx@(8!L0("  x@$8!ør“+ X+‹ ˜+Œ ”+ + Œ+ ˆ+ „+‘ €+’ |+“ x+” t+• p+– l+— h+˜ d+™ `+› \7œÃ   )Â   B \@ÿ%¹` ø /+¸ X \ ÿãÿÿ¬)‚   B \@ÿ»¹` ø /#¸ X \ ÿ´ãÿÿØ7œÿü[ ûÿ*ûÿü4  + 7œ Ã   7œÿğ[‹ [Œ [ [ ¸@` ûÿ + e‚  ¹bX E` + +‹ +Œ + 7œ Ã   ø /¸  4  Dkÿ÷x@(9kK¨4ƒ4 `à  ø .ı¸  D  (bØ¸` D@ÿû)d  (c ŒD  D Xb D€ Xd Q‚ÿóXm ø .î¸  \ ÿò4  + +‹ +Œ + 7œ Ã   4 ãÿÿò(&  x@(8¥Lô Æ (¥  Æàx@(8„0´†  È% (…Ğ! (‡È%  ! 
<% ´¡  4  HC ´‚  4  † 4B <Æ ´æ0 (Æ  €Ä0 4„  Æ DÀ ¸% HC <¥ ãÿÿôÃ   7œÿø[‹ [Œ ('  x@(8ÆLô ç (Æ  çàx@(8¥0´§( È& (¦Ğ! (¨È&  ! 
<& ´Á Hd ´# 4 4	 à  (Æ  ¸Ì` Xì  4c 4! Hd <¥  & ½!P <Æ ¹@` µ0 ¥@X  ¢P ¸À8 ]@ÿñ(Ê  ¡KX XË  ãÿÿğ+‹ +Œ 7œ Ã   7œÿü[ x@(8cK”(e  4 4  d¥  È(  E ûÿÿÅ+ 7œ Ã   7œÿ´[‹ D[Œ @[ <[ 8[ 4[ 0[‘ ,[’ ([“ $[”  [• [– [— [˜ [™ [› [ x@';{`\»` øt$x@'8!`X(9  ø .b4  D  ("Ø¶¢¨ ø .b\ ÿıø .[¸ € D  Rx@(x@(9 4 9ÎLø:1Lô4 8€  ° Ğ   *Ø4  »  4  ø›ƒ[ H[‚ L\  xŒU [’ LZ  +ƒ L+… H*Ğ c <¥ 4ÿ¸£ ¶C Z +ƒ L+… H*Ô c <¥ ­ 
¸£ ¶C =­ 
Z ´x Q¯ #6RÿR 
O 4 5¬ =­ )Ã  5‹ü Qc *4  4  4 ¶  º€ ûÿÿCF@ D¹à( Q ¹€( Qe 
*#  ´m  („   „ \€ 5¤  ´d 5k T« #D7 1D8 )5ƒ µ³h Uì Ğ  º  ø .¸ € \ ÿ¸ûÿúÙ»` øsk+ +‹ D+Œ @+ <+ 8+ 4+ 0+‘ ,+’ (+“ $+”  +• +– +— +˜ +™ +› 7œ LÃ   ¸`` ãÿÿÈ(d  4c   „ D€ÿÙ5ƒ µ³h UìÿøãÿÿÜº€ 4 ûÿÿ\º  º€ 4 ûÿü#6Rÿÿ5ƒ µ³h UìÿìãÿÿĞ\7ÿÌº€ 4 ûÿÿO4 º  º€ ûÿü5ƒ µ³h UìÿàãÿÿÄ7 Hº  ø›Z+’ Lãÿÿ‡7œÿø[‹ [ ¸@X ûÿE` ûÿÿI4  + +‹ 7œ Ã   7œÿ´[‹ D[Œ @[ <[ 8[ 4[ 0[‘ ,[’ ([“ $[”  [• [– [— [˜ [™ [› [ U ,¸@p 4B B ,¸ x 6¡  µá [‚ L[ Hx@#x@#x@ x@(8!áœ8Bá 4 
¸`ˆ 4 (8  (W  4ÿÿ4ÿ€:”i4 :sK”RN ~! 4    4  \€ 8¹` + +‹ D+Œ @+ <+ 8+ 4+ 0+‘ ,+’ (+“ $+”  +• +– +— +˜ +™ +› 7œ LÃ   >( µ  µä (! $µä  4„ $D$ ’+ H¹À0 º ( 4$ µ µá (+ $µå( 4„ÿÔ5kÿì)g )j ¿&H YG Xê  Yx Yw Yv Y` (¡ L´ˆ8 4!ÿÿX¡ LHÎ Med  ~!    D€ÿÊIÒ D>$ 4 
¶„ ('  4„ ´”  4á ;<! <ê µá 4) Dû ‡	ˆ ,)#  ¹@ µH µâ µèh 4B $5­ $Db rµè  (‡ L´( µá (+ $i… f! 4çÿÿX‡ L¸¡  5kÿì\€ <*a  \$ :)a )c Xa X#  Yx Yw Yv Y` MÌ >( 5¢ÿÔ¿,( ´H   ¥ (†  <¡ ´H8 µa 4# XÃ X& X' Xƒ  (C (5Œÿÿ4„ÿÔ4c XC (X, X0 I ]`ÿ†4 RNÿ˜ãÿÿ~4„ÿÔ) (ã  =! ´ˆ( µa 4" Xb X# X% Xâ  (‚ (4Æÿÿ4çÿÔ4B X‚ (X& X0 HÎÿîãÿÿ¢4BÿÔãÿÿÕ¹` ¹à º  ûÿû84ÿH" *a  D  ¹` º  ûÿşf)a )d X X$  Yx Yw Yv Y` ]’ÿ¼¹` º  ûÿşZãÿÿ¸+‚ L¹À0 µ µá 4! $4Æ 4 Å ,DÂÿG(#  µ µâ µå  4B $4„ $4! ,\bÿcãÿÿô¸€( (¢  4¥ <A D[ ´( µâ (c $µâ 4B $\bÿ…ãÿÿö5Œÿÿ5)ÿÔIÌÿ¯ãÿÿv7œÿÔ[‹ ,[Œ ([ $[  [ [ [‘ [’ [“ [” [ ($ ¸ X 4ÿ€¸@p ¸`˜ \ )q  x@()m 1 9ï0
1à4 ¾M` ¶/€ * 4  º  µƒ 4  4  ûÿû4  \  ¸@ + +‹ ,+Œ (+ $+  + + +‘ +’ +“ +” 7œ ,Ã   )a )b x@#8cáœXA X"  (a  x@#8cá 	´ ,Ya (a  ¶‘ µâ Ya (C L¹` 4cÿÿXC L4ÿÿYb Y` 4  4 ûÿı˜4 \" 5E® MÍ ¶‘ 4!  ´/ >c 4&ÿØ´Ã0 4! ¹ ( 4	ÿ€Œ (È  =„ 4!ÿÔµd  4‡ Y ´# Xˆ X‚ XÇ  (" (4¥ÿÿ4ÆÿÔ4B X" (X… X‰ H®ÿî4 P- 4  ½` 5Œÿàµl` Ql 4 8€ ¹` 4  4 ûÿıkD/ ¹` 4 ûÿı»µmX U‹ÿ÷4 ¼N ãÿÿ¤¾N È   Ğ   *L´C ZLĞ    Ğ   x@(8!L($  ´D X"  Ğ  ãÿÿ¼x@#x@$x@ 8!Ô08Bˆ4o8„ixøo{x@#8!Ô\øn×7œÿô[‹ [Œ [ (# 4ÿ€¸ X \b (, 4  ¹€ ûÿÿXD  4 ¼l Yc Lb ¹`  4 X… 04c 4„  \bÿı+ +‹ +Œ 7œ Ã   x@#x@$x@ 8!Ô08Bˆ4£8„ihøoTx@#8!Ô\øn°7œÿğ[‹ [Œ [ [ ($Ì¸`` 4ßÈ$  4„ı ¸@h 4  Pd ¸@ 4 4  ûÿı4 D" x@(8!Lô('  4  4  É§ B 4ÿ€4	 4ÿ´‚ <! ´á (& \À (& DÃ 4„ Qÿø4  ¹` + +‹ +Œ + 7œ Ã   (!   !  d!  ´¡( T¬ ãÿÿñ(! ½! 4!ÿÿ´  ãÿÿì4 ¹` + +‹ +Œ + 7œ Ã   7œÿü[ ¸  (!  x@(8cLô ! (d  #àx@(8!0´# ÈD  (eĞ„ 4  T¤ (fÔ´¦( P… ¸` 4  ûÿÿ©d!  + 7œ Ã   7œÿä[‹ [Œ [ [ [ [ [ (# ($ (% (& ¸  ¸ X x@$4„ 8! Äønã)k  x@$8! ü¹` ønŞx@$8!Ø(-  x@$8Æ=¡mh }¥  E  x@ x@$x@$x@$9kh(8Æ=4  :!9ï À4 )d  5Œ ¡¤ Dƒ ñÌ 5k  £ \`ÿù]  x@#8!éìønÀ+ +‹ +Œ + + + + 7œ Ã   )c ¤€  ¸À º  ¡¤h øn±}¥  ¹à0 ãÿÿçx@$¸À ¹  8!!øn©ãÿÿæ7œÿè[‹ [Œ [ [ [ [ x@(9­K´)¢  ¸ p 4 <\A x@'x@(9Œ<œ9kK¸)  )b  È" L  'x@(8BK°(A  4! XA  4ÿÿYÁ 4 ûşá*+ +‹ +Œ + + + 7œ Ã   4A Y¡  D@ x@(8B¨x@((B  8!Lô(#  (B  x@$ÉÃ c 4B¨8!!Pønr¹À ûÿÿ|ûÿÎxømÆãÿÿàx@(9ïK°)â  \@ 4 Y¡  )  4!:˜Ya  ãÿÿåx@'x@(9Œ<œ9kK¸ãÿÿøx@$8!! øn[Yà  ãÿÿñ7œÿà[‹ [Œ [ [ [ [ [ ¸ X (!  ! D  Y` 4 ¼" L  x@$8!Ü(0  x@$8!Ø(/  4  4  xÿà)a )e )c )d  |¥  |c  4! ¸% ¸#   ¸#  ( 4     \  D£ Yd  5Œ µ£h 5k  HLÿìe¡  + +‹ +Œ + + + + 7œ  Ã   ¹` [‚  ûÿÿw4 +‚  ãÿÿí7œÿä[‹ [Œ [ [ [ [ [ (#  4 ¸ h  c ½Âp  c 4  D` )¡ 8\A *)¡  4   !  ! D  %)¢  4¿ÿ A Y¡  4 L. x@$8!à(/  5«  4 )b  5Œ  B€ D@ )b ]¢ )b   O Yb  5k  IÌÿöº  + +‹ +Œ + + + + 7œ Ã   ¹  ûÿÿ;6 ãÿÿî¹  ûÿÿ74 ãÿÿÙ7œÿÔ[‹ $[Œ  [ [ [ [ [‘ [’ [ X   X D¸ ` (A  ¸@X ¸`h  !À \  x@(8!Lô4 	(!  PC  4ÿ€Ym Ya 	­ ,<† 5b ´Í0 µ† (% $4& $X¢ Ye Yf X" $µh )¡ L4! Y¡ L4 \ }+ +‹ $+Œ  + + + + +‘ +’ 7œ ,Ã   Éa ! 4 ½@  !ÿ˜(@ É( <¥ )f  µe( (¢   Æ  B DÂ &4ÿ€Ym Ye 4 U¢ÿÒ5¦ 4 ¼æ8  (@ É ˜è <B È( <! µb ´A (G  ("   ç  B \âÿÂ(" \EÿÀ(! \Áÿ¾	­ ,<† 5b ´Í0 µ†( (¡ (X¢ (4¥ $Ye Ya X"  ãÿÿ½(¦ 4ÿ€\ÂÿÙ(¢ \bÿ×x@#8Æáœ(Ò  x@#8Æá (Ñ  ¸ h ¸` 4ÿÿ4 	4 4	ÿ€(§ (ª F ,¡ YG Xê  X² X± µ†0 (È LÈ-8 4M 5ÿÿXÈ L½Í@ <ç ™@ X° X  É( µgX <¥ Qí ãÿÿ†µe( )g  (¦   ç  Æ \æÿ­(¢ \Iÿ«(¢ \Mÿ©¸ h ãÿÿİ¸@ ¸` [ƒ ,[„ (ûÿÿ+ƒ ,+„ (D ÿmãÿÿƒ4 ¼#   Ğ   )‚L´b Y‚LĞ    Ğ   x@(8!L($  ´d X#  Ğ  ãÿÿt7œÿğ[‹ [Œ [ [ ¸ X ¸@` ûÿşÄD   h Ğ   x@'8„bä(‚ 4 ¼¬( ¹` ´¢( X… 4  4 ûÿúÜ¸   )a  x@(8¥0 ! Yd !à¹` ¹€ ´% ûÿÿ(Ğ  + +‹ +Œ + 7œ Ã   7œÿü[ (#  4   c  c D` (" 8ûÿÿĞ+ 7œ Ã   7œÿ°[‹ D[Œ @[ <[ 8[ 4[ 0[‘ ,[’ ([“ $[”  [• [– [— [˜ [™ [› [ [‚ PX   X D¸ x D@ –x@#x@#8!áœ8Bá x@((9  (X  + P4  4  4 :”Lô4 4ÿ€4
 
4 à  6µ >¡ ´a ($ 42 ^D 5­ 5Œ ¹ ¨ ]·ÿ÷4  6µ >¡ 4  ´a ($ 42 FDÿõE— p>µ ´u¨ à  (Yg Ys Tû 4á ½Á   ¦0 ÈÅ( ˜†  È†0 <¥ <Æ µe( ´¦0 (Ä  (¥   „  ¥ D¤ Kç ,>Æ 5d ´Ç0 µæ (% $4& $X¤ Ye Yf X$ $µç8 (á L4! Xá L6ÿÿF  L5ŒÿÿE€ÿÌ*¡ D2ÿÊ*± 6+ÿì)a )d X X$  *)ÿìYy Yx !!À )v \  b*…  ¹à 4  Ée( ¥  ¥ÿ½Ç0 ) ˜Å0 ÈÅ  <„ µd  (ˆ   ](ÿ¿(ˆ ]ÿ½(ˆ \èÿ»(ˆ (‰  Å0 ÈÅ( Y( Y	  X™ X˜ (( L<¥ 4ÿÿ5ÿÿX( L4ç X‚ X€ µeX 4! ,Dê 9)i  ¸À( ãÿÿŞ(Ä \“ÿµ(Â \"ÿ³ç ,>Å 5b ´§( µå  ( (X‚ (4„ $Yd Ya X"  ãÿÿ²º ` ãÿÿ  Ğ   )âL+ƒ P´b YâLĞ    Ğ   x@(8!L(#  +„ P´ƒ X#  Ğ  + +‹ D+Œ @+ <+ 8+ 4+ 0+‘ ,+’ (+“ $+”  +• +– +— +˜ +™ +› 7œ PÃ   Yg Ys ãÿÿ¹` 4  [ƒ L[Š Hûÿıÿ+ƒ L+Š H\ ÿ†*)ÿìãÿÿ–7œÿè[‹ [Œ [ [ [ [ ¸@h 4  ¸ X (,  ûÿı°\  	+ +‹ +Œ + + + 7œ Ã   Œ ¹` 	à4  4 x@(ûÿùÆ9Œ0Ya µ(  x Ğ   x@'8cbä(b ¸   4B Xb 4 LA 4 4 D" /µ` )Œ ]  !4„ <„ 5a µ„  (‚ 4ƒ XA Yb Yc X )‚  ) 4B Y‚  H" 	)‚ ¸  ¹€ ûÿşã)‚  ) ÈA Y  Ğ  + +‹ +Œ + + + 7œ Ã   4„ <„ 5b µ„  ( 4ƒ X‚ Yc Ya X"  ãÿÿà¸  ¹` 4  4 ûÿıÚãÿÿç7œÿü[    Ğ   (# 4cÿÿX# Ğ  \` DC ûÿş†+ 7œ Ã   4  ûÿÿ‘+ 7œ Ã   7œÿü[ D  x@(8cLô ! (c  <! ´a ûÿÿä+ 7œ Ã   7œÿô[‹ [Œ [ 4ğ 4Bÿ L` ´,` ¸ X P, ¹` 4  5k ûÿÿæU‹ÿü+ +‹ +Œ 7œ Ã   7œÿğ[‹ [Œ [ [ ¸ h D  x@(8!Lô¤ (%  4 4 ½‚` 4kÿ<„ 4ğ ¼" ¡fX µ` µmX ´¤  L" 4 X 04c 4„  \bÿıU‹ ¹  + +‹ +Œ + 7œ Ã   ¹` 4  5k ûÿÿ¸U‹ÿüãÿÿô7œÿğ[‹ [Œ [ [ (#  ¸ ` ¸@h 4aÿì(+ Eƒ 	5kÿì¹  ûÿÿ5)d 5c ¹` 4‹ÿì]ƒÿú+ +‹ +Œ + 7œ Ã   7œÿğ[‹ [Œ [ [ ø 'â¸ X \  à  Ğ  ¹` ø 'á¸ X D  )aØD ÿû h Ğ   )l )‚  D@ÿõ¹` ¹€ ûÿş6Y€  ãÿÿğ+ +‹ +Œ + 7œ Ã   7œÿü[ ø 'Å¸  D  
(CØ¸@ D` (B (B  \@ ø 'Á¸  \ ÿø  Ğ   x@(8!K¼($  4ÿş ƒ X#  Ğ  (!   ! D  	   !ÿşĞ  4  ûÿÿÂ  8! Ğ  + 7œ Ã     Ğ   x@(8!K¼(#  8c X#  Ğ  ãÿÿê7œÿ|[‹ D[Œ @[ <[ 8[ 4[ 0[‘ ,[’ ([“ $[”  [• [– [— [˜ [™ [› [ (éÌ[‚ d[… h¸  x@$Èé8 8¥Ôé (§  ¸`Ø +ƒ d‰'8 [ H4 7„ „[† X¹   [‡ |ø '+˜ „[ T4  G  š+ Hx@([… \ ) x@([ p+ Xx@'[… L ! 4 +… \[ `+ p¼[° x@$[‚ x8¥LÈ 8![‚ €[… \+‚ x+… L[ p+ H6‡ <ó x x@(x@(8Bˆ8¥bä '8 }5  [‚ x[… L:÷¨;9Lô[‡ t+‚ `D@ +… t\  õ+ X ! [ PD  ã+‚ Hx@$8!Ø B [‚ l(1  _` ˆ  Ğ   + µ“  (… 4 EÅ ¥F  Ğµ“  („ 4ÿì)¥ )¤ x 8B X… X¤  x  8¥ Y¢ Y¥ )„  4„ÿÿY„  +Ìxé½8B7§Ë  „ + Lˆ‚  4„ <„ ´$( (¤  ¶Ä  X¤  Ğ  L )§ )¥ )¦ )¤  |¥  4ç |Æ  ¸å( ¸¦(  ‘  ¸¤  5©  4
  \€ P5J ¹ @ JÊ ?+… H4 Y  Y¢  ¦€ DÀ L ¹ ` 4  *â  (A 4! XA +!  4  4 É ! <! ø†á*â  (A 4!ÿÿXA 5k 5Œ  JËÿïG` + H &@ \À M]  P+‚ T+ƒ d7„ „4A +‚ hø &è+˜ „[ T_ ÿ‘4  ¹  + +‹ D+Œ @+ <+ 8+ 4+ 0+‘ ,+’ (+“ $+”  +• +– +— +˜ +™ +› 7œ „Ã   )$ )" ) )  |B  4„ |c  ¸‚ ¸C  1 ¸A 5)  D ÿ³¹ h ¹  ûÿûbG`ÿz+ l\  m  Ğ   »  »` º€ ûÿøí¸ h D  E4  4 ûÿ÷É  Ğ   +L+… €´¤  [LĞ    Ğ   + \($  ´¤  X$  Ğ  ãÿÿv¹  »` ûÿôuE ÿ²+… P|¡  1¡ ãÿÿ¸) )  4  Eà ¹ÀX »`h à  ^  <)b  XD X" X+ Yd  X4 5­ Q¯ ¸€X »  4  º€ ûÿø¼4$ \ ÿñÈ8    Ğ   +L´æ0 [LĞ     Ğ   + \(%  ´å( X%  Ğ  µ“( (¤ µ°h Y  ]Äÿ3Ğ  ãÿÿ‚µ“  („ 4ÿìãÿÿ1+‚ X+… X+„ | F <Æ »  ·0 (Ã  »` ûÿô»+… PD%ÿr+˜ „ãÿÿ»  ø ;D ÿm+˜ „ãÿÿ)b 4$ Yd X+ X" XD  ãÿÿÄ4 L[ÿ“+… p@¤  „ D€ÿ+ x4áûşÜà+ p4 0"  ãÿÿˆ7œÿl[‹ D[Œ @[ <[ 8[ 4[ 0[‘ ,[’ ([“ $[”  [• [– [— [˜ [™ [› [ x@$8Æä(Å  ¸ X ¸@¨  %0 ¸`x ¸€€ DÅ Dx@(8¥K”(¥  4  \  !f üÑ@ e =  ¥ ¹ˆ )æ x@'8¥`P(¬  4  DÀ º 0 F  .4 !e ”å( 5á  ´ º€ ¸À 7„ ”ø &+‡ ”4  Dà x ¡lX ¹f° ºÀ º  º  ¹à  º€( 4 Aº @ ûÿşZ¸ h D  ¹  + +‹ D+Œ @+ <+ 8+ 4+ 0+‘ ,+’ (+“ $+”  +• +– +— +˜ +™ +› 7œ ”Ã   x@'8Æ`HãÿÿÑx@$8!!€4 œûşÜzãÿÿ¹!a [ H+ ”[ 4 
V¡ Ôx@([‚ T4 ¼U !a  [‚ dx @¡b [‚ p8" @x@([‚ tx [… X¡b f  [‚ L+‚ X[† h+† T8BK¤8! P[‚ Xx x@([ \!e  8Æğ!a€¡b 4  :÷¨[… P!s [† T[ x[‚ |[– €+… pD  Ñ+† H+Œ t\À + L\& +Œ \4ÿ¿¡†` +… L\  +† P\Å ’*é  + P)* !F DÁ )&  (Æ  Æ \Á ‰xÿ8Bÿ ¡BP ]@ )&  (Æ  Ç \ê )&  Æ \Ç ~!† @+… hdÆ   Å0 \À ×!x 4ÿû[˜ `+˜ T!y ¡† !Œ [™ „[Œ l4 €4 ¹ÀÈ +‡ ¹` º  º  ¹à  º€( º@0 º @ ûÿıÔ\  ¿+† lDÁ +Œ º  º  »   º€( 4 ¹€8 º @ ¹` ûÿıÇD  ¸ h ãÿÿm\3 N» x + HD  8*é  )'  (ç  ê ]@ 3)'  ç Dê F` /+ øo×*ç  7… ˆ¹à (ê  [€ ˆº  )I ¹` º   9) YI (é  Y%Hø !™*é  4÷ÿ¸ p )*  Y@H)*  )I ¡&H YI øo¿EÀ H4  à  ] ûÿıj4 º  º  ¹à  º€( º@0 ¹ 8 º @ ¹` ûÿıD ÿô¸ h ãÿÿ4+† `DÀ ¹` º  4  ûÿóæ4  ãÿÿ,·.È ^f Su + „D3ÿö+‚ dTY ãÿÿó+ 4  4 ø (^ãÿÿš¹€ 4  4 ø (Yãÿÿ¢9Œ ãÿÿ‚*é  )&  (Ç 4 cHæÿe)& xÿ8Bÿ  Â0 \Àÿ`+Œ \ãÿÿ^!k ]`ÿ
x@(9kAa  ! D ÿx@$8!ˆ4	cûşÛ•4 1a  ãÿşş+ x\6ÿÉ+‚ X» p @G  \àÿÇ*æ  (Æ  (Æ  Æ DÇ F`ÿÁ¹à ¹` +Œ ûÿïz\  !4 øi*^`ÿ24 V¦ÿ·ãÿÿ/+† xé½8¥7§(ÇÌ5á º€ ÈÇ0 Æ 4  7„ ŒˆÅh ø $×¸ ` +„ Œº  ¹  ¸€ D€ÿø 5 º€ 4  7„ Œø $Ë¸ ` ãÿÿô+ €º  º  ¹à  º€( 4 B¹€8 º @ ûÿıD  ¸ h ¹` ¹à ûÿïãÿş¾¸ h ãÿş¼5á º€ 4  7„ ø $³ãÿÿ%\3 4 V¦ 	+… |\³ ¹à ¹` º  º   4  ûÿïœ¹à ¹` ûÿïwãÿÿ½7œÿô[‹ [Œ [ 4Dÿÿ „ ¸@` 4  D€ xÿÿ ‚ 4  \@ <„ 4 xÿ  ‚ \@ <„ 4!ÿøxğ  ‚ \@ <„ 4!ÿüxÀ  ‚ \@ <„ 4!ÿş4+ÿÿL€ ¸ X ¸` x@(¹` 8cğ4  ûÿş9¸ ( 4  D  
x@(8„Lô(„  ¹` ¹€ È¤ ! <! ûÿü:+ +‹ +Œ 7œ Ã   7œÿü[ x@(8cğ4  ûÿş"¸  4  D` x@(8BLô(A  Èa ! <! + 7œ Ã   7œÿô[‹ [Œ [ 4$ÿÿ „ ¸ ` 4  D€ xÿÿ  4  \  <„ 4 xÿ   \  <„ 4¥ÿøxğ   \  <„ 4¥ÿüxÀ   \  <„ 4¥ÿş4«ÿÿL€ ¸ X ¸@ ¹` ûÿÿË¹` ¹€ ûÿûü+ +‹ +Œ 7œ Ã   7œÿü[ 4  8!€ ûÿÿ¾+ 7œ Ã   (C <(c  c \` H(%   ¥    Ğ   ¥àx@(8c0´e (et4¥ XetĞ     Ğ   x@(8cL(e (4¥ Xe (Ğ  ($   „   Ğ   „àx@(8!0´$ ($¬4„ X$¬Ğ    Ğ   x@(8!L($ `4„ X$ `Ğ  (A <x@(8c¨(% $(&  (d  4£ ô£( X# $´¦ X#  (A <(# 4(% 04b ôb X" 4´e X" 0(  ("€4B X"€  Ğ   x@'8!`è(#  4c X#  Ğ  Ã   (#   c   Ğ   càx@(8!0´# (#x4c X#xĞ    Ğ   x@(8!L(# ,4c X# ,Ğ  Ã   (" D@ ,(C <(c  c \` (x@(8c¨(c  (c  (d€4„ÿÿXd€($   „   Ğ   „àx@(8!0´$ ($¬4„ÿÿX$¬Ğ    Ğ   x@(8!L($ `4„ÿÿX$ `Ğ  (A <  Ğ   (% 4($ 04¢ÿÿô¢( 4„ÿÿ´¤  X$ 0X" 4Ğ  Ã   7œÿü[ 4! øyÇ+ 7œ Ã   7œÿè[‹ [Œ [ [ [ [ (" ¸ X  A D    Ğ   )l  9‚  Yb  Ğ  !Œ  }Œ  ]€ ¹` ûÿÿ¡¹€ + +‹ +Œ + + + 7œ Ã   DAÿì(N < x Ğ     Ğ   )l  9ƒ  Yc  Ğ  !Œ  }Œ  4M E€ )a   !  ! D  )b ¹  4 øwĞ  ãÿÿİ)b ¹  4 øz·)Á  !