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

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/matt/Documents/Studies/4IRT/SystemOnChip/milkymist-various/boards/digilent-nexys3/ise_system/sysctl_icap.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static int ng3[] = {2, 0};
static int ng4[] = {3, 0};
static int ng5[] = {4, 0};
static int ng6[] = {5, 0};
static int ng7[] = {6, 0};
static int ng8[] = {7, 0};
static int ng9[] = {8, 0};
static int ng10[] = {9, 0};
static int ng11[] = {10, 0};
static int ng12[] = {11, 0};
static int ng13[] = {12, 0};
static int ng14[] = {13, 0};
static int ng15[] = {14, 0};
static int ng16[] = {15, 0};
static unsigned int ng17[] = {0U, 0U};
static unsigned int ng18[] = {1U, 0U};
static unsigned int ng19[] = {2U, 0U};
static unsigned int ng20[] = {3U, 0U};
static unsigned int ng21[] = {4U, 0U};
static unsigned int ng22[] = {5U, 0U};



static void Always_35_0(char *t0)
{
    char t15[8];
    char t24[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    unsigned int t30;
    int t31;

LAB0:    t1 = (t0 + 5256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 6320);
    *((int *)t2) = 1;
    t3 = (t0 + 5288);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(35, ng0);

LAB5:    xsi_set_current_line(36, ng0);
    t4 = (t0 + 3544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:
LAB8:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 3224);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3384);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    goto LAB2;

LAB6:    xsi_set_current_line(36, ng0);

LAB9:    xsi_set_current_line(37, ng0);
    t13 = (t0 + 2344U);
    t14 = *((char **)t13);
    memset(t15, 0, 8);
    t13 = (t15 + 4);
    t16 = (t14 + 4);
    t17 = *((unsigned int *)t14);
    t18 = (t17 >> 7);
    t19 = (t18 & 1);
    *((unsigned int *)t15) = t19;
    t20 = *((unsigned int *)t16);
    t21 = (t20 >> 7);
    t22 = (t21 & 1);
    *((unsigned int *)t13) = t22;
    t23 = (t0 + 3704);
    t25 = (t0 + 3704);
    t26 = (t25 + 72U);
    t27 = *((char **)t26);
    t28 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t24, t27, 2, t28, 32, 1);
    t29 = (t24 + 4);
    t30 = *((unsigned int *)t29);
    t31 = (!(t30));
    if (t31 == 1)
        goto LAB10;

LAB11:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 6);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 6);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng2)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB12;

LAB13:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 5);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 5);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB14;

LAB15:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 4);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 4);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng4)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB16;

LAB17:    xsi_set_current_line(41, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 3);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 3);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng5)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB18;

LAB19:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 2);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 2);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng6)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB20;

LAB21:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 1);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 1);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng7)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB22;

LAB23:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 0);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng8)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB24;

LAB25:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 15);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 15);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng9)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB26;

LAB27:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 14);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 14);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng10)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB28;

LAB29:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 13);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 13);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng11)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB30;

LAB31:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 12);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 12);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng12)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB32;

LAB33:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 11);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 11);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng13)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB34;

LAB35:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 10);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 10);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng14)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB36;

LAB37:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 9);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 9);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng15)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB38;

LAB39:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t15 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 8);
    t10 = (t9 & 1);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 8);
    t17 = (t12 & 1);
    *((unsigned int *)t2) = t17;
    t5 = (t0 + 3704);
    t6 = (t0 + 3704);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = ((char*)((ng16)));
    xsi_vlog_generic_convert_bit_index(t24, t13, 2, t14, 32, 1);
    t16 = (t24 + 4);
    t18 = *((unsigned int *)t16);
    t31 = (!(t18));
    if (t31 == 1)
        goto LAB40;

LAB41:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 2504U);
    t3 = *((char **)t2);
    t2 = (t0 + 3864);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(55, ng0);
    t2 = (t0 + 2664U);
    t3 = *((char **)t2);
    t2 = (t0 + 4024);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    goto LAB8;

LAB10:    xsi_vlogvar_wait_assign_value(t23, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB11;

LAB12:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB13;

LAB14:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB15;

LAB16:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB17;

LAB18:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB19;

LAB20:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB21;

LAB22:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB23;

LAB24:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB25;

LAB26:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB27;

LAB28:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB29;

LAB30:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB31;

LAB32:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB33;

LAB34:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB35;

LAB36:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB37;

LAB38:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB39;

LAB40:    xsi_vlogvar_wait_assign_value(t5, t15, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB41;

}

static void Initial_79_1(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(79, ng0);
    t1 = ((char*)((ng17)));
    t2 = (t0 + 4184);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 3);

LAB1:    return;
}

static void Always_81_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    t1 = (t0 + 5752U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(81, ng0);
    t2 = (t0 + 6336);
    *((int *)t2) = 1;
    t3 = (t0 + 5784);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(82, ng0);
    t4 = (t0 + 4344);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 4184);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 3, 0LL);
    goto LAB2;

}

static void Always_84_3(char *t0)
{
    char t9[8];
    char t24[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    char *t62;

LAB0:    t1 = (t0 + 6000U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 6352);
    *((int *)t2) = 1;
    t3 = (t0 + 6032);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(84, ng0);

LAB5:    xsi_set_current_line(85, ng0);
    t4 = ((char*)((ng17)));
    t5 = (t0 + 3064);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 3224);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(89, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4344);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 3);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB6:    t5 = ((char*)((ng17)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 3, t5, 3);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng18)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng19)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng20)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng21)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng22)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t6 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB2;

LAB7:    xsi_set_current_line(92, ng0);

LAB20:    xsi_set_current_line(93, ng0);
    t7 = ((char*)((ng18)));
    t8 = (t0 + 3064);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 1);
    xsi_set_current_line(94, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    t2 = (t0 + 2024U);
    t5 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t5 + 4);
    t10 = *((unsigned int *)t2);
    t11 = (~(t10));
    t12 = *((unsigned int *)t5);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB24;

LAB22:    if (*((unsigned int *)t2) == 0)
        goto LAB21;

LAB23:    t7 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t7) = 1;

LAB24:    t8 = (t9 + 4);
    t15 = (t5 + 4);
    t16 = *((unsigned int *)t5);
    t17 = (~(t16));
    *((unsigned int *)t9) = t17;
    *((unsigned int *)t8) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB26;

LAB25:    t22 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t22 & 1U);
    t23 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t23 & 1U);
    t25 = *((unsigned int *)t3);
    t26 = *((unsigned int *)t9);
    t27 = (t25 & t26);
    *((unsigned int *)t24) = t27;
    t28 = (t3 + 4);
    t29 = (t9 + 4);
    t30 = (t24 + 4);
    t31 = *((unsigned int *)t28);
    t32 = *((unsigned int *)t29);
    t33 = (t31 | t32);
    *((unsigned int *)t30) = t33;
    t34 = *((unsigned int *)t30);
    t35 = (t34 != 0);
    if (t35 == 1)
        goto LAB27;

LAB28:
LAB29:    t55 = (t24 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t24);
    t59 = (t58 & t57);
    t60 = (t59 != 0);
    if (t60 > 0)
        goto LAB30;

LAB31:
LAB32:    goto LAB19;

LAB9:    xsi_set_current_line(99, ng0);

LAB34:    xsi_set_current_line(100, ng0);
    t3 = ((char*)((ng19)));
    t5 = (t0 + 4344);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 3);
    goto LAB19;

LAB11:    xsi_set_current_line(102, ng0);

LAB35:    xsi_set_current_line(103, ng0);
    t3 = ((char*)((ng18)));
    t5 = (t0 + 3224);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    xsi_set_current_line(104, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 4344);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    goto LAB19;

LAB13:    xsi_set_current_line(106, ng0);

LAB36:    xsi_set_current_line(107, ng0);
    t3 = ((char*)((ng18)));
    t5 = (t0 + 3224);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    xsi_set_current_line(108, ng0);
    t2 = ((char*)((ng21)));
    t3 = (t0 + 4344);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    goto LAB19;

LAB15:    xsi_set_current_line(110, ng0);

LAB37:    xsi_set_current_line(111, ng0);
    t3 = ((char*)((ng18)));
    t5 = (t0 + 3224);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 4344);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    goto LAB19;

LAB17:    xsi_set_current_line(114, ng0);

LAB38:    xsi_set_current_line(115, ng0);
    t3 = ((char*)((ng17)));
    t5 = (t0 + 4344);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 3);
    goto LAB19;

LAB21:    *((unsigned int *)t9) = 1;
    goto LAB24;

LAB26:    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t9) = (t18 | t19);
    t20 = *((unsigned int *)t8);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t8) = (t20 | t21);
    goto LAB25;

LAB27:    t36 = *((unsigned int *)t24);
    t37 = *((unsigned int *)t30);
    *((unsigned int *)t24) = (t36 | t37);
    t38 = (t3 + 4);
    t39 = (t9 + 4);
    t40 = *((unsigned int *)t3);
    t41 = (~(t40));
    t42 = *((unsigned int *)t38);
    t43 = (~(t42));
    t44 = *((unsigned int *)t9);
    t45 = (~(t44));
    t46 = *((unsigned int *)t39);
    t47 = (~(t46));
    t6 = (t41 & t43);
    t48 = (t45 & t47);
    t49 = (~(t6));
    t50 = (~(t48));
    t51 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t51 & t49);
    t52 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t52 & t50);
    t53 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t53 & t49);
    t54 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t54 & t50);
    goto LAB29;

LAB30:    xsi_set_current_line(94, ng0);

LAB33:    xsi_set_current_line(95, ng0);
    t61 = ((char*)((ng18)));
    t62 = (t0 + 3544);
    xsi_vlogvar_assign_value(t62, t61, 0, 0, 1);
    xsi_set_current_line(96, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 4344);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    goto LAB32;

}


extern void work_m_10107412238588444151_0620347525_init()
{
	static char *pe[] = {(void *)Always_35_0,(void *)Initial_79_1,(void *)Always_81_2,(void *)Always_84_3};
	xsi_register_didat("work_m_10107412238588444151_0620347525", "isim/tb_system_isim_beh.exe.sim/work/m_10107412238588444151_0620347525.didat");
	xsi_register_executes(pe);
}
