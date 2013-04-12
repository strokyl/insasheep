/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x8ddf5b5d */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/flonesan/developments/milkymist-various/boards/mlx-1000/test/ise_system/lm32_mc_arithmetic.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static int ng3[] = {32, 0};
static unsigned int ng4[] = {3U, 0U};
static unsigned int ng5[] = {2U, 0U};



static void Cont_152_0(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;

LAB0:    t1 = (t0 + 4760U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(152, ng0);
    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB5;

LAB4:    if (t18 != 0)
        goto LAB6;

LAB7:    t22 = (t0 + 5688);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memset(t26, 0, 8);
    t27 = 1U;
    t28 = t27;
    t29 = (t6 + 4);
    t30 = *((unsigned int *)t6);
    t27 = (t27 & t30);
    t31 = *((unsigned int *)t29);
    t28 = (t28 & t31);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t33 | t27);
    t34 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t34 | t28);
    xsi_driver_vfirst_trans(t22, 0, 0);
    t35 = (t0 + 5576);
    *((int *)t35) = 1;

LAB1:    return;
LAB5:    *((unsigned int *)t6) = 1;
    goto LAB7;

LAB6:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB7;

}

static void Cont_156_1(char *t0)
{
    char t3[16];
    char t6[8];
    char t15[8];
    char t30[16];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;

LAB0:    t1 = (t0 + 5008U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(156, ng0);
    t2 = (t0 + 3368);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t7 = (t6 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 31);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 31);
    t14 = (t13 & 1);
    *((unsigned int *)t7) = t14;
    t16 = (t0 + 3208);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memset(t15, 0, 8);
    t19 = (t15 + 4);
    t20 = (t18 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (t21 >> 0);
    *((unsigned int *)t15) = t22;
    t23 = *((unsigned int *)t20);
    t24 = (t23 >> 0);
    *((unsigned int *)t19) = t24;
    t25 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t25 & 2147483647U);
    t26 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t26 & 2147483647U);
    xsi_vlogtype_concat(t3, 33, 32, 2U, t15, 31, t6, 1);
    t27 = (t0 + 3528);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    xsi_vlog_unsigned_minus(t30, 33, t3, 33, t29, 32);
    t31 = (t0 + 5752);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    xsi_vlog_bit_copy(t35, 0, t30, 0, 33);
    xsi_driver_vfirst_trans(t31, 0, 32);
    t36 = (t0 + 5592);
    *((int *)t36) = 1;

LAB1:    return;
}

static void Always_169_2(char *t0)
{
    char t6[8];
    char t33[8];
    char t40[8];
    char t55[8];
    char t63[8];
    char t100[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    int t30;
    char *t31;
    char *t32;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    char *t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    char *t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    char *t96;
    char *t97;
    char *t98;
    char *t99;
    char *t101;
    char *t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    char *t115;
    char *t116;

LAB0:    t1 = (t0 + 5256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(169, ng0);
    t2 = (t0 + 5608);
    *((int *)t2) = 1;
    t3 = (t0 + 5288);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(170, ng0);

LAB5:    xsi_set_current_line(171, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng2)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(187, ng0);

LAB14:    xsi_set_current_line(189, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(191, ng0);
    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB15:    t5 = ((char*)((ng1)));
    t30 = xsi_vlog_unsigned_case_compare(t4, 3, t5, 3);
    if (t30 == 1)
        goto LAB16;

LAB17:    t2 = ((char*)((ng4)));
    t30 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t30 == 1)
        goto LAB18;

LAB19:    t2 = ((char*)((ng5)));
    t30 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t30 == 1)
        goto LAB20;

LAB21:
LAB22:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(172, ng0);

LAB13:    xsi_set_current_line(173, ng0);
    t28 = ((char*)((ng1)));
    t29 = (t0 + 3848);
    xsi_vlogvar_wait_assign_value(t29, t28, 0, 0, 6, 0LL);
    xsi_set_current_line(174, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    xsi_set_current_line(175, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    xsi_set_current_line(176, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    xsi_set_current_line(181, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(183, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    xsi_set_current_line(184, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3688);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    goto LAB12;

LAB16:    xsi_set_current_line(193, ng0);

LAB23:    xsi_set_current_line(194, ng0);
    t7 = (t0 + 1368U);
    t8 = *((char **)t7);
    t7 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t21 = (t8 + 4);
    t22 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = *((unsigned int *)t7);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t21);
    t13 = *((unsigned int *)t22);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t21);
    t17 = *((unsigned int *)t22);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB27;

LAB24:    if (t18 != 0)
        goto LAB26;

LAB25:    *((unsigned int *)t6) = 1;

LAB27:    t29 = (t6 + 4);
    t23 = *((unsigned int *)t29);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB28;

LAB29:
LAB30:    goto LAB22;

LAB18:    xsi_set_current_line(232, ng0);

LAB46:    xsi_set_current_line(233, ng0);
    t3 = (t0 + 2488U);
    t5 = *((char **)t3);
    memset(t6, 0, 8);
    t3 = (t6 + 4);
    t7 = (t5 + 8);
    t8 = (t5 + 12);
    t9 = *((unsigned int *)t7);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 0);
    t14 = (t13 & 1);
    *((unsigned int *)t3) = t14;
    t21 = ((char*)((ng1)));
    memset(t33, 0, 8);
    t22 = (t6 + 4);
    t28 = (t21 + 4);
    t15 = *((unsigned int *)t6);
    t16 = *((unsigned int *)t21);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t22);
    t19 = *((unsigned int *)t28);
    t20 = (t18 ^ t19);
    t23 = (t17 | t20);
    t24 = *((unsigned int *)t22);
    t25 = *((unsigned int *)t28);
    t26 = (t24 | t25);
    t27 = (~(t26));
    t34 = (t23 & t27);
    if (t34 != 0)
        goto LAB50;

LAB47:    if (t26 != 0)
        goto LAB49;

LAB48:    *((unsigned int *)t33) = 1;

LAB50:    t31 = (t33 + 4);
    t35 = *((unsigned int *)t31);
    t36 = (~(t35));
    t37 = *((unsigned int *)t33);
    t38 = (t37 & t36);
    t39 = (t38 != 0);
    if (t39 > 0)
        goto LAB51;

LAB52:    xsi_set_current_line(239, ng0);

LAB55:    xsi_set_current_line(240, ng0);
    t2 = (t0 + 3368);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    memset(t33, 0, 8);
    t7 = (t33 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 31);
    t11 = (t10 & 1);
    *((unsigned int *)t33) = t11;
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 31);
    t14 = (t13 & 1);
    *((unsigned int *)t7) = t14;
    t21 = (t0 + 3208);
    t22 = (t21 + 56U);
    t28 = *((char **)t22);
    memset(t40, 0, 8);
    t29 = (t40 + 4);
    t31 = (t28 + 4);
    t15 = *((unsigned int *)t28);
    t16 = (t15 >> 0);
    *((unsigned int *)t40) = t16;
    t17 = *((unsigned int *)t31);
    t18 = (t17 >> 0);
    *((unsigned int *)t29) = t18;
    t19 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t19 & 2147483647U);
    t20 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t20 & 2147483647U);
    xsi_vlogtype_concat(t6, 32, 32, 2U, t40, 31, t33, 1);
    t32 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t32, t6, 0, 0, 32, 0LL);
    xsi_set_current_line(241, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    t5 = (t3 + 56U);
    t7 = *((char **)t5);
    memset(t33, 0, 8);
    t8 = (t33 + 4);
    t21 = (t7 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (t9 >> 0);
    *((unsigned int *)t33) = t10;
    t11 = *((unsigned int *)t21);
    t12 = (t11 >> 0);
    *((unsigned int *)t8) = t12;
    t13 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t13 & 2147483647U);
    t14 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t14 & 2147483647U);
    xsi_vlogtype_concat(t6, 32, 32, 2U, t33, 31, t2, 1);
    t22 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t22, t6, 0, 0, 32, 0LL);

LAB53:    xsi_set_current_line(243, ng0);
    t2 = (t0 + 3368);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t7 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 32, 0LL);
    xsi_set_current_line(244, ng0);
    t2 = (t0 + 3848);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t8 = (t5 + 4);
    t21 = (t7 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t7);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t8);
    t13 = *((unsigned int *)t21);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t8);
    t17 = *((unsigned int *)t21);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB59;

LAB56:    if (t18 != 0)
        goto LAB58;

LAB57:    *((unsigned int *)t6) = 1;

LAB59:    memset(t33, 0, 8);
    t28 = (t6 + 4);
    t23 = *((unsigned int *)t28);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t28) != 0)
        goto LAB62;

LAB63:    t31 = (t33 + 4);
    t34 = *((unsigned int *)t33);
    t35 = (!(t34));
    t36 = *((unsigned int *)t31);
    t37 = (t35 || t36);
    if (t37 > 0)
        goto LAB64;

LAB65:    memcpy(t63, t33, 8);

LAB66:    t90 = (t63 + 4);
    t91 = *((unsigned int *)t90);
    t92 = (~(t91));
    t93 = *((unsigned int *)t63);
    t94 = (t93 & t92);
    t95 = (t94 != 0);
    if (t95 > 0)
        goto LAB78;

LAB79:
LAB80:    xsi_set_current_line(250, ng0);
    t2 = (t0 + 3848);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t7 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_minus(t6, 6, t5, 6, t7, 6);
    t8 = (t0 + 3848);
    xsi_vlogvar_wait_assign_value(t8, t6, 0, 0, 6, 0LL);
    goto LAB22;

LAB20:    xsi_set_current_line(253, ng0);

LAB86:    xsi_set_current_line(254, ng0);
    t3 = (t0 + 2488U);
    t5 = *((char **)t3);
    memset(t6, 0, 8);
    t3 = (t6 + 4);
    t7 = (t5 + 8);
    t8 = (t5 + 12);
    t9 = *((unsigned int *)t7);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 0);
    t14 = (t13 & 1);
    *((unsigned int *)t3) = t14;
    t21 = ((char*)((ng1)));
    memset(t33, 0, 8);
    t22 = (t6 + 4);
    t28 = (t21 + 4);
    t15 = *((unsigned int *)t6);
    t16 = *((unsigned int *)t21);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t22);
    t19 = *((unsigned int *)t28);
    t20 = (t18 ^ t19);
    t23 = (t17 | t20);
    t24 = *((unsigned int *)t22);
    t25 = *((unsigned int *)t28);
    t26 = (t24 | t25);
    t27 = (~(t26));
    t34 = (t23 & t27);
    if (t34 != 0)
        goto LAB90;

LAB87:    if (t26 != 0)
        goto LAB89;

LAB88:    *((unsigned int *)t33) = 1;

LAB90:    t31 = (t33 + 4);
    t35 = *((unsigned int *)t31);
    t36 = (~(t35));
    t37 = *((unsigned int *)t33);
    t38 = (t37 & t36);
    t39 = (t38 != 0);
    if (t39 > 0)
        goto LAB91;

LAB92:    xsi_set_current_line(260, ng0);

LAB95:    xsi_set_current_line(261, ng0);
    t2 = (t0 + 3368);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    memset(t33, 0, 8);
    t7 = (t33 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 31);
    t11 = (t10 & 1);
    *((unsigned int *)t33) = t11;
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 31);
    t14 = (t13 & 1);
    *((unsigned int *)t7) = t14;
    t21 = (t0 + 3208);
    t22 = (t21 + 56U);
    t28 = *((char **)t22);
    memset(t40, 0, 8);
    t29 = (t40 + 4);
    t31 = (t28 + 4);
    t15 = *((unsigned int *)t28);
    t16 = (t15 >> 0);
    *((unsigned int *)t40) = t16;
    t17 = *((unsigned int *)t31);
    t18 = (t17 >> 0);
    *((unsigned int *)t29) = t18;
    t19 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t19 & 2147483647U);
    t20 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t20 & 2147483647U);
    xsi_vlogtype_concat(t6, 32, 32, 2U, t40, 31, t33, 1);
    t32 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t32, t6, 0, 0, 32, 0LL);
    xsi_set_current_line(262, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    t5 = (t3 + 56U);
    t7 = *((char **)t5);
    memset(t33, 0, 8);
    t8 = (t33 + 4);
    t21 = (t7 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (t9 >> 0);
    *((unsigned int *)t33) = t10;
    t11 = *((unsigned int *)t21);
    t12 = (t11 >> 0);
    *((unsigned int *)t8) = t12;
    t13 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t13 & 2147483647U);
    t14 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t14 & 2147483647U);
    xsi_vlogtype_concat(t6, 32, 32, 2U, t33, 31, t2, 1);
    t22 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t22, t6, 0, 0, 32, 0LL);

LAB93:    xsi_set_current_line(264, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t7 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 32, 0LL);
    xsi_set_current_line(265, ng0);
    t2 = (t0 + 3848);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t8 = (t5 + 4);
    t21 = (t7 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t7);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t8);
    t13 = *((unsigned int *)t21);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t8);
    t17 = *((unsigned int *)t21);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB99;

LAB96:    if (t18 != 0)
        goto LAB98;

LAB97:    *((unsigned int *)t6) = 1;

LAB99:    memset(t33, 0, 8);
    t28 = (t6 + 4);
    t23 = *((unsigned int *)t28);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB100;

LAB101:    if (*((unsigned int *)t28) != 0)
        goto LAB102;

LAB103:    t31 = (t33 + 4);
    t34 = *((unsigned int *)t33);
    t35 = (!(t34));
    t36 = *((unsigned int *)t31);
    t37 = (t35 || t36);
    if (t37 > 0)
        goto LAB104;

LAB105:    memcpy(t63, t33, 8);

LAB106:    t90 = (t63 + 4);
    t91 = *((unsigned int *)t90);
    t92 = (~(t91));
    t93 = *((unsigned int *)t63);
    t94 = (t93 & t92);
    t95 = (t94 != 0);
    if (t95 > 0)
        goto LAB118;

LAB119:
LAB120:    xsi_set_current_line(271, ng0);
    t2 = (t0 + 3848);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t7 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_minus(t6, 6, t5, 6, t7, 6);
    t8 = (t0 + 3848);
    xsi_vlogvar_wait_assign_value(t8, t6, 0, 0, 6, 0LL);
    goto LAB22;

LAB26:    t28 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB27;

LAB28:    xsi_set_current_line(195, ng0);

LAB31:    xsi_set_current_line(196, ng0);
    t31 = ((char*)((ng3)));
    t32 = (t0 + 3848);
    xsi_vlogvar_wait_assign_value(t32, t31, 0, 0, 6, 0LL);
    xsi_set_current_line(197, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    xsi_set_current_line(198, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);
    t2 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 32, 0LL);
    xsi_set_current_line(199, ng0);
    t2 = (t0 + 2168U);
    t3 = *((char **)t2);
    t2 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 32, 0LL);
    xsi_set_current_line(201, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t6, 0, 8);
    t5 = (t3 + 4);
    t7 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t5);
    t13 = *((unsigned int *)t7);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t5);
    t17 = *((unsigned int *)t7);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB35;

LAB32:    if (t18 != 0)
        goto LAB34;

LAB33:    *((unsigned int *)t6) = 1;

LAB35:    t21 = (t6 + 4);
    t23 = *((unsigned int *)t21);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB36;

LAB37:
LAB38:    xsi_set_current_line(203, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t6, 0, 8);
    t5 = (t3 + 4);
    t7 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t5);
    t13 = *((unsigned int *)t7);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t5);
    t17 = *((unsigned int *)t7);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB42;

LAB39:    if (t18 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t6) = 1;

LAB42:    t21 = (t6 + 4);
    t23 = *((unsigned int *)t21);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB43;

LAB44:
LAB45:    goto LAB30;

LAB34:    t8 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB35;

LAB36:    xsi_set_current_line(202, ng0);
    t22 = ((char*)((ng4)));
    t28 = (t0 + 3688);
    xsi_vlogvar_wait_assign_value(t28, t22, 0, 0, 3, 0LL);
    goto LAB38;

LAB41:    t8 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB42;

LAB43:    xsi_set_current_line(204, ng0);
    t22 = ((char*)((ng5)));
    t28 = (t0 + 3688);
    xsi_vlogvar_wait_assign_value(t28, t22, 0, 0, 3, 0LL);
    goto LAB45;

LAB49:    t29 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB50;

LAB51:    xsi_set_current_line(234, ng0);

LAB54:    xsi_set_current_line(235, ng0);
    t32 = (t0 + 2488U);
    t41 = *((char **)t32);
    memset(t40, 0, 8);
    t32 = (t40 + 4);
    t42 = (t41 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (t43 >> 0);
    *((unsigned int *)t40) = t44;
    t45 = *((unsigned int *)t42);
    t46 = (t45 >> 0);
    *((unsigned int *)t32) = t46;
    t47 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t47 & 4294967295U);
    t48 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t48 & 4294967295U);
    t49 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t49, t40, 0, 0, 32, 0LL);
    xsi_set_current_line(236, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3368);
    t5 = (t3 + 56U);
    t7 = *((char **)t5);
    memset(t33, 0, 8);
    t8 = (t33 + 4);
    t21 = (t7 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (t9 >> 0);
    *((unsigned int *)t33) = t10;
    t11 = *((unsigned int *)t21);
    t12 = (t11 >> 0);
    *((unsigned int *)t8) = t12;
    t13 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t13 & 2147483647U);
    t14 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t14 & 2147483647U);
    xsi_vlogtype_concat(t6, 32, 32, 2U, t33, 31, t2, 1);
    t22 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t22, t6, 0, 0, 32, 0LL);
    goto LAB53;

LAB58:    t22 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB59;

LAB60:    *((unsigned int *)t33) = 1;
    goto LAB63;

LAB62:    t29 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB63;

LAB64:    t32 = (t0 + 1528U);
    t41 = *((char **)t32);
    t32 = ((char*)((ng2)));
    memset(t40, 0, 8);
    t42 = (t41 + 4);
    t49 = (t32 + 4);
    t38 = *((unsigned int *)t41);
    t39 = *((unsigned int *)t32);
    t43 = (t38 ^ t39);
    t44 = *((unsigned int *)t42);
    t45 = *((unsigned int *)t49);
    t46 = (t44 ^ t45);
    t47 = (t43 | t46);
    t48 = *((unsigned int *)t42);
    t50 = *((unsigned int *)t49);
    t51 = (t48 | t50);
    t52 = (~(t51));
    t53 = (t47 & t52);
    if (t53 != 0)
        goto LAB70;

LAB67:    if (t51 != 0)
        goto LAB69;

LAB68:    *((unsigned int *)t40) = 1;

LAB70:    memset(t55, 0, 8);
    t56 = (t40 + 4);
    t57 = *((unsigned int *)t56);
    t58 = (~(t57));
    t59 = *((unsigned int *)t40);
    t60 = (t59 & t58);
    t61 = (t60 & 1U);
    if (t61 != 0)
        goto LAB71;

LAB72:    if (*((unsigned int *)t56) != 0)
        goto LAB73;

LAB74:    t64 = *((unsigned int *)t33);
    t65 = *((unsigned int *)t55);
    t66 = (t64 | t65);
    *((unsigned int *)t63) = t66;
    t67 = (t33 + 4);
    t68 = (t55 + 4);
    t69 = (t63 + 4);
    t70 = *((unsigned int *)t67);
    t71 = *((unsigned int *)t68);
    t72 = (t70 | t71);
    *((unsigned int *)t69) = t72;
    t73 = *((unsigned int *)t69);
    t74 = (t73 != 0);
    if (t74 == 1)
        goto LAB75;

LAB76:
LAB77:    goto LAB66;

LAB69:    t54 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB70;

LAB71:    *((unsigned int *)t55) = 1;
    goto LAB74;

LAB73:    t62 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t62) = 1;
    goto LAB74;

LAB75:    t75 = *((unsigned int *)t63);
    t76 = *((unsigned int *)t69);
    *((unsigned int *)t63) = (t75 | t76);
    t77 = (t33 + 4);
    t78 = (t55 + 4);
    t79 = *((unsigned int *)t77);
    t80 = (~(t79));
    t81 = *((unsigned int *)t33);
    t30 = (t81 & t80);
    t82 = *((unsigned int *)t78);
    t83 = (~(t82));
    t84 = *((unsigned int *)t55);
    t85 = (t84 & t83);
    t86 = (~(t30));
    t87 = (~(t85));
    t88 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t88 & t86);
    t89 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t89 & t87);
    goto LAB77;

LAB78:    xsi_set_current_line(245, ng0);

LAB81:    xsi_set_current_line(247, ng0);
    t96 = (t0 + 3528);
    t97 = (t96 + 56U);
    t98 = *((char **)t97);
    t99 = ((char*)((ng1)));
    memset(t100, 0, 8);
    t101 = (t98 + 4);
    t102 = (t99 + 4);
    t103 = *((unsigned int *)t98);
    t104 = *((unsigned int *)t99);
    t105 = (t103 ^ t104);
    t106 = *((unsigned int *)t101);
    t107 = *((unsigned int *)t102);
    t108 = (t106 ^ t107);
    t109 = (t105 | t108);
    t110 = *((unsigned int *)t101);
    t111 = *((unsigned int *)t102);
    t112 = (t110 | t111);
    t113 = (~(t112));
    t114 = (t109 & t113);
    if (t114 != 0)
        goto LAB85;

LAB82:    if (t112 != 0)
        goto LAB84;

LAB83:    *((unsigned int *)t100) = 1;

LAB85:    t116 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t116, t100, 0, 0, 1, 0LL);
    xsi_set_current_line(248, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3688);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    goto LAB80;

LAB84:    t115 = (t100 + 4);
    *((unsigned int *)t100) = 1;
    *((unsigned int *)t115) = 1;
    goto LAB85;

LAB89:    t29 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB90;

LAB91:    xsi_set_current_line(255, ng0);

LAB94:    xsi_set_current_line(256, ng0);
    t32 = (t0 + 2488U);
    t41 = *((char **)t32);
    memset(t40, 0, 8);
    t32 = (t40 + 4);
    t42 = (t41 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (t43 >> 0);
    *((unsigned int *)t40) = t44;
    t45 = *((unsigned int *)t42);
    t46 = (t45 >> 0);
    *((unsigned int *)t32) = t46;
    t47 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t47 & 4294967295U);
    t48 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t48 & 4294967295U);
    t49 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t49, t40, 0, 0, 32, 0LL);
    xsi_set_current_line(257, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3368);
    t5 = (t3 + 56U);
    t7 = *((char **)t5);
    memset(t33, 0, 8);
    t8 = (t33 + 4);
    t21 = (t7 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (t9 >> 0);
    *((unsigned int *)t33) = t10;
    t11 = *((unsigned int *)t21);
    t12 = (t11 >> 0);
    *((unsigned int *)t8) = t12;
    t13 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t13 & 2147483647U);
    t14 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t14 & 2147483647U);
    xsi_vlogtype_concat(t6, 32, 32, 2U, t33, 31, t2, 1);
    t22 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t22, t6, 0, 0, 32, 0LL);
    goto LAB93;

LAB98:    t22 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB99;

LAB100:    *((unsigned int *)t33) = 1;
    goto LAB103;

LAB102:    t29 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB103;

LAB104:    t32 = (t0 + 1528U);
    t41 = *((char **)t32);
    t32 = ((char*)((ng2)));
    memset(t40, 0, 8);
    t42 = (t41 + 4);
    t49 = (t32 + 4);
    t38 = *((unsigned int *)t41);
    t39 = *((unsigned int *)t32);
    t43 = (t38 ^ t39);
    t44 = *((unsigned int *)t42);
    t45 = *((unsigned int *)t49);
    t46 = (t44 ^ t45);
    t47 = (t43 | t46);
    t48 = *((unsigned int *)t42);
    t50 = *((unsigned int *)t49);
    t51 = (t48 | t50);
    t52 = (~(t51));
    t53 = (t47 & t52);
    if (t53 != 0)
        goto LAB110;

LAB107:    if (t51 != 0)
        goto LAB109;

LAB108:    *((unsigned int *)t40) = 1;

LAB110:    memset(t55, 0, 8);
    t56 = (t40 + 4);
    t57 = *((unsigned int *)t56);
    t58 = (~(t57));
    t59 = *((unsigned int *)t40);
    t60 = (t59 & t58);
    t61 = (t60 & 1U);
    if (t61 != 0)
        goto LAB111;

LAB112:    if (*((unsigned int *)t56) != 0)
        goto LAB113;

LAB114:    t64 = *((unsigned int *)t33);
    t65 = *((unsigned int *)t55);
    t66 = (t64 | t65);
    *((unsigned int *)t63) = t66;
    t67 = (t33 + 4);
    t68 = (t55 + 4);
    t69 = (t63 + 4);
    t70 = *((unsigned int *)t67);
    t71 = *((unsigned int *)t68);
    t72 = (t70 | t71);
    *((unsigned int *)t69) = t72;
    t73 = *((unsigned int *)t69);
    t74 = (t73 != 0);
    if (t74 == 1)
        goto LAB115;

LAB116:
LAB117:    goto LAB106;

LAB109:    t54 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB110;

LAB111:    *((unsigned int *)t55) = 1;
    goto LAB114;

LAB113:    t62 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t62) = 1;
    goto LAB114;

LAB115:    t75 = *((unsigned int *)t63);
    t76 = *((unsigned int *)t69);
    *((unsigned int *)t63) = (t75 | t76);
    t77 = (t33 + 4);
    t78 = (t55 + 4);
    t79 = *((unsigned int *)t77);
    t80 = (~(t79));
    t81 = *((unsigned int *)t33);
    t30 = (t81 & t80);
    t82 = *((unsigned int *)t78);
    t83 = (~(t82));
    t84 = *((unsigned int *)t55);
    t85 = (t84 & t83);
    t86 = (~(t30));
    t87 = (~(t85));
    t88 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t88 & t86);
    t89 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t89 & t87);
    goto LAB117;

LAB118:    xsi_set_current_line(266, ng0);

LAB121:    xsi_set_current_line(268, ng0);
    t96 = (t0 + 3528);
    t97 = (t96 + 56U);
    t98 = *((char **)t97);
    t99 = ((char*)((ng1)));
    memset(t100, 0, 8);
    t101 = (t98 + 4);
    t102 = (t99 + 4);
    t103 = *((unsigned int *)t98);
    t104 = *((unsigned int *)t99);
    t105 = (t103 ^ t104);
    t106 = *((unsigned int *)t101);
    t107 = *((unsigned int *)t102);
    t108 = (t106 ^ t107);
    t109 = (t105 | t108);
    t110 = *((unsigned int *)t101);
    t111 = *((unsigned int *)t102);
    t112 = (t110 | t111);
    t113 = (~(t112));
    t114 = (t109 & t113);
    if (t114 != 0)
        goto LAB125;

LAB122:    if (t112 != 0)
        goto LAB124;

LAB123:    *((unsigned int *)t100) = 1;

LAB125:    t116 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t116, t100, 0, 0, 1, 0LL);
    xsi_set_current_line(269, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3688);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    goto LAB120;

LAB124:    t115 = (t100 + 4);
    *((unsigned int *)t100) = 1;
    *((unsigned int *)t115) = 1;
    goto LAB125;

}


extern void work_m_09477880950646915025_0207033106_init()
{
	static char *pe[] = {(void *)Cont_152_0,(void *)Cont_156_1,(void *)Always_169_2};
	xsi_register_didat("work_m_09477880950646915025_0207033106", "isim/tb_system_isim_beh.exe.sim/work/m_09477880950646915025_0207033106.didat");
	xsi_register_executes(pe);
}
