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
static const char *ng0 = "/home/flonesan/developments/milkymist-various/boards/mlx-1000/test/ise_system/conbus_arb5.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {3U, 0U};
static unsigned int ng5[] = {4U, 0U};



static void Cont_29_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 3000U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(29, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3928);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 7U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 2);
    t18 = (t0 + 3816);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_31_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;

LAB0:    t1 = (t0 + 3248U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(31, ng0);
    t2 = (t0 + 3832);
    *((int *)t2) = 1;
    t3 = (t0 + 3280);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(31, ng0);

LAB5:    xsi_set_current_line(32, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 2088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(33, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 3, 0LL);
    goto LAB8;

}

static void Always_38_2(char *t0)
{
    char t9[8];
    char t10[8];
    char t43[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    char *t58;

LAB0:    t1 = (t0 + 3496U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 3848);
    *((int *)t2) = 1;
    t3 = (t0 + 3528);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(38, ng0);

LAB5:    xsi_set_current_line(39, ng0);
    t4 = (t0 + 1928);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 2088);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 3);
    xsi_set_current_line(40, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB6:    t5 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t5, 3);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t8 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t8 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(41, ng0);

LAB18:    xsi_set_current_line(42, ng0);
    t6 = (t0 + 1368U);
    t7 = *((char **)t6);
    memset(t10, 0, 8);
    t6 = (t10 + 4);
    t11 = (t7 + 4);
    t12 = *((unsigned int *)t7);
    t13 = (t12 >> 0);
    t14 = (t13 & 1);
    *((unsigned int *)t10) = t14;
    t15 = *((unsigned int *)t11);
    t16 = (t15 >> 0);
    t17 = (t16 & 1);
    *((unsigned int *)t6) = t17;
    memset(t9, 0, 8);
    t18 = (t10 + 4);
    t19 = *((unsigned int *)t18);
    t20 = (~(t19));
    t21 = *((unsigned int *)t10);
    t22 = (t21 & t20);
    t23 = (t22 & 1U);
    if (t23 != 0)
        goto LAB22;

LAB20:    if (*((unsigned int *)t18) == 0)
        goto LAB19;

LAB21:    t24 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t24) = 1;

LAB22:    t25 = (t9 + 4);
    t26 = (t10 + 4);
    t27 = *((unsigned int *)t10);
    t28 = (~(t27));
    *((unsigned int *)t9) = t28;
    *((unsigned int *)t25) = 0;
    if (*((unsigned int *)t26) != 0)
        goto LAB24;

LAB23:    t33 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t33 & 1U);
    t34 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t34 & 1U);
    t35 = (t9 + 4);
    t36 = *((unsigned int *)t35);
    t37 = (~(t36));
    t38 = *((unsigned int *)t9);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB25;

LAB26:
LAB27:    goto LAB17;

LAB9:    xsi_set_current_line(49, ng0);

LAB41:    xsi_set_current_line(50, ng0);
    t3 = (t0 + 1368U);
    t5 = *((char **)t3);
    memset(t10, 0, 8);
    t3 = (t10 + 4);
    t6 = (t5 + 4);
    t12 = *((unsigned int *)t5);
    t13 = (t12 >> 1);
    t14 = (t13 & 1);
    *((unsigned int *)t10) = t14;
    t15 = *((unsigned int *)t6);
    t16 = (t15 >> 1);
    t17 = (t16 & 1);
    *((unsigned int *)t3) = t17;
    memset(t9, 0, 8);
    t7 = (t10 + 4);
    t19 = *((unsigned int *)t7);
    t20 = (~(t19));
    t21 = *((unsigned int *)t10);
    t22 = (t21 & t20);
    t23 = (t22 & 1U);
    if (t23 != 0)
        goto LAB45;

LAB43:    if (*((unsigned int *)t7) == 0)
        goto LAB42;

LAB44:    t11 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t11) = 1;

LAB45:    t18 = (t9 + 4);
    t24 = (t10 + 4);
    t27 = *((unsigned int *)t10);
    t28 = (~(t27));
    *((unsigned int *)t9) = t28;
    *((unsigned int *)t18) = 0;
    if (*((unsigned int *)t24) != 0)
        goto LAB47;

LAB46:    t33 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t33 & 1U);
    t34 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t34 & 1U);
    t25 = (t9 + 4);
    t36 = *((unsigned int *)t25);
    t37 = (~(t36));
    t38 = *((unsigned int *)t9);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB48;

LAB49:
LAB50:    goto LAB17;

LAB11:    xsi_set_current_line(57, ng0);

LAB64:    xsi_set_current_line(58, ng0);
    t3 = (t0 + 1368U);
    t5 = *((char **)t3);
    memset(t10, 0, 8);
    t3 = (t10 + 4);
    t6 = (t5 + 4);
    t12 = *((unsigned int *)t5);
    t13 = (t12 >> 2);
    t14 = (t13 & 1);
    *((unsigned int *)t10) = t14;
    t15 = *((unsigned int *)t6);
    t16 = (t15 >> 2);
    t17 = (t16 & 1);
    *((unsigned int *)t3) = t17;
    memset(t9, 0, 8);
    t7 = (t10 + 4);
    t19 = *((unsigned int *)t7);
    t20 = (~(t19));
    t21 = *((unsigned int *)t10);
    t22 = (t21 & t20);
    t23 = (t22 & 1U);
    if (t23 != 0)
        goto LAB68;

LAB66:    if (*((unsigned int *)t7) == 0)
        goto LAB65;

LAB67:    t11 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t11) = 1;

LAB68:    t18 = (t9 + 4);
    t24 = (t10 + 4);
    t27 = *((unsigned int *)t10);
    t28 = (~(t27));
    *((unsigned int *)t9) = t28;
    *((unsigned int *)t18) = 0;
    if (*((unsigned int *)t24) != 0)
        goto LAB70;

LAB69:    t33 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t33 & 1U);
    t34 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t34 & 1U);
    t25 = (t9 + 4);
    t36 = *((unsigned int *)t25);
    t37 = (~(t36));
    t38 = *((unsigned int *)t9);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB71;

LAB72:
LAB73:    goto LAB17;

LAB13:    xsi_set_current_line(65, ng0);

LAB87:    xsi_set_current_line(66, ng0);
    t3 = (t0 + 1368U);
    t5 = *((char **)t3);
    memset(t10, 0, 8);
    t3 = (t10 + 4);
    t6 = (t5 + 4);
    t12 = *((unsigned int *)t5);
    t13 = (t12 >> 3);
    t14 = (t13 & 1);
    *((unsigned int *)t10) = t14;
    t15 = *((unsigned int *)t6);
    t16 = (t15 >> 3);
    t17 = (t16 & 1);
    *((unsigned int *)t3) = t17;
    memset(t9, 0, 8);
    t7 = (t10 + 4);
    t19 = *((unsigned int *)t7);
    t20 = (~(t19));
    t21 = *((unsigned int *)t10);
    t22 = (t21 & t20);
    t23 = (t22 & 1U);
    if (t23 != 0)
        goto LAB91;

LAB89:    if (*((unsigned int *)t7) == 0)
        goto LAB88;

LAB90:    t11 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t11) = 1;

LAB91:    t18 = (t9 + 4);
    t24 = (t10 + 4);
    t27 = *((unsigned int *)t10);
    t28 = (~(t27));
    *((unsigned int *)t9) = t28;
    *((unsigned int *)t18) = 0;
    if (*((unsigned int *)t24) != 0)
        goto LAB93;

LAB92:    t33 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t33 & 1U);
    t34 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t34 & 1U);
    t25 = (t9 + 4);
    t36 = *((unsigned int *)t25);
    t37 = (~(t36));
    t38 = *((unsigned int *)t9);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB94;

LAB95:
LAB96:    goto LAB17;

LAB15:    xsi_set_current_line(73, ng0);

LAB110:    xsi_set_current_line(74, ng0);
    t3 = (t0 + 1368U);
    t5 = *((char **)t3);
    memset(t10, 0, 8);
    t3 = (t10 + 4);
    t6 = (t5 + 4);
    t12 = *((unsigned int *)t5);
    t13 = (t12 >> 4);
    t14 = (t13 & 1);
    *((unsigned int *)t10) = t14;
    t15 = *((unsigned int *)t6);
    t16 = (t15 >> 4);
    t17 = (t16 & 1);
    *((unsigned int *)t3) = t17;
    memset(t9, 0, 8);
    t7 = (t10 + 4);
    t19 = *((unsigned int *)t7);
    t20 = (~(t19));
    t21 = *((unsigned int *)t10);
    t22 = (t21 & t20);
    t23 = (t22 & 1U);
    if (t23 != 0)
        goto LAB114;

LAB112:    if (*((unsigned int *)t7) == 0)
        goto LAB111;

LAB113:    t11 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t11) = 1;

LAB114:    t18 = (t9 + 4);
    t24 = (t10 + 4);
    t27 = *((unsigned int *)t10);
    t28 = (~(t27));
    *((unsigned int *)t9) = t28;
    *((unsigned int *)t18) = 0;
    if (*((unsigned int *)t24) != 0)
        goto LAB116;

LAB115:    t33 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t33 & 1U);
    t34 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t34 & 1U);
    t25 = (t9 + 4);
    t36 = *((unsigned int *)t25);
    t37 = (~(t36));
    t38 = *((unsigned int *)t9);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB117;

LAB118:
LAB119:    goto LAB17;

LAB19:    *((unsigned int *)t9) = 1;
    goto LAB22;

LAB24:    t29 = *((unsigned int *)t9);
    t30 = *((unsigned int *)t26);
    *((unsigned int *)t9) = (t29 | t30);
    t31 = *((unsigned int *)t25);
    t32 = *((unsigned int *)t26);
    *((unsigned int *)t25) = (t31 | t32);
    goto LAB23;

LAB25:    xsi_set_current_line(42, ng0);

LAB28:    xsi_set_current_line(43, ng0);
    t41 = (t0 + 1368U);
    t42 = *((char **)t41);
    memset(t43, 0, 8);
    t41 = (t43 + 4);
    t44 = (t42 + 4);
    t45 = *((unsigned int *)t42);
    t46 = (t45 >> 1);
    t47 = (t46 & 1);
    *((unsigned int *)t43) = t47;
    t48 = *((unsigned int *)t44);
    t49 = (t48 >> 1);
    t50 = (t49 & 1);
    *((unsigned int *)t41) = t50;
    t51 = (t43 + 4);
    t52 = *((unsigned int *)t51);
    t53 = (~(t52));
    t54 = *((unsigned int *)t43);
    t55 = (t54 & t53);
    t56 = (t55 != 0);
    if (t56 > 0)
        goto LAB29;

LAB30:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 2);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 2);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB32;

LAB33:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 3);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 3);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB35;

LAB36:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 4);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 4);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB38;

LAB39:
LAB40:
LAB37:
LAB34:
LAB31:    goto LAB27;

LAB29:    xsi_set_current_line(43, ng0);
    t57 = ((char*)((ng2)));
    t58 = (t0 + 2088);
    xsi_vlogvar_assign_value(t58, t57, 0, 0, 3);
    goto LAB31;

LAB32:    xsi_set_current_line(44, ng0);
    t7 = ((char*)((ng3)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB34;

LAB35:    xsi_set_current_line(45, ng0);
    t7 = ((char*)((ng4)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB37;

LAB38:    xsi_set_current_line(46, ng0);
    t7 = ((char*)((ng5)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB40;

LAB42:    *((unsigned int *)t9) = 1;
    goto LAB45;

LAB47:    t29 = *((unsigned int *)t9);
    t30 = *((unsigned int *)t24);
    *((unsigned int *)t9) = (t29 | t30);
    t31 = *((unsigned int *)t18);
    t32 = *((unsigned int *)t24);
    *((unsigned int *)t18) = (t31 | t32);
    goto LAB46;

LAB48:    xsi_set_current_line(50, ng0);

LAB51:    xsi_set_current_line(51, ng0);
    t26 = (t0 + 1368U);
    t35 = *((char **)t26);
    memset(t43, 0, 8);
    t26 = (t43 + 4);
    t41 = (t35 + 4);
    t45 = *((unsigned int *)t35);
    t46 = (t45 >> 2);
    t47 = (t46 & 1);
    *((unsigned int *)t43) = t47;
    t48 = *((unsigned int *)t41);
    t49 = (t48 >> 2);
    t50 = (t49 & 1);
    *((unsigned int *)t26) = t50;
    t42 = (t43 + 4);
    t52 = *((unsigned int *)t42);
    t53 = (~(t52));
    t54 = *((unsigned int *)t43);
    t55 = (t54 & t53);
    t56 = (t55 != 0);
    if (t56 > 0)
        goto LAB52;

LAB53:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 3);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 3);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB55;

LAB56:    xsi_set_current_line(53, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 4);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 4);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB58;

LAB59:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 0);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 0);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB61;

LAB62:
LAB63:
LAB60:
LAB57:
LAB54:    goto LAB50;

LAB52:    xsi_set_current_line(51, ng0);
    t44 = ((char*)((ng3)));
    t51 = (t0 + 2088);
    xsi_vlogvar_assign_value(t51, t44, 0, 0, 3);
    goto LAB54;

LAB55:    xsi_set_current_line(52, ng0);
    t7 = ((char*)((ng4)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB57;

LAB58:    xsi_set_current_line(53, ng0);
    t7 = ((char*)((ng5)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB60;

LAB61:    xsi_set_current_line(54, ng0);
    t7 = ((char*)((ng1)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB63;

LAB65:    *((unsigned int *)t9) = 1;
    goto LAB68;

LAB70:    t29 = *((unsigned int *)t9);
    t30 = *((unsigned int *)t24);
    *((unsigned int *)t9) = (t29 | t30);
    t31 = *((unsigned int *)t18);
    t32 = *((unsigned int *)t24);
    *((unsigned int *)t18) = (t31 | t32);
    goto LAB69;

LAB71:    xsi_set_current_line(58, ng0);

LAB74:    xsi_set_current_line(59, ng0);
    t26 = (t0 + 1368U);
    t35 = *((char **)t26);
    memset(t43, 0, 8);
    t26 = (t43 + 4);
    t41 = (t35 + 4);
    t45 = *((unsigned int *)t35);
    t46 = (t45 >> 3);
    t47 = (t46 & 1);
    *((unsigned int *)t43) = t47;
    t48 = *((unsigned int *)t41);
    t49 = (t48 >> 3);
    t50 = (t49 & 1);
    *((unsigned int *)t26) = t50;
    t42 = (t43 + 4);
    t52 = *((unsigned int *)t42);
    t53 = (~(t52));
    t54 = *((unsigned int *)t43);
    t55 = (t54 & t53);
    t56 = (t55 != 0);
    if (t56 > 0)
        goto LAB75;

LAB76:    xsi_set_current_line(60, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 4);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 4);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB78;

LAB79:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 0);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 0);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB81;

LAB82:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 1);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 1);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB84;

LAB85:
LAB86:
LAB83:
LAB80:
LAB77:    goto LAB73;

LAB75:    xsi_set_current_line(59, ng0);
    t44 = ((char*)((ng4)));
    t51 = (t0 + 2088);
    xsi_vlogvar_assign_value(t51, t44, 0, 0, 3);
    goto LAB77;

LAB78:    xsi_set_current_line(60, ng0);
    t7 = ((char*)((ng5)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB80;

LAB81:    xsi_set_current_line(61, ng0);
    t7 = ((char*)((ng1)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB83;

LAB84:    xsi_set_current_line(62, ng0);
    t7 = ((char*)((ng2)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB86;

LAB88:    *((unsigned int *)t9) = 1;
    goto LAB91;

LAB93:    t29 = *((unsigned int *)t9);
    t30 = *((unsigned int *)t24);
    *((unsigned int *)t9) = (t29 | t30);
    t31 = *((unsigned int *)t18);
    t32 = *((unsigned int *)t24);
    *((unsigned int *)t18) = (t31 | t32);
    goto LAB92;

LAB94:    xsi_set_current_line(66, ng0);

LAB97:    xsi_set_current_line(67, ng0);
    t26 = (t0 + 1368U);
    t35 = *((char **)t26);
    memset(t43, 0, 8);
    t26 = (t43 + 4);
    t41 = (t35 + 4);
    t45 = *((unsigned int *)t35);
    t46 = (t45 >> 4);
    t47 = (t46 & 1);
    *((unsigned int *)t43) = t47;
    t48 = *((unsigned int *)t41);
    t49 = (t48 >> 4);
    t50 = (t49 & 1);
    *((unsigned int *)t26) = t50;
    t42 = (t43 + 4);
    t52 = *((unsigned int *)t42);
    t53 = (~(t52));
    t54 = *((unsigned int *)t43);
    t55 = (t54 & t53);
    t56 = (t55 != 0);
    if (t56 > 0)
        goto LAB98;

LAB99:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 0);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 0);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB101;

LAB102:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 1);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 1);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB104;

LAB105:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 2);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 2);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB107;

LAB108:
LAB109:
LAB106:
LAB103:
LAB100:    goto LAB96;

LAB98:    xsi_set_current_line(67, ng0);
    t44 = ((char*)((ng5)));
    t51 = (t0 + 2088);
    xsi_vlogvar_assign_value(t51, t44, 0, 0, 3);
    goto LAB100;

LAB101:    xsi_set_current_line(68, ng0);
    t7 = ((char*)((ng1)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB103;

LAB104:    xsi_set_current_line(69, ng0);
    t7 = ((char*)((ng2)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB106;

LAB107:    xsi_set_current_line(70, ng0);
    t7 = ((char*)((ng3)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB109;

LAB111:    *((unsigned int *)t9) = 1;
    goto LAB114;

LAB116:    t29 = *((unsigned int *)t9);
    t30 = *((unsigned int *)t24);
    *((unsigned int *)t9) = (t29 | t30);
    t31 = *((unsigned int *)t18);
    t32 = *((unsigned int *)t24);
    *((unsigned int *)t18) = (t31 | t32);
    goto LAB115;

LAB117:    xsi_set_current_line(74, ng0);

LAB120:    xsi_set_current_line(75, ng0);
    t26 = (t0 + 1368U);
    t35 = *((char **)t26);
    memset(t43, 0, 8);
    t26 = (t43 + 4);
    t41 = (t35 + 4);
    t45 = *((unsigned int *)t35);
    t46 = (t45 >> 0);
    t47 = (t46 & 1);
    *((unsigned int *)t43) = t47;
    t48 = *((unsigned int *)t41);
    t49 = (t48 >> 0);
    t50 = (t49 & 1);
    *((unsigned int *)t26) = t50;
    t42 = (t43 + 4);
    t52 = *((unsigned int *)t42);
    t53 = (~(t52));
    t54 = *((unsigned int *)t43);
    t55 = (t54 & t53);
    t56 = (t55 != 0);
    if (t56 > 0)
        goto LAB121;

LAB122:    xsi_set_current_line(76, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 1);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 1);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB124;

LAB125:    xsi_set_current_line(77, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 2);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 2);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB127;

LAB128:    xsi_set_current_line(78, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t5 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 3);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 3);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t6 = (t9 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB130;

LAB131:
LAB132:
LAB129:
LAB126:
LAB123:    goto LAB119;

LAB121:    xsi_set_current_line(75, ng0);
    t44 = ((char*)((ng1)));
    t51 = (t0 + 2088);
    xsi_vlogvar_assign_value(t51, t44, 0, 0, 3);
    goto LAB123;

LAB124:    xsi_set_current_line(76, ng0);
    t7 = ((char*)((ng2)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB126;

LAB127:    xsi_set_current_line(77, ng0);
    t7 = ((char*)((ng3)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB129;

LAB130:    xsi_set_current_line(78, ng0);
    t7 = ((char*)((ng4)));
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 3);
    goto LAB132;

}


extern void work_m_06177755924903558964_2426858711_init()
{
	static char *pe[] = {(void *)Cont_29_0,(void *)Always_31_1,(void *)Always_38_2};
	xsi_register_didat("work_m_06177755924903558964_2426858711", "isim/tb_system_isim_beh.exe.sim/work/m_06177755924903558964_2426858711.didat");
	xsi_register_executes(pe);
}
