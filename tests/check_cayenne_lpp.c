#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
    uint8_t buffer[CAYENNE_LPP_DIGITAL_INPUT_SIZE] = { 0x00, 0x00, 0x0A };
    ck_assert_int_eq(memcmp(lpp.buffer,
                     buffer, CAYENNE_LPP_DIGITAL_INPUT_SIZE), 0);
}
END_TEST

START_TEST(test_cayenne_lpp_digital_output)
{
    cayenne_lpp_add_digital_output(&lpp, 1, 25);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_DIGITAL_OUTPUT_SIZE);
    char buffer[CAYENNE_LPP_DIGITAL_OUTPUT_SIZE] = { 0x01, 0x01, 0x19 };
    ck_assert_int_eq(memcmp(lpp.buffer,
                            buffer, CAYENNE_LPP_DIGITAL_OUTPUT_SIZE), 0);
}
END_TEST

START_TEST(test_cayenne_lpp_analog_input)
{
    cayenne_lpp_add_analog_input(&lpp, 0, 5.2);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_ANALOG_INPUT_SIZE);
    char buffer[CAYENNE_LPP_ANALOG_INPUT_SIZE] = { 0x00, 0x02, 0x02, 0x08 };
    ck_assert_int_eq(memcmp(lpp.buffer,
                            buffer, CAYENNE_LPP_ANALOG_INPUT_SIZE), 0);
}
END_TEST

START_TEST(test_cayenne_lpp_analog_output)
{
    cayenne_lpp_add_analog_output(&lpp, 1, 25.1);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_ANALOG_OUTPUT_SIZE);
    char buffer[CAYENNE_LPP_ANALOG_OUTPUT_SIZE] = { 0x01, 0x03, 0x09, 0xCE };
    ck_assert_int_eq(memcmp(lpp.buffer,
                            buffer, CAYENNE_LPP_ANALOG_OUTPUT_SIZE), 0);
}
END_TEST

START_TEST(test_cayenne_lpp_luminosity)
{
    cayenne_lpp_add_luminosity(&lpp, 10, 123);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_LUMINOSITY_SIZE);
    char buffer[CAYENNE_LPP_LUMINOSITY_SIZE] = { 0x0A, 0x65, 0x00, 0x7B };
    ck_assert_int_eq(memcmp(lpp.buffer,
                            buffer, CAYENNE_LPP_LUMINOSITY_SIZE), 0);
}
END_TEST

START_TEST(test_cayenne_lpp_presence)
{
    cayenne_lpp_add_presence(&lpp, 5, 1);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_PRESENCE_SIZE);
    char buffer[CAYENNE_LPP_PRESENCE_SIZE] = { 0x05, 0x66, 0x01 };
    ck_assert_int_eq(memcmp(lpp.buffer,
                            buffer, CAYENNE_LPP_PRESENCE_SIZE), 0);
}
END_TEST

START_TEST(test_cayenne_lpp_temperature)
{
    ck_assert_int_eq(lpp.cursor, 0);
    cayenne_lpp_add_temperature(&lpp, 1, -4.1);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_TEMPERATURE_SIZE);
    char buffer[CAYENNE_LPP_TEMPERATURE_SIZE] = { 0x01, 0x67, 0xFF, 0xD7 };
    ck_assert_int_eq(memcmp(lpp.buffer,
                            buffer, CAYENNE_LPP_TEMPERATURE_SIZE), 0);
}
END_TEST

START_TEST(test_cayenne_lpp_relative_humidity)
{
    cayenne_lpp_add_relative_humidity(&lpp, 3, 48.5);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_RELATIVE_HUMIDITY_SIZE);
    char buffer[CAYENNE_LPP_RELATIVE_HUMIDITY_SIZE] = { 0x03, 0x68, 0x61 };
    ck_assert_int_eq(memcmp(lpp.buffer,
                            buffer, CAYENNE_LPP_RELATIVE_HUMIDITY_SIZE), 0);
}
END_TEST

START_TEST(test_cayenne_lpp_barometric_pressure)
{
    cayenne_lpp_add_barometric_pressure(&lpp, 10, 996.23);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_BAROMETRIC_PRESSURE_SIZE);
    char buffer[CAYENNE_LPP_BAROMETRIC_PRESSURE_SIZE] = { 0x0A, 0x67, 0x26, 0xEA };
    ck_assert_int_eq(memcmp(lpp.buffer,
                            buffer, CAYENNE_LPP_BAROMETRIC_PRESSURE_SIZE), 0);
}
END_TEST

START_TEST(test_cayenne_lpp_accelerometer)
{
    ck_assert_int_eq(lpp.cursor, 0);
    cayenne_lpp_add_accelerometer(&lpp, 6, 1.234, -1.234, 0);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_ACCELEROMETER_SIZE);
    char buffer[CAYENNE_LPP_ACCELEROMETER_SIZE] = { 0x06, 0x71, 0x04, 0xD2, \
                                                    0xFB, 0x2E, 0x00, 0x00 };
    ck_assert_int_eq(memcmp(lpp.buffer,
                            buffer, CAYENNE_LPP_ACCELEROMETER_SIZE), 0);
}
END_TEST

START_TEST(test_cayenne_lpp_gyrometer)
{
    cayenne_lpp_add_gyrometer(&lpp, 2, 5.3, 4.2, -2.3);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_GYROMETER_SIZE);
    char buffer[CAYENNE_LPP_GYROMETER_SIZE] = { 0x02, 0x86, 0x02, 0x12, \
                                                0x01, 0xA3, 0xFF, 0x1A };
    ck_assert_int_eq(memcmp(lpp.buffer,
                            buffer, CAYENNE_LPP_GYROMETER_SIZE), 0);
}
END_TEST

START_TEST(test_cayenne_lpp_gps)
{
    ck_assert_int_eq(lpp.cursor, 0);
    cayenne_lpp_add_gps(&lpp, 1, 42.3519, -87.9094, 10);
    ck_assert_int_eq(lpp.cursor, CAYENNE_LPP_GPS_SIZE);
    char buffer[CAYENNE_LPP_GPS_SIZE] = { 0x01, 0x88, 0x06, 0x76, \
                                          0x5E, 0xF2, 0x96, 0x0A, \
                                          0x00, 0x03, 0xE8 };
    ck_assert_int_eq(memcmp(lpp.buffer,
                            buffer, CAYENNE_LPP_GPS_SIZE), 0);
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
