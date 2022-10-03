/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "blabla.check" instead.
 */

#include <check.h>

#line 1 "blabla.check"
#include "./s21_math.h"


START_TEST(test_ceil) {
#line 5

long double x = 3.2;
ck_assert_int_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(test_ceil_2) {
#line 12

long double x = -3.2;
ck_assert_int_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(test_ceil_3) {
#line 19

long double x = 0;
ck_assert_int_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(test_fabs_1) {
#line 25

long double x = -3.434;
ck_assert_int_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(test_fabs_2) {
#line 31

long double x = 7.898096089;
ck_assert_int_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(test_fabs_3) {
#line 37

long double x = 0;
ck_assert_int_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(test_abs_1) {
#line 42

long double x = -3.434;
ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(test_abs_2) {
#line 48

long double x = 7.898096089;
ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(test_abs_3) {
#line 54

long double x = 0;
ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(test_exp_1) {
#line 60

long double x = -3.434;
ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(test_exp_2) {
#line 65

long double x = 0;
ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(s21_log_test1) {
#line 71
    double number = 0.0;
    ck_assert_ldouble_infinite(s21_log(number));
    ck_assert_double_infinite(log(number));
}
END_TEST

START_TEST(s21_log_test2) {
#line 77
    double number = 0.0000001;
    ck_assert_ldouble_infinite(s21_log(number));
    ck_assert_double_infinite(log(0));
}
END_TEST

START_TEST(s21_log_test3) {
#line 83
    ck_assert_ldouble_infinite(s21_log(S21_HUGE_VAL));
    ck_assert_double_infinite(log(S21_HUGE_VAL));
}
END_TEST

START_TEST(s21_log_test4) {
#line 88
    ck_assert_ldouble_infinite(s21_log(S21_HUGE_VAL));
    ck_assert_double_infinite(log(S21_HUGE_VAL));
}
END_TEST

START_TEST(s21_log_test5) {
#line 93
    double number = 1.0001;
    ck_assert_ldouble_eq_tol(s21_log(number), (long double)log(number), EPS);
}
END_TEST

START_TEST(s21_log_test6) {
#line 98
    double number = -1.0001;
    ck_assert_ldouble_nan(s21_log(number));
    ck_assert_double_nan(log(number));
}
END_TEST

START_TEST(s21_log_test7) {
#line 104
    double number = 2;
    ck_assert_ldouble_eq_tol(s21_log(number), (long double)log(number), EPS);
}
END_TEST

START_TEST(s21_log_test8) {
#line 109
    double number = 1.5;
    ck_assert_ldouble_eq_tol(s21_log(number), (long double)log(number), EPS);
}
END_TEST

START_TEST(s21_log_test9) {
#line 114
    double number = 15;
    ck_assert_ldouble_eq_tol(s21_log(number), (long double)log(number), EPS);
}
END_TEST

START_TEST(s21_log_test10) {
#line 119
    double number = S21_ME + 1e-16;
    ck_assert_ldouble_eq_tol(s21_log(number), (long double)log(number), EPS);
}
END_TEST

START_TEST(s21_log_test11) {
#line 124
    double number = 0.9999;
    ck_assert_ldouble_eq_tol(s21_log(number), (long double)log(number), EPS);
}
END_TEST

START_TEST(s21_log_test12) {
#line 129
    double number = 100.5;
    ck_assert_ldouble_eq_tol(s21_log(number), (long double)log(number), EPS);
}
END_TEST

START_TEST(s21_log_test13) {
#line 134
    for (double k = 1; k < 100; k += 13.2) {
        double a = s21_log(k);
        double b = log(k);
        ck_assert_double_eq_tol(a, b, 1e-6);
    }
}
END_TEST

START_TEST(s21_log_test14) {
#line 142
    for (double k = 0.1; k < 4; k += 0.24) {
        double a = s21_log(k);
        double b = log(k);
        ck_assert_double_eq_tol(a, b, 1e-6);
    }
}
END_TEST

START_TEST(s21_log_test15) {
#line 150
    for (double k = 0.1; k < 10000; k += 123) {
        double a = s21_log(k);
        double b = log(k);
        ck_assert_double_eq_tol(a, b, EPS);
    }
}
END_TEST

START_TEST(s21_log_test16) {
#line 158
    for (double k = 0.000005; k < 1; k *= 5) {
        double a = s21_log(k);
        double b = log(k);
        ck_assert_double_eq_tol(a, b, EPS);
    }
}
END_TEST

START_TEST(s21_log_test17) {
#line 166
    ck_assert_double_nan(s21_log(S21_NAN));
}
END_TEST

START_TEST(s21_log_test18) {
#line 170
    ck_assert_double_eq(log(0), s21_log(0));
}
END_TEST

START_TEST(s21_log_test19) {
#line 174
    ck_assert_double_nan(s21_log(-3));
}
END_TEST

START_TEST(s21_log_test20) {
#line 178
    ck_assert_double_eq(log(INFINITY), s21_log(S21_HUGE_VAL));
}
END_TEST

START_TEST(s21_log_test21) {
#line 182
    ck_assert_double_nan(s21_log(-S21_HUGE_VAL));
}
END_TEST

START_TEST(s21_log_test22) {
#line 186
    ck_assert_double_eq(log(1), s21_log(1));
}
END_TEST

START_TEST(s21_log_test23) {
#line 190
    ck_assert_double_eq_tol(log(2), s21_log(2), 1e-6);
}
END_TEST

START_TEST(s21_log_test24) {
#line 194
    ck_assert_double_nan(s21_log(-S21_HUGE_VAL * 2));
}
END_TEST

START_TEST(s21_pow_test1) {
#line 197
    double res1 = pow(2, 3);
    long double res2 = s21_pow(2, 3);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test2) {
#line 203
    double res1 = pow(0, 0);
    long double res2 = s21_pow(0, 0);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test3) {
#line 209
    double res1 = pow(3, -1);
    long double res2 = s21_pow(3, -1);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test4) {
#line 215
    double res1 = pow(-5, 5);
    long double res2 = s21_pow(-5, 5);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test5) {
#line 221
    long double res1 = pow(0.352342, 7);
    long double res2 = s21_pow(0.352342, 7);
    ck_assert_ldouble_eq_tol(res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test6) {
#line 227
    double res1 = pow(0.5, 1.245);
    long double res2 = s21_pow(0.5, 1.245);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test7) {
#line 233
    double res1 = pow(0.99999, 0.99999);
    long double res2 = s21_pow(0.99999, 0.99999);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test8) {
#line 239
    double res1 = pow(99, -0.99999);
    long double res2 = s21_pow(99, -0.99999);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test9) {
#line 245
    double res1 = pow(99, -0.0001);
    long double res2 = s21_pow(99, -0.0001);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test10) {
#line 251
    double res1 = pow(1, 10.000199999);
    long double res2 = s21_pow(1, 10.000199999);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test11) {
#line 257
    double res1 = pow(1.0001, 10.000199999);
    long double res2 = s21_pow(1.0001, 10.000199999);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test12) {
#line 263
    double res1 = pow(1.0001, -10.000199999);
    long double res2 = s21_pow(1.0001, -10.000199999);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test13) {
#line 269
    double res1 = pow(-1.0001, -10.100199999);
    long double res2 = s21_pow(-1.0001, -10.100199999);
    ck_assert_ldouble_nan((long double)res1);
    ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(s21_pow_test14) {
#line 276
    double res1 = pow(S21_HUGE_VAL, -S21_HUGE_VAL);
    long double res2 = s21_pow(S21_HUGE_VAL, -S21_HUGE_VAL);
    ck_assert_ldouble_eq_tol(res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test15) {
#line 282
    double res1 = pow(-12.5, 5);
    long double res2 = s21_pow(-12.5, 5);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test16) {
#line 288
    double res1 = pow(-12.5, 6);
    long double res2 = s21_pow(-12.5, 6);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test17) {
#line 294
    double res1 = pow(0.0, 6);
    long double res2 = s21_pow(0.0, 6);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test18) {
#line 300
    double res1 = pow(S21_HUGE_VAL, -2);
    long double res2 = s21_pow(S21_HUGE_VAL, -2);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST

START_TEST(s21_pow_test19) {
#line 306
    ck_assert_double_eq_tol(pow(0.3123, 0.789456), s21_pow(0.3123, 0.789456), 1e-6);
}
END_TEST

START_TEST(s21_pow_test20) {
#line 310
    ck_assert_double_eq_tol(pow(56.3, 0.3), s21_pow(56.3, 0.3), 1e-6);
}
END_TEST

START_TEST(s21_pow_test21) {
#line 314
    ck_assert_double_eq(pow(1, 0), s21_pow(1, 0));
}
END_TEST

START_TEST(s21_pow_test22) {
#line 318
    ck_assert_double_eq(pow(-1, 3), s21_pow(-1, 3));
}
END_TEST

START_TEST(s21_pow_test23) {
#line 322
    ck_assert_double_eq(pow(-INFINITY, 3), s21_pow(-S21_HUGE_VAL, 3));
}
END_TEST

START_TEST(s21_pow_test24) {
#line 326
    ck_assert_double_eq(pow(0, 0), s21_pow(0, 0));
}
END_TEST

START_TEST(s21_pow_test25) {
#line 330
    ck_assert_double_eq(pow(0, -1), s21_pow(0, -1));
}
END_TEST

START_TEST(s21_pow_test26) {
#line 334
    ck_assert_double_eq(pow(0, 1), s21_pow(0, 1));
}
END_TEST

START_TEST(s21_pow_test27) {
#line 338
    ck_assert_double_eq(pow(INFINITY, 0), s21_pow(S21_HUGE_VAL, 0));
}
END_TEST

START_TEST(s21_pow_test28) {
#line 342
    ck_assert_double_eq(pow(INFINITY, -1), s21_pow(S21_HUGE_VAL, -1));
}
END_TEST

START_TEST(s21_pow_test29) {
#line 346
    ck_assert_double_nan(s21_pow(0, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test30) {
#line 350
    ck_assert_double_nan(s21_pow(S21_NAN, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test31) {
#line 354
    ck_assert_double_eq(pow(INFINITY, INFINITY), s21_pow(S21_HUGE_VAL, S21_HUGE_VAL));
}
END_TEST

START_TEST(s21_pow_test32) {
#line 358
    ck_assert_double_nan(s21_pow(S21_NAN, S21_HUGE_VAL));
}
END_TEST

START_TEST(s21_pow_test33) {
#line 362
    ck_assert_double_nan(s21_pow(S21_HUGE_VAL, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test34) {
#line 366
    ck_assert_double_nan(s21_pow(S21_NAN, -S21_HUGE_VAL));
}
END_TEST

START_TEST(s21_pow_test35) {
#line 370
    ck_assert_double_nan(s21_pow(-S21_HUGE_VAL, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test36) {
#line 374
    ck_assert_double_eq(pow(2, INFINITY), s21_pow(2, S21_HUGE_VAL));
}
END_TEST

START_TEST(s21_pow_test37) {
#line 378
    ck_assert_double_nan(s21_pow(-0.789456, -0.789456));
}
END_TEST

START_TEST(s21_pow_test38) {
#line 382
    ck_assert_double_nan(s21_pow(-500.789456, -10.1354323));
}
END_TEST

START_TEST(s21_pow_test39) {
#line 386
    ck_assert_double_nan(s21_pow(-500.789456, 34.13));
}
END_TEST

START_TEST(s21_pow_test40) {
#line 390
    ck_assert_double_eq_tol(pow(10.789456, 3.13), s21_pow(10.789456, 3.13), 1e-2);
}
END_TEST

START_TEST(s21_pow_test41) {
#line 394
    ck_assert_double_eq_tol(pow(-1, -S21_HUGE_VAL), s21_pow(-1, -S21_HUGE_VAL), EPS);
}
END_TEST

START_TEST(s21_pow_test42) {
#line 398
    ck_assert_double_eq_tol(pow(0, S21_HUGE_VAL), s21_pow(0, S21_HUGE_VAL), EPS);
}
END_TEST

START_TEST(s21_pow_test43) {
#line 402
    double res1 = pow(-S21_HUGE_VAL, -2);
    long double res2 = s21_pow(-S21_HUGE_VAL, -2);
    ck_assert_ldouble_eq_tol((long double)res1, res2, EPS);
}
END_TEST


START_TEST(s21_acos_test3) {
#line 417
    ck_assert_ldouble_nan(s21_acos(-S21_HUGE_VAL));
}
END_TEST


START_TEST(s21_acos_test6) {
#line 431
    ck_assert_ldouble_nan(s21_acos(S21_NAN));
}
END_TEST

START_TEST(s21_acos_test7) {
#line 435
    ck_assert_ldouble_nan(s21_acos(-1.0/0.0));
}
END_TEST

START_TEST(s21_acos_test8) {
#line 439
    ck_assert_ldouble_nan(s21_acos(6.654));
}
END_TEST

START_TEST(s21_acos_test9) {
#line 443
    ck_assert_ldouble_nan(s21_acos(1.5 * S21_PI));
}
END_TEST

START_TEST(s21_acos_test10) {
#line 447
    ck_assert_ldouble_eq_tol(acos(0.00001), s21_acos(0.00001), 1e-6);
}
END_TEST

START_TEST(s21_atan_test1) {
#line 451
    ck_assert_ldouble_eq_tol(atan(500.000), s21_atan(500.000), 1e-4);
}
END_TEST

START_TEST(s21_atan_test2) {
#line 455
    for (double i = -565.324; i <= 789.532; i += 50.6235)
        ck_assert_ldouble_eq_tol(atan(i), s21_atan(i), 1e-6);
}
END_TEST

START_TEST(s21_atan_test4) {
#line 465
    ck_assert_ldouble_eq_tol(atan(-1.0/0.0), s21_atan(-1.0/0.0), 1e-7);
}
END_TEST

START_TEST(s21_atan_test5) {
#line 469
    ck_assert_ldouble_eq_tol(atan(0.0), s21_atan(0.0), 1e-7);
}
END_TEST

START_TEST(s21_atan_test6) {
#line 473
    ck_assert_ldouble_nan(s21_atan(0.0/0.0));
}
END_TEST

START_TEST(s21_atan_test7) {
#line 477
    ck_assert_ldouble_eq_tol(atan(0.0), s21_atan(0.0), 1e-7);
}
END_TEST

START_TEST(s21_atan_test9) {
#line 486
    ck_assert_ldouble_eq_tol(atan(INFINITY), s21_atan(S21_HUGE_VAL), 1e-7);
}
END_TEST

START_TEST(s21_atan_test10) {
#line 490
    ck_assert_ldouble_eq_tol(atan(-2.78965), s21_atan(-2.78965), 1e-7);
}
END_TEST

START_TEST(s21_asin_test3) {
#line 502
    ck_assert_ldouble_nan(s21_asin(S21_NAN));
}
END_TEST


START_TEST(s21_asin_test5) {
#line 510
    ck_assert_ldouble_eq_tol(asin(-1), s21_asin(-1), 1e-6);
}
END_TEST

START_TEST(s21_asin_test7) {
#line 519
    ck_assert_ldouble_eq_tol(asin(0), s21_asin(0), 1e-6);
}
END_TEST

START_TEST(s21_asin_test8) {
#line 523
    ck_assert_ldouble_nan(s21_asin(INFINITY));
}
END_TEST

START_TEST(s21_asin_test9) {
#line 527
    ck_assert_ldouble_nan(s21_asin(-INFINITY));
}
END_TEST

START_TEST(s21_asin_test10) {
#line 531
    ck_assert_ldouble_nan(s21_asin(-252.568));
}
END_TEST

START_TEST(s21_asin_test11) {
#line 535
    ck_assert_ldouble_nan(s21_asin(555));
}
END_TEST

START_TEST(s21_exp_test1) {
#line 539
    double number = 0.0;
    ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
}
END_TEST

START_TEST(s21_exp_test2) {
#line 544
    double number = -0.0;
    ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
}
END_TEST

START_TEST(s21_exp_test3) {
#line 549
    double number = 1.0;
    ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
}
END_TEST

START_TEST(s21_exp_test4) {
#line 554
    double number = 1.1111;
    ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
}
END_TEST

START_TEST(s21_exp_test5) {
#line 559
    double number = -1.1111;
    ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
}
END_TEST

START_TEST(s21_exp_test6) {
#line 564
    double number = 10;
    ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
}
END_TEST

START_TEST(s21_exp_test7) {
#line 569
    double number = -10;
    ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
}
END_TEST

START_TEST(s21_exp_test8) {
#line 574
    double number = -1.9999999;
    ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
}
END_TEST

START_TEST(s21_exp_test9) {
#line 579
    double number = 1.9999999;
    ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
}
END_TEST

START_TEST(s21_exp_test10) {
#line 584
    double number = -0.9999999;
    ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
}
END_TEST

START_TEST(s21_exp_test11) {
#line 589
    double number = 0.9999999;
    ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
}
END_TEST

START_TEST(s21_exp_test12) {
#line 594
    ck_assert_ldouble_nan(s21_exp(S21_NAN));
    ck_assert_double_nan(exp(S21_NAN));
}
END_TEST

START_TEST(s21_exp_test13) {
#line 599
    ck_assert_ldouble_infinite(s21_exp(S21_HUGE_VAL));
    ck_assert_double_infinite(exp(S21_HUGE_VAL));
}
END_TEST

START_TEST(s21_exp_test14) {
#line 604
    ck_assert_ldouble_eq(s21_exp(-S21_HUGE_VAL), 0.0);
    ck_assert_ldouble_eq(exp(-S21_HUGE_VAL), 0.0);
}
END_TEST

START_TEST(s21_exp_test15) {
#line 609
    double number = 5.5;
    ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
}
END_TEST

START_TEST(s21_exp_test16) {
#line 614
    ck_assert_double_eq_tol(s21_exp(3.3333), s21_exp(3.3333), EPS);
}
END_TEST

START_TEST(s21_exp_test17) {
#line 618
    ck_assert_double_eq_tol(s21_exp(-5.5), s21_exp(-5.5), EPS);
}
END_TEST

START_TEST(s21_exp_test18) {
#line 622
    ck_assert_double_eq(s21_exp(4566.7899), s21_exp(4566.7899));
}
END_TEST

START_TEST(s21_exp_test19) {
#line 626
    ck_assert_double_nan(s21_exp(NAN));
}
END_TEST

START_TEST(s21_exp_test20) {
#line 630
    ck_assert_double_eq(exp(INFINITY), s21_exp(INFINITY));
}
END_TEST

START_TEST(s21_exp_test21) {
#line 634
    ck_assert_double_eq_tol(exp(0.4564), s21_exp(0.4564), EPS);
}
END_TEST

START_TEST(s21_exp_test22) {
#line 638
    ck_assert_double_eq(exp(0), s21_exp(0));
}
END_TEST

START_TEST(s21_exp_test23) {
#line 642
    ck_assert_double_eq_tol(exp(-45.11), s21_exp(-45.11), EPS);
}
END_TEST

START_TEST(s21_exp_test24) {
#line 646
    ck_assert_double_eq_tol(exp(-1), s21_exp(-1), EPS);
}
END_TEST

START_TEST(s21_exp_test25) {
#line 650
    ck_assert_double_eq_tol(exp(-0.000001), s21_exp(-0.000001), EPS);
}
END_TEST

START_TEST(s21_exp_test26) {
#line 654
    for (double i = -2.7863; i <= 2.6831; i += 0.001)
        ck_assert_double_eq_tol(exp(i), s21_exp(i), EPS);
}
END_TEST

START_TEST(s21_floor_test1) {
#line 658
    ck_assert_double_eq(floor(INFINITY), s21_floor(S21_HUGE_VAL));
}
END_TEST

START_TEST(s21_floor_test2) {
#line 662
    ck_assert_double_eq(floor(-INFINITY), s21_floor(-S21_HUGE_VAL));
}
END_TEST

START_TEST(s21_floor_test3) {
#line 666
    ck_assert_double_nan(floor(NAN));
}
END_TEST

START_TEST(s21_floor_test4) {
#line 670
    ck_assert_double_nan(s21_floor(NAN));
}
END_TEST

START_TEST(s21_floor_test5) {
#line 674
    ck_assert_int_eq(floor(-7.0), s21_floor(-7.0));
}
END_TEST

START_TEST(s21_floor_test6) {
#line 678
    ck_assert_double_eq(floor(-98.1), s21_floor(-98.1));
}
END_TEST

START_TEST(s21_floor_test7) {
#line 682
    ck_assert_double_eq(floor(123.02), s21_floor(123.02));
}
END_TEST

START_TEST(s21_floor_test9) {
#line 690
    ck_assert_double_eq(floor(-10009.555), s21_floor(-10009.555));
}
END_TEST

START_TEST(s21_floor_test10) {
#line 694
    ck_assert_double_eq(floor(-0.10009), s21_floor(-0.10009));
}
END_TEST

START_TEST(s21_floor_test11) {
#line 698
    ck_assert_double_eq(floor(-1e-23), s21_floor(-1e-23));
}
END_TEST

START_TEST(s21_floor_test12) {
#line 702
    ck_assert_double_eq(floor(100091234.5), s21_floor(100091234.5));
}
END_TEST

START_TEST(s21_floor_test13) {
#line 706
    ck_assert_double_eq(floor(7), s21_floor(7));
}
END_TEST

START_TEST(s21_floor_test14) {
#line 710
    ck_assert_double_eq(floor(0), s21_floor(0));
}
END_TEST

START_TEST(s21_floor_test15) {
#line 714
    ck_assert_double_eq(floor(0.0), s21_floor(0.0));
}
END_TEST

START_TEST(s21_sqrt_test1) {
#line 717
    ck_assert_ldouble_eq_tol(sqrt(1234567891234567), s21_sqrt(1234567891234567), EPS);
}
END_TEST

START_TEST(s21_sqrt_test2) {
#line 721
    ck_assert_ldouble_eq_tol(sqrt(0.0), s21_sqrt(0.0), EPS);
}
END_TEST

START_TEST(s21_sqrt_test3) {
#line 725
    ck_assert_ldouble_eq_tol(sqrt(0.01), s21_sqrt(0.01), EPS);
}
END_TEST

START_TEST(s21_sqrt_test4) {
#line 729
    ck_assert_ldouble_eq_tol(sqrt(0.00001), s21_sqrt(0.00001), EPS);
}
END_TEST

START_TEST(s21_sqrt_test5) {
#line 733
    ck_assert_ldouble_nan(s21_sqrt(-0.00001));
}
END_TEST

START_TEST(s21_sqrt_test6) {
#line 737
    ck_assert_ldouble_nan(s21_sqrt(-1));
}
END_TEST

START_TEST(s21_sqrt_test7) {
#line 741
    ck_assert_ldouble_eq_tol(sqrt(2), s21_sqrt(2), EPS);
}
END_TEST

START_TEST(s21_sqrt_test8) {
#line 745
    ck_assert_ldouble_eq_tol(sqrt(121), s21_sqrt(121), EPS);
}
END_TEST

START_TEST(s21_sqrt_test9) {
#line 749
    ck_assert_ldouble_eq_tol(sqrt(1244.12414), s21_sqrt(1244.12414), EPS);
}
END_TEST

START_TEST(s21_sqrt_test10) {
#line 753
    ck_assert_ldouble_eq_tol(sqrt(1.21), s21_sqrt(1.21), EPS);
}
END_TEST

START_TEST(s21_sqrt_test11) {
#line 757
    ck_assert_ldouble_eq_tol(sqrt(0.999998), s21_sqrt(0.999998), EPS);
}
END_TEST

START_TEST(s21_sqrt_test12) {
#line 761
    ck_assert_double_eq_tol(s21_sqrt(233), sqrt(233), 1e-6);
}
END_TEST

START_TEST(s21_sqrt_test13) {
#line 765
    ck_assert_double_nan(s21_sqrt(S21_NAN));
}
END_TEST

START_TEST(s21_sqrt_test14) {
#line 769
    ck_assert_double_nan(sqrt(NAN));
}
END_TEST

START_TEST(s21_sqrt_test15) {
#line 773
    ck_assert_double_eq(s21_sqrt(S21_HUGE_VAL), sqrt(INFINITY));
}
END_TEST

START_TEST(s21_sqrt_test16) {
#line 777
    ck_assert_double_nan(s21_sqrt(-S21_HUGE_VAL));
}
END_TEST

START_TEST(s21_sqrt_test17) {
#line 781
    ck_assert_double_nan(sqrt(-INFINITY));
}
END_TEST

START_TEST(s21_sqrt_test18) {
#line 785
    ck_assert_double_nan(s21_sqrt(-5));
}
END_TEST

START_TEST(s21_sqrt_test19) {
#line 789
    ck_assert_double_nan(sqrt(-0.000001));
}
END_TEST

START_TEST(s21_sqrt_test20) {
#line 793
    ck_assert_double_eq_tol(s21_sqrt(1000), sqrt(1000), 1e-7);
}
END_TEST

START_TEST(s21_sqrt_test21) {
#line 797
    ck_assert_double_eq_tol(s21_sqrt(0.000001), sqrt(0.000001), 1e-7);
}
END_TEST

START_TEST(s21_tan_test1) {
#line 800
    ck_assert_ldouble_eq_tol(tan(0.123456), s21_tan(0.123456), EPS);
}
END_TEST

START_TEST(s21_tan_test2) {
#line 804
    ck_assert_ldouble_nan(s21_tan(S21_NAN));
}
END_TEST

START_TEST(s21_tan_test3) {
#line 808
    ck_assert_ldouble_nan(s21_tan(S21_HUGE_VAL));
}
END_TEST

START_TEST(s21_tan_test4) {
#line 812
    ck_assert_ldouble_nan(s21_tan(-S21_HUGE_VAL));
}
END_TEST

START_TEST(s21_tan_test5) {
#line 816
    ck_assert_ldouble_eq_tol(tan(-0.123456), s21_tan(-0.123456), EPS);
}
END_TEST

START_TEST(s21_tan_test6) {
#line 819
    ck_assert_ldouble_eq_tol(tan(11115.123456), s21_tan(11115.123456), EPS);
}
END_TEST

START_TEST(s21_tan_test7s) {
#line 823
    ck_assert_ldouble_eq_tol(tan(-11115.123456), s21_tan(-11115.123456), EPS);
}
END_TEST

START_TEST(s21_tan_test8) {
#line 827
    ck_assert_ldouble_eq_tol(tan(0.000001), s21_tan(0.000001), EPS);
}
END_TEST

START_TEST(s21_tan_test9) {
#line 831
    ck_assert_ldouble_eq_tol(tan(-0.0), s21_tan(-0.0), EPS);
}
END_TEST

START_TEST(s21_tan_test10) {
#line 835
    ck_assert_ldouble_nan(s21_tan(-0.0/0.0));
}
END_TEST

START_TEST(s21_tan_test11) {
#line 839
    for (double i = 1.0; i >= -1.0; i -= 0.0001)
        ck_assert_ldouble_eq_tol(tan(i), s21_tan(i), EPS);
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, test_ceil);
    tcase_add_test(tc1_1, test_ceil_2);
    tcase_add_test(tc1_1, test_ceil_3);
    tcase_add_test(tc1_1, test_fabs_1);
    tcase_add_test(tc1_1, test_fabs_2);
    tcase_add_test(tc1_1, test_fabs_3);
    tcase_add_test(tc1_1, test_abs_1);
    tcase_add_test(tc1_1, test_abs_2);
    tcase_add_test(tc1_1, test_abs_3);
    tcase_add_test(tc1_1, test_exp_1);
    tcase_add_test(tc1_1, test_exp_2);
    tcase_add_test(tc1_1, s21_log_test1);
    tcase_add_test(tc1_1, s21_log_test2);
    tcase_add_test(tc1_1, s21_log_test3);
    tcase_add_test(tc1_1, s21_log_test4);
    tcase_add_test(tc1_1, s21_log_test5);
    tcase_add_test(tc1_1, s21_log_test6);
    tcase_add_test(tc1_1, s21_log_test7);
    tcase_add_test(tc1_1, s21_log_test8);
    tcase_add_test(tc1_1, s21_log_test9);
    tcase_add_test(tc1_1, s21_log_test10);
    tcase_add_test(tc1_1, s21_log_test11);
    tcase_add_test(tc1_1, s21_log_test12);
    tcase_add_test(tc1_1, s21_log_test13);
    tcase_add_test(tc1_1, s21_log_test14);
    tcase_add_test(tc1_1, s21_log_test15);
    tcase_add_test(tc1_1, s21_log_test16);
    tcase_add_test(tc1_1, s21_log_test17);
    tcase_add_test(tc1_1, s21_log_test18);
    tcase_add_test(tc1_1, s21_log_test19);
    tcase_add_test(tc1_1, s21_log_test20);
    tcase_add_test(tc1_1, s21_log_test21);
    tcase_add_test(tc1_1, s21_log_test22);
    tcase_add_test(tc1_1, s21_log_test23);
    tcase_add_test(tc1_1, s21_log_test24);
    tcase_add_test(tc1_1, s21_pow_test1);
    tcase_add_test(tc1_1, s21_pow_test2);
    tcase_add_test(tc1_1, s21_pow_test3);
    tcase_add_test(tc1_1, s21_pow_test4);
    tcase_add_test(tc1_1, s21_pow_test5);
    tcase_add_test(tc1_1, s21_pow_test6);
    tcase_add_test(tc1_1, s21_pow_test7);
    tcase_add_test(tc1_1, s21_pow_test8);
    tcase_add_test(tc1_1, s21_pow_test9);
    tcase_add_test(tc1_1, s21_pow_test10);
    tcase_add_test(tc1_1, s21_pow_test11);
    tcase_add_test(tc1_1, s21_pow_test12);
    tcase_add_test(tc1_1, s21_pow_test13);
    tcase_add_test(tc1_1, s21_pow_test14);
    tcase_add_test(tc1_1, s21_pow_test15);
    tcase_add_test(tc1_1, s21_pow_test16);
    tcase_add_test(tc1_1, s21_pow_test17);
    tcase_add_test(tc1_1, s21_pow_test18);
    tcase_add_test(tc1_1, s21_pow_test19);
    tcase_add_test(tc1_1, s21_pow_test20);
    tcase_add_test(tc1_1, s21_pow_test21);
    tcase_add_test(tc1_1, s21_pow_test22);
    tcase_add_test(tc1_1, s21_pow_test23);
    tcase_add_test(tc1_1, s21_pow_test24);
    tcase_add_test(tc1_1, s21_pow_test25);
    tcase_add_test(tc1_1, s21_pow_test26);
    tcase_add_test(tc1_1, s21_pow_test27);
    tcase_add_test(tc1_1, s21_pow_test28);
    tcase_add_test(tc1_1, s21_pow_test29);
    tcase_add_test(tc1_1, s21_pow_test30);
    tcase_add_test(tc1_1, s21_pow_test31);
    tcase_add_test(tc1_1, s21_pow_test32);
    tcase_add_test(tc1_1, s21_pow_test33);
    tcase_add_test(tc1_1, s21_pow_test34);
    tcase_add_test(tc1_1, s21_pow_test35);
    tcase_add_test(tc1_1, s21_pow_test36);
    tcase_add_test(tc1_1, s21_pow_test37);
    tcase_add_test(tc1_1, s21_pow_test38);
    tcase_add_test(tc1_1, s21_pow_test39);
    tcase_add_test(tc1_1, s21_pow_test40);
    tcase_add_test(tc1_1, s21_pow_test41);
    tcase_add_test(tc1_1, s21_pow_test42);
    tcase_add_test(tc1_1, s21_pow_test43);
    tcase_add_test(tc1_1, s21_acos_test3);
    tcase_add_test(tc1_1, s21_acos_test6);
    tcase_add_test(tc1_1, s21_acos_test7);
    tcase_add_test(tc1_1, s21_acos_test8);
    tcase_add_test(tc1_1, s21_acos_test9);
    tcase_add_test(tc1_1, s21_acos_test10);
    tcase_add_test(tc1_1, s21_atan_test1);
    tcase_add_test(tc1_1, s21_atan_test2);
    tcase_add_test(tc1_1, s21_atan_test4);
    tcase_add_test(tc1_1, s21_atan_test5);
    tcase_add_test(tc1_1, s21_atan_test6);
    tcase_add_test(tc1_1, s21_atan_test7);
    tcase_add_test(tc1_1, s21_atan_test9);
    tcase_add_test(tc1_1, s21_atan_test10);
    tcase_add_test(tc1_1, s21_asin_test3);
    tcase_add_test(tc1_1, s21_asin_test5);
    tcase_add_test(tc1_1, s21_asin_test7);
    tcase_add_test(tc1_1, s21_asin_test8);
    tcase_add_test(tc1_1, s21_asin_test9);
    tcase_add_test(tc1_1, s21_asin_test10);
    tcase_add_test(tc1_1, s21_asin_test11);
    tcase_add_test(tc1_1, s21_exp_test1);
    tcase_add_test(tc1_1, s21_exp_test2);
    tcase_add_test(tc1_1, s21_exp_test3);
    tcase_add_test(tc1_1, s21_exp_test4);
    tcase_add_test(tc1_1, s21_exp_test5);
    tcase_add_test(tc1_1, s21_exp_test6);
    tcase_add_test(tc1_1, s21_exp_test7);
    tcase_add_test(tc1_1, s21_exp_test8);
    tcase_add_test(tc1_1, s21_exp_test9);
    tcase_add_test(tc1_1, s21_exp_test10);
    tcase_add_test(tc1_1, s21_exp_test11);
    tcase_add_test(tc1_1, s21_exp_test12);
    tcase_add_test(tc1_1, s21_exp_test13);
    tcase_add_test(tc1_1, s21_exp_test14);
    tcase_add_test(tc1_1, s21_exp_test15);
    tcase_add_test(tc1_1, s21_exp_test16);
    tcase_add_test(tc1_1, s21_exp_test17);
    tcase_add_test(tc1_1, s21_exp_test18);
    tcase_add_test(tc1_1, s21_exp_test19);
    tcase_add_test(tc1_1, s21_exp_test20);
    tcase_add_test(tc1_1, s21_exp_test21);
    tcase_add_test(tc1_1, s21_exp_test22);
    tcase_add_test(tc1_1, s21_exp_test23);
    tcase_add_test(tc1_1, s21_exp_test24);
    tcase_add_test(tc1_1, s21_exp_test25);
    tcase_add_test(tc1_1, s21_exp_test26);
    tcase_add_test(tc1_1, s21_floor_test1);
    tcase_add_test(tc1_1, s21_floor_test2);
    tcase_add_test(tc1_1, s21_floor_test3);
    tcase_add_test(tc1_1, s21_floor_test4);
    tcase_add_test(tc1_1, s21_floor_test5);
    tcase_add_test(tc1_1, s21_floor_test6);
    tcase_add_test(tc1_1, s21_floor_test7);
    tcase_add_test(tc1_1, s21_floor_test9);
    tcase_add_test(tc1_1, s21_floor_test10);
    tcase_add_test(tc1_1, s21_floor_test11);
    tcase_add_test(tc1_1, s21_floor_test12);
    tcase_add_test(tc1_1, s21_floor_test13);
    tcase_add_test(tc1_1, s21_floor_test14);
    tcase_add_test(tc1_1, s21_floor_test15);
    tcase_add_test(tc1_1, s21_sqrt_test1);
    tcase_add_test(tc1_1, s21_sqrt_test2);
    tcase_add_test(tc1_1, s21_sqrt_test3);
    tcase_add_test(tc1_1, s21_sqrt_test4);
    tcase_add_test(tc1_1, s21_sqrt_test5);
    tcase_add_test(tc1_1, s21_sqrt_test6);
    tcase_add_test(tc1_1, s21_sqrt_test7);
    tcase_add_test(tc1_1, s21_sqrt_test8);
    tcase_add_test(tc1_1, s21_sqrt_test9);
    tcase_add_test(tc1_1, s21_sqrt_test10);
    tcase_add_test(tc1_1, s21_sqrt_test11);
    tcase_add_test(tc1_1, s21_sqrt_test12);
    tcase_add_test(tc1_1, s21_sqrt_test13);
    tcase_add_test(tc1_1, s21_sqrt_test14);
    tcase_add_test(tc1_1, s21_sqrt_test15);
    tcase_add_test(tc1_1, s21_sqrt_test16);
    tcase_add_test(tc1_1, s21_sqrt_test17);
    tcase_add_test(tc1_1, s21_sqrt_test18);
    tcase_add_test(tc1_1, s21_sqrt_test19);
    tcase_add_test(tc1_1, s21_sqrt_test20);
    tcase_add_test(tc1_1, s21_sqrt_test21);
    tcase_add_test(tc1_1, s21_tan_test1);
    tcase_add_test(tc1_1, s21_tan_test2);
    tcase_add_test(tc1_1, s21_tan_test3);
    tcase_add_test(tc1_1, s21_tan_test4);
    tcase_add_test(tc1_1, s21_tan_test5);
    tcase_add_test(tc1_1, s21_tan_test6);
    tcase_add_test(tc1_1, s21_tan_test7s);
    tcase_add_test(tc1_1, s21_tan_test8);
    tcase_add_test(tc1_1, s21_tan_test9);
    tcase_add_test(tc1_1, s21_tan_test10);
    tcase_add_test(tc1_1, s21_tan_test11);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
