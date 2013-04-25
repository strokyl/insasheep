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
static const char *ng0 = "/home/matt/Documents/Studies/4IRT/SystemOnChip/milkymist-various/boards/digilent-nexys3/ise_system/lm32_logic_op.v";
static int ng1[] = {0, 0};
static int ng2[] = {32, 0};
static int ng3[] = {1, 0};



static void Always_90_0(char *t0)
{
    char t6[8];
    char t15[8];
    char t18[8];
    char t21[8];
    char t29[8];
    char t36[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t16;
    char *t17;
    char *t19;
    char *t20;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    unsigned int t44;
    int t45;

LAB0:    t1 = (t0 + 2840U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(90, ng0);
    t2 = (t0 + 3160);
    *((int *)t2) = 1;
    t3 = (t0 + 2872);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(91, ng0);

LAB5:    xsi_set_current_line(92, ng0);
    xsi_set_current_line(92, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 1928);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB6:    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_signed_less(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB7;

LAB8:    goto LAB2;

LAB7:    xsi_set_current_line(93, ng0);
    t13 = (t0 + 1048U);
    t14 = *((char **)t13);
    t13 = (t0 + 1008U);
    t16 = (t13 + 72U);
    t17 = *((char **)t16);
    t19 = (t0 + 1208U);
    t20 = *((char **)t19);
    t19 = (t0 + 1168U);
    t22 = (t19 + 72U);
    t23 = *((char **)t22);
    t24 = (t0 + 1928);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    xsi_vlog_generic_get_index_select_value(t21, 1, t20, t23, 2, t26, 32, 1);
    t27 = (t0 + 1368U);
    t28 = *((char **)t27);
    t27 = (t0 + 1328U);
    t30 = (t27 + 72U);
    t31 = *((char **)t30);
    t32 = (t0 + 1928);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    xsi_vlog_generic_get_index_select_value(t29, 1, t28, t31, 2, t34, 32, 1);
    xsi_vlogtype_concat(t18, 2, 2, 2U, t29, 1, t21, 1);
    xsi_vlog_generic_get_index_select_value(t15, 1, t14, t17, 2, t18, 2, 2);
    t35 = (t0 + 1768);
    t37 = (t0 + 1768);
    t38 = (t37 + 72U);
    t39 = *((char **)t38);
    t40 = (t0 + 1928);
    t41 = (t40 + 56U);
    t42 = *((char **)t41);
    xsi_vlog_generic_convert_bit_index(t36, t39, 2, t42, 32, 1);
    t43 = (t36 + 4);
    t44 = *((unsigned int *)t43);
    t45 = (!(t44));
    if (t45 == 1)
        goto LAB9;

LAB10:    xsi_set_current_line(92, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 1928);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    goto LAB6;

LAB9:    xsi_vlogvar_assign_value(t35, t15, 0, *((unsigned int *)t36), 1);
    goto LAB10;

}


extern void work_m_06481119736299298197_2458323856_init()
{
	static char *pe[] = {(void *)Always_90_0};
	xsi_register_didat("work_m_06481119736299298197_2458323856", "isim/tb_system_isim_beh.exe.sim/work/m_06481119736299298197_2458323856.didat");
	xsi_register_executes(pe);
}
