
software/bios/bios.elf:     file format elf32-lm32


Disassembly of section .text:

00860000 <_ftext>:
  860000:	98 00 00 00 	xor r0,r0,r0
  860004:	d0 00 00 00 	wcsr IE,r0
  860008:	78 01 00 86 	mvhi r1,0x86
  86000c:	38 21 00 00 	ori r1,r1,0x0
  860010:	d0 e1 00 00 	wcsr EBA,r1
  860014:	98 42 10 00 	xor r2,r2,r2
  860018:	e0 00 00 33 	bi 8600e4 <_crt0>

0086001c <_breakpoint_handler>:
  86001c:	e0 00 00 00 	bi 86001c <_breakpoint_handler>
  860020:	34 00 00 00 	nop
  860024:	34 00 00 00 	nop
  860028:	34 00 00 00 	nop
  86002c:	34 00 00 00 	nop
  860030:	34 00 00 00 	nop
  860034:	34 00 00 00 	nop
  860038:	34 00 00 00 	nop

0086003c <_instruction_bus_error_handler>:
  86003c:	e0 00 00 00 	bi 86003c <_instruction_bus_error_handler>
  860040:	34 00 00 00 	nop
  860044:	34 00 00 00 	nop
  860048:	34 00 00 00 	nop
  86004c:	34 00 00 00 	nop
  860050:	34 00 00 00 	nop
  860054:	34 00 00 00 	nop
  860058:	34 00 00 00 	nop

0086005c <_watchpoint_hander>:
  86005c:	e0 00 00 00 	bi 86005c <_watchpoint_hander>
  860060:	34 00 00 00 	nop
  860064:	34 00 00 00 	nop
  860068:	34 00 00 00 	nop
  86006c:	34 00 00 00 	nop
  860070:	34 00 00 00 	nop
  860074:	34 00 00 00 	nop
  860078:	34 00 00 00 	nop

0086007c <_data_bus_error_handler>:
  86007c:	e0 00 00 00 	bi 86007c <_data_bus_error_handler>
  860080:	34 00 00 00 	nop
  860084:	34 00 00 00 	nop
  860088:	34 00 00 00 	nop
  86008c:	34 00 00 00 	nop
  860090:	34 00 00 00 	nop
  860094:	34 00 00 00 	nop
  860098:	34 00 00 00 	nop

0086009c <_divide_by_zero_handler>:
  86009c:	e0 00 00 00 	bi 86009c <_divide_by_zero_handler>
  8600a0:	34 00 00 00 	nop
  8600a4:	34 00 00 00 	nop
  8600a8:	34 00 00 00 	nop
  8600ac:	34 00 00 00 	nop
  8600b0:	34 00 00 00 	nop
  8600b4:	34 00 00 00 	nop
  8600b8:	34 00 00 00 	nop

008600bc <_interrupt_handler>:
  8600bc:	5b 9d 00 00 	sw (sp+0),ra
  8600c0:	f8 00 00 19 	calli 860124 <.save_all>
  8600c4:	f8 00 00 37 	calli 8601a0 <isr>
  8600c8:	e0 00 00 27 	bi 860164 <.restore_all_and_eret>
  8600cc:	34 00 00 00 	nop
  8600d0:	34 00 00 00 	nop
  8600d4:	34 00 00 00 	nop
  8600d8:	34 00 00 00 	nop

008600dc <macaddress>:
  8600dc:	10 e2 d5 00 	lb r2,(r7+-11008)
  8600e0:	00 00 00 00 	srui r0,r0,0

008600e4 <_crt0>:
  8600e4:	78 1c 40 00 	mvhi sp,0x4000
  8600e8:	3b 9c 3f fc 	ori sp,sp,0x3ffc
  8600ec:	78 1a 00 86 	mvhi gp,0x86
  8600f0:	3b 5a 1f 40 	ori gp,gp,0x1f40
  8600f4:	78 01 40 00 	mvhi r1,0x4000
  8600f8:	38 21 00 00 	ori r1,r1,0x0
  8600fc:	78 03 40 00 	mvhi r3,0x4000
  860100:	38 63 20 30 	ori r3,r3,0x2030

00860104 <.clearBSS>:
  860104:	44 23 00 04 	be r1,r3,860114 <.callMain>
  860108:	58 20 00 00 	sw (r1+0),r0
  86010c:	34 21 00 04 	addi r1,r1,4
  860110:	e3 ff ff fd 	bi 860104 <.clearBSS>

00860114 <.callMain>:
  860114:	b8 40 08 00 	mv r1,r2
  860118:	34 02 00 00 	mvi r2,0
  86011c:	34 03 00 00 	mvi r3,0
  860120:	e0 00 00 2b 	bi 8601cc <main>

00860124 <.save_all>:
  860124:	37 9c ff c8 	addi sp,sp,-56
  860128:	5b 81 00 04 	sw (sp+4),r1
  86012c:	5b 82 00 08 	sw (sp+8),r2
  860130:	5b 83 00 0c 	sw (sp+12),r3
  860134:	5b 84 00 10 	sw (sp+16),r4
  860138:	5b 85 00 14 	sw (sp+20),r5
  86013c:	5b 86 00 18 	sw (sp+24),r6
  860140:	5b 87 00 1c 	sw (sp+28),r7
  860144:	5b 88 00 20 	sw (sp+32),r8
  860148:	5b 89 00 24 	sw (sp+36),r9
  86014c:	5b 8a 00 28 	sw (sp+40),r10
  860150:	5b 9e 00 30 	sw (sp+48),ea
  860154:	5b 9f 00 34 	sw (sp+52),ba
  860158:	2b 81 00 38 	lw r1,(sp+56)
  86015c:	5b 81 00 2c 	sw (sp+44),r1
  860160:	c3 a0 00 00 	ret

00860164 <.restore_all_and_eret>:
  860164:	2b 81 00 04 	lw r1,(sp+4)
  860168:	2b 82 00 08 	lw r2,(sp+8)
  86016c:	2b 83 00 0c 	lw r3,(sp+12)
  860170:	2b 84 00 10 	lw r4,(sp+16)
  860174:	2b 85 00 14 	lw r5,(sp+20)
  860178:	2b 86 00 18 	lw r6,(sp+24)
  86017c:	2b 87 00 1c 	lw r7,(sp+28)
  860180:	2b 88 00 20 	lw r8,(sp+32)
  860184:	2b 89 00 24 	lw r9,(sp+36)
  860188:	2b 8a 00 28 	lw r10,(sp+40)
  86018c:	2b 9d 00 2c 	lw ra,(sp+44)
  860190:	2b 9e 00 30 	lw ea,(sp+48)
  860194:	2b 9f 00 34 	lw ba,(sp+52)
  860198:	37 9c 00 38 	addi sp,sp,56
  86019c:	c3 c0 00 00 	eret

008601a0 <isr>:
  8601a0:	37 9c ff fc 	addi sp,sp,-4
  8601a4:	5b 9d 00 04 	sw (sp+4),ra
  8601a8:	90 40 08 00 	rcsr r1,IP
  8601ac:	90 20 10 00 	rcsr r2,IM
  8601b0:	a0 41 08 00 	and r1,r2,r1
  8601b4:	20 21 00 01 	andi r1,r1,0x1
  8601b8:	44 20 00 02 	be r1,r0,8601c0 <isr+0x20>
  8601bc:	f8 00 04 71 	calli 861380 <uart_isr>
  8601c0:	2b 9d 00 04 	lw ra,(sp+4)
  8601c4:	37 9c 00 04 	addi sp,sp,4
  8601c8:	c3 a0 00 00 	ret

008601cc <main>:
  8601cc:	37 9c ff 88 	addi sp,sp,-120
  8601d0:	5b 8b 00 34 	sw (sp+52),r11
  8601d4:	5b 8c 00 30 	sw (sp+48),r12
  8601d8:	5b 8d 00 2c 	sw (sp+44),r13
  8601dc:	5b 8e 00 28 	sw (sp+40),r14
  8601e0:	5b 8f 00 24 	sw (sp+36),r15
  8601e4:	5b 90 00 20 	sw (sp+32),r16
  8601e8:	5b 91 00 1c 	sw (sp+28),r17
  8601ec:	5b 92 00 18 	sw (sp+24),r18
  8601f0:	5b 93 00 14 	sw (sp+20),r19
  8601f4:	5b 94 00 10 	sw (sp+16),r20
  8601f8:	5b 95 00 0c 	sw (sp+12),r21
  8601fc:	5b 96 00 08 	sw (sp+8),r22
  860200:	5b 9d 00 04 	sw (sp+4),ra
  860204:	78 05 00 86 	mvhi r5,0x86
  860208:	38 a5 1b f0 	ori r5,r5,0x1bf0
  86020c:	28 a3 00 00 	lw r3,(r5+0)
  860210:	78 01 00 86 	mvhi r1,0x86
  860214:	38 21 01 cc 	ori r1,r1,0x1cc
  860218:	78 02 00 86 	mvhi r2,0x86
  86021c:	f0 41 10 00 	cmpgeu r2,r2,r1
  860220:	34 04 00 01 	mvi r4,1
  860224:	78 01 40 00 	mvhi r1,0x4000
  860228:	58 64 00 00 	sw (r3+0),r4
  86022c:	38 21 20 2c 	ori r1,r1,0x202c
  860230:	58 22 00 00 	sw (r1+0),r2
  860234:	34 01 00 00 	mvi r1,0
  860238:	d0 21 00 00 	wcsr IM,r1
  86023c:	34 01 00 01 	mvi r1,1
  860240:	d0 01 00 00 	wcsr IE,r1
  860244:	f8 00 04 bf 	calli 861540 <uart_init>
  860248:	78 01 00 86 	mvhi r1,0x86
  86024c:	38 21 1b f4 	ori r1,r1,0x1bf4
  860250:	78 10 00 86 	mvhi r16,0x86
  860254:	78 15 00 86 	mvhi r21,0x86
  860258:	78 0f 00 86 	mvhi r15,0x86
  86025c:	78 0e 00 86 	mvhi r14,0x86
  860260:	f8 00 03 f6 	calli 861238 <putsnonl>
  860264:	3a 10 1b c4 	ori r16,r16,0x1bc4
  860268:	3a b5 1b d4 	ori r21,r21,0x1bd4
  86026c:	37 8d 00 38 	addi r13,sp,56
  860270:	39 ef 1b d8 	ori r15,r15,0x1bd8
  860274:	39 ce 1b dc 	ori r14,r14,0x1bdc
  860278:	34 0c 00 0a 	mvi r12,10
  86027c:	34 12 00 1b 	mvi r18,27
  860280:	34 14 00 7f 	mvi r20,127
  860284:	34 16 00 0d 	mvi r22,13
  860288:	34 11 00 07 	mvi r17,7
  86028c:	34 13 00 08 	mvi r19,8
  860290:	ba 00 08 00 	mv r1,r16
  860294:	f8 00 03 e9 	calli 861238 <putsnonl>
  860298:	34 0b 00 00 	mvi r11,0
  86029c:	33 80 00 79 	sb (sp+121),r0
  8602a0:	f8 00 03 8a 	calli 8610c8 <readchar>
  8602a4:	33 81 00 78 	sb (sp+120),r1
  8602a8:	44 2c 00 0d 	be r1,r12,8602dc <main+0x110>
  8602ac:	48 2c 00 18 	bg r1,r12,86030c <main+0x140>
  8602b0:	44 31 ff fc 	be r1,r17,8602a0 <main+0xd4>
  8602b4:	44 33 00 24 	be r1,r19,860344 <main+0x178>
  8602b8:	37 81 00 78 	addi r1,sp,120
  8602bc:	f8 00 03 df 	calli 861238 <putsnonl>
  8602c0:	43 83 00 78 	lbu r3,(sp+120)
  8602c4:	b5 ab 10 00 	add r2,r13,r11
  8602c8:	35 6b 00 01 	addi r11,r11,1
  8602cc:	30 43 00 00 	sb (r2+0),r3
  8602d0:	f8 00 03 7e 	calli 8610c8 <readchar>
  8602d4:	33 81 00 78 	sb (sp+120),r1
  8602d8:	5c 2c ff f5 	bne r1,r12,8602ac <main+0xe0>
  8602dc:	b5 ab 58 00 	add r11,r13,r11
  8602e0:	b9 e0 08 00 	mv r1,r15
  8602e4:	31 60 00 00 	sb (r11+0),r0
  8602e8:	f8 00 03 d4 	calli 861238 <putsnonl>
  8602ec:	b9 a0 08 00 	mv r1,r13
  8602f0:	34 02 00 20 	mvi r2,32
  8602f4:	f8 00 00 19 	calli 860358 <strchr>
  8602f8:	44 20 00 10 	be r1,r0,860338 <main+0x16c>
  8602fc:	30 20 00 00 	sb (r1+0),r0
  860300:	b9 c0 08 00 	mv r1,r14
  860304:	f8 00 03 ec 	calli 8612b4 <printf>
  860308:	e3 ff ff e2 	bi 860290 <main+0xc4>
  86030c:	44 32 ff e5 	be r1,r18,8602a0 <main+0xd4>
  860310:	44 34 00 0d 	be r1,r20,860344 <main+0x178>
  860314:	5c 36 ff e9 	bne r1,r22,8602b8 <main+0xec>
  860318:	b5 ab 58 00 	add r11,r13,r11
  86031c:	b9 e0 08 00 	mv r1,r15
  860320:	31 60 00 00 	sb (r11+0),r0
  860324:	f8 00 03 c5 	calli 861238 <putsnonl>
  860328:	b9 a0 08 00 	mv r1,r13
  86032c:	34 02 00 20 	mvi r2,32
  860330:	f8 00 00 0a 	calli 860358 <strchr>
  860334:	5c 20 ff f2 	bne r1,r0,8602fc <main+0x130>
  860338:	b9 a0 08 00 	mv r1,r13
  86033c:	f8 00 00 72 	calli 860504 <strlen>
  860340:	e3 ff ff f0 	bi 860300 <main+0x134>
  860344:	45 60 ff d7 	be r11,r0,8602a0 <main+0xd4>
  860348:	ba a0 08 00 	mv r1,r21
  86034c:	35 6b ff ff 	addi r11,r11,-1
  860350:	f8 00 03 ba 	calli 861238 <putsnonl>
  860354:	e3 ff ff d3 	bi 8602a0 <main+0xd4>

00860358 <strchr>:
  860358:	10 23 00 00 	lb r3,(r1+0)
  86035c:	b0 40 10 00 	sextb r2,r2
  860360:	44 62 00 09 	be r3,r2,860384 <strchr+0x2c>
  860364:	5c 60 00 03 	bne r3,r0,860370 <strchr+0x18>
  860368:	e0 00 00 08 	bi 860388 <strchr+0x30>
  86036c:	44 60 00 05 	be r3,r0,860380 <strchr+0x28>
  860370:	34 21 00 01 	addi r1,r1,1
  860374:	10 23 00 00 	lb r3,(r1+0)
  860378:	5c 62 ff fd 	bne r3,r2,86036c <strchr+0x14>
  86037c:	c3 a0 00 00 	ret
  860380:	34 01 00 00 	mvi r1,0
  860384:	c3 a0 00 00 	ret
  860388:	34 01 00 00 	mvi r1,0
  86038c:	c3 a0 00 00 	ret

00860390 <strrchr>:
  860390:	10 24 00 00 	lb r4,(r1+0)
  860394:	34 03 00 00 	mvi r3,0
  860398:	44 80 00 06 	be r4,r0,8603b0 <strrchr+0x20>
  86039c:	b8 20 18 00 	mv r3,r1
  8603a0:	34 63 00 01 	addi r3,r3,1
  8603a4:	10 64 00 00 	lb r4,(r3+0)
  8603a8:	5c 80 ff fe 	bne r4,r0,8603a0 <strrchr+0x10>
  8603ac:	c8 61 18 00 	sub r3,r3,r1
  8603b0:	b4 23 18 00 	add r3,r1,r3
  8603b4:	b0 40 10 00 	sextb r2,r2
  8603b8:	10 64 00 00 	lb r4,(r3+0)
  8603bc:	44 82 00 04 	be r4,r2,8603cc <strrchr+0x3c>
  8603c0:	34 63 ff ff 	addi r3,r3,-1
  8603c4:	50 61 ff fd 	bgeu r3,r1,8603b8 <strrchr+0x28>
  8603c8:	34 03 00 00 	mvi r3,0
  8603cc:	b8 60 08 00 	mv r1,r3
  8603d0:	c3 a0 00 00 	ret

008603d4 <strnchr>:
  8603d4:	44 40 00 0f 	be r2,r0,860410 <strnchr+0x3c>
  8603d8:	10 24 00 00 	lb r4,(r1+0)
  8603dc:	44 80 00 0d 	be r4,r0,860410 <strnchr+0x3c>
  8603e0:	b0 60 18 00 	sextb r3,r3
  8603e4:	34 42 ff ff 	addi r2,r2,-1
  8603e8:	5c 83 00 06 	bne r4,r3,860400 <strnchr+0x2c>
  8603ec:	e0 00 00 08 	bi 86040c <strnchr+0x38>
  8603f0:	10 24 00 00 	lb r4,(r1+0)
  8603f4:	34 42 ff ff 	addi r2,r2,-1
  8603f8:	44 80 00 06 	be r4,r0,860410 <strnchr+0x3c>
  8603fc:	44 83 00 04 	be r4,r3,86040c <strnchr+0x38>
  860400:	34 21 00 01 	addi r1,r1,1
  860404:	5c 40 ff fb 	bne r2,r0,8603f0 <strnchr+0x1c>
  860408:	34 01 00 00 	mvi r1,0
  86040c:	c3 a0 00 00 	ret
  860410:	34 01 00 00 	mvi r1,0
  860414:	c3 a0 00 00 	ret

00860418 <strcpy>:
  860418:	34 03 00 00 	mvi r3,0
  86041c:	b4 43 20 00 	add r4,r2,r3
  860420:	10 84 00 00 	lb r4,(r4+0)
  860424:	b4 23 28 00 	add r5,r1,r3
  860428:	34 63 00 01 	addi r3,r3,1
  86042c:	30 a4 00 00 	sb (r5+0),r4
  860430:	5c 80 ff fb 	bne r4,r0,86041c <strcpy+0x4>
  860434:	c3 a0 00 00 	ret

00860438 <strncpy>:
  860438:	44 60 00 09 	be r3,r0,86045c <strncpy+0x24>
  86043c:	34 04 00 00 	mvi r4,0
  860440:	10 45 00 00 	lb r5,(r2+0)
  860444:	b4 24 38 00 	add r7,r1,r4
  860448:	34 84 00 01 	addi r4,r4,1
  86044c:	7c a6 00 00 	cmpnei r6,r5,0
  860450:	30 e5 00 00 	sb (r7+0),r5
  860454:	b4 46 10 00 	add r2,r2,r6
  860458:	5c 83 ff fa 	bne r4,r3,860440 <strncpy+0x8>
  86045c:	c3 a0 00 00 	ret

00860460 <strcmp>:
  860460:	34 03 00 00 	mvi r3,0
  860464:	e0 00 00 02 	bi 86046c <strcmp+0xc>
  860468:	44 a4 00 0b 	be r5,r4,860494 <strcmp+0x34>
  86046c:	b4 23 28 00 	add r5,r1,r3
  860470:	b4 43 20 00 	add r4,r2,r3
  860474:	10 a5 00 00 	lb r5,(r5+0)
  860478:	40 84 00 00 	lbu r4,(r4+0)
  86047c:	34 63 00 01 	addi r3,r3,1
  860480:	c8 a4 20 00 	sub r4,r5,r4
  860484:	b0 80 20 00 	sextb r4,r4
  860488:	44 80 ff f8 	be r4,r0,860468 <strcmp+0x8>
  86048c:	b8 80 08 00 	mv r1,r4
  860490:	c3 a0 00 00 	ret
  860494:	34 01 00 00 	mvi r1,0
  860498:	c3 a0 00 00 	ret

0086049c <strncmp>:
  86049c:	b8 20 38 00 	mv r7,r1
  8604a0:	34 01 00 00 	mvi r1,0
  8604a4:	4c 03 00 15 	bge r0,r3,8604f8 <strncmp+0x5c>
  8604a8:	10 e4 00 00 	lb r4,(r7+0)
  8604ac:	40 41 00 00 	lbu r1,(r2+0)
  8604b0:	c8 81 08 00 	sub r1,r4,r1
  8604b4:	b0 20 08 00 	sextb r1,r1
  8604b8:	5c 20 00 10 	bne r1,r0,8604f8 <strncmp+0x5c>
  8604bc:	44 81 00 0f 	be r4,r1,8604f8 <strncmp+0x5c>
  8604c0:	34 04 00 00 	mvi r4,0
  8604c4:	34 84 00 01 	addi r4,r4,1
  8604c8:	b4 e4 30 00 	add r6,r7,r4
  8604cc:	b4 44 28 00 	add r5,r2,r4
  8604d0:	48 64 00 03 	bg r3,r4,8604dc <strncmp+0x40>
  8604d4:	34 01 00 00 	mvi r1,0
  8604d8:	c3 a0 00 00 	ret
  8604dc:	10 c6 00 00 	lb r6,(r6+0)
  8604e0:	40 a5 00 00 	lbu r5,(r5+0)
  8604e4:	c8 c5 28 00 	sub r5,r6,r5
  8604e8:	b0 a0 28 00 	sextb r5,r5
  8604ec:	5c a0 00 04 	bne r5,r0,8604fc <strncmp+0x60>
  8604f0:	5c c5 ff f5 	bne r6,r5,8604c4 <strncmp+0x28>
  8604f4:	34 01 00 00 	mvi r1,0
  8604f8:	c3 a0 00 00 	ret
  8604fc:	b8 a0 08 00 	mv r1,r5
  860500:	c3 a0 00 00 	ret

00860504 <strlen>:
  860504:	10 23 00 00 	lb r3,(r1+0)
  860508:	34 02 00 00 	mvi r2,0
  86050c:	44 60 00 06 	be r3,r0,860524 <strlen+0x20>
  860510:	b8 20 10 00 	mv r2,r1
  860514:	34 42 00 01 	addi r2,r2,1
  860518:	10 43 00 00 	lb r3,(r2+0)
  86051c:	5c 60 ff fe 	bne r3,r0,860514 <strlen+0x10>
  860520:	c8 41 10 00 	sub r2,r2,r1
  860524:	b8 40 08 00 	mv r1,r2
  860528:	c3 a0 00 00 	ret

0086052c <strnlen>:
  86052c:	34 03 00 00 	mvi r3,0
  860530:	44 40 00 0c 	be r2,r0,860560 <strnlen+0x34>
  860534:	10 24 00 00 	lb r4,(r1+0)
  860538:	44 80 00 0a 	be r4,r0,860560 <strnlen+0x34>
  86053c:	34 42 ff ff 	addi r2,r2,-1
  860540:	b8 20 18 00 	mv r3,r1
  860544:	e0 00 00 04 	bi 860554 <strnlen+0x28>
  860548:	10 64 00 00 	lb r4,(r3+0)
  86054c:	34 42 ff ff 	addi r2,r2,-1
  860550:	44 80 00 03 	be r4,r0,86055c <strnlen+0x30>
  860554:	34 63 00 01 	addi r3,r3,1
  860558:	5c 40 ff fc 	bne r2,r0,860548 <strnlen+0x1c>
  86055c:	c8 61 18 00 	sub r3,r3,r1
  860560:	b8 60 08 00 	mv r1,r3
  860564:	c3 a0 00 00 	ret

00860568 <memcmp>:
  860568:	b8 20 20 00 	mv r4,r1
  86056c:	34 01 00 00 	mvi r1,0
  860570:	4c 03 00 0f 	bge r0,r3,8605ac <memcmp+0x44>
  860574:	40 85 00 00 	lbu r5,(r4+0)
  860578:	40 41 00 00 	lbu r1,(r2+0)
  86057c:	c8 a1 08 00 	sub r1,r5,r1
  860580:	5c 20 00 0c 	bne r1,r0,8605b0 <memcmp+0x48>
  860584:	34 63 ff ff 	addi r3,r3,-1
  860588:	34 84 00 01 	addi r4,r4,1
  86058c:	34 42 00 01 	addi r2,r2,1
  860590:	48 60 00 02 	bg r3,r0,860598 <memcmp+0x30>
  860594:	c3 a0 00 00 	ret
  860598:	40 86 00 00 	lbu r6,(r4+0)
  86059c:	40 45 00 00 	lbu r5,(r2+0)
  8605a0:	c8 c5 28 00 	sub r5,r6,r5
  8605a4:	44 a0 ff f8 	be r5,r0,860584 <memcmp+0x1c>
  8605a8:	b8 a0 08 00 	mv r1,r5
  8605ac:	c3 a0 00 00 	ret
  8605b0:	c3 a0 00 00 	ret

008605b4 <memset>:
  8605b4:	37 9c ff f8 	addi sp,sp,-8
  8605b8:	5b 8b 00 08 	sw (sp+8),r11
  8605bc:	5b 8c 00 04 	sw (sp+4),r12
  8605c0:	44 60 00 2b 	be r3,r0,86066c <memset+0xb8>
  8605c4:	c8 01 30 00 	sub r6,r0,r1
  8605c8:	20 c6 00 03 	andi r6,r6,0x3
  8605cc:	b8 20 20 00 	mv r4,r1
  8605d0:	34 67 ff ff 	addi r7,r3,-1
  8605d4:	b0 40 10 00 	sextb r2,r2
  8605d8:	50 66 00 02 	bgeu r3,r6,8605e0 <memset+0x2c>
  8605dc:	b8 60 30 00 	mv r6,r3
  8605e0:	44 c0 00 09 	be r6,r0,860604 <memset+0x50>
  8605e4:	34 05 00 00 	mvi r5,0
  8605e8:	34 68 ff fe 	addi r8,r3,-2
  8605ec:	30 82 00 00 	sb (r4+0),r2
  8605f0:	c9 05 38 00 	sub r7,r8,r5
  8605f4:	34 a5 00 01 	addi r5,r5,1
  8605f8:	34 84 00 01 	addi r4,r4,1
  8605fc:	54 c5 ff fc 	bgu r6,r5,8605ec <memset+0x38>
  860600:	44 66 00 1b 	be r3,r6,86066c <memset+0xb8>
  860604:	c8 66 18 00 	sub r3,r3,r6
  860608:	00 68 00 02 	srui r8,r3,2
  86060c:	3d 0a 00 02 	sli r10,r8,2
  860610:	45 40 00 11 	be r10,r0,860654 <memset+0xa0>
  860614:	20 45 00 ff 	andi r5,r2,0xff
  860618:	3c a9 00 10 	sli r9,r5,16
  86061c:	3c ac 00 18 	sli r12,r5,24
  860620:	3c ab 00 08 	sli r11,r5,8
  860624:	b9 89 48 00 	or r9,r12,r9
  860628:	b9 2b 48 00 	or r9,r9,r11
  86062c:	b9 25 48 00 	or r9,r9,r5
  860630:	b4 26 30 00 	add r6,r1,r6
  860634:	34 05 00 00 	mvi r5,0
  860638:	58 c9 00 00 	sw (r6+0),r9
  86063c:	34 a5 00 01 	addi r5,r5,1
  860640:	34 c6 00 04 	addi r6,r6,4
  860644:	55 05 ff fd 	bgu r8,r5,860638 <memset+0x84>
  860648:	b4 8a 20 00 	add r4,r4,r10
  86064c:	c8 ea 38 00 	sub r7,r7,r10
  860650:	44 6a 00 07 	be r3,r10,86066c <memset+0xb8>
  860654:	34 e7 00 01 	addi r7,r7,1
  860658:	34 03 00 00 	mvi r3,0
  86065c:	b4 83 28 00 	add r5,r4,r3
  860660:	30 a2 00 00 	sb (r5+0),r2
  860664:	34 63 00 01 	addi r3,r3,1
  860668:	5c 67 ff fd 	bne r3,r7,86065c <memset+0xa8>
  86066c:	2b 8b 00 08 	lw r11,(sp+8)
  860670:	2b 8c 00 04 	lw r12,(sp+4)
  860674:	37 9c 00 08 	addi sp,sp,8
  860678:	c3 a0 00 00 	ret

0086067c <memcpy>:
  86067c:	37 9c ff f8 	addi sp,sp,-8
  860680:	5b 8b 00 08 	sw (sp+8),r11
  860684:	5b 8c 00 04 	sw (sp+4),r12
  860688:	44 60 00 34 	be r3,r0,860758 <memcpy+0xdc>
  86068c:	20 25 00 01 	andi r5,r1,0x1
  860690:	b8 20 20 00 	mv r4,r1
  860694:	44 a0 00 06 	be r5,r0,8606ac <memcpy+0x30>
  860698:	40 44 00 00 	lbu r4,(r2+0)
  86069c:	34 63 ff ff 	addi r3,r3,-1
  8606a0:	34 42 00 01 	addi r2,r2,1
  8606a4:	30 24 00 00 	sb (r1+0),r4
  8606a8:	34 24 00 01 	addi r4,r1,1
  8606ac:	20 45 00 01 	andi r5,r2,0x1
  8606b0:	b8 40 30 00 	mv r6,r2
  8606b4:	44 a0 00 2d 	be r5,r0,860768 <memcpy+0xec>
  8606b8:	44 60 00 28 	be r3,r0,860758 <memcpy+0xdc>
  8606bc:	b8 82 38 00 	or r7,r4,r2
  8606c0:	00 69 00 02 	srui r9,r3,2
  8606c4:	20 e7 00 03 	andi r7,r7,0x3
  8606c8:	34 45 00 04 	addi r5,r2,4
  8606cc:	34 86 00 04 	addi r6,r4,4
  8606d0:	f4 46 30 00 	cmpgu r6,r2,r6
  8606d4:	74 68 00 03 	cmpgui r8,r3,0x3
  8606d8:	64 e7 00 00 	cmpei r7,r7,0
  8606dc:	f4 85 28 00 	cmpgu r5,r4,r5
  8606e0:	3d 2a 00 02 	sli r10,r9,2
  8606e4:	a1 07 38 00 	and r7,r8,r7
  8606e8:	b8 a6 28 00 	or r5,r5,r6
  8606ec:	a0 e5 28 00 	and r5,r7,r5
  8606f0:	65 46 00 00 	cmpei r6,r10,0
  8606f4:	18 a5 00 01 	xori r5,r5,0x1
  8606f8:	b8 c5 28 00 	or r5,r6,r5
  8606fc:	b8 40 38 00 	mv r7,r2
  860700:	b8 80 30 00 	mv r6,r4
  860704:	b8 60 58 00 	mv r11,r3
  860708:	5c a0 00 0d 	bne r5,r0,86073c <memcpy+0xc0>
  86070c:	34 06 00 00 	mvi r6,0
  860710:	b4 45 38 00 	add r7,r2,r5
  860714:	28 e8 00 00 	lw r8,(r7+0)
  860718:	b4 85 38 00 	add r7,r4,r5
  86071c:	34 c6 00 01 	addi r6,r6,1
  860720:	58 e8 00 00 	sw (r7+0),r8
  860724:	34 a5 00 04 	addi r5,r5,4
  860728:	55 26 ff fa 	bgu r9,r6,860710 <memcpy+0x94>
  86072c:	c8 6a 18 00 	sub r3,r3,r10
  860730:	b4 8a 30 00 	add r6,r4,r10
  860734:	b4 4a 38 00 	add r7,r2,r10
  860738:	45 6a 00 08 	be r11,r10,860758 <memcpy+0xdc>
  86073c:	34 02 00 00 	mvi r2,0
  860740:	b4 e2 20 00 	add r4,r7,r2
  860744:	40 85 00 00 	lbu r5,(r4+0)
  860748:	b4 c2 20 00 	add r4,r6,r2
  86074c:	34 42 00 01 	addi r2,r2,1
  860750:	30 85 00 00 	sb (r4+0),r5
  860754:	5c 43 ff fb 	bne r2,r3,860740 <memcpy+0xc4>
  860758:	2b 8b 00 08 	lw r11,(sp+8)
  86075c:	2b 8c 00 04 	lw r12,(sp+4)
  860760:	37 9c 00 08 	addi sp,sp,8
  860764:	c3 a0 00 00 	ret
  860768:	34 05 00 02 	mvi r5,2
  86076c:	4c a3 00 09 	bge r5,r3,860790 <memcpy+0x114>
  860770:	20 85 00 02 	andi r5,r4,0x2
  860774:	44 a0 00 07 	be r5,r0,860790 <memcpy+0x114>
  860778:	2c 45 00 00 	lhu r5,(r2+0)
  86077c:	34 42 00 02 	addi r2,r2,2
  860780:	34 63 ff fe 	addi r3,r3,-2
  860784:	0c 85 00 00 	sh (r4+0),r5
  860788:	b8 40 30 00 	mv r6,r2
  86078c:	34 84 00 02 	addi r4,r4,2
  860790:	20 c6 00 02 	andi r6,r6,0x2
  860794:	44 c0 00 34 	be r6,r0,860864 <memcpy+0x1e8>
  860798:	14 65 00 01 	sri r5,r3,1
  86079c:	b8 80 38 00 	mv r7,r4
  8607a0:	b8 40 30 00 	mv r6,r2
  8607a4:	44 a0 00 2b 	be r5,r0,860850 <memcpy+0x1d4>
  8607a8:	b8 82 40 00 	or r8,r4,r2
  8607ac:	00 aa 00 01 	srui r10,r5,1
  8607b0:	21 08 00 03 	andi r8,r8,0x3
  8607b4:	34 46 00 04 	addi r6,r2,4
  8607b8:	34 87 00 04 	addi r7,r4,4
  8607bc:	f4 47 38 00 	cmpgu r7,r2,r7
  8607c0:	74 a9 00 01 	cmpgui r9,r5,0x1
  8607c4:	65 08 00 00 	cmpei r8,r8,0
  8607c8:	f4 86 30 00 	cmpgu r6,r4,r6
  8607cc:	3d 4b 00 01 	sli r11,r10,1
  8607d0:	b8 c7 30 00 	or r6,r6,r7
  8607d4:	a1 28 40 00 	and r8,r9,r8
  8607d8:	65 67 00 00 	cmpei r7,r11,0
  8607dc:	a1 06 30 00 	and r6,r8,r6
  8607e0:	18 c6 00 01 	xori r6,r6,0x1
  8607e4:	b8 e6 30 00 	or r6,r7,r6
  8607e8:	b8 a0 60 00 	mv r12,r5
  8607ec:	5c c0 00 37 	bne r6,r0,8608c8 <memcpy+0x24c>
  8607f0:	34 07 00 00 	mvi r7,0
  8607f4:	b4 46 40 00 	add r8,r2,r6
  8607f8:	29 09 00 00 	lw r9,(r8+0)
  8607fc:	b4 86 40 00 	add r8,r4,r6
  860800:	34 e7 00 01 	addi r7,r7,1
  860804:	59 09 00 00 	sw (r8+0),r9
  860808:	34 c6 00 04 	addi r6,r6,4
  86080c:	55 47 ff fa 	bgu r10,r7,8607f4 <memcpy+0x178>
  860810:	3d 6a 00 01 	sli r10,r11,1
  860814:	c8 ab 28 00 	sub r5,r5,r11
  860818:	b4 8a 48 00 	add r9,r4,r10
  86081c:	b4 4a 50 00 	add r10,r2,r10
  860820:	45 8b 00 09 	be r12,r11,860844 <memcpy+0x1c8>
  860824:	34 06 00 00 	mvi r6,0
  860828:	b5 46 38 00 	add r7,r10,r6
  86082c:	2c e8 00 00 	lhu r8,(r7+0)
  860830:	b5 26 38 00 	add r7,r9,r6
  860834:	34 a5 ff ff 	addi r5,r5,-1
  860838:	0c e8 00 00 	sh (r7+0),r8
  86083c:	34 c6 00 02 	addi r6,r6,2
  860840:	5c a0 ff fa 	bne r5,r0,860828 <memcpy+0x1ac>
  860844:	3d 86 00 01 	sli r6,r12,1
  860848:	b4 86 38 00 	add r7,r4,r6
  86084c:	b4 46 30 00 	add r6,r2,r6
  860850:	20 63 00 01 	andi r3,r3,0x1
  860854:	44 60 ff c1 	be r3,r0,860758 <memcpy+0xdc>
  860858:	40 c2 00 00 	lbu r2,(r6+0)
  86085c:	30 e2 00 00 	sb (r7+0),r2
  860860:	e3 ff ff be 	bi 860758 <memcpy+0xdc>
  860864:	14 69 00 02 	sri r9,r3,2
  860868:	45 26 00 0d 	be r9,r6,86089c <memcpy+0x220>
  86086c:	b9 20 30 00 	mv r6,r9
  860870:	34 05 00 00 	mvi r5,0
  860874:	b4 45 38 00 	add r7,r2,r5
  860878:	28 e8 00 00 	lw r8,(r7+0)
  86087c:	b4 85 38 00 	add r7,r4,r5
  860880:	34 c6 ff ff 	addi r6,r6,-1
  860884:	58 e8 00 00 	sw (r7+0),r8
  860888:	34 a5 00 04 	addi r5,r5,4
  86088c:	5c c0 ff fa 	bne r6,r0,860874 <memcpy+0x1f8>
  860890:	3d 29 00 02 	sli r9,r9,2
  860894:	b4 49 10 00 	add r2,r2,r9
  860898:	b4 89 20 00 	add r4,r4,r9
  86089c:	20 65 00 02 	andi r5,r3,0x2
  8608a0:	44 a0 00 05 	be r5,r0,8608b4 <memcpy+0x238>
  8608a4:	2c 45 00 00 	lhu r5,(r2+0)
  8608a8:	34 42 00 02 	addi r2,r2,2
  8608ac:	0c 85 00 00 	sh (r4+0),r5
  8608b0:	34 84 00 02 	addi r4,r4,2
  8608b4:	20 63 00 01 	andi r3,r3,0x1
  8608b8:	44 60 ff a8 	be r3,r0,860758 <memcpy+0xdc>
  8608bc:	40 42 00 00 	lbu r2,(r2+0)
  8608c0:	30 82 00 00 	sb (r4+0),r2
  8608c4:	e3 ff ff a5 	bi 860758 <memcpy+0xdc>
  8608c8:	b8 40 50 00 	mv r10,r2
  8608cc:	b8 80 48 00 	mv r9,r4
  8608d0:	e3 ff ff d5 	bi 860824 <memcpy+0x1a8>

008608d4 <memmove>:
  8608d4:	54 22 00 2b 	bgu r1,r2,860980 <memmove+0xac>
  8608d8:	44 60 00 35 	be r3,r0,8609ac <memmove+0xd8>
  8608dc:	b8 41 30 00 	or r6,r2,r1
  8608e0:	00 68 00 02 	srui r8,r3,2
  8608e4:	20 c6 00 03 	andi r6,r6,0x3
  8608e8:	34 44 00 04 	addi r4,r2,4
  8608ec:	34 25 00 04 	addi r5,r1,4
  8608f0:	f4 45 28 00 	cmpgu r5,r2,r5
  8608f4:	74 67 00 03 	cmpgui r7,r3,0x3
  8608f8:	64 c6 00 00 	cmpei r6,r6,0
  8608fc:	f4 24 20 00 	cmpgu r4,r1,r4
  860900:	3d 09 00 02 	sli r9,r8,2
  860904:	a0 e6 30 00 	and r6,r7,r6
  860908:	b8 85 20 00 	or r4,r4,r5
  86090c:	a0 c4 20 00 	and r4,r6,r4
  860910:	65 25 00 00 	cmpei r5,r9,0
  860914:	18 84 00 01 	xori r4,r4,0x1
  860918:	b8 a4 20 00 	or r4,r5,r4
  86091c:	b8 40 30 00 	mv r6,r2
  860920:	b8 20 28 00 	mv r5,r1
  860924:	34 6a ff ff 	addi r10,r3,-1
  860928:	5c 80 00 0d 	bne r4,r0,86095c <memmove+0x88>
  86092c:	34 05 00 00 	mvi r5,0
  860930:	b4 44 30 00 	add r6,r2,r4
  860934:	28 c7 00 00 	lw r7,(r6+0)
  860938:	b4 24 30 00 	add r6,r1,r4
  86093c:	34 a5 00 01 	addi r5,r5,1
  860940:	58 c7 00 00 	sw (r6+0),r7
  860944:	34 84 00 04 	addi r4,r4,4
  860948:	55 05 ff fa 	bgu r8,r5,860930 <memmove+0x5c>
  86094c:	b4 29 28 00 	add r5,r1,r9
  860950:	b4 49 30 00 	add r6,r2,r9
  860954:	c9 49 50 00 	sub r10,r10,r9
  860958:	44 69 00 15 	be r3,r9,8609ac <memmove+0xd8>
  86095c:	35 47 00 01 	addi r7,r10,1
  860960:	34 02 00 00 	mvi r2,0
  860964:	b4 c2 18 00 	add r3,r6,r2
  860968:	40 64 00 00 	lbu r4,(r3+0)
  86096c:	b4 a2 18 00 	add r3,r5,r2
  860970:	34 42 00 01 	addi r2,r2,1
  860974:	30 64 00 00 	sb (r3+0),r4
  860978:	5c 47 ff fb 	bne r2,r7,860964 <memmove+0x90>
  86097c:	c3 a0 00 00 	ret
  860980:	44 60 00 0b 	be r3,r0,8609ac <memmove+0xd8>
  860984:	b4 23 20 00 	add r4,r1,r3
  860988:	b4 43 10 00 	add r2,r2,r3
  86098c:	34 05 ff ff 	mvi r5,-1
  860990:	34 63 ff ff 	addi r3,r3,-1
  860994:	34 42 ff ff 	addi r2,r2,-1
  860998:	40 46 00 00 	lbu r6,(r2+0)
  86099c:	34 84 ff ff 	addi r4,r4,-1
  8609a0:	34 63 ff ff 	addi r3,r3,-1
  8609a4:	30 86 00 00 	sb (r4+0),r6
  8609a8:	5c 65 ff fb 	bne r3,r5,860994 <memmove+0xc0>
  8609ac:	c3 a0 00 00 	ret

008609b0 <strstr>:
  8609b0:	10 43 00 00 	lb r3,(r2+0)
  8609b4:	44 60 00 07 	be r3,r0,8609d0 <strstr+0x20>
  8609b8:	b8 40 18 00 	mv r3,r2
  8609bc:	34 63 00 01 	addi r3,r3,1
  8609c0:	10 64 00 00 	lb r4,(r3+0)
  8609c4:	5c 80 ff fe 	bne r4,r0,8609bc <strstr+0xc>
  8609c8:	c8 62 40 00 	sub r8,r3,r2
  8609cc:	5d 04 00 02 	bne r8,r4,8609d4 <strstr+0x24>
  8609d0:	c3 a0 00 00 	ret
  8609d4:	10 23 00 00 	lb r3,(r1+0)
  8609d8:	b8 20 48 00 	mv r9,r1
  8609dc:	44 60 00 04 	be r3,r0,8609ec <strstr+0x3c>
  8609e0:	35 29 00 01 	addi r9,r9,1
  8609e4:	11 23 00 00 	lb r3,(r9+0)
  8609e8:	5c 60 ff fe 	bne r3,r0,8609e0 <strstr+0x30>
  8609ec:	c9 21 48 00 	sub r9,r9,r1
  8609f0:	49 09 00 16 	bg r8,r9,860a48 <strstr+0x98>
  8609f4:	4c 08 ff f7 	bge r0,r8,8609d0 <strstr+0x20>
  8609f8:	40 4a 00 00 	lbu r10,(r2+0)
  8609fc:	40 23 00 00 	lbu r3,(r1+0)
  860a00:	b8 20 20 00 	mv r4,r1
  860a04:	5d 43 00 0b 	bne r10,r3,860a30 <strstr+0x80>
  860a08:	b9 00 18 00 	mv r3,r8
  860a0c:	b8 40 28 00 	mv r5,r2
  860a10:	34 63 ff ff 	addi r3,r3,-1
  860a14:	34 84 00 01 	addi r4,r4,1
  860a18:	34 a5 00 01 	addi r5,r5,1
  860a1c:	48 60 00 02 	bg r3,r0,860a24 <strstr+0x74>
  860a20:	c3 a0 00 00 	ret
  860a24:	40 87 00 00 	lbu r7,(r4+0)
  860a28:	40 a6 00 00 	lbu r6,(r5+0)
  860a2c:	44 e6 ff f9 	be r7,r6,860a10 <strstr+0x60>
  860a30:	35 29 ff ff 	addi r9,r9,-1
  860a34:	49 09 00 03 	bg r8,r9,860a40 <strstr+0x90>
  860a38:	34 21 00 01 	addi r1,r1,1
  860a3c:	e3 ff ff f0 	bi 8609fc <strstr+0x4c>
  860a40:	34 01 00 00 	mvi r1,0
  860a44:	c3 a0 00 00 	ret
  860a48:	34 01 00 00 	mvi r1,0
  860a4c:	c3 a0 00 00 	ret

00860a50 <strtoul>:
  860a50:	37 9c ff f8 	addi sp,sp,-8
  860a54:	5b 8b 00 08 	sw (sp+8),r11
  860a58:	5b 8c 00 04 	sw (sp+4),r12
  860a5c:	5c 60 00 28 	bne r3,r0,860afc <strtoul+0xac>
  860a60:	40 24 00 00 	lbu r4,(r1+0)
  860a64:	34 05 00 30 	mvi r5,48
  860a68:	34 03 00 0a 	mvi r3,10
  860a6c:	b0 80 30 00 	sextb r6,r4
  860a70:	44 c5 00 37 	be r6,r5,860b4c <strtoul+0xfc>
  860a74:	34 06 00 00 	mvi r6,0
  860a78:	34 0a 00 09 	mvi r10,9
  860a7c:	34 0b 00 05 	mvi r11,5
  860a80:	34 0c 00 19 	mvi r12,25
  860a84:	b0 80 28 00 	sextb r5,r4
  860a88:	20 a4 00 ff 	andi r4,r5,0xff
  860a8c:	34 87 ff d0 	addi r7,r4,-48
  860a90:	34 88 ff 9f 	addi r8,r4,-97
  860a94:	20 e7 00 ff 	andi r7,r7,0xff
  860a98:	88 c3 48 00 	mul r9,r6,r3
  860a9c:	21 08 00 ff 	andi r8,r8,0xff
  860aa0:	34 a5 ff d0 	addi r5,r5,-48
  860aa4:	51 47 00 10 	bgeu r10,r7,860ae4 <strtoul+0x94>
  860aa8:	34 85 ff bf 	addi r5,r4,-65
  860aac:	20 a5 00 ff 	andi r5,r5,0xff
  860ab0:	34 87 ff e0 	addi r7,r4,-32
  860ab4:	51 68 00 0a 	bgeu r11,r8,860adc <strtoul+0x8c>
  860ab8:	51 65 00 08 	bgeu r11,r5,860ad8 <strtoul+0x88>
  860abc:	44 40 00 02 	be r2,r0,860ac4 <strtoul+0x74>
  860ac0:	58 41 00 00 	sw (r2+0),r1
  860ac4:	b8 c0 08 00 	mv r1,r6
  860ac8:	2b 8b 00 08 	lw r11,(sp+8)
  860acc:	2b 8c 00 04 	lw r12,(sp+4)
  860ad0:	37 9c 00 08 	addi sp,sp,8
  860ad4:	c3 a0 00 00 	ret
  860ad8:	55 0c 00 02 	bgu r8,r12,860ae0 <strtoul+0x90>
  860adc:	20 e4 00 ff 	andi r4,r7,0xff
  860ae0:	34 85 ff c9 	addi r5,r4,-55
  860ae4:	54 65 00 02 	bgu r3,r5,860aec <strtoul+0x9c>
  860ae8:	e3 ff ff f5 	bi 860abc <strtoul+0x6c>
  860aec:	34 21 00 01 	addi r1,r1,1
  860af0:	40 24 00 00 	lbu r4,(r1+0)
  860af4:	b4 a9 30 00 	add r6,r5,r9
  860af8:	e3 ff ff e3 	bi 860a84 <strtoul+0x34>
  860afc:	34 04 00 10 	mvi r4,16
  860b00:	44 64 00 03 	be r3,r4,860b0c <strtoul+0xbc>
  860b04:	40 24 00 00 	lbu r4,(r1+0)
  860b08:	e3 ff ff db 	bi 860a74 <strtoul+0x24>
  860b0c:	40 24 00 00 	lbu r4,(r1+0)
  860b10:	34 05 00 30 	mvi r5,48
  860b14:	b0 80 30 00 	sextb r6,r4
  860b18:	5c c5 ff d7 	bne r6,r5,860a74 <strtoul+0x24>
  860b1c:	40 25 00 01 	lbu r5,(r1+1)
  860b20:	34 06 00 19 	mvi r6,25
  860b24:	34 a7 ff 9f 	addi r7,r5,-97
  860b28:	20 e7 00 ff 	andi r7,r7,0xff
  860b2c:	54 e6 00 03 	bgu r7,r6,860b38 <strtoul+0xe8>
  860b30:	34 a5 ff e0 	addi r5,r5,-32
  860b34:	20 a5 00 ff 	andi r5,r5,0xff
  860b38:	34 06 00 58 	mvi r6,88
  860b3c:	5c a6 ff ce 	bne r5,r6,860a74 <strtoul+0x24>
  860b40:	34 21 00 02 	addi r1,r1,2
  860b44:	40 24 00 00 	lbu r4,(r1+0)
  860b48:	e3 ff ff cb 	bi 860a74 <strtoul+0x24>
  860b4c:	34 21 00 01 	addi r1,r1,1
  860b50:	40 23 00 00 	lbu r3,(r1+0)
  860b54:	34 04 00 19 	mvi r4,25
  860b58:	34 65 ff 9f 	addi r5,r3,-97
  860b5c:	20 a5 00 ff 	andi r5,r5,0xff
  860b60:	54 a4 00 03 	bgu r5,r4,860b6c <strtoul+0x11c>
  860b64:	34 63 ff e0 	addi r3,r3,-32
  860b68:	20 63 00 ff 	andi r3,r3,0xff
  860b6c:	34 04 00 58 	mvi r4,88
  860b70:	44 64 00 04 	be r3,r4,860b80 <strtoul+0x130>
  860b74:	34 03 00 08 	mvi r3,8
  860b78:	40 24 00 00 	lbu r4,(r1+0)
  860b7c:	e3 ff ff be 	bi 860a74 <strtoul+0x24>
  860b80:	40 23 00 01 	lbu r3,(r1+1)
  860b84:	34 06 00 09 	mvi r6,9
  860b88:	34 24 00 01 	addi r4,r1,1
  860b8c:	34 65 ff d0 	addi r5,r3,-48
  860b90:	20 a5 00 ff 	andi r5,r5,0xff
  860b94:	50 c5 00 08 	bgeu r6,r5,860bb4 <strtoul+0x164>
  860b98:	34 66 ff 9f 	addi r6,r3,-97
  860b9c:	20 c6 00 ff 	andi r6,r6,0xff
  860ba0:	34 05 00 05 	mvi r5,5
  860ba4:	50 a6 00 08 	bgeu r5,r6,860bc4 <strtoul+0x174>
  860ba8:	34 63 ff bf 	addi r3,r3,-65
  860bac:	20 63 00 ff 	andi r3,r3,0xff
  860bb0:	54 65 00 09 	bgu r3,r5,860bd4 <strtoul+0x184>
  860bb4:	b8 80 08 00 	mv r1,r4
  860bb8:	34 03 00 10 	mvi r3,16
  860bbc:	40 84 00 00 	lbu r4,(r4+0)
  860bc0:	e3 ff ff ad 	bi 860a74 <strtoul+0x24>
  860bc4:	b8 80 08 00 	mv r1,r4
  860bc8:	34 03 00 10 	mvi r3,16
  860bcc:	40 24 00 00 	lbu r4,(r1+0)
  860bd0:	e3 ff ff a9 	bi 860a74 <strtoul+0x24>
  860bd4:	40 24 00 00 	lbu r4,(r1+0)
  860bd8:	34 03 00 08 	mvi r3,8
  860bdc:	e3 ff ff a6 	bi 860a74 <strtoul+0x24>

00860be0 <strtol>:
  860be0:	37 9c ff fc 	addi sp,sp,-4
  860be4:	5b 9d 00 04 	sw (sp+4),ra
  860be8:	10 26 00 00 	lb r6,(r1+0)
  860bec:	34 05 00 2d 	mvi r5,45
  860bf0:	44 c5 00 05 	be r6,r5,860c04 <strtol+0x24>
  860bf4:	fb ff ff 97 	calli 860a50 <strtoul>
  860bf8:	2b 9d 00 04 	lw ra,(sp+4)
  860bfc:	37 9c 00 04 	addi sp,sp,4
  860c00:	c3 a0 00 00 	ret
  860c04:	34 21 00 01 	addi r1,r1,1
  860c08:	fb ff ff 92 	calli 860a50 <strtoul>
  860c0c:	c8 01 08 00 	sub r1,r0,r1
  860c10:	2b 9d 00 04 	lw ra,(sp+4)
  860c14:	37 9c 00 04 	addi sp,sp,4
  860c18:	c3 a0 00 00 	ret

00860c1c <skip_atoi>:
  860c1c:	28 22 00 00 	lw r2,(r1+0)
  860c20:	34 04 00 09 	mvi r4,9
  860c24:	b8 20 38 00 	mv r7,r1
  860c28:	10 43 00 00 	lb r3,(r2+0)
  860c2c:	34 01 00 00 	mvi r1,0
  860c30:	34 63 ff d0 	addi r3,r3,-48
  860c34:	20 65 00 ff 	andi r5,r3,0xff
  860c38:	54 a4 00 0c 	bgu r5,r4,860c68 <skip_atoi+0x4c>
  860c3c:	34 08 00 09 	mvi r8,9
  860c40:	34 42 00 01 	addi r2,r2,1
  860c44:	58 e2 00 00 	sw (r7+0),r2
  860c48:	3c 26 00 01 	sli r6,r1,1
  860c4c:	3c 25 00 03 	sli r5,r1,3
  860c50:	10 44 00 00 	lb r4,(r2+0)
  860c54:	b4 c5 28 00 	add r5,r6,r5
  860c58:	b4 65 08 00 	add r1,r3,r5
  860c5c:	34 83 ff d0 	addi r3,r4,-48
  860c60:	20 64 00 ff 	andi r4,r3,0xff
  860c64:	51 04 ff f7 	bgeu r8,r4,860c40 <skip_atoi+0x24>
  860c68:	c3 a0 00 00 	ret

00860c6c <number>:
  860c6c:	37 9c ff a0 	addi sp,sp,-96
  860c70:	5b 8b 00 1c 	sw (sp+28),r11
  860c74:	5b 8c 00 18 	sw (sp+24),r12
  860c78:	5b 8d 00 14 	sw (sp+20),r13
  860c7c:	5b 8e 00 10 	sw (sp+16),r14
  860c80:	5b 8f 00 0c 	sw (sp+12),r15
  860c84:	5b 90 00 08 	sw (sp+8),r16
  860c88:	5b 91 00 04 	sw (sp+4),r17
  860c8c:	20 e8 00 40 	andi r8,r7,0x40
  860c90:	45 00 00 63 	be r8,r0,860e1c <number+0x1b0>
  860c94:	78 0e 00 86 	mvhi r14,0x86
  860c98:	78 0b 00 86 	mvhi r11,0x86
  860c9c:	39 ce 1d 65 	ori r14,r14,0x1d65
  860ca0:	39 6b 1d 44 	ori r11,r11,0x1d44
  860ca4:	20 e8 00 10 	andi r8,r7,0x10
  860ca8:	45 00 00 03 	be r8,r0,860cb4 <number+0x48>
  860cac:	34 08 ff fe 	mvi r8,-2
  860cb0:	a0 e8 38 00 	and r7,r7,r8
  860cb4:	34 89 ff fe 	addi r9,r4,-2
  860cb8:	34 08 00 22 	mvi r8,34
  860cbc:	55 28 00 79 	bgu r9,r8,860ea0 <number+0x234>
  860cc0:	20 ed 00 01 	andi r13,r7,0x1
  860cc4:	65 ad 00 00 	cmpei r13,r13,0
  860cc8:	34 08 ff f0 	mvi r8,-16
  860ccc:	c8 0d 68 00 	sub r13,r0,r13
  860cd0:	a1 a8 68 00 	and r13,r13,r8
  860cd4:	20 e8 00 02 	andi r8,r7,0x2
  860cd8:	35 ad 00 30 	addi r13,r13,48
  860cdc:	34 0f 00 00 	mvi r15,0
  860ce0:	45 00 00 05 	be r8,r0,860cf4 <number+0x88>
  860ce4:	4c 60 00 53 	bge r3,r0,860e30 <number+0x1c4>
  860ce8:	c8 03 18 00 	sub r3,r0,r3
  860cec:	34 a5 ff ff 	addi r5,r5,-1
  860cf0:	34 0f 00 2d 	mvi r15,45
  860cf4:	20 f0 00 20 	andi r16,r7,0x20
  860cf8:	46 00 00 05 	be r16,r0,860d0c <number+0xa0>
  860cfc:	34 08 00 10 	mvi r8,16
  860d00:	44 88 00 82 	be r4,r8,860f08 <number+0x29c>
  860d04:	64 88 00 08 	cmpei r8,r4,8
  860d08:	c8 a8 28 00 	sub r5,r5,r8
  860d0c:	34 08 00 00 	mvi r8,0
  860d10:	37 8c 00 20 	addi r12,sp,32
  860d14:	5c 60 00 38 	bne r3,r0,860df4 <number+0x188>
  860d18:	34 03 00 30 	mvi r3,48
  860d1c:	33 83 00 20 	sb (sp+32),r3
  860d20:	34 08 00 01 	mvi r8,1
  860d24:	34 03 00 00 	mvi r3,0
  860d28:	b9 00 50 00 	mv r10,r8
  860d2c:	4d 06 00 02 	bge r8,r6,860d34 <number+0xc8>
  860d30:	b8 c0 50 00 	mv r10,r6
  860d34:	20 e6 00 11 	andi r6,r7,0x11
  860d38:	c8 aa 48 00 	sub r9,r5,r10
  860d3c:	5c c0 00 0e 	bne r6,r0,860d74 <number+0x108>
  860d40:	35 31 ff ff 	addi r17,r9,-1
  860d44:	4c c9 00 7a 	bge r6,r9,860f2c <number+0x2c0>
  860d48:	ba 20 30 00 	mv r6,r17
  860d4c:	b8 20 28 00 	mv r5,r1
  860d50:	34 0c 00 20 	mvi r12,32
  860d54:	34 0b ff ff 	mvi r11,-1
  860d58:	34 c6 ff ff 	addi r6,r6,-1
  860d5c:	50 a2 00 02 	bgeu r5,r2,860d64 <number+0xf8>
  860d60:	30 ac 00 00 	sb (r5+0),r12
  860d64:	34 a5 00 01 	addi r5,r5,1
  860d68:	5c cb ff fc 	bne r6,r11,860d58 <number+0xec>
  860d6c:	b4 29 08 00 	add r1,r1,r9
  860d70:	ca 29 48 00 	sub r9,r17,r9
  860d74:	45 e0 00 04 	be r15,r0,860d84 <number+0x118>
  860d78:	50 22 00 02 	bgeu r1,r2,860d80 <number+0x114>
  860d7c:	30 2f 00 00 	sb (r1+0),r15
  860d80:	34 21 00 01 	addi r1,r1,1
  860d84:	46 00 00 05 	be r16,r0,860d98 <number+0x12c>
  860d88:	34 05 00 08 	mvi r5,8
  860d8c:	44 85 00 61 	be r4,r5,860f10 <number+0x2a4>
  860d90:	34 05 00 10 	mvi r5,16
  860d94:	44 85 00 54 	be r4,r5,860ee4 <number+0x278>
  860d98:	20 e7 00 10 	andi r7,r7,0x10
  860d9c:	5c e0 00 0c 	bne r7,r0,860dcc <number+0x160>
  860da0:	35 25 ff ff 	addi r5,r9,-1
  860da4:	4c e9 00 60 	bge r7,r9,860f24 <number+0x2b8>
  860da8:	b8 20 20 00 	mv r4,r1
  860dac:	34 06 ff ff 	mvi r6,-1
  860db0:	34 a5 ff ff 	addi r5,r5,-1
  860db4:	50 82 00 02 	bgeu r4,r2,860dbc <number+0x150>
  860db8:	30 8d 00 00 	sb (r4+0),r13
  860dbc:	34 84 00 01 	addi r4,r4,1
  860dc0:	5c a6 ff fc 	bne r5,r6,860db0 <number+0x144>
  860dc4:	b4 29 08 00 	add r1,r1,r9
  860dc8:	34 09 ff ff 	mvi r9,-1
  860dcc:	4d 0a 00 22 	bge r8,r10,860e54 <number+0x1e8>
  860dd0:	35 45 ff ff 	addi r5,r10,-1
  860dd4:	b8 20 20 00 	mv r4,r1
  860dd8:	34 06 00 30 	mvi r6,48
  860ddc:	50 82 00 02 	bgeu r4,r2,860de4 <number+0x178>
  860de0:	30 86 00 00 	sb (r4+0),r6
  860de4:	34 84 00 01 	addi r4,r4,1
  860de8:	4d 05 00 19 	bge r8,r5,860e4c <number+0x1e0>
  860dec:	34 a5 ff ff 	addi r5,r5,-1
  860df0:	e3 ff ff fb 	bi 860ddc <number+0x170>
  860df4:	c4 64 48 00 	modu r9,r3,r4
  860df8:	b5 88 50 00 	add r10,r12,r8
  860dfc:	b5 69 48 00 	add r9,r11,r9
  860e00:	41 29 00 00 	lbu r9,(r9+0)
  860e04:	8c 64 18 00 	divu r3,r3,r4
  860e08:	35 08 00 01 	addi r8,r8,1
  860e0c:	31 49 00 00 	sb (r10+0),r9
  860e10:	5c 60 ff f9 	bne r3,r0,860df4 <number+0x188>
  860e14:	35 03 ff ff 	addi r3,r8,-1
  860e18:	e3 ff ff c4 	bi 860d28 <number+0xbc>
  860e1c:	78 0e 00 86 	mvhi r14,0x86
  860e20:	78 0b 00 86 	mvhi r11,0x86
  860e24:	39 ce 1d 8d 	ori r14,r14,0x1d8d
  860e28:	39 6b 1d 6c 	ori r11,r11,0x1d6c
  860e2c:	e3 ff ff 9e 	bi 860ca4 <number+0x38>
  860e30:	20 e8 00 04 	andi r8,r7,0x4
  860e34:	5d 00 00 27 	bne r8,r0,860ed0 <number+0x264>
  860e38:	20 e8 00 08 	andi r8,r7,0x8
  860e3c:	45 0f ff ae 	be r8,r15,860cf4 <number+0x88>
  860e40:	34 a5 ff ff 	addi r5,r5,-1
  860e44:	34 0f 00 20 	mvi r15,32
  860e48:	e3 ff ff ab 	bi 860cf4 <number+0x88>
  860e4c:	c9 48 40 00 	sub r8,r10,r8
  860e50:	b4 28 08 00 	add r1,r1,r8
  860e54:	37 85 00 20 	addi r5,sp,32
  860e58:	e0 00 00 02 	bi 860e60 <number+0x1f4>
  860e5c:	34 63 ff ff 	addi r3,r3,-1
  860e60:	b4 a3 20 00 	add r4,r5,r3
  860e64:	50 22 00 03 	bgeu r1,r2,860e70 <number+0x204>
  860e68:	40 84 00 00 	lbu r4,(r4+0)
  860e6c:	30 24 00 00 	sb (r1+0),r4
  860e70:	34 21 00 01 	addi r1,r1,1
  860e74:	5c 60 ff fa 	bne r3,r0,860e5c <number+0x1f0>
  860e78:	b8 20 28 00 	mv r5,r1
  860e7c:	4c 69 00 0a 	bge r3,r9,860ea4 <number+0x238>
  860e80:	35 23 ff ff 	addi r3,r9,-1
  860e84:	34 04 00 20 	mvi r4,32
  860e88:	50 22 00 02 	bgeu r1,r2,860e90 <number+0x224>
  860e8c:	30 24 00 00 	sb (r1+0),r4
  860e90:	34 21 00 01 	addi r1,r1,1
  860e94:	44 60 00 0d 	be r3,r0,860ec8 <number+0x25c>
  860e98:	34 63 ff ff 	addi r3,r3,-1
  860e9c:	e3 ff ff fb 	bi 860e88 <number+0x21c>
  860ea0:	34 01 00 00 	mvi r1,0
  860ea4:	2b 8b 00 1c 	lw r11,(sp+28)
  860ea8:	2b 8c 00 18 	lw r12,(sp+24)
  860eac:	2b 8d 00 14 	lw r13,(sp+20)
  860eb0:	2b 8e 00 10 	lw r14,(sp+16)
  860eb4:	2b 8f 00 0c 	lw r15,(sp+12)
  860eb8:	2b 90 00 08 	lw r16,(sp+8)
  860ebc:	2b 91 00 04 	lw r17,(sp+4)
  860ec0:	37 9c 00 60 	addi sp,sp,96
  860ec4:	c3 a0 00 00 	ret
  860ec8:	b4 a9 08 00 	add r1,r5,r9
  860ecc:	e3 ff ff f6 	bi 860ea4 <number+0x238>
  860ed0:	20 f0 00 20 	andi r16,r7,0x20
  860ed4:	34 a5 ff ff 	addi r5,r5,-1
  860ed8:	34 0f 00 2b 	mvi r15,43
  860edc:	46 00 ff 8c 	be r16,r0,860d0c <number+0xa0>
  860ee0:	e3 ff ff 87 	bi 860cfc <number+0x90>
  860ee4:	50 22 00 03 	bgeu r1,r2,860ef0 <number+0x284>
  860ee8:	34 04 00 30 	mvi r4,48
  860eec:	30 24 00 00 	sb (r1+0),r4
  860ef0:	34 24 00 01 	addi r4,r1,1
  860ef4:	50 82 00 03 	bgeu r4,r2,860f00 <number+0x294>
  860ef8:	41 c5 00 00 	lbu r5,(r14+0)
  860efc:	30 25 00 01 	sb (r1+1),r5
  860f00:	34 81 00 01 	addi r1,r4,1
  860f04:	e3 ff ff a5 	bi 860d98 <number+0x12c>
  860f08:	34 a5 ff fe 	addi r5,r5,-2
  860f0c:	e3 ff ff 80 	bi 860d0c <number+0xa0>
  860f10:	50 22 00 03 	bgeu r1,r2,860f1c <number+0x2b0>
  860f14:	34 04 00 30 	mvi r4,48
  860f18:	30 24 00 00 	sb (r1+0),r4
  860f1c:	34 21 00 01 	addi r1,r1,1
  860f20:	e3 ff ff 9e 	bi 860d98 <number+0x12c>
  860f24:	b8 a0 48 00 	mv r9,r5
  860f28:	e3 ff ff a9 	bi 860dcc <number+0x160>
  860f2c:	ba 20 48 00 	mv r9,r17
  860f30:	e3 ff ff 91 	bi 860d74 <number+0x108>

00860f34 <vscnprintf>:
  860f34:	37 9c ff f8 	addi sp,sp,-8
  860f38:	5b 8b 00 08 	sw (sp+8),r11
  860f3c:	5b 9d 00 04 	sw (sp+4),ra
  860f40:	b8 40 58 00 	mv r11,r2
  860f44:	f8 00 01 a8 	calli 8615e4 <vsnprintf>
  860f48:	49 61 00 02 	bg r11,r1,860f50 <vscnprintf+0x1c>
  860f4c:	35 61 ff ff 	addi r1,r11,-1
  860f50:	2b 9d 00 04 	lw ra,(sp+4)
  860f54:	2b 8b 00 08 	lw r11,(sp+8)
  860f58:	37 9c 00 08 	addi sp,sp,8
  860f5c:	c3 a0 00 00 	ret

00860f60 <snprintf>:
  860f60:	37 9c ff e4 	addi sp,sp,-28
  860f64:	5b 9d 00 04 	sw (sp+4),ra
  860f68:	5b 84 00 0c 	sw (sp+12),r4
  860f6c:	37 84 00 0c 	addi r4,sp,12
  860f70:	5b 83 00 08 	sw (sp+8),r3
  860f74:	5b 85 00 10 	sw (sp+16),r5
  860f78:	5b 86 00 14 	sw (sp+20),r6
  860f7c:	5b 87 00 18 	sw (sp+24),r7
  860f80:	5b 88 00 1c 	sw (sp+28),r8
  860f84:	f8 00 01 98 	calli 8615e4 <vsnprintf>
  860f88:	2b 9d 00 04 	lw ra,(sp+4)
  860f8c:	37 9c 00 1c 	addi sp,sp,28
  860f90:	c3 a0 00 00 	ret

00860f94 <scnprintf>:
  860f94:	37 9c ff e0 	addi sp,sp,-32
  860f98:	5b 8b 00 08 	sw (sp+8),r11
  860f9c:	5b 9d 00 04 	sw (sp+4),ra
  860fa0:	5b 84 00 10 	sw (sp+16),r4
  860fa4:	37 84 00 10 	addi r4,sp,16
  860fa8:	b8 40 58 00 	mv r11,r2
  860fac:	5b 83 00 0c 	sw (sp+12),r3
  860fb0:	5b 85 00 14 	sw (sp+20),r5
  860fb4:	5b 86 00 18 	sw (sp+24),r6
  860fb8:	5b 87 00 1c 	sw (sp+28),r7
  860fbc:	5b 88 00 20 	sw (sp+32),r8
  860fc0:	f8 00 01 89 	calli 8615e4 <vsnprintf>
  860fc4:	49 61 00 02 	bg r11,r1,860fcc <scnprintf+0x38>
  860fc8:	35 61 ff ff 	addi r1,r11,-1
  860fcc:	2b 9d 00 04 	lw ra,(sp+4)
  860fd0:	2b 8b 00 08 	lw r11,(sp+8)
  860fd4:	37 9c 00 20 	addi sp,sp,32
  860fd8:	c3 a0 00 00 	ret

00860fdc <vsprintf>:
  860fdc:	37 9c ff fc 	addi sp,sp,-4
  860fe0:	5b 9d 00 04 	sw (sp+4),ra
  860fe4:	78 04 00 86 	mvhi r4,0x86
  860fe8:	38 84 1d 30 	ori r4,r4,0x1d30
  860fec:	b8 40 28 00 	mv r5,r2
  860ff0:	28 82 00 00 	lw r2,(r4+0)
  860ff4:	b8 60 20 00 	mv r4,r3
  860ff8:	b8 a0 18 00 	mv r3,r5
  860ffc:	f8 00 01 7a 	calli 8615e4 <vsnprintf>
  861000:	2b 9d 00 04 	lw ra,(sp+4)
  861004:	37 9c 00 04 	addi sp,sp,4
  861008:	c3 a0 00 00 	ret

0086100c <sprintf>:
  86100c:	37 9c ff e0 	addi sp,sp,-32
  861010:	5b 9d 00 04 	sw (sp+4),ra
  861014:	78 0a 00 86 	mvhi r10,0x86
  861018:	39 4a 1d 30 	ori r10,r10,0x1d30
  86101c:	b8 40 48 00 	mv r9,r2
  861020:	5b 82 00 08 	sw (sp+8),r2
  861024:	29 42 00 00 	lw r2,(r10+0)
  861028:	5b 83 00 0c 	sw (sp+12),r3
  86102c:	5b 84 00 10 	sw (sp+16),r4
  861030:	b9 20 18 00 	mv r3,r9
  861034:	37 84 00 0c 	addi r4,sp,12
  861038:	5b 85 00 14 	sw (sp+20),r5
  86103c:	5b 86 00 18 	sw (sp+24),r6
  861040:	5b 87 00 1c 	sw (sp+28),r7
  861044:	5b 88 00 20 	sw (sp+32),r8
  861048:	f8 00 01 67 	calli 8615e4 <vsnprintf>
  86104c:	2b 9d 00 04 	lw ra,(sp+4)
  861050:	37 9c 00 20 	addi sp,sp,32
  861054:	c3 a0 00 00 	ret

00861058 <rand>:
  861058:	78 02 40 00 	mvhi r2,0x4000
  86105c:	38 42 00 00 	ori r2,r2,0x0
  861060:	28 41 00 00 	lw r1,(r2+0)
  861064:	78 04 00 86 	mvhi r4,0x86
  861068:	38 84 1d 34 	ori r4,r4,0x1d34
  86106c:	3c 23 00 07 	sli r3,r1,7
  861070:	b4 61 08 00 	add r1,r3,r1
  861074:	28 83 00 00 	lw r3,(r4+0)
  861078:	b4 23 08 00 	add r1,r1,r3
  86107c:	58 41 00 00 	sw (r2+0),r1
  861080:	c3 a0 00 00 	ret

00861084 <abort>:
  861084:	37 9c ff fc 	addi sp,sp,-4
  861088:	5b 9d 00 04 	sw (sp+4),ra
  86108c:	78 01 00 86 	mvhi r1,0x86
  861090:	38 21 1d 38 	ori r1,r1,0x1d38
  861094:	f8 00 00 88 	calli 8612b4 <printf>
  861098:	e0 00 00 00 	bi 861098 <abort+0x14>

0086109c <console_set_write_hook>:
  86109c:	78 02 40 00 	mvhi r2,0x4000
  8610a0:	38 42 00 04 	ori r2,r2,0x4
  8610a4:	58 41 00 00 	sw (r2+0),r1
  8610a8:	c3 a0 00 00 	ret

008610ac <console_set_read_hook>:
  8610ac:	78 04 40 00 	mvhi r4,0x4000
  8610b0:	78 03 40 00 	mvhi r3,0x4000
  8610b4:	38 84 00 0c 	ori r4,r4,0xc
  8610b8:	38 63 00 08 	ori r3,r3,0x8
  8610bc:	58 81 00 00 	sw (r4+0),r1
  8610c0:	58 62 00 00 	sw (r3+0),r2
  8610c4:	c3 a0 00 00 	ret

008610c8 <readchar>:
  8610c8:	37 9c ff f0 	addi sp,sp,-16
  8610cc:	5b 8b 00 0c 	sw (sp+12),r11
  8610d0:	5b 8c 00 08 	sw (sp+8),r12
  8610d4:	5b 9d 00 04 	sw (sp+4),ra
  8610d8:	78 0b 40 00 	mvhi r11,0x4000
  8610dc:	39 6b 00 08 	ori r11,r11,0x8
  8610e0:	34 0c 03 e7 	mvi r12,999
  8610e4:	f8 00 00 e8 	calli 861484 <uart_read_nonblock>
  8610e8:	5c 20 00 0f 	bne r1,r0,861124 <readchar+0x5c>
  8610ec:	29 62 00 00 	lw r2,(r11+0)
  8610f0:	44 41 00 03 	be r2,r1,8610fc <readchar+0x34>
  8610f4:	d8 40 00 00 	call r2
  8610f8:	5c 20 00 11 	bne r1,r0,86113c <readchar+0x74>
  8610fc:	5b 80 00 10 	sw (sp+16),r0
  861100:	2b 81 00 10 	lw r1,(sp+16)
  861104:	48 2c ff f8 	bg r1,r12,8610e4 <readchar+0x1c>
  861108:	2b 81 00 10 	lw r1,(sp+16)
  86110c:	34 21 00 01 	addi r1,r1,1
  861110:	5b 81 00 10 	sw (sp+16),r1
  861114:	2b 81 00 10 	lw r1,(sp+16)
  861118:	4d 81 ff fc 	bge r12,r1,861108 <readchar+0x40>
  86111c:	f8 00 00 da 	calli 861484 <uart_read_nonblock>
  861120:	44 20 ff f3 	be r1,r0,8610ec <readchar+0x24>
  861124:	f8 00 00 c7 	calli 861440 <uart_read>
  861128:	2b 9d 00 04 	lw ra,(sp+4)
  86112c:	2b 8b 00 0c 	lw r11,(sp+12)
  861130:	2b 8c 00 08 	lw r12,(sp+8)
  861134:	37 9c 00 10 	addi sp,sp,16
  861138:	c3 a0 00 00 	ret
  86113c:	78 01 40 00 	mvhi r1,0x4000
  861140:	38 21 00 0c 	ori r1,r1,0xc
  861144:	28 21 00 00 	lw r1,(r1+0)
  861148:	d8 20 00 00 	call r1
  86114c:	2b 9d 00 04 	lw ra,(sp+4)
  861150:	2b 8b 00 0c 	lw r11,(sp+12)
  861154:	2b 8c 00 08 	lw r12,(sp+8)
  861158:	37 9c 00 10 	addi sp,sp,16
  86115c:	c3 a0 00 00 	ret

00861160 <readchar_nonblock>:
  861160:	37 9c ff fc 	addi sp,sp,-4
  861164:	5b 9d 00 04 	sw (sp+4),ra
  861168:	f8 00 00 c7 	calli 861484 <uart_read_nonblock>
  86116c:	34 02 00 01 	mvi r2,1
  861170:	5c 20 00 08 	bne r1,r0,861190 <readchar_nonblock+0x30>
  861174:	78 01 40 00 	mvhi r1,0x4000
  861178:	38 21 00 08 	ori r1,r1,0x8
  86117c:	28 21 00 00 	lw r1,(r1+0)
  861180:	34 02 00 00 	mvi r2,0
  861184:	44 22 00 03 	be r1,r2,861190 <readchar_nonblock+0x30>
  861188:	d8 20 00 00 	call r1
  86118c:	7c 22 00 00 	cmpnei r2,r1,0
  861190:	b8 40 08 00 	mv r1,r2
  861194:	2b 9d 00 04 	lw ra,(sp+4)
  861198:	37 9c 00 04 	addi sp,sp,4
  86119c:	c3 a0 00 00 	ret

008611a0 <puts>:
  8611a0:	37 9c ff ec 	addi sp,sp,-20
  8611a4:	5b 8b 00 14 	sw (sp+20),r11
  8611a8:	5b 8c 00 10 	sw (sp+16),r12
  8611ac:	5b 8d 00 0c 	sw (sp+12),r13
  8611b0:	5b 8e 00 08 	sw (sp+8),r14
  8611b4:	5b 9d 00 04 	sw (sp+4),ra
  8611b8:	b8 20 60 00 	mv r12,r1
  8611bc:	90 20 70 00 	rcsr r14,IM
  8611c0:	34 01 00 01 	mvi r1,1
  8611c4:	d0 21 00 00 	wcsr IM,r1
  8611c8:	11 8b 00 00 	lb r11,(r12+0)
  8611cc:	78 0d 40 00 	mvhi r13,0x4000
  8611d0:	39 ad 00 04 	ori r13,r13,0x4
  8611d4:	45 60 00 0a 	be r11,r0,8611fc <puts+0x5c>
  8611d8:	b9 60 08 00 	mv r1,r11
  8611dc:	f8 00 00 b2 	calli 8614a4 <uart_write>
  8611e0:	29 a2 00 00 	lw r2,(r13+0)
  8611e4:	35 8c 00 01 	addi r12,r12,1
  8611e8:	b9 60 08 00 	mv r1,r11
  8611ec:	44 40 00 02 	be r2,r0,8611f4 <puts+0x54>
  8611f0:	d8 40 00 00 	call r2
  8611f4:	11 8b 00 00 	lb r11,(r12+0)
  8611f8:	5d 60 ff f8 	bne r11,r0,8611d8 <puts+0x38>
  8611fc:	34 01 00 0a 	mvi r1,10
  861200:	f8 00 00 a9 	calli 8614a4 <uart_write>
  861204:	29 a2 00 00 	lw r2,(r13+0)
  861208:	44 40 00 03 	be r2,r0,861214 <puts+0x74>
  86120c:	34 01 00 0a 	mvi r1,10
  861210:	d8 40 00 00 	call r2
  861214:	d0 2e 00 00 	wcsr IM,r14
  861218:	34 01 00 01 	mvi r1,1
  86121c:	2b 9d 00 04 	lw ra,(sp+4)
  861220:	2b 8b 00 14 	lw r11,(sp+20)
  861224:	2b 8c 00 10 	lw r12,(sp+16)
  861228:	2b 8d 00 0c 	lw r13,(sp+12)
  86122c:	2b 8e 00 08 	lw r14,(sp+8)
  861230:	37 9c 00 14 	addi sp,sp,20
  861234:	c3 a0 00 00 	ret

00861238 <putsnonl>:
  861238:	37 9c ff ec 	addi sp,sp,-20
  86123c:	5b 8b 00 14 	sw (sp+20),r11
  861240:	5b 8c 00 10 	sw (sp+16),r12
  861244:	5b 8d 00 0c 	sw (sp+12),r13
  861248:	5b 8e 00 08 	sw (sp+8),r14
  86124c:	5b 9d 00 04 	sw (sp+4),ra
  861250:	b8 20 60 00 	mv r12,r1
  861254:	90 20 70 00 	rcsr r14,IM
  861258:	34 01 00 01 	mvi r1,1
  86125c:	d0 21 00 00 	wcsr IM,r1
  861260:	11 8b 00 00 	lb r11,(r12+0)
  861264:	45 60 00 0c 	be r11,r0,861294 <putsnonl+0x5c>
  861268:	78 0d 40 00 	mvhi r13,0x4000
  86126c:	39 ad 00 04 	ori r13,r13,0x4
  861270:	b9 60 08 00 	mv r1,r11
  861274:	f8 00 00 8c 	calli 8614a4 <uart_write>
  861278:	29 a2 00 00 	lw r2,(r13+0)
  86127c:	35 8c 00 01 	addi r12,r12,1
  861280:	b9 60 08 00 	mv r1,r11
  861284:	44 40 00 02 	be r2,r0,86128c <putsnonl+0x54>
  861288:	d8 40 00 00 	call r2
  86128c:	11 8b 00 00 	lb r11,(r12+0)
  861290:	5d 60 ff f8 	bne r11,r0,861270 <putsnonl+0x38>
  861294:	d0 2e 00 00 	wcsr IM,r14
  861298:	2b 9d 00 04 	lw ra,(sp+4)
  86129c:	2b 8b 00 14 	lw r11,(sp+20)
  8612a0:	2b 8c 00 10 	lw r12,(sp+16)
  8612a4:	2b 8d 00 0c 	lw r13,(sp+12)
  8612a8:	2b 8e 00 08 	lw r14,(sp+8)
  8612ac:	37 9c 00 14 	addi sp,sp,20
  8612b0:	c3 a0 00 00 	ret

008612b4 <printf>:
  8612b4:	37 9c fe c8 	addi sp,sp,-312
  8612b8:	5b 8b 00 18 	sw (sp+24),r11
  8612bc:	5b 8c 00 14 	sw (sp+20),r12
  8612c0:	5b 8d 00 10 	sw (sp+16),r13
  8612c4:	5b 8e 00 0c 	sw (sp+12),r14
  8612c8:	5b 8f 00 08 	sw (sp+8),r15
  8612cc:	5b 9d 00 04 	sw (sp+4),ra
  8612d0:	b8 20 48 00 	mv r9,r1
  8612d4:	37 8c 00 1c 	addi r12,sp,28
  8612d8:	5b 81 01 1c 	sw (sp+284),r1
  8612dc:	5b 82 01 20 	sw (sp+288),r2
  8612e0:	5b 83 01 24 	sw (sp+292),r3
  8612e4:	5b 84 01 28 	sw (sp+296),r4
  8612e8:	b9 80 08 00 	mv r1,r12
  8612ec:	34 02 01 00 	mvi r2,256
  8612f0:	b9 20 18 00 	mv r3,r9
  8612f4:	37 84 01 20 	addi r4,sp,288
  8612f8:	5b 85 01 2c 	sw (sp+300),r5
  8612fc:	5b 86 01 30 	sw (sp+304),r6
  861300:	5b 87 01 34 	sw (sp+308),r7
  861304:	5b 88 01 38 	sw (sp+312),r8
  861308:	fb ff ff 0b 	calli 860f34 <vscnprintf>
  86130c:	b8 20 70 00 	mv r14,r1
  861310:	b5 81 08 00 	add r1,r12,r1
  861314:	30 20 00 00 	sb (r1+0),r0
  861318:	90 20 78 00 	rcsr r15,IM
  86131c:	34 01 00 01 	mvi r1,1
  861320:	d0 21 00 00 	wcsr IM,r1
  861324:	13 8b 00 1c 	lb r11,(sp+28)
  861328:	45 60 00 0c 	be r11,r0,861358 <printf+0xa4>
  86132c:	78 0d 40 00 	mvhi r13,0x4000
  861330:	39 ad 00 04 	ori r13,r13,0x4
  861334:	b9 60 08 00 	mv r1,r11
  861338:	f8 00 00 5b 	calli 8614a4 <uart_write>
  86133c:	29 a2 00 00 	lw r2,(r13+0)
  861340:	35 8c 00 01 	addi r12,r12,1
  861344:	b9 60 08 00 	mv r1,r11
  861348:	44 40 00 02 	be r2,r0,861350 <printf+0x9c>
  86134c:	d8 40 00 00 	call r2
  861350:	11 8b 00 00 	lb r11,(r12+0)
  861354:	5d 60 ff f8 	bne r11,r0,861334 <printf+0x80>
  861358:	d0 2f 00 00 	wcsr IM,r15
  86135c:	b9 c0 08 00 	mv r1,r14
  861360:	2b 9d 00 04 	lw ra,(sp+4)
  861364:	2b 8b 00 18 	lw r11,(sp+24)
  861368:	2b 8c 00 14 	lw r12,(sp+20)
  86136c:	2b 8d 00 10 	lw r13,(sp+16)
  861370:	2b 8e 00 0c 	lw r14,(sp+12)
  861374:	2b 8f 00 08 	lw r15,(sp+8)
  861378:	37 9c 01 38 	addi sp,sp,312
  86137c:	c3 a0 00 00 	ret

00861380 <uart_isr>:
  861380:	78 01 00 86 	mvhi r1,0x86
  861384:	38 21 1d 94 	ori r1,r1,0x1d94
  861388:	28 22 00 00 	lw r2,(r1+0)
  86138c:	28 41 00 00 	lw r1,(r2+0)
  861390:	58 41 00 00 	sw (r2+0),r1
  861394:	20 22 00 02 	andi r2,r1,0x2
  861398:	44 40 00 0e 	be r2,r0,8613d0 <uart_isr+0x50>
  86139c:	78 02 40 00 	mvhi r2,0x4000
  8613a0:	38 42 00 18 	ori r2,r2,0x18
  8613a4:	78 03 e0 00 	mvhi r3,0xe000
  8613a8:	28 46 00 00 	lw r6,(r2+0)
  8613ac:	28 65 00 00 	lw r5,(r3+0)
  8613b0:	28 44 00 00 	lw r4,(r2+0)
  8613b4:	78 03 40 00 	mvhi r3,0x4000
  8613b8:	38 63 10 28 	ori r3,r3,0x1028
  8613bc:	34 84 00 01 	addi r4,r4,1
  8613c0:	b4 66 18 00 	add r3,r3,r6
  8613c4:	20 84 0f ff 	andi r4,r4,0xfff
  8613c8:	30 65 00 00 	sb (r3+0),r5
  8613cc:	58 44 00 00 	sw (r2+0),r4
  8613d0:	20 21 00 04 	andi r1,r1,0x4
  8613d4:	44 20 00 11 	be r1,r0,861418 <uart_isr+0x98>
  8613d8:	78 01 40 00 	mvhi r1,0x4000
  8613dc:	78 02 40 00 	mvhi r2,0x4000
  8613e0:	38 21 00 24 	ori r1,r1,0x24
  8613e4:	38 42 00 20 	ori r2,r2,0x20
  8613e8:	28 23 00 00 	lw r3,(r1+0)
  8613ec:	28 42 00 00 	lw r2,(r2+0)
  8613f0:	44 43 00 0d 	be r2,r3,861424 <uart_isr+0xa4>
  8613f4:	78 02 40 00 	mvhi r2,0x4000
  8613f8:	38 42 00 28 	ori r2,r2,0x28
  8613fc:	b4 43 10 00 	add r2,r2,r3
  861400:	10 44 00 00 	lb r4,(r2+0)
  861404:	34 63 00 01 	addi r3,r3,1
  861408:	78 02 e0 00 	mvhi r2,0xe000
  86140c:	58 44 00 00 	sw (r2+0),r4
  861410:	20 63 0f ff 	andi r3,r3,0xfff
  861414:	58 23 00 00 	sw (r1+0),r3
  861418:	34 01 00 01 	mvi r1,1
  86141c:	d0 41 00 00 	wcsr IP,r1
  861420:	c3 a0 00 00 	ret
  861424:	78 01 40 00 	mvhi r1,0x4000
  861428:	38 21 00 10 	ori r1,r1,0x10
  86142c:	34 02 00 01 	mvi r2,1
  861430:	58 22 00 00 	sw (r1+0),r2
  861434:	34 01 00 01 	mvi r1,1
  861438:	d0 41 00 00 	wcsr IP,r1
  86143c:	c3 a0 00 00 	ret

00861440 <uart_read>:
  861440:	78 02 40 00 	mvhi r2,0x4000
  861444:	78 04 40 00 	mvhi r4,0x4000
  861448:	38 42 00 1c 	ori r2,r2,0x1c
  86144c:	38 84 00 18 	ori r4,r4,0x18
  861450:	28 43 00 00 	lw r3,(r2+0)
  861454:	28 81 00 00 	lw r1,(r4+0)
  861458:	44 61 ff fe 	be r3,r1,861450 <uart_read+0x10>
  86145c:	28 44 00 00 	lw r4,(r2+0)
  861460:	28 43 00 00 	lw r3,(r2+0)
  861464:	78 01 40 00 	mvhi r1,0x4000
  861468:	38 21 10 28 	ori r1,r1,0x1028
  86146c:	34 63 00 01 	addi r3,r3,1
  861470:	b4 24 08 00 	add r1,r1,r4
  861474:	20 63 0f ff 	andi r3,r3,0xfff
  861478:	10 21 00 00 	lb r1,(r1+0)
  86147c:	58 43 00 00 	sw (r2+0),r3
  861480:	c3 a0 00 00 	ret

00861484 <uart_read_nonblock>:
  861484:	78 01 40 00 	mvhi r1,0x4000
  861488:	78 02 40 00 	mvhi r2,0x4000
  86148c:	38 21 00 1c 	ori r1,r1,0x1c
  861490:	38 42 00 18 	ori r2,r2,0x18
  861494:	28 23 00 00 	lw r3,(r1+0)
  861498:	28 41 00 00 	lw r1,(r2+0)
  86149c:	fc 61 08 00 	cmpne r1,r3,r1
  8614a0:	c3 a0 00 00 	ret

008614a4 <uart_write>:
  8614a4:	b0 20 08 00 	sextb r1,r1
  8614a8:	90 20 20 00 	rcsr r4,IM
  8614ac:	34 02 00 00 	mvi r2,0
  8614b0:	d0 22 00 00 	wcsr IM,r2
  8614b4:	78 02 40 00 	mvhi r2,0x4000
  8614b8:	38 42 00 14 	ori r2,r2,0x14
  8614bc:	28 43 00 00 	lw r3,(r2+0)
  8614c0:	44 60 00 0b 	be r3,r0,8614ec <uart_write+0x48>
  8614c4:	78 03 00 86 	mvhi r3,0x86
  8614c8:	38 63 1d 94 	ori r3,r3,0x1d94
  8614cc:	28 62 00 00 	lw r2,(r3+0)
  8614d0:	78 03 e0 00 	mvhi r3,0xe000
  8614d4:	58 61 00 00 	sw (r3+0),r1
  8614d8:	28 41 00 00 	lw r1,(r2+0)
  8614dc:	20 21 00 01 	andi r1,r1,0x1
  8614e0:	44 20 ff fe 	be r1,r0,8614d8 <uart_write+0x34>
  8614e4:	d0 24 00 00 	wcsr IM,r4
  8614e8:	c3 a0 00 00 	ret
  8614ec:	78 02 40 00 	mvhi r2,0x4000
  8614f0:	38 42 00 10 	ori r2,r2,0x10
  8614f4:	28 45 00 00 	lw r5,(r2+0)
  8614f8:	5c a3 00 0d 	bne r5,r3,86152c <uart_write+0x88>
  8614fc:	78 02 40 00 	mvhi r2,0x4000
  861500:	38 42 00 20 	ori r2,r2,0x20
  861504:	28 46 00 00 	lw r6,(r2+0)
  861508:	78 03 40 00 	mvhi r3,0x4000
  86150c:	38 63 00 28 	ori r3,r3,0x28
  861510:	34 c5 00 01 	addi r5,r6,1
  861514:	b4 66 18 00 	add r3,r3,r6
  861518:	20 a5 0f ff 	andi r5,r5,0xfff
  86151c:	30 61 00 00 	sb (r3+0),r1
  861520:	58 45 00 00 	sw (r2+0),r5
  861524:	d0 24 00 00 	wcsr IM,r4
  861528:	c3 a0 00 00 	ret
  86152c:	58 40 00 00 	sw (r2+0),r0
  861530:	78 02 e0 00 	mvhi r2,0xe000
  861534:	58 41 00 00 	sw (r2+0),r1
  861538:	d0 24 00 00 	wcsr IM,r4
  86153c:	c3 a0 00 00 	ret

00861540 <uart_init>:
  861540:	78 01 40 00 	mvhi r1,0x4000
  861544:	38 21 00 18 	ori r1,r1,0x18
  861548:	78 04 40 00 	mvhi r4,0x4000
  86154c:	78 02 40 00 	mvhi r2,0x4000
  861550:	58 20 00 00 	sw (r1+0),r0
  861554:	38 84 00 1c 	ori r4,r4,0x1c
  861558:	38 42 00 24 	ori r2,r2,0x24
  86155c:	78 03 40 00 	mvhi r3,0x4000
  861560:	78 01 40 00 	mvhi r1,0x4000
  861564:	58 80 00 00 	sw (r4+0),r0
  861568:	58 40 00 00 	sw (r2+0),r0
  86156c:	38 63 00 20 	ori r3,r3,0x20
  861570:	38 21 00 10 	ori r1,r1,0x10
  861574:	34 02 00 01 	mvi r2,1
  861578:	58 22 00 00 	sw (r1+0),r2
  86157c:	58 60 00 00 	sw (r3+0),r0
  861580:	34 01 00 01 	mvi r1,1
  861584:	d0 41 00 00 	wcsr IP,r1
  861588:	78 02 00 86 	mvhi r2,0x86
  86158c:	38 42 1d 94 	ori r2,r2,0x1d94
  861590:	28 41 00 00 	lw r1,(r2+0)
  861594:	78 03 00 86 	mvhi r3,0x86
  861598:	38 63 1d 98 	ori r3,r3,0x1d98
  86159c:	28 22 00 00 	lw r2,(r1+0)
  8615a0:	58 22 00 00 	sw (r1+0),r2
  8615a4:	28 61 00 00 	lw r1,(r3+0)
  8615a8:	34 02 00 03 	mvi r2,3
  8615ac:	58 22 00 00 	sw (r1+0),r2
  8615b0:	90 20 08 00 	rcsr r1,IM
  8615b4:	38 21 00 01 	ori r1,r1,0x1
  8615b8:	d0 21 00 00 	wcsr IM,r1
  8615bc:	c3 a0 00 00 	ret

008615c0 <uart_force_sync>:
  8615c0:	44 20 00 05 	be r1,r0,8615d4 <uart_force_sync+0x14>
  8615c4:	78 03 40 00 	mvhi r3,0x4000
  8615c8:	38 63 00 10 	ori r3,r3,0x10
  8615cc:	28 62 00 00 	lw r2,(r3+0)
  8615d0:	44 40 ff ff 	be r2,r0,8615cc <uart_force_sync+0xc>
  8615d4:	78 02 40 00 	mvhi r2,0x4000
  8615d8:	38 42 00 14 	ori r2,r2,0x14
  8615dc:	58 41 00 00 	sw (r2+0),r1
  8615e0:	c3 a0 00 00 	ret

008615e4 <vsnprintf>:
  8615e4:	37 9c ff b4 	addi sp,sp,-76
  8615e8:	5b 8b 00 44 	sw (sp+68),r11
  8615ec:	5b 8c 00 40 	sw (sp+64),r12
  8615f0:	5b 8d 00 3c 	sw (sp+60),r13
  8615f4:	5b 8e 00 38 	sw (sp+56),r14
  8615f8:	5b 8f 00 34 	sw (sp+52),r15
  8615fc:	5b 90 00 30 	sw (sp+48),r16
  861600:	5b 91 00 2c 	sw (sp+44),r17
  861604:	5b 92 00 28 	sw (sp+40),r18
  861608:	5b 93 00 24 	sw (sp+36),r19
  86160c:	5b 94 00 20 	sw (sp+32),r20
  861610:	5b 95 00 1c 	sw (sp+28),r21
  861614:	5b 96 00 18 	sw (sp+24),r22
  861618:	5b 97 00 14 	sw (sp+20),r23
  86161c:	5b 98 00 10 	sw (sp+16),r24
  861620:	5b 99 00 0c 	sw (sp+12),r25
  861624:	5b 9b 00 08 	sw (sp+8),fp
  861628:	5b 9d 00 04 	sw (sp+4),ra
  86162c:	5b 83 00 4c 	sw (sp+76),r3
  861630:	b8 40 a0 00 	mv r20,r2
  861634:	b8 20 90 00 	mv r18,r1
  861638:	b8 80 78 00 	mv r15,r4
  86163c:	34 05 00 00 	mvi r5,0
  861640:	48 02 00 79 	bg r0,r2,861824 <vsnprintf+0x240>
  861644:	b4 22 70 00 	add r14,r1,r2
  861648:	54 2e 00 99 	bgu r1,r14,8618ac <vsnprintf+0x2c8>
  86164c:	2b 87 00 4c 	lw r7,(sp+76)
  861650:	ba 40 60 00 	mv r12,r18
  861654:	34 05 00 00 	mvi r5,0
  861658:	10 e3 00 00 	lb r3,(r7+0)
  86165c:	44 60 00 87 	be r3,r0,861878 <vsnprintf+0x294>
  861660:	78 11 00 86 	mvhi r17,0x86
  861664:	78 16 00 86 	mvhi r22,0x86
  861668:	78 19 00 86 	mvhi r25,0x86
  86166c:	34 13 00 25 	mvi r19,37
  861670:	34 10 00 10 	mvi r16,16
  861674:	3a 31 1d a4 	ori r17,r17,0x1da4
  861678:	34 18 00 09 	mvi r24,9
  86167c:	34 1b 00 53 	mvi fp,83
  861680:	3a d6 1d e8 	ori r22,r22,0x1de8
  861684:	34 17 00 6c 	mvi r23,108
  861688:	34 15 00 20 	mvi r21,32
  86168c:	3b 39 1d 9c 	ori r25,r25,0x1d9c
  861690:	b8 e0 20 00 	mv r4,r7
  861694:	e0 00 00 09 	bi 8616b8 <vsnprintf+0xd4>
  861698:	51 8e 00 02 	bgeu r12,r14,8616a0 <vsnprintf+0xbc>
  86169c:	31 83 00 00 	sb (r12+0),r3
  8616a0:	2b 84 00 4c 	lw r4,(sp+76)
  8616a4:	35 8c 00 01 	addi r12,r12,1
  8616a8:	34 84 00 01 	addi r4,r4,1
  8616ac:	5b 84 00 4c 	sw (sp+76),r4
  8616b0:	10 83 00 00 	lb r3,(r4+0)
  8616b4:	44 60 00 70 	be r3,r0,861874 <vsnprintf+0x290>
  8616b8:	34 0b 00 00 	mvi r11,0
  8616bc:	5c 73 ff f7 	bne r3,r19,861698 <vsnprintf+0xb4>
  8616c0:	34 84 00 01 	addi r4,r4,1
  8616c4:	5b 84 00 4c 	sw (sp+76),r4
  8616c8:	10 88 00 00 	lb r8,(r4+0)
  8616cc:	35 01 ff e0 	addi r1,r8,-32
  8616d0:	20 21 00 ff 	andi r1,r1,0xff
  8616d4:	54 30 00 0f 	bgu r1,r16,861710 <vsnprintf+0x12c>
  8616d8:	3c 21 00 02 	sli r1,r1,2
  8616dc:	b6 21 08 00 	add r1,r17,r1
  8616e0:	28 21 00 00 	lw r1,(r1+0)
  8616e4:	c0 20 00 00 	b r1
  8616e8:	39 6b 00 01 	ori r11,r11,0x1
  8616ec:	e3 ff ff f5 	bi 8616c0 <vsnprintf+0xdc>
  8616f0:	39 6b 00 10 	ori r11,r11,0x10
  8616f4:	e3 ff ff f3 	bi 8616c0 <vsnprintf+0xdc>
  8616f8:	39 6b 00 04 	ori r11,r11,0x4
  8616fc:	e3 ff ff f1 	bi 8616c0 <vsnprintf+0xdc>
  861700:	39 6b 00 20 	ori r11,r11,0x20
  861704:	e3 ff ff ef 	bi 8616c0 <vsnprintf+0xdc>
  861708:	39 6b 00 08 	ori r11,r11,0x8
  86170c:	e3 ff ff ed 	bi 8616c0 <vsnprintf+0xdc>
  861710:	35 03 ff d0 	addi r3,r8,-48
  861714:	20 63 00 ff 	andi r3,r3,0xff
  861718:	54 78 00 19 	bgu r3,r24,86177c <vsnprintf+0x198>
  86171c:	37 81 00 4c 	addi r1,sp,76
  861720:	fb ff fd 3f 	calli 860c1c <skip_atoi>
  861724:	2b 84 00 4c 	lw r4,(sp+76)
  861728:	b8 20 28 00 	mv r5,r1
  86172c:	34 01 00 2e 	mvi r1,46
  861730:	10 88 00 00 	lb r8,(r4+0)
  861734:	34 06 ff ff 	mvi r6,-1
  861738:	5d 01 00 17 	bne r8,r1,861794 <vsnprintf+0x1b0>
  86173c:	34 84 00 01 	addi r4,r4,1
  861740:	5b 84 00 4c 	sw (sp+76),r4
  861744:	10 88 00 00 	lb r8,(r4+0)
  861748:	35 03 ff d0 	addi r3,r8,-48
  86174c:	20 63 00 ff 	andi r3,r3,0xff
  861750:	54 78 00 4e 	bgu r3,r24,861888 <vsnprintf+0x2a4>
  861754:	37 81 00 4c 	addi r1,sp,76
  861758:	5b 85 00 48 	sw (sp+72),r5
  86175c:	fb ff fd 30 	calli 860c1c <skip_atoi>
  861760:	b8 20 30 00 	mv r6,r1
  861764:	2b 85 00 48 	lw r5,(sp+72)
  861768:	4c c0 01 06 	bge r6,r0,861b80 <vsnprintf+0x59c>
  86176c:	2b 84 00 4c 	lw r4,(sp+76)
  861770:	34 06 00 00 	mvi r6,0
  861774:	10 88 00 00 	lb r8,(r4+0)
  861778:	e0 00 00 07 	bi 861794 <vsnprintf+0x1b0>
  86177c:	34 03 00 2a 	mvi r3,42
  861780:	34 05 ff ff 	mvi r5,-1
  861784:	45 03 00 f8 	be r8,r3,861b64 <vsnprintf+0x580>
  861788:	34 01 00 2e 	mvi r1,46
  86178c:	34 06 ff ff 	mvi r6,-1
  861790:	45 01 ff eb 	be r8,r1,86173c <vsnprintf+0x158>
  861794:	65 07 00 6c 	cmpei r7,r8,108
  861798:	65 03 00 68 	cmpei r3,r8,104
  86179c:	b8 e3 18 00 	or r3,r7,r3
  8617a0:	5c 60 00 15 	bne r3,r0,8617f4 <vsnprintf+0x210>
  8617a4:	34 01 00 4c 	mvi r1,76
  8617a8:	45 01 00 08 	be r8,r1,8617c8 <vsnprintf+0x1e4>
  8617ac:	34 03 00 5a 	mvi r3,90
  8617b0:	45 03 00 06 	be r8,r3,8617c8 <vsnprintf+0x1e4>
  8617b4:	34 03 00 7a 	mvi r3,122
  8617b8:	45 03 00 04 	be r8,r3,8617c8 <vsnprintf+0x1e4>
  8617bc:	34 01 00 74 	mvi r1,116
  8617c0:	34 07 ff ff 	mvi r7,-1
  8617c4:	5d 01 00 05 	bne r8,r1,8617d8 <vsnprintf+0x1f4>
  8617c8:	34 84 00 01 	addi r4,r4,1
  8617cc:	5b 84 00 4c 	sw (sp+76),r4
  8617d0:	b9 00 38 00 	mv r7,r8
  8617d4:	10 88 00 00 	lb r8,(r4+0)
  8617d8:	35 03 ff db 	addi r3,r8,-37
  8617dc:	20 63 00 ff 	andi r3,r3,0xff
  8617e0:	54 7b 00 80 	bgu r3,fp,8619e0 <vsnprintf+0x3fc>
  8617e4:	3c 63 00 02 	sli r3,r3,2
  8617e8:	b6 c3 18 00 	add r3,r22,r3
  8617ec:	28 63 00 00 	lw r3,(r3+0)
  8617f0:	c0 60 00 00 	b r3
  8617f4:	34 84 00 01 	addi r4,r4,1
  8617f8:	5b 84 00 4c 	sw (sp+76),r4
  8617fc:	b9 00 38 00 	mv r7,r8
  861800:	5d 17 ff f5 	bne r8,r23,8617d4 <vsnprintf+0x1f0>
  861804:	10 88 00 00 	lb r8,(r4+0)
  861808:	5d 07 ff f4 	bne r8,r7,8617d8 <vsnprintf+0x1f4>
  86180c:	34 84 00 01 	addi r4,r4,1
  861810:	5b 84 00 4c 	sw (sp+76),r4
  861814:	10 88 00 00 	lb r8,(r4+0)
  861818:	34 07 00 4c 	mvi r7,76
  86181c:	e3 ff ff ef 	bi 8617d8 <vsnprintf+0x1f4>
  861820:	31 c0 ff ff 	sb (r14+-1),r0
  861824:	b8 a0 08 00 	mv r1,r5
  861828:	2b 9d 00 04 	lw ra,(sp+4)
  86182c:	2b 8b 00 44 	lw r11,(sp+68)
  861830:	2b 8c 00 40 	lw r12,(sp+64)
  861834:	2b 8d 00 3c 	lw r13,(sp+60)
  861838:	2b 8e 00 38 	lw r14,(sp+56)
  86183c:	2b 8f 00 34 	lw r15,(sp+52)
  861840:	2b 90 00 30 	lw r16,(sp+48)
  861844:	2b 91 00 2c 	lw r17,(sp+44)
  861848:	2b 92 00 28 	lw r18,(sp+40)
  86184c:	2b 93 00 24 	lw r19,(sp+36)
  861850:	2b 94 00 20 	lw r20,(sp+32)
  861854:	2b 95 00 1c 	lw r21,(sp+28)
  861858:	2b 96 00 18 	lw r22,(sp+24)
  86185c:	2b 97 00 14 	lw r23,(sp+20)
  861860:	2b 98 00 10 	lw r24,(sp+16)
  861864:	2b 99 00 0c 	lw r25,(sp+12)
  861868:	2b 9b 00 08 	lw fp,(sp+8)
  86186c:	37 9c 00 4c 	addi sp,sp,76
  861870:	c3 a0 00 00 	ret
  861874:	c9 92 28 00 	sub r5,r12,r18
  861878:	4c 14 ff eb 	bge r0,r20,861824 <vsnprintf+0x240>
  86187c:	51 8e ff e9 	bgeu r12,r14,861820 <vsnprintf+0x23c>
  861880:	31 80 00 00 	sb (r12+0),r0
  861884:	e3 ff ff e8 	bi 861824 <vsnprintf+0x240>
  861888:	34 03 00 2a 	mvi r3,42
  86188c:	34 06 00 00 	mvi r6,0
  861890:	5d 03 ff c1 	bne r8,r3,861794 <vsnprintf+0x1b0>
  861894:	29 e6 00 00 	lw r6,(r15+0)
  861898:	34 84 00 01 	addi r4,r4,1
  86189c:	5b 84 00 4c 	sw (sp+76),r4
  8618a0:	35 ef 00 04 	addi r15,r15,4
  8618a4:	4c c0 00 b7 	bge r6,r0,861b80 <vsnprintf+0x59c>
  8618a8:	e3 ff ff b1 	bi 86176c <vsnprintf+0x188>
  8618ac:	a4 20 a0 00 	not r20,r1
  8618b0:	34 0e ff ff 	mvi r14,-1
  8618b4:	e3 ff ff 66 	bi 86164c <vsnprintf+0x68>
  8618b8:	39 6b 00 02 	ori r11,r11,0x2
  8618bc:	34 04 00 0a 	mvi r4,10
  8618c0:	34 01 00 4c 	mvi r1,76
  8618c4:	44 e1 00 38 	be r7,r1,8619a4 <vsnprintf+0x3c0>
  8618c8:	44 f7 00 95 	be r7,r23,861b1c <vsnprintf+0x538>
  8618cc:	64 e3 00 7a 	cmpei r3,r7,122
  8618d0:	64 e1 00 5a 	cmpei r1,r7,90
  8618d4:	b8 61 18 00 	or r3,r3,r1
  8618d8:	5c 60 00 91 	bne r3,r0,861b1c <vsnprintf+0x538>
  8618dc:	34 01 00 74 	mvi r1,116
  8618e0:	44 e1 00 8f 	be r7,r1,861b1c <vsnprintf+0x538>
  8618e4:	34 01 00 68 	mvi r1,104
  8618e8:	5c e1 00 8d 	bne r7,r1,861b1c <vsnprintf+0x538>
  8618ec:	21 61 00 02 	andi r1,r11,0x2
  8618f0:	2d e3 00 02 	lhu r3,(r15+2)
  8618f4:	35 ef 00 04 	addi r15,r15,4
  8618f8:	44 20 00 8b 	be r1,r0,861b24 <vsnprintf+0x540>
  8618fc:	dc 60 18 00 	sexth r3,r3
  861900:	e0 00 00 89 	bi 861b24 <vsnprintf+0x540>
  861904:	21 6b 00 10 	andi r11,r11,0x10
  861908:	5d 60 00 0d 	bne r11,r0,86193c <vsnprintf+0x358>
  86190c:	34 a1 ff ff 	addi r1,r5,-1
  861910:	b8 20 28 00 	mv r5,r1
  861914:	b8 20 20 00 	mv r4,r1
  861918:	4d 61 00 09 	bge r11,r1,86193c <vsnprintf+0x358>
  86191c:	b9 80 18 00 	mv r3,r12
  861920:	50 6e 00 02 	bgeu r3,r14,861928 <vsnprintf+0x344>
  861924:	30 75 00 00 	sb (r3+0),r21
  861928:	34 84 ff ff 	addi r4,r4,-1
  86192c:	34 63 00 01 	addi r3,r3,1
  861930:	5c 80 ff fc 	bne r4,r0,861920 <vsnprintf+0x33c>
  861934:	b5 81 60 00 	add r12,r12,r1
  861938:	34 05 00 00 	mvi r5,0
  86193c:	35 e1 00 04 	addi r1,r15,4
  861940:	29 e2 00 00 	lw r2,(r15+0)
  861944:	51 8e 00 02 	bgeu r12,r14,86194c <vsnprintf+0x368>
  861948:	31 82 00 00 	sb (r12+0),r2
  86194c:	35 82 00 01 	addi r2,r12,1
  861950:	34 04 00 01 	mvi r4,1
  861954:	b5 85 60 00 	add r12,r12,r5
  861958:	b8 40 18 00 	mv r3,r2
  86195c:	48 a4 00 05 	bg r5,r4,861970 <vsnprintf+0x38c>
  861960:	2b 84 00 4c 	lw r4,(sp+76)
  861964:	b8 40 60 00 	mv r12,r2
  861968:	b8 20 78 00 	mv r15,r1
  86196c:	e3 ff ff 4f 	bi 8616a8 <vsnprintf+0xc4>
  861970:	50 6e 00 02 	bgeu r3,r14,861978 <vsnprintf+0x394>
  861974:	30 75 00 00 	sb (r3+0),r21
  861978:	34 63 00 01 	addi r3,r3,1
  86197c:	5c 6c ff fd 	bne r3,r12,861970 <vsnprintf+0x38c>
  861980:	34 a5 ff ff 	addi r5,r5,-1
  861984:	b4 45 60 00 	add r12,r2,r5
  861988:	2b 84 00 4c 	lw r4,(sp+76)
  86198c:	b8 20 78 00 	mv r15,r1
  861990:	e3 ff ff 46 	bi 8616a8 <vsnprintf+0xc4>
  861994:	34 01 00 4c 	mvi r1,76
  861998:	39 6b 00 40 	ori r11,r11,0x40
  86199c:	34 04 00 10 	mvi r4,16
  8619a0:	5c e1 ff ca 	bne r7,r1,8618c8 <vsnprintf+0x2e4>
  8619a4:	29 e3 00 04 	lw r3,(r15+4)
  8619a8:	b9 80 08 00 	mv r1,r12
  8619ac:	b9 c0 10 00 	mv r2,r14
  8619b0:	b9 60 38 00 	mv r7,r11
  8619b4:	fb ff fc ae 	calli 860c6c <number>
  8619b8:	35 ef 00 08 	addi r15,r15,8
  8619bc:	b8 20 60 00 	mv r12,r1
  8619c0:	2b 84 00 4c 	lw r4,(sp+76)
  8619c4:	e3 ff ff 39 	bi 8616a8 <vsnprintf+0xc4>
  8619c8:	51 8e 00 04 	bgeu r12,r14,8619d8 <vsnprintf+0x3f4>
  8619cc:	34 04 00 25 	mvi r4,37
  8619d0:	31 84 00 00 	sb (r12+0),r4
  8619d4:	2b 84 00 4c 	lw r4,(sp+76)
  8619d8:	35 8c 00 01 	addi r12,r12,1
  8619dc:	e3 ff ff 33 	bi 8616a8 <vsnprintf+0xc4>
  8619e0:	51 8e 00 05 	bgeu r12,r14,8619f4 <vsnprintf+0x410>
  8619e4:	34 01 00 25 	mvi r1,37
  8619e8:	31 81 00 00 	sb (r12+0),r1
  8619ec:	2b 84 00 4c 	lw r4,(sp+76)
  8619f0:	10 88 00 00 	lb r8,(r4+0)
  8619f4:	35 8c 00 01 	addi r12,r12,1
  8619f8:	45 00 00 65 	be r8,r0,861b8c <vsnprintf+0x5a8>
  8619fc:	51 8e ff f7 	bgeu r12,r14,8619d8 <vsnprintf+0x3f4>
  861a00:	31 88 00 00 	sb (r12+0),r8
  861a04:	2b 84 00 4c 	lw r4,(sp+76)
  861a08:	35 8c 00 01 	addi r12,r12,1
  861a0c:	e3 ff ff 27 	bi 8616a8 <vsnprintf+0xc4>
  861a10:	34 04 00 10 	mvi r4,16
  861a14:	e3 ff ff ab 	bi 8618c0 <vsnprintf+0x2dc>
  861a18:	34 04 00 0a 	mvi r4,10
  861a1c:	e3 ff ff a9 	bi 8618c0 <vsnprintf+0x2dc>
  861a20:	29 ed 00 00 	lw r13,(r15+0)
  861a24:	35 ef 00 04 	addi r15,r15,4
  861a28:	45 a0 00 62 	be r13,r0,861bb0 <vsnprintf+0x5cc>
  861a2c:	b8 c0 10 00 	mv r2,r6
  861a30:	b9 a0 08 00 	mv r1,r13
  861a34:	5b 85 00 48 	sw (sp+72),r5
  861a38:	21 6b 00 10 	andi r11,r11,0x10
  861a3c:	fb ff fa bc 	calli 86052c <strnlen>
  861a40:	b8 20 10 00 	mv r2,r1
  861a44:	2b 85 00 48 	lw r5,(sp+72)
  861a48:	5d 60 00 12 	bne r11,r0,861a90 <vsnprintf+0x4ac>
  861a4c:	34 a6 ff ff 	addi r6,r5,-1
  861a50:	4c 25 00 5a 	bge r1,r5,861bb8 <vsnprintf+0x5d4>
  861a54:	b8 a0 08 00 	mv r1,r5
  861a58:	b8 a0 20 00 	mv r4,r5
  861a5c:	b9 80 18 00 	mv r3,r12
  861a60:	50 6e 00 02 	bgeu r3,r14,861a68 <vsnprintf+0x484>
  861a64:	30 75 00 00 	sb (r3+0),r21
  861a68:	34 84 ff ff 	addi r4,r4,-1
  861a6c:	34 63 00 01 	addi r3,r3,1
  861a70:	48 82 ff fc 	bg r4,r2,861a60 <vsnprintf+0x47c>
  861a74:	34 04 00 01 	mvi r4,1
  861a78:	c8 85 18 00 	sub r3,r4,r5
  861a7c:	b4 62 18 00 	add r3,r3,r2
  861a80:	34 c4 ff ff 	addi r4,r6,-1
  861a84:	c8 22 08 00 	sub r1,r1,r2
  861a88:	b4 83 28 00 	add r5,r4,r3
  861a8c:	b5 81 60 00 	add r12,r12,r1
  861a90:	4c 02 00 0b 	bge r0,r2,861abc <vsnprintf+0x4d8>
  861a94:	b9 80 20 00 	mv r4,r12
  861a98:	34 03 00 00 	mvi r3,0
  861a9c:	50 8e 00 04 	bgeu r4,r14,861aac <vsnprintf+0x4c8>
  861aa0:	b5 a3 08 00 	add r1,r13,r3
  861aa4:	40 21 00 00 	lbu r1,(r1+0)
  861aa8:	30 81 00 00 	sb (r4+0),r1
  861aac:	34 63 00 01 	addi r3,r3,1
  861ab0:	34 84 00 01 	addi r4,r4,1
  861ab4:	5c 62 ff fa 	bne r3,r2,861a9c <vsnprintf+0x4b8>
  861ab8:	b5 82 60 00 	add r12,r12,r2
  861abc:	34 a4 ff ff 	addi r4,r5,-1
  861ac0:	b9 80 18 00 	mv r3,r12
  861ac4:	48 a2 00 20 	bg r5,r2,861b44 <vsnprintf+0x560>
  861ac8:	2b 84 00 4c 	lw r4,(sp+76)
  861acc:	e3 ff fe f7 	bi 8616a8 <vsnprintf+0xc4>
  861ad0:	34 01 ff ff 	mvi r1,-1
  861ad4:	44 a1 00 30 	be r5,r1,861b94 <vsnprintf+0x5b0>
  861ad8:	29 e3 00 00 	lw r3,(r15+0)
  861adc:	b9 80 08 00 	mv r1,r12
  861ae0:	34 04 00 10 	mvi r4,16
  861ae4:	b9 c0 10 00 	mv r2,r14
  861ae8:	b9 60 38 00 	mv r7,r11
  861aec:	fb ff fc 60 	calli 860c6c <number>
  861af0:	35 ef 00 04 	addi r15,r15,4
  861af4:	b8 20 60 00 	mv r12,r1
  861af8:	2b 84 00 4c 	lw r4,(sp+76)
  861afc:	e3 ff fe eb 	bi 8616a8 <vsnprintf+0xc4>
  861b00:	34 04 00 08 	mvi r4,8
  861b04:	e3 ff ff 6f 	bi 8618c0 <vsnprintf+0x2dc>
  861b08:	29 e1 00 00 	lw r1,(r15+0)
  861b0c:	c9 92 10 00 	sub r2,r12,r18
  861b10:	35 ef 00 04 	addi r15,r15,4
  861b14:	58 22 00 00 	sw (r1+0),r2
  861b18:	e3 ff fe e4 	bi 8616a8 <vsnprintf+0xc4>
  861b1c:	29 e3 00 00 	lw r3,(r15+0)
  861b20:	35 ef 00 04 	addi r15,r15,4
  861b24:	b9 80 08 00 	mv r1,r12
  861b28:	b9 c0 10 00 	mv r2,r14
  861b2c:	b9 60 38 00 	mv r7,r11
  861b30:	fb ff fc 4f 	calli 860c6c <number>
  861b34:	b8 20 60 00 	mv r12,r1
  861b38:	2b 84 00 4c 	lw r4,(sp+76)
  861b3c:	e3 ff fe db 	bi 8616a8 <vsnprintf+0xc4>
  861b40:	34 84 ff ff 	addi r4,r4,-1
  861b44:	50 6e 00 02 	bgeu r3,r14,861b4c <vsnprintf+0x568>
  861b48:	30 75 00 00 	sb (r3+0),r21
  861b4c:	34 63 00 01 	addi r3,r3,1
  861b50:	48 82 ff fc 	bg r4,r2,861b40 <vsnprintf+0x55c>
  861b54:	c8 a2 10 00 	sub r2,r5,r2
  861b58:	b5 82 60 00 	add r12,r12,r2
  861b5c:	2b 84 00 4c 	lw r4,(sp+76)
  861b60:	e3 ff fe d2 	bi 8616a8 <vsnprintf+0xc4>
  861b64:	29 e5 00 00 	lw r5,(r15+0)
  861b68:	34 84 00 01 	addi r4,r4,1
  861b6c:	5b 84 00 4c 	sw (sp+76),r4
  861b70:	35 ef 00 04 	addi r15,r15,4
  861b74:	48 05 00 0b 	bg r0,r5,861ba0 <vsnprintf+0x5bc>
  861b78:	10 88 00 00 	lb r8,(r4+0)
  861b7c:	e3 ff ff 03 	bi 861788 <vsnprintf+0x1a4>
  861b80:	2b 84 00 4c 	lw r4,(sp+76)
  861b84:	10 88 00 00 	lb r8,(r4+0)
  861b88:	e3 ff ff 03 	bi 861794 <vsnprintf+0x1b0>
  861b8c:	34 84 ff ff 	addi r4,r4,-1
  861b90:	e3 ff fe c6 	bi 8616a8 <vsnprintf+0xc4>
  861b94:	39 6b 00 01 	ori r11,r11,0x1
  861b98:	34 05 00 08 	mvi r5,8
  861b9c:	e3 ff ff cf 	bi 861ad8 <vsnprintf+0x4f4>
  861ba0:	10 88 00 00 	lb r8,(r4+0)
  861ba4:	c8 05 28 00 	sub r5,r0,r5
  861ba8:	39 6b 00 10 	ori r11,r11,0x10
  861bac:	e3 ff fe f7 	bi 861788 <vsnprintf+0x1a4>
  861bb0:	bb 20 68 00 	mv r13,r25
  861bb4:	e3 ff ff 9e 	bi 861a2c <vsnprintf+0x448>
  861bb8:	b8 c0 28 00 	mv r5,r6
  861bbc:	4c 02 ff c0 	bge r0,r2,861abc <vsnprintf+0x4d8>
  861bc0:	e3 ff ff b5 	bi 861a94 <vsnprintf+0x4b0>
