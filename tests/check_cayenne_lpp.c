#include <stdlib.h>
#include <stdio.h>
#include <check.h>

#include "../cayenne_lpp.h"

cayenne_lpp_t lpp;

void setup(void)
{
    ck_assert_int_eq(lpp.cursor, 0);
}

void teardown(void)
{
    cayenne_lpp_reset(&lpp);
}

void _convert_buffer(cayenne_lpp_t *lpp, char *buffer)
{
    for (uint8_t i = 0; i < lpp->cursor; ++i) {
        sprintf(&buffer[i * 2], "%02X", lpp->buffer[i]);
    }
}

START_TEST(test_cayenne_lpp_init)
{
    ck_assert_int_eq(lpp.cursor, 0);
}
END_TEST

START_TEST(test_cayenne_lpp_reset)
{
    lpp.cursor = 10;
    ck_assert_int_eq(lpp.cursor, 10);
    cayenne_lpp_reset(&lpp);
    ck_assert_int_eq(lpp.cursor, 0);
}
END_TEST

START_TEST(test_cayenne_lpp_digital_input)
{
    cayenne_lpp_add_digital_input(&lpp, 0, 10);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_DIGITAL_INPUT_SIZE);
    char buffer[2 * CAYENNE_LPP_DIGITAL_INPUT_SIZE + 1];
    _convert_buffer(&lpp, buffer);
    ck_assert_str_eq(buffer, "00000A");
}
END_TEST

START_TEST(test_cayenne_lpp_digital_output)
{
    cayenne_lpp_add_digital_output(&lpp, 1, 25);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_DIGITAL_OUTPUT_SIZE);
    char buffer[2 * CAYENNE_LPP_DIGITAL_OUTPUT_SIZE + 1];
    _convert_buffer(&lpp, buffer);
    ck_assert_str_eq(buffer, "010119");
}
END_TEST

START_TEST(test_cayenne_lpp_analog_input)
{
    cayenne_lpp_add_analog_input(&lpp, 0, 5.2);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_ANALOG_INPUT_SIZE);
    char buffer[2 * CAYENNE_LPP_ANALOG_INPUT_SIZE + 1];
    _convert_buffer(&lpp, buffer);
    ck_assert_str_eq(buffer, "00020208");
}
END_TEST

START_TEST(test_cayenne_lpp_analog_output)
{
    cayenne_lpp_add_analog_output(&lpp, 1, 25.1);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_ANALOG_OUTPUT_SIZE);
    char buffer[2 * CAYENNE_LPP_ANALOG_OUTPUT_SIZE + 1];
    _convert_buffer(&lpp, buffer);
    ck_assert_str_eq(buffer, "010309CE");
}
END_TEST

START_TEST(test_cayenne_lpp_luminosity)
{
    cayenne_lpp_add_luminosity(&lpp, 10, 123);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_LUMINOSITY_SIZE);
    char buffer[2 * CAYENNE_LPP_LUMINOSITY_SIZE + 1];
    _convert_buffer(&lpp, buffer);
    ck_assert_str_eq(buffer, "0A65007B");
}
END_TEST

START_TEST(test_cayenne_lpp_presence)
{
    cayenne_lpp_add_presence(&lpp, 5, 1);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_PRESENCE_SIZE);
    char buffer[2 * CAYENNE_LPP_PRESENCE_SIZE + 1];
    _convert_buffer(&lpp, buffer);
    ck_assert_str_eq(buffer, "056601");
}
END_TEST

START_TEST(test_cayenne_lpp_temperature)
{
    ck_assert_int_eq(lpp.cursor, 0);
    cayenne_lpp_add_temperature(&lpp, 1, -4.1);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_TEMPERATURE_SIZE);
    char buffer[2 * CAYENNE_LPP_TEMPERATURE_SIZE + 1];
    _convert_buffer(&lpp, buffer);
    ck_assert_str_eq(buffer, "0167FFD7");
}
END_TEST

START_TEST(test_cayenne_lpp_relative_humidity)
{
    cayenne_lpp_add_relative_humidity(&lpp, 3, 48.5);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_RELATIVE_HUMIDITY_SIZE);
    char buffer[2 * CAYENNE_LPP_RELATIVE_HUMIDITY_SIZE + 1];
    _convert_buffer(&lpp, buffer);
    ck_assert_str_eq(buffer, "036861");
}
END_TEST

START_TEST(test_cayenne_lpp_barometric_pressure)
{
    cayenne_lpp_add_barometric_pressure(&lpp, 10, 996.23);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_BAROMETRIC_PRESSURE_SIZE);
    char buffer[2 * CAYENNE_LPP_BAROMETRIC_PRESSURE_SIZE + 1];
    _convert_buffer(&lpp, buffer);
    ck_assert_str_eq(buffer, "0A6726EA");
}
END_TEST

START_TEST(test_cayenne_lpp_accelerometer)
{
    ck_assert_int_eq(lpp.cursor, 0);
    cayenne_lpp_add_accelerometer(&lpp, 6, 1.234, -1.234, 0);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_ACCELEROMETER_SIZE);
    char buffer[2 * CAYENNE_LPP_ACCELEROMETER_SIZE + 1];
    _convert_buffer(&lpp, buffer);
    ck_assert_str_eq(buffer, "067104D2FB2E0000");
}
END_TEST

START_TEST(test_cayenne_lpp_gyrometer)
{
    cayenne_lpp_add_gyrometer(&lpp, 2, 5.3, 4.2, -2.3);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_GYROMETER_SIZE);
    char buffer[2 * CAYENNE_LPP_GYROMETER_SIZE + 1];
    _convert_buffer(&lpp, buffer);
    ck_assert_str_eq(buffer, "0286021201A3FF1A");
}
END_TEST

START_TEST(test_cayenne_lpp_gps)
{
    ck_assert_int_eq(lpp.cursor, 0);
    cayenne_lpp_add_gps(&lpp, 1, 42.3519, -87.9094, 10);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_GPS_SIZE);
    char buffer[2 * CAYENNE_LPP_GPS_SIZE + 1];
    _convert_buffer(&lpp, buffer);
    ck_assert_str_eq(buffer, "018806765EF2960A0003E8");
}
END_TEST

Suite * cayenne_lpp_suite(void)
{
    Suite *s;
    TCase *tc_lib;

    s = suite_create("cayenne_lpp");

    /* Cayenne LPP test case */
    tc_lib = tcase_create("Library");
    tcase_add_checked_fixture(tc_lib, setup, teardown);

    tcase_add_test(tc_lib, test_cayenne_lpp_init);
    tcase_add_test(tc_lib, test_cayenne_lpp_reset);
    tcase_add_test(tc_lib, test_cayenne_lpp_digital_input);
    tcase_add_test(tc_lib, test_cayenne_lpp_digital_output);
    tcase_add_test(tc_lib, test_cayenne_lpp_analog_input);
    tcase_add_test(tc_lib, test_cayenne_lpp_analog_output);
    tcase_add_test(tc_lib, test_cayenne_lpp_luminosity);
    tcase_add_test(tc_lib, test_cayenne_lpp_presence);
    tcase_add_test(tc_lib, test_cayenne_lpp_temperature);
    tcase_add_test(tc_lib, test_cayenne_lpp_relative_humidity);
    tcase_add_test(tc_lib, test_cayenne_lpp_barometric_pressure);
    tcase_add_test(tc_lib, test_cayenne_lpp_accelerometer);
    tcase_add_test(tc_lib, test_cayenne_lpp_gyrometer);
    tcase_add_test(tc_lib, test_cayenne_lpp_gps);
    suite_add_tcase(s, tc_lib);

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
