#include <stdlib.h>
#include <check.h>

#include "../cayenne_lpp.h"

START_TEST(test_cayenne_lpp_init)
{
    cayenne_lpp_t lpp = { 0 };
    ck_assert_int_eq(lpp.cursor, 0);
}
END_TEST

START_TEST(test_cayenne_lpp_reset)
{
    cayenne_lpp_t lpp = { 0 };
    lpp.cursor = 10;
    ck_assert_int_eq(lpp.cursor, 10);
    cayenne_lpp_reset(&lpp);
    ck_assert_int_eq(lpp.cursor, 0);
}
END_TEST

Suite * cayenne_lpp_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("cayenne_lpp");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_cayenne_lpp_init);
    tcase_add_test(tc_core, test_cayenne_lpp_reset);
    suite_add_tcase(s, tc_core);

    return s;
}

 int main(void)
 {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = cayenne_lpp_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
 }
