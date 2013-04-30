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
�4� <� 4B �%( (�  P� ��  Q�������7���[� [� [� [� x@'� 2�9�`T4 D  4 5k��=d X  X ���  (�  ("�L 	e��C  �% Xd (c�E` 5k��=d �C ��  (�  L 	e��C  �% Xd (c�]`��� 2�\+������+� +� +� +� 7� à  X�  4 ����7���[� [� x@(8BK�(B  � X x@(Yb Y` 8!L(!  Ya �)�Ya 4 Y` ,Y` 0Ya 4+� +� 7� à  7���[� [� [� � ` x@(8!��� 4  7� � 2�+� 4  D� (��(� 4! �� 4  7� ��8 P� �gX � 2�+� \����` +� +� +� 7� à  7���[� 4  ����+� 7� à  x@$8��(�  4 4 4�����<g 4����$  (�شG8 E  X� (��4c ȉ  � ��  X� \���` à  7���[� [� [� [� [� [� (,�4-�4  �� � x ���ݸ  5� H  x@(8!0�� ���ָ  L x@(4  9�0E` 5k I���4c �<c ��x Y� Y� +� +� +� +� +� +� 7� à  �� �� �����  ����7���[� [� � X D  ("�\@ x@(9k0�` ����x@'8B`h4 x@'x@'x@'8�`t8�`|8c`�XA 4  Y`�X@  X@ XE XE XD XD XC XC  +� +� 7� à  ����Y`�����x@4$  8cddX� X� ($  4 �b 8�@ X$  Lb �  4 (e  X` 0Xa <8�� Xe  4� 4c  \���à  7���[� [� [� [� [� (F  (g  x@( �  � ����8�0��0 ��( � X \� /4  Pb +� +� +� +� +� 7� à  <� 4��4  4 (E D� 
4B  Pb��+� +� +� +� +� 7� à  (E (G (I � ,4H Y' ��P X�  �j8 (� $4� $Y( XI XJ ��H X� $��( XD �I �% Pb������x@#x@$x@ 8!�08B�4�8�i��ux@#8!�\�ts7���[� x@(8�L�(�  4� (&��G( � ��( <� �`  ��8 4��T� �� (#�4  ��0 Q 4������� ( �� +� 7� à  4 �b Lb 4 X$ 04c 4!  \b��à  (&L4� <� 4 �@ �$  4�  �  (�  ��0 D�  g ��8 � �g  � D� e  � ��( � �e �d( 4  L� 4 L 
(% Lc 4  ��( Le 4� c HD 4 �� à  (& x4! ,��0 Ȧ( Le ����4  �� à  (' (&LD� P� (&L4 4� ��@ <� ��8 �$   �  (�  ��0 E   g ��8 � �g  � D� e  � ��( � �e �d( 4  L� 4 L 
(% Lc 4  ��( Le 4� c HD 4 �� à  (& x4! ,��0 Ȧ( Le ����4  �� à  7���[� [� [� [� [� [� ([� ,[� 0[� 4[� 8[� < , � X �@h E� +� +� +� +� +� 7� <à  x@'x@ 8!`�8BiT[� ���+� D,��x x@(�a 4 9��\  )�  4  ("  B  B \L (!  (, !�e�  )�  x@$8�p(" (�  �A \  !b \A 4����` \` )�  �� �`  ("  x@$8!�4B��tK�s��� �������x@$7� ,[� 7� 7� $8!�[� $[�  �t>���� $   % 8� @\� x �# \e 8� P4���D \`  !  \# x@(8!�(!  (#  d \� x@$8�p(�  �d \` ($  (�  � D� 8B  A  ! à  x@(8c�(c  4 c(e  (� L� x �# ����($  (�  � D���8B ����(!  !  ! \$�� A  ! à  x@$8�p(e (�  �� \`��8� P����7���[� 4 ����+� 7� à   # 4  D` 
 A x@'<! 8c`H�# (a  �"  ! ! à  7���[� �[� �[� �[� �[� �[� �[� �[� |[� x[� t[� p[� l[� h[� d[� `[� \[� X� � � 0�� X D  !x@$x@$x@'"� 9��9��9�`H�  )b��s�)e 4  �� (� (� (�  �sù` � 0q� X D  )b�D@���� E���)�   B \@��` � 0f� X \ ��x@(x@(x@(x@(x@(x@(x@(x@(x@(x@(x@(x@(x@(x@(x@(x@(x
@(x	@(:sL4:RL8:1LL:L9�L<9�L@9�Lh9kLD9JLP9)Lx8BL8cL8�L`8�L8�L8�Ld9L 9�L,(B  (c  (�  (�  (�  (�  )  *u  *T  *3  *  )�  )�  )�  )�  )l  )K  )*  x	@$�  8![� ([� ,[� [� [� [� [� [� [� [�  [� $�so� 0� X D  �x@$x@$x@$x@$x@%x@$x@'"� :s�9� :R�9�t�:1:|�9�`H)i�E  ��� ]� �)cL)gT)hP)j\)tX)u`)w�)x�)yd)bt=) =J [� �)dx? ?9 [� �)el>� >� [� �)f�)e >� [� �){|<c <� [� �)}�<� = [� �)b�)d�[� �)f�[� �){�)fD[� �)}�<[ )b�[� �)d�{ 
[� �[� �[� �+� �)}  [� �=) +� �?� [� �)} +� �=J ?� =) +� �[� �+� �[� �+� �?� =J [� �[� �== +� �+� �[� �[� �=8 =Y +� �+� �[� �[� �=5 =W )i  +� �[� �=T �`P E  � P +� �[� 8+� �[� +� �[� 4[� <[� +� �[� @[� D[� +� �[� H[� L[� +� �[� P[� +� �[� +� �[� +� �[�  +� �[� $+� �[� (+� �[� ,+� �[� 0[� T�rۺ@ �r�)b �� �r�)b �� �rӺ  �rѹ` � /� X \ �q� /w� X D  2x@$x@$x@$x@'"� :�7� �4 9� 4 9�9�`H)b�D@  ]� D)bܺ  �r�� ( �   4  �`  �@� �@ 4  (� L4� ,��0 XG  4c ��� 4B \q���  4  *�  �t �� 6� �r�6� ^���>� �� �r��` � /K� X \ ��x@(8!L0("  x@$8!�r�+� X+� �+� �+� �+� �+� �+� �+� �+� |+� x+� t+� p+� l+� h+� d+� `+� \7�à  )�   B \@�%�` � /+� X \ �����)�   B \@���` � /#� X \ ������7���[� ��*���4  +� 7� à  7���[� [� [� [� �@` �� + e�  �bX E` +� +� +� +� 7� à  � /�  4  Dk��x@(9kK�4�4 `�  � .��  D  (bظ` D@��)d  (c �D  D Xb D� Xd Q���Xm � .�  \ ��4  +� +� +� +� 7� à  4 ����(&  x@(8�L� � (�  ��x@(8�0��  �% (��! (��%  ! 
<% ��  4  HC ��  4  � 4B <� ��0 (�  ��0 4�  � D� �% HC <� ����à  7���[� [� ('  x@(8�L� � (�  ��x@(8�0��( �& (��! (��&  ! 
<& �� Hd �# 4 4	 �  (�  ��` X�  4c 4! Hd <�  & �!P <� �@` �0 �@X ��P ��8 ]@��(�  �KX X�  ����+� +� 7� à  7���[� x@(8cK�(e  4 4  d�  �( �E ����+� 7� à  7���[� D[� @[� <[� 8[� 4[� 0[� ,[� ([� $[�  [� [� [� [� [� [� [� x@';{`\�` �t$x@'8!`X(9  � .b4  D  ("ض�� � .b\ ��� .[� � D  Rx@(x@(9 4 9�L�:1L�4 8� � � �   *�4  �  4  ���[� H[� L\  x�U� [� LZ  +� L+� H*� c <� 4���� �C Z +� L+� H*� c <� � 
�� �C =� 
Z ��x Q� #6R�R 
O 4 5� =� )�  5�� Qc *4  4  4 ��� �� ���CF@ D��( Q� ��( Qe 
*#  �m  (�   � \� 5�  �d 5k T� #D7 1D8 )5� ��h U� �  �  � .� � \ �����ٻ` �sk+� +� D+� @+� <+� 8+� 4+� 0+� ,+� (+� $+�  +� +� +� +� +� +� 7� Là  �`` ����(d  4c   � D���5� ��h U������ܺ� 4 ���\�  �� 4 ���#6R��5� ��h U�������\7�̺� 4 ���O4 �  �� ���5� ��h U�������7� H�� ��Z+� L����7���[� [� �@X ��E` ���I4  +� +� 7� à  7���[� D[� @[� <[� 8[� 4[� 0[� ,[� ([� $[�  [� [� [� [� [� [� [� U ,�@p 4B B ,� x 6�  �� [� L[� Hx@#x@#x@ x@(8!�8B�4 
�`� 4 (8  (W  4��4��:�i4 :sK�RN ~! 4 ��  4  \� 8�` +� +� D+� @+� <+� 8+� 4+� 0+� ,+� (+� $+�  +� +� +� +� +� +� 7� Là  >( �  �� (! $��  4� $D$ �+� H��0 ��( 4$ � �� (+ $��( 4���5k��)g )j �&H YG X�  Yx Yw Yv Y` (� L��8 4!��X� LH� Med  ~! ��  D���I� D>$ 4 
�� ('  4� ��  4� ;<! <� �� 4) D� �	� ,)#  �@ �H �� ��h 4B $5� $Db r��  (� L�( �� (+ $i� f! 4���X� L��  5k��\� <*a  \$ :)a )c Xa X#  Yx Yw Yv Y` M� >( 5��Կ,( �H   � (�  <� �H8 �a 4# X� X& X' X�  (C (5���4���4c XC (X, X0 I� ]`��4 RN�����~4���) (�  =! ��( �a 4" Xb X# X% X�  (� (4���4���4B X� (X& X0 H�������4B�����չ` �� �  ���84�H" *a  D  �` �  ���f)a )d X� X$  Yx Yw Yv Y` ]����` �  ���Z����+� L��0 � �� 4! $4� 4 � ,D��G(#  � �� ��  4B $4� $4! ,\b�c������( (�  4� <A D[ �( �� (c $�� 4B $\b������5���5)��I������v7���[� ,[� ([� $[�  [� [� [� [� [� [� [� ($ � X 4���@p �`� \� �)q  x@()m 1 9�0
1�4 �M` �/� * 4  �  �� 4  4  ���4  \  �@ +� +� ,+� (+� $+�  +� +� +� +� +� +� 7� ,à  )a )b x@#8c�XA X"  (a  x@#8c�	� ,Ya (a  �� �� Ya (C L�` 4c��XC L4��Yb Y` 4  4 ����4 \" 5E� M� �� 4!  �/ >c 4&�ش�0 4! ��( 4	��� (�  =� 4!�Եd  4� Y �# X� X� X�  (" (4���4���4B X" (X� X� H���4 P- 4  ��` 5���l` Ql 4 8� �` 4  4 ���kD/ �` 4 �����mX U���4 �N �����N � �  �   *L�C ZL�  �  �   x@(8!L($  �D X"  �  ����x@#x@$x@ 8!�08B�4o8�ix�o{x@#8!�\�n�7���[� [� [� (# 4��� X \b (, 4  �� ���XD  4 �l Yc Lb �`  4 X� 04c 4�  \b��+� +� +� 7� à  x@#x@$x@ 8!�08B�4�8�ih�oTx@#8!�\�n�7���[� [� [� [� ($̸`` 4��$  4�� �@h 4  Pd �@ 4 4  ���4 D" x@(8!L�('  4  4  ɧ B 4��4	 4��� <! �� (& \� (& D� 4� Q��4  �` +� +� +� +� 7� à  (!   !  d!  ��( T� ����(! �! 4!����  ����4 �` +� +� +� +� 7� à  7���[� �  (!  x@(8cL� ! (d  #�x@(8!0�# �D  (e�� 4  T� (fԴ�( P� �` 4  ����d!  +� 7� à  7���[� [� [� [� [� [� [� (# ($ (% (& �  � X x@$4� 8! ��n�)k  x@$8! ��` �n�x@$8!�(-  x@$8�=�mh }�  E� x@ x@$x@$x@$9kh(8�=4  :!9� �4 )d  5� �� D� �� 5k �� \`��]� x@#8!���n�+� +� +� +� +� +� +� 7� à  )c ��  �� �  ��h �n�}�  ��0 ����x@$�� �� 8!!�n�����7���[� [� [� [� [� [� x@(9�K�)�  � p 4 <\A x@'x@(9�<�9kK�)�  )b  �" L  'x@(8BK�(A  4! XA  4��Y� 4 ���*+� +� +� +� +� +� 7� à  4A Y�  D@ x@(8B�x@((B  8!L�(#  (B  x@$�� c 4B�8!!P�nr�� ���|���x�m�����x@(9�K�)�  \@ 4 Y�  )�  4!:�Ya  ����x@'x@(9�<�9kK�����x@$8!! �n[Y�  ����7���[� [� [� [� [� [� [� � X (!  ! D  Y` 4 �" L  x@$8!�(0  x@$8!�(/  4  4  x��)a )e )c )d  |�  |c  4! �% �# �� �# ��( 4  ��  \  D� Yd  5� ��h 5k  HL��e�  +� +� +� +� +� +� +� 7�  à  �` [�  ���w4 +�  ����7���[� [� [� [� [� [� [� (#  4 � h  c ��p  c 4  D` )� 8\A *)�  4   !  ! D  %)�  4���A Y�  4 L. x@$8!�(/  5�  4 )b  5�  B� D@ )b ]� )b  �O Yb  5k  I����  +� +� +� +� +� +� +� 7� à  �� ���;6 ��� ���74 ����7���[� $[�  [� [� [� [� [� [� [� X   X D� ` (A  �@X �`h  !� \  �x@(8!L�4 	(!  PC  4��Ym Ya 	� ,<� 5b ��0 �� (% $4& $X� Ye Yf X" $��h )� L4! Y� L4 \� }+� +� $+�  +� +� +� +� +� +� 7� ,à  �a ! 4 �@  !��(@ �( <� )f  �e( (�   �  B D� &4��Ym Ye 4 U���5� 4 ��8 �(@ � �� <B �( <! �b �A (G  ("   �  B \���(" \E��(! \���	� ,<� 5b ��0 ��( (� (X� (4� $Ye Ya X"  ����(� 4��\���(� \b��x@#8��(�  x@#8��(�  � h �` 4��4 	4 4	��(� (� F ,� YG X�  X� X� ��0 (� L�-8 4M 5��X� L��@ <� �@ X� X� �( �gX <� Q� �����e( )g  (�   �  � \���(� \I��(� \M��� h ���ݸ@ �` [� ,[� (���+� ,+� (D �m����4 �# �  �   )�L�b Y�L�  �  �   x@(8!L($  �d X#  �  ���t7���[� [� [� [� � X �@` ����D  � h �   x@'8�b�(� 4 ��( �` ��( X� 4  4 ���ܸ   )a  x@(8�0 ! Yd !�` �� �% ���(�  +� +� +� +� 7� à  7���[� (#  4   c  c D` (" 8����+� 7� à  7���[� D[� @[� <[� 8[� 4[� 0[� ,[� ([� $[�  [� [� [� [� [� [� [� [� PX   X D� x D@ �x@#x@#8!�8B�x@((9  (X  +� P4  4  4 :�L�4 4��4
 
4 �  6� >� �a ($ 42 ^D 5� 5� ��� ]���4  6� >� 4  �a ($ 42 FD��E� p>� �u� �  (Yg Ys T� 4� ��  ��0 ��( ��  Ȇ0 <� <� �e( ��0 (�  (�   �  � D� K� ,>� 5d ��0 �� (% $4& $X� Ye Yf X$ $��8 (� L4! X� L6��F  L5���E���*� D2��*� 6+��)a )d X� X$  *)��Yy Yx !!� )v \  b*�  �� 4  �e( �  ����0 ) ��0 ��  <� �d  (�   ](��(� ]��(� \���(� (� ��0 ��( Y( Y	  X� X� (( L<� 4��5��X( L4� X� X� �eX 4! ,D� 9)i  ��( ����(� \���(� \"��� ,>� 5b ��( ��  (� (X� (4� $Yd Ya X"  ����� ` �����  �   )�L+� P�b Y�L�  �  �   x@(8!L(#  +� P�� X#  �  +� +� D+� @+� <+� 8+� 4+� 0+� ,+� (+� $+�  +� +� +� +� +� +� 7� Pà  Yg Ys ����` 4  [� L[� H����+� L+� H\ ��*)������7���[� [� [� [� [� [� �@h 4  � X (,  ����\  	+� +� +� +� +� +� 7� à  � �` 	��4  4 x@(����9�0Ya ��( � x �   x@'8cb�(b �   4B Xb 4 LA 4 4 D" /��` )� ]� !4� <� 5a ��  (� 4� XA Yb Yc X� )�  )� 4B Y�  H" 	)� �� �� ����)�  )� �A Y�  �  +� +� +� +� +� +� 7� à  4� <� 5b ��  (� 4� X� Yc Ya X"  ���ภ �` 4  4 ��������7���[� �   �   (# 4c��X# �  \` DC ����+� 7� à  4  ����+� 7� à  7���[� D  x@(8cL� ! (c  <! �a ����+� 7� à  7���[� [� [� 4� 4B��L` �,` � X P, �` 4  5k ����U���+� +� +� 7� à  7���[� [� [� [� � h D  x@(8!L�� (%  4 4 ��` 4k�<� 4� �" �fX ��` �mX ��  L" 4 X� 04c 4�  \b��U� �� +� +� +� +� 7� à  �` 4  5k ����U�������7���[� [� [� [� (#  � ` �@h 4a��(+ E� 	5k�칠 ���5)d 5c �` 4���]���+� +� +� +� 7� à  7���[� [� [� [� � '� X \  �  �  �` � '� X D  )a�D ��� h �   )l )�  D@���` �� ���6Y�  ����+� +� +� +� 7� à  7���[� � 'Ÿ  D  
(Cظ@ D` (B (B  \@ � '��  \ ���  �   x@(8!K�($  4���� X#  �  (!   ! D  	�   !���  4  ���  8! �  +� 7� à  �  �   x@(8!K�(#  8c X#  �  ����7��|[� D[� @[� <[� 8[� 4[� 0[� ,[� ([� $[�  [� [� [� [� [� [� [� (��[� d[� h�� x@$��8 8��� (�  �`� +� d�'8 [� H4� 7� �[� X� � [� |� '�+� �[� T4  G  �+� Hx@([� \ ) x@([� p+� Xx@'[� L ! 4 +� \[� `+� p�[� x@$[� x8�L� 8![� �[� \+� x+� L[� p+� H6� <� x x@(x@(8B�8�b�'8 }5  [� x[� L:��;9L�[� t+� `D@ +� t\� �+� X ! [� PD  �+� Hx@$8!� B [� l(1  _` �� � �   + ��  (� 4� E� �F� е�  (� 4���)� )� x 8B X� X�  x  8� Y� Y� )�  4���Y�  +�x�8B7��  � +� L��  4� <� �$( (�  ��  X�  �  L )� )� )� )�  |�  4� |�  ��( ��( ��  ��  5�  4
  \� P5J � @ J� ?+� H4 Y� Y�  �� D� L ��` 4  *�  (A 4! XA +!  4  4 Ɂ ! <! ���*�  (A 4!��XA 5k 5�  J���G` +� H &@ \� M]� P+� T+� d7� �4A +� h� &�+� �[� T_ ��4  �� +� +� D+� @+� <+� 8+� 4+� 0+� ,+� (+� $+�  +� +� +� +� +� +� 7� �à  )$ )" ) )  |B  4� |c  �� �C �1 �A 5)  D ��� h �� ���bG`�z+� l\  m� � �   �  �` �� ���� h D  E4  4 ���ɐ  �   +L+� ���  [L�  �  �   +� \($  ��  X$  �  ���v�� �` ���uE���+� P|�  1� ����)� )�  4  E� ��X �`h �  ^� <)b  XD X" X+ Yd  X4 5� Q� ��X �  4  �� ����4$ \ ���8 �   �   +L��0 [L�  �   �   +� \(%  ��( X%  �  ��( (� ��h Y�  ]��3�  ������  (� 4������1+� X+� X+� | F <� �  �0 (�  �` ����+� PD%�r+� �����  � ;D �m+� ����)b 4$ Yd X+ X" XD  ����4 L[��+� p@�  � D���+� x4�����+� p4 0"  ����7��l[� D[� @[� <[� 8[� 4[� 0[� ,[� ([� $[�  [� [� [� [� [� [� [� x@$8��(�  � X �@� �%0 �`x ��� D� Dx@(8�K�(�  4  \� !f ��@ e =  � �� )� x@'8�`P(�  4  D� � 0 F  .4 !e ��( 5�  � �� �� 7� �� &+� �4  D� x �lX �f� �� �  �� ��  ��( 4 A� @ ���Z� h D  �� +� +� D+� @+� <+� 8+� 4+� 0+� ,+� (+� $+�  +� +� +� +� +� +� 7� �à  x@'8�`H����x@$8!!�4 ����z����!a [� H+� �[� �4 
V� �x@([� T4 �U !a  [� dx @�b [� p8" @x@([� tx [� X�b f  [� L+� X[� h+� T8BK�8! P[� Xx x@([� \!e  8��!a��b 4  :��[� P!s [� T[� x[� |[� �+� pD� �+� H+� t\� �+� L\& +� \4����` +� L\� +� P\� �*�  +� P)* !F D� )&  (�  � \� �x�8B� �BP ]@ )&  (�  � \� �)&  � \� ~!� @+� hd�  ��0 \� �!x 4��[� `+� T!y ��� !� [� �[� l4 �4 ��� +� ��` �  �� ��  ��( �@0 � @ ����\  �+� lD� +� ��  �� �   ��( 4 ��8 � @ �` ����D  � h ���m\3 N� x +� HD  8*�  )'  (�  � ]@ 3)'  � D� F` /+� ��o�*�  7� ��� (�  [� ��� )I �` �   9) YI (�  Y%H� !�*�  4��� p )*  Y@H)*  )I �&H YI �o�E� H4  �  ]� ���j4 �  �� ��  ��( �@0 ��8 � @ �` ����D ��� h ���4+� `D� �` �� 4  ����4  ���,�.� ^f Su +� �D3��+� dTY ����+� �4  4 � (^������ 4  4 � (Y����9� ����*�  )&  (� 4 cH��e)& x�8B� ��0 \��`+� \���^!k ]`�
x@(9kAa  ! D �x@$8!�4	c��ە4 1a  ����+� x\6��+� X� p @G  \���*�  (�  (�  � D� F`���� �` +� ����z\  !4 �i*^`�24 V������/+� �x�8�7�(��5� �� ��0 � 4  7� ���h � $׸ ` +� ��� �� �� D��� 5� �� 4  7� �� $˸ ` ����+� ��  �� ��  ��( 4 B��8 � @ ���D  � h �` �� �������� h ����5� �� 4  7� �� $����%\3 4 V� 	+� |\� �� �` �� �   4  ��� �` ���w����7���[� [� [� 4D�� � �@` 4  D� x���� 4  \@ <� 4 x� �� \@ <� 4!��x� �� \@ <� 4!��x� �� \@ <� 4!��4+��L� � X �` x@(�` 8c�4  ���9� ( 4  D� 
x@(8�L�(�  �` �� Ȥ ! <! ���:+� +� +� 7� à  7���[� x@(8c�4  ���"�  4  D` x@(8BL�(A  �a ! <! +� 7� à  7���[� [� [� 4$�� � � ` 4  D� x���� 4  \  <� 4 x� �� \  <� 4���x� �� \  <� 4���x� �� \  <� 4���4���L� ��X �@ �` ���˹` �� ����+� +� +� 7� à  7���[� 4  8!� ����+� 7� à  (C <(c  c \` H(%   � �   �   ��x@(8c0�e (et4� Xet�  �   �   x@(8cL(e (4� Xe (�  ($   � �  �   ��x@(8!0�$ ($�4� X$��  �  �   x@(8!L($ `4� X$ `�  (A <x@(8c�(% $(&  (d  4� ��( X# $�� X#  (A <(# 4(% 04b �b X" 4�e X" 0(�  ("�4B X"��  �   x@'8!`�(#  4c X#  �  à  (#   c �  �   c�x@(8!0�# (#x4c X#x�  �  �   x@(8!L(# ,4c X# ,�  à  (" D@ ,(C <(c  c \` (x@(8c�(c  (c  (d�4���Xd�($   � �  �   ��x@(8!0�$ ($�4���X$��  �  �   x@(8!L($ `4���X$ `�  (A <�  �   (% 4($ 04�����( 4�����  X$ 0X" 4�  à  7���[� 4! �y�+� 7� à  7���[� [� [� [� [� [� (" � X  A D  �  �   )l  9�  Yb  �  !�  }�  ]� �` ������ +� +� +� +� +� +� 7� à  DA��(N <� x �   �  �   )l  9�  Yc  �  !�  }�  4M E� )a   !  ! D  )b �� 4 �w��  ����)b �� 4 �z�)�  !