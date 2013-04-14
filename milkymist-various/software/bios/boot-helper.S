.section    .text, "ax", @progbits
.global     boot_helper
boot_helper:
	/* Invalidate instruction cache 
	wcsr ICC, r0
	nop
	nop
	nop
	nop
	/*call r5 */
	/*calli 0x0860000*/
	calli 0x0920000
