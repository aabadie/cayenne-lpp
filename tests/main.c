/*
 * Copyright (C) 2018 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @brief       Cayenne LPP test application
 *
 * @author      Alexandre Abadie <alexandre.abadie@inria.fr>
 */

#include <stdio.h>

#include "cayenne_lpp.h"

static cayenne_lpp_t lpp;

static void _print_buffer(void)
{
    for (uint8_t i = 0; i < lpp.cursor; ++i) {
        printf("%02X ", lpp.buffer[i]);
    }
    puts("");
}

int test_lpp_cayenne(void)
{
    cayenne_lpp_add_temperature(&lpp, 1, 22.5);
    cayenne_lpp_add_barometric_pressure(&lpp, 2, 1072.21);
    cayenne_lpp_add_relative_humidity(&lpp, 3, 42.5);
    cayenne_lpp_add_luminosity(&lpp, 4, 300);
    cayenne_lpp_add_gps(&lpp, 5, 52.37365, 4.88650, 2);

    printf("Buffer 1:\n");
    _print_buffer();
    puts("----------------------------------");

    cayenne_lpp_reset(&lpp);

    cayenne_lpp_add_digital_input(&lpp, 1, 42);
    cayenne_lpp_add_digital_output(&lpp, 1, 123);
    cayenne_lpp_add_analog_input(&lpp, 1, 0.01);
    cayenne_lpp_add_analog_output(&lpp, 1, 0.05);

    printf("Buffer 2:\n");
    _print_buffer();
    puts("----------------------------------");

    cayenne_lpp_reset(&lpp);

    cayenne_lpp_add_presence(&lpp, 1, 1);
    cayenne_lpp_add_accelerometer(&lpp, 3, 0.5, 0.42, 0.1);
    cayenne_lpp_add_gyrometer(&lpp, 4, 0.3, 0.4, 0.5);

    printf("Buffer 3:\n");
    _print_buffer();
    puts("----------------------------------");

    cayenne_lpp_reset(&lpp);
    printf("Empty buffer:\n");
    _print_buffer();

    return 0;
}

int main(void)
{
    int ret = 1;
    ret = test_lpp_cayenne();
    return ret;
}