/*
 * Copyright (C) 2018 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @brief       Cayenne LPP implementation
 *
 * @author      Alexandre Abadie <alexandre.abadie@inria.fr>
 */

#include <inttypes.h>
#include <assert.h>
#include <string.h>

#include "cayenne-lpp.h"

void cayenne_lpp_reset(cayenne_lpp_t *lpp)
{
    memset(lpp->buffer, 0, CAYENNE_LPP_MAX_BUFFER_SIZE);
    lpp->cursor = 0;
}

void cayenne_lpp_add_digital_input(cayenne_lpp_t *lpp, uint8_t channel, uint8_t value)
{
    assert((lpp->cursor + CAYENNE_LPP_DIGITAL_INPUT_SIZE) < CAYENNE_LPP_MAX_BUFFER_SIZE);

    lpp->buffer[lpp->cursor++] = channel;
    lpp->buffer[lpp->cursor++] = CAYENNE_LPP_DIGITAL_INPUT;
    lpp->buffer[lpp->cursor++] = value;
}

void cayenne_lpp_add_digital_output(cayenne_lpp_t *lpp, uint8_t channel, uint8_t value)
{
    assert((lpp->cursor + CAYENNE_LPP_DIGITAL_OUTPUT_SIZE) < CAYENNE_LPP_MAX_BUFFER_SIZE);

    lpp->buffer[lpp->cursor++] = channel;
    lpp->buffer[lpp->cursor++] = CAYENNE_LPP_DIGITAL_OUTPUT;
    lpp->buffer[lpp->cursor++] = value;
}

void cayenne_lpp_add_analog_input(cayenne_lpp_t *lpp, uint8_t channel, float value)
{
    assert((lpp->cursor + CAYENNE_LPP_ANALOG_INPUT_SIZE) < CAYENNE_LPP_MAX_BUFFER_SIZE);

    int16_t val = value * 100;
    lpp->buffer[lpp->cursor++] = channel;
    lpp->buffer[lpp->cursor++] = CAYENNE_LPP_ANALOG_INPUT;
    lpp->buffer[lpp->cursor++] = val >> 8;
    lpp->buffer[lpp->cursor++] = val;
}

void cayenne_lpp_add_analog_output(cayenne_lpp_t *lpp, uint8_t channel, float value)
{
    assert((lpp->cursor + CAYENNE_LPP_ANALOG_OUTPUT_SIZE) < CAYENNE_LPP_MAX_BUFFER_SIZE);

    int16_t val = value * 100;
    lpp->buffer[lpp->cursor++] = channel;
    lpp->buffer[lpp->cursor++] = CAYENNE_LPP_ANALOG_OUTPUT;
    lpp->buffer[lpp->cursor++] = val >> 8;
    lpp->buffer[lpp->cursor++] = val;
}

void cayenne_lpp_add_luminosity(cayenne_lpp_t *lpp, uint8_t channel, uint16_t lux)
{
    assert((lpp->cursor + CAYENNE_LPP_LUMINOSITY_SIZE) < CAYENNE_LPP_MAX_BUFFER_SIZE);

    lpp->buffer[lpp->cursor++] = channel;
    lpp->buffer[lpp->cursor++] = CAYENNE_LPP_LUMINOSITY;
    lpp->buffer[lpp->cursor++] = lux >> 8;
    lpp->buffer[lpp->cursor++] = lux;
}

void cayenne_lpp_add_presence(cayenne_lpp_t *lpp, uint8_t channel, uint8_t value)
{
    assert((lpp->cursor + CAYENNE_LPP_PRESENCE_SIZE) < CAYENNE_LPP_MAX_BUFFER_SIZE);

    lpp->buffer[lpp->cursor++] = channel;
    lpp->buffer[lpp->cursor++] = CAYENNE_LPP_PRESENCE;
    lpp->buffer[lpp->cursor++] = value;
}

void cayenne_lpp_add_temperature(cayenne_lpp_t *lpp, uint8_t channel, float celsius)
{
    assert((lpp->cursor + CAYENNE_LPP_TEMPERATURE_SIZE) < CAYENNE_LPP_MAX_BUFFER_SIZE);

    int16_t val = celsius * 10;
    lpp->buffer[lpp->cursor++] = channel;
    lpp->buffer[lpp->cursor++] = CAYENNE_LPP_TEMPERATURE;
    lpp->buffer[lpp->cursor++] = val >> 8;
    lpp->buffer[lpp->cursor++] = val;
}

void cayenne_lpp_add_relative_humidity(cayenne_lpp_t *lpp, uint8_t channel, float rh)
{
    assert((lpp->cursor + CAYENNE_LPP_RELATIVE_HUMIDITY_SIZE) < CAYENNE_LPP_MAX_BUFFER_SIZE);

    uint8_t val = rh * 2;
    lpp->buffer[lpp->cursor++] = channel;
    lpp->buffer[lpp->cursor++] = CAYENNE_LPP_RELATIVE_HUMIDITY;
    lpp->buffer[lpp->cursor++] = val;
}

void cayenne_lpp_add_accelerometer(cayenne_lpp_t *lpp, uint8_t channel, float x, float y, float z)
{
    assert((lpp->cursor + CAYENNE_LPP_ACCELEROMETER_SIZE) < CAYENNE_LPP_MAX_BUFFER_SIZE);

    int16_t vx = x * 1000;
    int16_t vy = y * 1000;
    int16_t vz = z * 1000;

    lpp->buffer[lpp->cursor++] = channel;
    lpp->buffer[lpp->cursor++] = CAYENNE_LPP_ACCELEROMETER;
    lpp->buffer[lpp->cursor++] = vx >> 8;
    lpp->buffer[lpp->cursor++] = vx;
    lpp->buffer[lpp->cursor++] = vy >> 8;
    lpp->buffer[lpp->cursor++] = vy;
    lpp->buffer[lpp->cursor++] = vz >> 8;
    lpp->buffer[lpp->cursor++] = vz;
}

void cayenne_lpp_add_barometric_pressure(cayenne_lpp_t *lpp, uint8_t channel, float hpa)
{
    assert((lpp->cursor + CAYENNE_LPP_BAROMETRIC_PRESSURE_SIZE) < CAYENNE_LPP_MAX_BUFFER_SIZE);

    int16_t val = hpa * 10;
    lpp->buffer[lpp->cursor++] = channel;
    lpp->buffer[lpp->cursor++] = CAYENNE_LPP_TEMPERATURE;
    lpp->buffer[lpp->cursor++] = val >> 8;
    lpp->buffer[lpp->cursor++] = val;
}

void cayenne_lpp_add_gyrometer(cayenne_lpp_t *lpp, uint8_t channel, float x, float y, float z)
{
    assert((lpp->cursor + CAYENNE_LPP_GYROMETER_SIZE) < CAYENNE_LPP_MAX_BUFFER_SIZE);

    int16_t vx = x * 100;
    int16_t vy = y * 100;
    int16_t vz = z * 100;

    lpp->buffer[lpp->cursor++] = channel;
    lpp->buffer[lpp->cursor++] = CAYENNE_LPP_GYROMETER;
    lpp->buffer[lpp->cursor++] = vx >> 8;
    lpp->buffer[lpp->cursor++] = vx;
    lpp->buffer[lpp->cursor++] = vy >> 8;
    lpp->buffer[lpp->cursor++] = vy;
    lpp->buffer[lpp->cursor++] = vz >> 8;
    lpp->buffer[lpp->cursor++] = vz;
}

void cayenne_lpp_add_gps(cayenne_lpp_t *lpp, uint8_t channel, float latitude, float longitude, float meters)
{
    assert((lpp->cursor + CAYENNE_LPP_GPS_SIZE) < CAYENNE_LPP_MAX_BUFFER_SIZE);

    int32_t lat = latitude * 10000;
    int32_t lon = longitude * 10000;
    int32_t alt = meters * 100;

    lpp->buffer[lpp->cursor++] = channel;
    lpp->buffer[lpp->cursor++] = CAYENNE_LPP_GPS;

    lpp->buffer[lpp->cursor++] = lat >> 16;
    lpp->buffer[lpp->cursor++] = lat >> 8;
    lpp->buffer[lpp->cursor++] = lat;
    lpp->buffer[lpp->cursor++] = lon >> 16;
    lpp->buffer[lpp->cursor++] = lon >> 8;
    lpp->buffer[lpp->cursor++] = lon;
    lpp->buffer[lpp->cursor++] = alt >> 16;
    lpp->buffer[lpp->cursor++] = alt >> 8;
    lpp->buffer[lpp->cursor++] = alt;
}
