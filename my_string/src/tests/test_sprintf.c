/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "s21_test_sprintf.check" instead.
 */

#include <stdio.h>

#line 1 "s21_test_sprintf.check"
#include "../tests_includes/s21_tests.h"

START_TEST(Baby_boom_za_shekoi_shepuchka) {
#line 5
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple value %d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precise_int) {
#line 16
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
#line 27
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%5d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
#line 41
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%+12d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(padding_int) {
#line 53
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%12i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int) {
#line 66
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%+5.10li";
    long int val = 698518581899;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
// #test flags_short_int
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%-16.9hi";
//     short int val = 6958;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision_zero_int) {
#line 92
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.0d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
#line 109
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
#line 122
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
// #test unsigned_val_flags
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%-16u";
//     unsigned int val = 14140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
#line 148
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.5u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many_flags) {
#line 161
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% 5.10u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_short) {
#line 174
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%hu";
    unsigned short int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
#line 187
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%lu";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
// #test unsigned_val_many
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%lu, %u, %hu, %.5u, %5.u";
//     unsigned long int val = 949149114140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
//                      sprintf(str2, format, val, 14,
//                              1441, 14414,
//                              9681));

//     ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags) {
#line 215
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% -5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width) {
#line 228
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many) {
#line 241
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5.3c%c%c%c%c Hello! govno";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                     sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
#line 254
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s";
    char *val = "YA HOCHU SDOHNUT";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_precision) {
#line 266
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.15s";
    char *val = "YA HOCHU SDOHNUT UBEYTE MENYA PLIZ AAA";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width) {
#line 278
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15s";
    char *val = "QW QW QW QWQWQWQW QWQWQW";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_flags) {
#line 290
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-15.9s";
    char *val = "QW QW QW QWQWQWQW QWQWQW";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
#line 303
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s";
    char *val =
        "QW QW QW QWQWQWQW QWQWQW QW QW QW QWQWQWQW QWQWQW";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(test_one_string) {
#line 334
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%s", "gg dead inside"),
                     sprintf(str2, "%s", "gg dead inside"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
#line 345
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%s%s%s%s%s", "gg", " ", "dead", " ", "inside"),
        sprintf(str2, "%s%s%s%s%s", "gg", " ", "dead", " ", "inside"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_dec) {
#line 357
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_dec) {
#line 367
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                     sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_int) {
#line 378
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_int) {
#line 388
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                     sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_float) {
#line 399
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%f", 0.01),
                     sprintf(str2, "%f", 0.01));

    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(test_one_unsigned_dec) {
#line 422
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                     sprintf(str2, "%u", (unsigned)100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_unsigned_dec) {
#line 433
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                     sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                             (unsigned)666, (unsigned)100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_left) {
#line 445
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'),
                     sprintf(str2, "%8c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_right) {
#line 456
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                     sprintf(str2, "%-8c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(dermo1) {
#line 465
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(dermo2) {
#line 476
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% 5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int) {
#line 489
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%c";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(procent1) {
#line 501
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%%";
    // int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format),
                     sprintf(str2, format));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(procent2) {
#line 512
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "idfbg %% obyhg %d";
    int val = 5;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
    // c, d, i, f, s, u


    ///   Ошибки в s, u, f,
}
END_TEST

START_TEST(dermo3) {
#line 545
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%-20f", 0.00341231),
                     sprintf(str2, "%-20f", 0.00341231));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(govno5) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                     sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_float) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
        sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_unsigned_dec2) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                     sprintf(str2, "%u", (unsigned)100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_unsigned_dec2) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                     sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                             (unsigned)666, (unsigned)100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_left2) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'),
                     sprintf(str2, "%8c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char_with_alignment) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
        sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf1) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                    "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
        sprintf(str2, format, 'f', 21, 42, 666.666,
                "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(test_sprintf4) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-.1d";

    ck_assert_int_eq(s21_sprintf(str1, format, 111),
                     sprintf(str2, format, 111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf5) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple wide char %5c";
    char w = 'c';
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(one_many_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5.3c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s%s%s%s";
    char *val =
        "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    char *s1 = "";
    char *s2 = "87418347813748913749871389480913";
    char *s3 = "HAHAABOBASUCKER";
    ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                     sprintf(str2, format, val, s1, s2, s3));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width_huge) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *val = "kjafdiuhfjahfjdahf";
    char *format = "%120s";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(all_empty) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                     sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "abc as, 12 dasdasdasdasd"),
    sprintf(str2, "abc as, 12 dasdasdasdasd"));

    ck_assert_str_eq(str1, str2);
}
END_TEST


Suite *suite_sprintf(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, Baby_boom_za_shekoi_shepuchka);
    tcase_add_test(tc1_1, precise_int);
    tcase_add_test(tc1_1, width_int);
    tcase_add_test(tc1_1, plus_width_int);
    tcase_add_test(tc1_1, padding_int);
    tcase_add_test(tc1_1, flags_long_int);
    tcase_add_test(tc1_1, zero_precision_zero_int);
    tcase_add_test(tc1_1, unsigned_val);
    tcase_add_test(tc1_1, unsigned_val_width);
    tcase_add_test(tc1_1, unsigned_val_precision);
    tcase_add_test(tc1_1, unsigned_val_many_flags);
    tcase_add_test(tc1_1, unsigned_val_short);
    tcase_add_test(tc1_1, unsigned_val_long);
    tcase_add_test(tc1_1, test_one_char);
    tcase_add_test(tc1_1, test_many_char);
    tcase_add_test(tc1_1, one_flags);
    tcase_add_test(tc1_1, one_width);
    tcase_add_test(tc1_1, one_many);
    tcase_add_test(tc1_1, one_many_flags);
    tcase_add_test(tc1_1, string);
    tcase_add_test(tc1_1, string_precision);
    tcase_add_test(tc1_1, string_width);
    tcase_add_test(tc1_1, string_width_huge);
    tcase_add_test(tc1_1, string_flags);
    tcase_add_test(tc1_1, string_long);
    tcase_add_test(tc1_1, string_many);
    tcase_add_test(tc1_1, test_one_string);
    tcase_add_test(tc1_1, test_many_string);
    tcase_add_test(tc1_1, test_one_dec);
    tcase_add_test(tc1_1, test_many_dec);
    tcase_add_test(tc1_1, test_one_int);
    tcase_add_test(tc1_1, test_many_int);
    tcase_add_test(tc1_1, test_one_float);
    tcase_add_test(tc1_1, test_one_unsigned_dec);
    tcase_add_test(tc1_1, test_many_unsigned_dec);
    tcase_add_test(tc1_1, test_one_char_with_alignment_left);
    tcase_add_test(tc1_1, test_one_char_with_alignment_right);
    tcase_add_test(tc1_1, dermo1);
    tcase_add_test(tc1_1, dermo2);
    tcase_add_test(tc1_1, space_flag_int);
    tcase_add_test(tc1_1, procent1);
    tcase_add_test(tc1_1, procent2);
    tcase_add_test(tc1_1, dermo3);
    tcase_add_test(tc1_1, govno5);
    tcase_add_test(tc1_1, test_many_float);
    tcase_add_test(tc1_1, test_one_unsigned_dec2);
    tcase_add_test(tc1_1, test_many_unsigned_dec2);
    tcase_add_test(tc1_1, test_one_char_with_alignment_left2);
    tcase_add_test(tc1_1, test_many_char_with_alignment);
    tcase_add_test(tc1_1, test_sprintf1);
    tcase_add_test(tc1_1, test_sprintf4);
    tcase_add_test(tc1_1, test_sprintf5);
    tcase_add_test(tc1_1, all_empty);
    tcase_add_test(tc1_1, empty_format_and_parameters);
    return s1;
}
