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
static const char *ng0 = "/home/flonesan/developments/milkymist-various/boards/mlx-1000/test/ise_system/tb_system.v";
static unsigned int ng1[] = {1U, 0U};
static unsigned int ng2[] = {0U, 0U};
static const char *ng3 = "[UART] W: %h (%c)";
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {3U, 0U};
static const char *ng6 = "[UART] R: %h (%c)";



static int sp_csr_write(char *t1, char *t2)
{
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 2480);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(102, ng0);

LAB5:    xsi_set_current_line(103, ng0);
    t5 = (t1 + 7208);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 6408);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 14);
    xsi_set_current_line(104, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t1 + 6568);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(105, ng0);
    t4 = (t1 + 7368);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 6728);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    xsi_set_current_line(107, ng0);
    t4 = (t2 + 88U);
    t5 = *((char **)t4);
    t6 = (t5 + 0U);
    xsi_wp_set_status(t6, 1);
    *((char **)t3) = &&LAB6;

LAB1:    return t0;
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;
    goto LAB1;

LAB6:    xsi_set_current_line(108, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 6568);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    goto LAB4;

}

static int sp_csr_read(char *t1, char *t2)
{
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 2912);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(115, ng0);

LAB5:    xsi_set_current_line(116, ng0);
    t5 = (t1 + 7528);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 6408);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 14);
    xsi_set_current_line(117, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 6568);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(119, ng0);
    t4 = (t2 + 88U);
    t5 = *((char **)t4);
    t6 = (t5 + 0U);
    xsi_wp_set_status(t6, 1);
    *((char **)t3) = &&LAB6;

LAB1:    return t0;
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;
    goto LAB1;

LAB6:    xsi_set_current_line(120, ng0);
    t4 = (t1 + 5048U);
    t5 = *((char **)t4);
    t4 = (t1 + 7688);
    xsi_vlogvar_assign_value(t4, t5, 0, 0, 32);
    goto LAB4;

}

static int sp_uart_write(char *t1, char *t2)
{
    char t6[8];
    char t40[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    int t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t71;
    int t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 3344);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(144, ng0);

LAB5:    xsi_set_current_line(145, ng0);
    t5 = ((char*)((ng2)));
    t7 = (t1 + 7848);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = ((char*)((ng2)));
    xsi_vlogtype_concat(t6, 32, 32, 2U, t10, 24, t9, 8);
    t11 = (t2 + 56U);
    t12 = *((char **)t11);
    t13 = (t2 + 56U);
    t14 = *((char **)t13);
    xsi_vlog_subprograminvocation_setJumpstate(t2, t14, &&LAB6);
    t15 = (t2 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 2480);
    t18 = xsi_create_subprogram_invocation(t16, 0, t1, t17, 0, t2);
    xsi_vlog_subprogram_pushinvocation(t17, t18);
    t19 = (t1 + 7208);
    xsi_vlogvar_assign_value(t19, t5, 0, 0, 14);
    t20 = (t1 + 7368);
    xsi_vlogvar_assign_value(t20, t6, 0, 0, 32);

LAB8:    t21 = (t2 + 64U);
    t22 = *((char **)t21);
    t23 = (t22 + 80U);
    t24 = *((char **)t23);
    t25 = (t24 + 272U);
    t26 = *((char **)t25);
    t27 = (t26 + 0U);
    t28 = *((char **)t27);
    t29 = ((int  (*)(char *, char *))t28)(t1, t22);
    if (t29 == -1)
        goto LAB9;

LAB10:    if (t29 != 0)
        goto LAB11;

LAB6:    t22 = (t1 + 2480);
    xsi_vlog_subprogram_popinvocation(t22);

LAB7:    t30 = (t2 + 64U);
    t31 = *((char **)t30);
    t30 = (t1 + 2480);
    t32 = (t2 + 56U);
    t33 = *((char **)t32);
    xsi_delete_subprogram_invocation(t30, t31, t1, t33, t2);
    xsi_set_current_line(146, ng0);
    t4 = (t1 + 7848);
    t5 = (t4 + 56U);
    t7 = *((char **)t5);
    t8 = (t1 + 7848);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t6, 0, 8);
    t11 = (t6 + 4);
    t12 = (t10 + 4);
    t34 = *((unsigned int *)t10);
    t35 = (t34 >> 0);
    *((unsigned int *)t6) = t35;
    t36 = *((unsigned int *)t12);
    t37 = (t36 >> 0);
    *((unsigned int *)t11) = t37;
    t38 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t38 & 255U);
    t39 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t39 & 255U);
    t13 = (t1 + 3344);
    xsi_vlogfile_write(1, 0, 0, ng3, 3, t13, (char)118, t7, 8, (char)118, t6, 8);
    xsi_set_current_line(148, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t2 + 56U);
    t7 = *((char **)t5);
    t8 = (t2 + 56U);
    t9 = *((char **)t8);
    xsi_vlog_subprograminvocation_setJumpstate(t2, t9, &&LAB12);
    t10 = (t2 + 56U);
    t11 = *((char **)t10);
    t12 = (t1 + 2912);
    t13 = xsi_create_subprogram_invocation(t11, 0, t1, t12, 0, t2);
    xsi_vlog_subprogram_pushinvocation(t12, t13);
    t14 = (t1 + 7528);
    xsi_vlogvar_assign_value(t14, t4, 0, 0, 14);

LAB14:    t15 = (t2 + 64U);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t29 = ((int  (*)(char *, char *))t22)(t1, t16);
    if (t29 == -1)
        goto LAB15;

LAB16:    if (t29 != 0)
        goto LAB17;

LAB12:    t16 = (t1 + 2912);
    xsi_vlog_subprogram_popinvocation(t16);

LAB13:    t23 = (t2 + 64U);
    t24 = *((char **)t23);
    t23 = (t1 + 7688);
    t25 = (t23 + 56U);
    t26 = *((char **)t25);
    t27 = (t1 + 8008);
    xsi_vlogvar_assign_value(t27, t26, 0, 0, 32);
    t28 = (t1 + 2912);
    t30 = (t2 + 56U);
    t31 = *((char **)t30);
    xsi_delete_subprogram_invocation(t28, t24, t1, t31, t2);
    xsi_set_current_line(149, ng0);

LAB18:    t4 = (t1 + 8008);
    t5 = (t4 + 56U);
    t7 = *((char **)t5);
    t8 = ((char*)((ng1)));
    t34 = *((unsigned int *)t7);
    t35 = *((unsigned int *)t8);
    t36 = (t34 & t35);
    *((unsigned int *)t40) = t36;
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t11 = (t40 + 4);
    t37 = *((unsigned int *)t9);
    t38 = *((unsigned int *)t10);
    t39 = (t37 | t38);
    *((unsigned int *)t11) = t39;
    t41 = *((unsigned int *)t11);
    t42 = (t41 != 0);
    if (t42 == 1)
        goto LAB19;

LAB20:
LAB21:    memset(t6, 0, 8);
    t14 = (t40 + 4);
    t60 = *((unsigned int *)t14);
    t61 = (~(t60));
    t62 = *((unsigned int *)t40);
    t63 = (t62 & t61);
    t64 = (t63 & 4294967295U);
    if (t64 != 0)
        goto LAB25;

LAB23:    if (*((unsigned int *)t14) == 0)
        goto LAB22;

LAB24:    t15 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t15) = 1;

LAB25:    t16 = (t6 + 4);
    t65 = *((unsigned int *)t16);
    t66 = (~(t65));
    t67 = *((unsigned int *)t6);
    t68 = (t67 & t66);
    t69 = (t68 != 0);
    if (t69 > 0)
        goto LAB26;

LAB27:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB9:    t0 = -1;
    goto LAB1;

LAB11:    t21 = (t2 + 48U);
    *((char **)t21) = &&LAB8;
    goto LAB1;

LAB15:    t0 = -1;
    goto LAB1;

LAB17:    t15 = (t2 + 48U);
    *((char **)t15) = &&LAB14;
    goto LAB1;

LAB19:    t43 = *((unsigned int *)t40);
    t44 = *((unsigned int *)t11);
    *((unsigned int *)t40) = (t43 | t44);
    t12 = (t7 + 4);
    t13 = (t8 + 4);
    t45 = *((unsigned int *)t7);
    t46 = (~(t45));
    t47 = *((unsigned int *)t12);
    t48 = (~(t47));
    t49 = *((unsigned int *)t8);
    t50 = (~(t49));
    t51 = *((unsigned int *)t13);
    t52 = (~(t51));
    t29 = (t46 & t48);
    t53 = (t50 & t52);
    t54 = (~(t29));
    t55 = (~(t53));
    t56 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t56 & t54);
    t57 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t57 & t55);
    t58 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t58 & t54);
    t59 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t59 & t55);
    goto LAB21;

LAB22:    *((unsigned int *)t6) = 1;
    goto LAB25;

LAB26:    xsi_set_current_line(149, ng0);

LAB28:    xsi_set_current_line(150, ng0);
    t17 = ((char*)((ng4)));
    t18 = (t2 + 56U);
    t19 = *((char **)t18);
    t20 = (t2 + 56U);
    t21 = *((char **)t20);
    xsi_vlog_subprograminvocation_setJumpstate(t2, t21, &&LAB29);
    t22 = (t2 + 56U);
    t23 = *((char **)t22);
    t24 = (t1 + 2912);
    t25 = xsi_create_subprogram_invocation(t23, 0, t1, t24, 0, t2);
    xsi_vlog_subprogram_pushinvocation(t24, t25);
    t26 = (t1 + 7528);
    xsi_vlogvar_assign_value(t26, t17, 0, 0, 14);

LAB31:    t27 = (t2 + 64U);
    t28 = *((char **)t27);
    t30 = (t28 + 80U);
    t31 = *((char **)t30);
    t32 = (t31 + 272U);
    t33 = *((char **)t32);
    t70 = (t33 + 0U);
    t71 = *((char **)t70);
    t72 = ((int  (*)(char *, char *))t71)(t1, t28);
    if (t72 == -1)
        goto LAB32;

LAB33:    if (t72 != 0)
        goto LAB34;

LAB29:    t28 = (t1 + 2912);
    xsi_vlog_subprogram_popinvocation(t28);

LAB30:    t73 = (t2 + 64U);
    t74 = *((char **)t73);
    t73 = (t1 + 7688);
    t75 = (t73 + 56U);
    t76 = *((char **)t75);
    t77 = (t1 + 8008);
    xsi_vlogvar_assign_value(t77, t76, 0, 0, 32);
    t78 = (t1 + 2912);
    t79 = (t2 + 56U);
    t80 = *((char **)t79);
    xsi_delete_subprogram_invocation(t78, t74, t1, t80, t2);
    goto LAB18;

LAB32:    t0 = -1;
    goto LAB1;

LAB34:    t27 = (t2 + 48U);
    *((char **)t27) = &&LAB31;
    goto LAB1;

}

static int sp_uart_init(char *t1, char *t2)
{
    char t32[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    int t54;
    char *t55;
    char *t56;
    char *t57;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 3776);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(157, ng0);

LAB5:    xsi_set_current_line(159, ng0);
    t5 = ((char*)((ng4)));
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t2 + 56U);
    t9 = *((char **)t8);
    xsi_vlog_subprograminvocation_setJumpstate(t2, t9, &&LAB6);
    t10 = (t2 + 56U);
    t11 = *((char **)t10);
    t12 = (t1 + 2912);
    t13 = xsi_create_subprogram_invocation(t11, 0, t1, t12, 0, t2);
    xsi_vlog_subprogram_pushinvocation(t12, t13);
    t14 = (t1 + 7528);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 14);

LAB8:    t15 = (t2 + 64U);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t1, t16);
    if (t23 == -1)
        goto LAB9;

LAB10:    if (t23 != 0)
        goto LAB11;

LAB6:    t16 = (t1 + 2912);
    xsi_vlog_subprogram_popinvocation(t16);

LAB7:    t24 = (t2 + 64U);
    t25 = *((char **)t24);
    t24 = (t1 + 7688);
    t26 = (t24 + 56U);
    t27 = *((char **)t26);
    t28 = (t1 + 8168);
    xsi_vlogvar_assign_value(t28, t27, 0, 0, 32);
    t29 = (t1 + 2912);
    t30 = (t2 + 56U);
    t31 = *((char **)t30);
    xsi_delete_subprogram_invocation(t29, t25, t1, t31, t2);
    xsi_set_current_line(160, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t1 + 8168);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t2 + 56U);
    t9 = *((char **)t8);
    t10 = (t2 + 56U);
    t11 = *((char **)t10);
    xsi_vlog_subprograminvocation_setJumpstate(t2, t11, &&LAB12);
    t12 = (t2 + 56U);
    t13 = *((char **)t12);
    t14 = (t1 + 2480);
    t15 = xsi_create_subprogram_invocation(t13, 0, t1, t14, 0, t2);
    xsi_vlog_subprogram_pushinvocation(t14, t15);
    t16 = (t1 + 7208);
    xsi_vlogvar_assign_value(t16, t4, 0, 0, 14);
    t17 = (t1 + 7368);
    xsi_vlogvar_assign_value(t17, t7, 0, 0, 32);

LAB14:    t18 = (t2 + 64U);
    t19 = *((char **)t18);
    t20 = (t19 + 80U);
    t21 = *((char **)t20);
    t22 = (t21 + 272U);
    t24 = *((char **)t22);
    t25 = (t24 + 0U);
    t26 = *((char **)t25);
    t23 = ((int  (*)(char *, char *))t26)(t1, t19);
    if (t23 == -1)
        goto LAB15;

LAB16:    if (t23 != 0)
        goto LAB17;

LAB12:    t19 = (t1 + 2480);
    xsi_vlog_subprogram_popinvocation(t19);

LAB13:    t27 = (t2 + 64U);
    t28 = *((char **)t27);
    t27 = (t1 + 2480);
    t29 = (t2 + 56U);
    t30 = *((char **)t29);
    xsi_delete_subprogram_invocation(t27, t28, t1, t30, t2);
    xsi_set_current_line(163, ng0);
    t4 = ((char*)((ng5)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng4)));
    t33 = *((unsigned int *)t5);
    t34 = *((unsigned int *)t6);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t7 = (t5 + 4);
    t8 = (t6 + 4);
    t9 = (t32 + 4);
    t36 = *((unsigned int *)t7);
    t37 = *((unsigned int *)t8);
    t38 = (t36 | t37);
    *((unsigned int *)t9) = t38;
    t39 = *((unsigned int *)t9);
    t40 = (t39 != 0);
    if (t40 == 1)
        goto LAB18;

LAB19:
LAB20:    t12 = (t2 + 56U);
    t13 = *((char **)t12);
    t14 = (t2 + 56U);
    t15 = *((char **)t14);
    xsi_vlog_subprograminvocation_setJumpstate(t2, t15, &&LAB21);
    t16 = (t2 + 56U);
    t17 = *((char **)t16);
    t18 = (t1 + 2480);
    t19 = xsi_create_subprogram_invocation(t17, 0, t1, t18, 0, t2);
    xsi_vlog_subprogram_pushinvocation(t18, t19);
    t20 = (t1 + 7208);
    xsi_vlogvar_assign_value(t20, t4, 0, 0, 14);
    t21 = (t1 + 7368);
    xsi_vlogvar_assign_value(t21, t32, 0, 0, 32);

LAB23:    t22 = (t2 + 64U);
    t24 = *((char **)t22);
    t25 = (t24 + 80U);
    t26 = *((char **)t25);
    t27 = (t26 + 272U);
    t28 = *((char **)t27);
    t29 = (t28 + 0U);
    t30 = *((char **)t29);
    t54 = ((int  (*)(char *, char *))t30)(t1, t24);
    if (t54 == -1)
        goto LAB24;

LAB25:    if (t54 != 0)
        goto LAB26;

LAB21:    t24 = (t1 + 2480);
    xsi_vlog_subprogram_popinvocation(t24);

LAB22:    t31 = (t2 + 64U);
    t55 = *((char **)t31);
    t31 = (t1 + 2480);
    t56 = (t2 + 56U);
    t57 = *((char **)t56);
    xsi_delete_subprogram_invocation(t31, t55, t1, t57, t2);

LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB9:    t0 = -1;
    goto LAB1;

LAB11:    t15 = (t2 + 48U);
    *((char **)t15) = &&LAB8;
    goto LAB1;

LAB15:    t0 = -1;
    goto LAB1;

LAB17:    t18 = (t2 + 48U);
    *((char **)t18) = &&LAB14;
    goto LAB1;

LAB18:    t41 = *((unsigned int *)t32);
    t42 = *((unsigned int *)t9);
    *((unsigned int *)t32) = (t41 | t42);
    t10 = (t5 + 4);
    t11 = (t6 + 4);
    t43 = *((unsigned int *)t10);
    t44 = (~(t43));
    t45 = *((unsigned int *)t5);
    t23 = (t45 & t44);
    t46 = *((unsigned int *)t11);
    t47 = (~(t46));
    t48 = *((unsigned int *)t6);
    t49 = (t48 & t47);
    t50 = (~(t23));
    t51 = (~(t49));
    t52 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t52 & t50);
    t53 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t53 & t51);
    goto LAB20;

LAB24:    t0 = -1;
    goto LAB1;

LAB26:    t22 = (t2 + 48U);
    *((char **)t22) = &&LAB23;
    goto LAB1;

}

static void Always_126_0(char *t0)
{
    char t33[8];
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
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    int t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    int t59;
    char *t60;
    char *t61;
    char *t62;
    char *t63;
    char *t64;
    char *t65;

LAB0:    t1 = (t0 + 9080U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(126, ng0);
    t2 = (t0 + 10176);
    *((int *)t2) = 1;
    t3 = (t0 + 9112);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(127, ng0);

LAB5:    xsi_set_current_line(128, ng0);
    t4 = (t0 + 5208U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(128, ng0);

LAB9:    xsi_set_current_line(130, ng0);
    t11 = ((char*)((ng4)));
    t12 = (t0 + 8888);
    t13 = (t0 + 2912);
    t14 = xsi_create_subprogram_invocation(t12, 0, t0, t13, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t13, t14);
    t15 = (t0 + 7528);
    xsi_vlogvar_assign_value(t15, t11, 0, 0, 14);

LAB12:    t16 = (t0 + 8984);
    t17 = *((char **)t16);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t24 = ((int  (*)(char *, char *))t23)(t0, t17);

LAB14:    if (t24 != 0)
        goto LAB15;

LAB10:    t17 = (t0 + 2912);
    xsi_vlog_subprogram_popinvocation(t17);

LAB11:    t25 = (t0 + 8984);
    t26 = *((char **)t25);
    t25 = (t0 + 7688);
    t27 = (t25 + 56U);
    t28 = *((char **)t27);
    t29 = (t0 + 6888);
    xsi_vlogvar_assign_value(t29, t28, 0, 0, 32);
    t30 = (t0 + 2912);
    t31 = (t0 + 8888);
    t32 = 0;
    xsi_delete_subprogram_invocation(t30, t26, t0, t31, t32);
    xsi_set_current_line(131, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 6888);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t11 = (t0 + 8888);
    t12 = (t0 + 2480);
    t13 = xsi_create_subprogram_invocation(t11, 0, t0, t12, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t12, t13);
    t14 = (t0 + 7208);
    xsi_vlogvar_assign_value(t14, t2, 0, 0, 14);
    t15 = (t0 + 7368);
    xsi_vlogvar_assign_value(t15, t5, 0, 0, 32);

LAB18:    t16 = (t0 + 8984);
    t17 = *((char **)t16);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t24 = ((int  (*)(char *, char *))t23)(t0, t17);

LAB20:    if (t24 != 0)
        goto LAB21;

LAB16:    t17 = (t0 + 2480);
    xsi_vlog_subprogram_popinvocation(t17);

LAB17:    t25 = (t0 + 8984);
    t26 = *((char **)t25);
    t25 = (t0 + 2480);
    t27 = (t0 + 8888);
    t28 = 0;
    xsi_delete_subprogram_invocation(t25, t26, t0, t27, t28);
    xsi_set_current_line(134, ng0);
    t2 = (t0 + 7048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    t6 = *((unsigned int *)t4);
    t7 = *((unsigned int *)t5);
    t8 = (t6 & t7);
    *((unsigned int *)t33) = t8;
    t11 = (t4 + 4);
    t12 = (t5 + 4);
    t13 = (t33 + 4);
    t9 = *((unsigned int *)t11);
    t10 = *((unsigned int *)t12);
    t34 = (t9 | t10);
    *((unsigned int *)t13) = t34;
    t35 = *((unsigned int *)t13);
    t36 = (t35 != 0);
    if (t36 == 1)
        goto LAB22;

LAB23:
LAB24:    t16 = (t33 + 4);
    t54 = *((unsigned int *)t16);
    t55 = (~(t54));
    t56 = *((unsigned int *)t33);
    t57 = (t56 & t55);
    t58 = (t57 != 0);
    if (t58 > 0)
        goto LAB25;

LAB26:
LAB27:    goto LAB8;

LAB13:;
LAB15:    t16 = (t0 + 9080U);
    *((char **)t16) = &&LAB12;
    goto LAB1;

LAB19:;
LAB21:    t16 = (t0 + 9080U);
    *((char **)t16) = &&LAB18;
    goto LAB1;

LAB22:    t37 = *((unsigned int *)t33);
    t38 = *((unsigned int *)t13);
    *((unsigned int *)t33) = (t37 | t38);
    t14 = (t4 + 4);
    t15 = (t5 + 4);
    t39 = *((unsigned int *)t4);
    t40 = (~(t39));
    t41 = *((unsigned int *)t14);
    t42 = (~(t41));
    t43 = *((unsigned int *)t5);
    t44 = (~(t43));
    t45 = *((unsigned int *)t15);
    t46 = (~(t45));
    t24 = (t40 & t42);
    t47 = (t44 & t46);
    t48 = (~(t24));
    t49 = (~(t47));
    t50 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t50 & t48);
    t51 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t51 & t49);
    t52 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t52 & t48);
    t53 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t53 & t49);
    goto LAB24;

LAB25:    xsi_set_current_line(134, ng0);

LAB28:    xsi_set_current_line(135, ng0);
    t17 = ((char*)((ng2)));
    t18 = (t0 + 8888);
    t19 = (t0 + 2912);
    t20 = xsi_create_subprogram_invocation(t18, 0, t0, t19, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t19, t20);
    t21 = (t0 + 7528);
    xsi_vlogvar_assign_value(t21, t17, 0, 0, 14);

LAB31:    t22 = (t0 + 8984);
    t23 = *((char **)t22);
    t25 = (t23 + 80U);
    t26 = *((char **)t25);
    t27 = (t26 + 272U);
    t28 = *((char **)t27);
    t29 = (t28 + 0U);
    t30 = *((char **)t29);
    t59 = ((int  (*)(char *, char *))t30)(t0, t23);

LAB33:    if (t59 != 0)
        goto LAB34;

LAB29:    t23 = (t0 + 2912);
    xsi_vlog_subprogram_popinvocation(t23);

LAB30:    t31 = (t0 + 8984);
    t32 = *((char **)t31);
    t31 = (t0 + 7688);
    t60 = (t31 + 56U);
    t61 = *((char **)t60);
    t62 = (t0 + 7048);
    xsi_vlogvar_assign_value(t62, t61, 0, 0, 32);
    t63 = (t0 + 2912);
    t64 = (t0 + 8888);
    t65 = 0;
    xsi_delete_subprogram_invocation(t63, t32, t0, t64, t65);
    xsi_set_current_line(136, ng0);
    t2 = (t0 + 7048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7048);
    t11 = (t5 + 56U);
    t12 = *((char **)t11);
    memset(t33, 0, 8);
    t13 = (t33 + 4);
    t14 = (t12 + 4);
    t6 = *((unsigned int *)t12);
    t7 = (t6 >> 0);
    *((unsigned int *)t33) = t7;
    t8 = *((unsigned int *)t14);
    t9 = (t8 >> 0);
    *((unsigned int *)t13) = t9;
    t10 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t10 & 255U);
    t34 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t34 & 255U);
    xsi_vlogfile_write(1, 0, 0, ng6, 3, t0, (char)118, t4, 32, (char)118, t33, 8);
    goto LAB27;

LAB32:;
LAB34:    t22 = (t0 + 9080U);
    *((char **)t22) = &&LAB31;
    goto LAB1;

}

static void Always_172_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
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
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 9328U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(172, ng0);
    t2 = (t0 + 9136);
    xsi_process_wait(t2, 6300LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(172, ng0);
    t4 = (t0 + 5608);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t7) == 0)
        goto LAB5;

LAB7:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB8:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB10;

LAB9:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 5608);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB9;

}

static void Cont_173_2(char *t0)
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

LAB0:    t1 = (t0 + 9576U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(173, ng0);
    t2 = (t0 + 5608);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 10272);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
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
    xsi_driver_vfirst_trans(t5, 0, 0);
    t18 = (t0 + 10192);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Initial_175_3(char *t0)
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
    char *t10;
    char *t11;
    char *t12;
    int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;

LAB0:    t1 = (t0 + 9824U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(175, ng0);

LAB4:    xsi_set_current_line(180, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(181, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(183, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(184, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(185, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(188, ng0);
    t2 = (t0 + 9632);
    t3 = (t0 + 3776);
    t4 = xsi_create_subprogram_invocation(t2, 0, t0, t3, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t3, t4);

LAB7:    t5 = (t0 + 9728);
    t6 = *((char **)t5);
    t7 = (t6 + 80U);
    t8 = *((char **)t7);
    t9 = (t8 + 272U);
    t10 = *((char **)t9);
    t11 = (t10 + 0U);
    t12 = *((char **)t11);
    t13 = ((int  (*)(char *, char *))t12)(t0, t6);

LAB9:    if (t13 != 0)
        goto LAB10;

LAB5:    t6 = (t0 + 3776);
    xsi_vlog_subprogram_popinvocation(t6);

LAB6:    t14 = (t0 + 9728);
    t15 = *((char **)t14);
    t14 = (t0 + 3776);
    t16 = (t0 + 9632);
    t17 = 0;
    xsi_delete_subprogram_invocation(t14, t15, t0, t16, t17);
    xsi_set_current_line(190, ng0);
    t2 = (t0 + 9632);
    xsi_process_wait(t2, 5000000LL);
    *((char **)t1) = &&LAB11;

LAB1:    return;
LAB8:;
LAB10:    t5 = (t0 + 9824U);
    *((char **)t5) = &&LAB7;
    goto LAB1;

LAB11:    goto LAB1;

}


extern void work_m_00312774917586812272_1043376690_init()
{
	static char *pe[] = {(void *)Always_126_0,(void *)Always_172_1,(void *)Cont_173_2,(void *)Initial_175_3};
	static char *se[] = {(void *)sp_csr_write,(void *)sp_csr_read,(void *)sp_uart_write,(void *)sp_uart_init};
	xsi_register_didat("work_m_00312774917586812272_1043376690", "isim/tb_system_isim_beh.exe.sim/work/m_00312774917586812272_1043376690.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
