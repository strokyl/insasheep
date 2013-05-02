.section    .text, "ax", @progbits
.global     boot_helper
boot_helper:
	/* Invalidate instruction cache */
	wcsr ICC, r0
	nop
	nop
	nop
	nop
	calli 0x0920000
	/*call r5*/
