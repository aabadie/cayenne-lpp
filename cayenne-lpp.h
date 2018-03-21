/*
 * Copyright (C) 2018 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @brief       Cayenne LPP interface
 *
 * @author      Alexandre Abadie <alexandre.abadie@inria.fr>
 */

#ifndef CAYENNE_LPP_H
#define CAYENNE_LPP_H

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CAYENNE_LPP_MAX_BUFFER_SIZE
#define CAYENNE_LPP_MAX_BUFFER_SIZE          (42U)
#endif

/**
 * @name Cayenne LPP data type
 * @{
 */
#define CAYENNE_LPP_DIGITAL_INPUT            (0U)   /* 1 byte */
#define CAYENNE_LPP_DIGITAL_OUTPUT           (1U)   /* 1 byte */
#define CAYENNE_LPP_ANALOG_INPUT             (2U)   /* 2 bytes, 0.01 signed */
#define CAYENNE_LPP_ANALOG_OUTPUT            (3U)   /* 2 bytes, 0.01 signed */
#define CAYENNE_LPP_LUMINOSITY               (101U) /* 2 bytes, 1 lux unsigned */
#define CAYENNE_LPP_PRESENCE                 (102U) /* 1 byte, 1 */
#define CAYENNE_LPP_TEMPERATURE              (103U) /* 2 bytes, 0.1°C signed */
#define CAYENNE_LPP_RELATIVE_HUMIDITY        (104U) /* 1 byte, 0.5% unsigned */
#define CAYENNE_LPP_ACCELEROMETER            (113U) /* 2 bytes per axis, 0.001G */
#define CAYENNE_LPP_BAROMETRIC_PRESSURE      (115U) /* 2 bytes 0.1 hPa Unsigned */
#define CAYENNE_LPP_GYROMETER                (134U) /* 2 bytes per axis, 0.01 °/s */
#define CAYENNE_LPP_GPS                      (136U) /* 3 byte lon/lat 0.0001 °, 3 bytes alt 0.01 meter */
/** @} */

/**
 * @name Cayenne LPP data type
 *
 * @note Data ID + Data Type + Data Size
 * @{
 */
#define CAYENNE_LPP_DIGITAL_INPUT_SIZE       (3U)   /* 1 byte */
#define CAYENNE_LPP_DIGITAL_OUTPUT_SIZE      (3U)   /* 1 byte */
#define CAYENNE_LPP_ANALOG_INPUT_SIZE        (4U)   /* 2 bytes, 0.01 signed */
#define CAYENNE_LPP_ANALOG_OUTPUT_SIZE       (4U)   /* 2 bytes, 0.01 signed */
#define CAYENNE_LPP_LUMINOSITY_SIZE          (4U)   /* 2 bytes, 1 lux unsigned */
#define CAYENNE_LPP_PRESENCE_SIZE            (3U)   /* 1 byte, 1 */
#define CAYENNE_LPP_TEMPERATURE_SIZE         (4U)   /* 2 bytes, 0.1°C signed */
#define CAYENNE_LPP_RELATIVE_HUMIDITY_SIZE   (3U)   /* 1 byte, 0.5% unsigned */
#define CAYENNE_LPP_ACCELEROMETER_SIZE       (8U)   /* 2 bytes per axis, 0.001G */
#define CAYENNE_LPP_BAROMETRIC_PRESSURE_SIZE (4U)   /* 2 bytes 0.1 hPa Unsigned */
#define CAYENNE_LPP_GYROMETER_SIZE           (8U)   /* 2 bytes per axis, 0.01 °/s */
#define CAYENNE_LPP_GPS_SIZE                 (11U)  /* 3 byte lon/lat 0.0001 °, 3 bytes alt 0.01 meter */
/** @} */

/**
 * @brief Cayenne LPP descriptor
 */
typedef struct {
    uint8_t buffer[CAYENNE_LPP_MAX_BUFFER_SIZE];    /**< payload buffer */
    uint8_t cursor;                                 /**< current position in buffer */
} cayenne_lpp_t;

void cayenne_lpp_reset(cayenne_lpp_t *lpp);
void cayenne_lpp_add_digital_input(cayenne_lpp_t *lpp, uint8_t channel, uint8_t value);
void cayenne_lpp_add_digital_output(cayenne_lpp_t *lpp, uint8_t channel, uint8_t value);
void cayenne_lpp_add_analog_input(cayenne_lpp_t *lpp, uint8_t channel, float value);
void cayenne_lpp_add_analog_output(cayenne_lpp_t *lpp, uint8_t channel, float value);
void cayenne_lpp_add_luminosity(cayenne_lpp_t *lpp, uint8_t channel, uint16_t lux);
void cayenne_lpp_add_presence(cayenne_lpp_t *lpp, uint8_t channel, uint8_t value);
void cayenne_lpp_add_temperature(cayenne_lpp_t *lpp, uint8_t channel, float celsius);
void cayenne_lpp_add_relative_humidity(cayenne_lpp_t *lpp, uint8_t channel, float rh);
void cayenne_lpp_add_accelerometer(cayenne_lpp_t *lpp, uint8_t channel, float x, float y, float z);
void cayenne_lpp_add_barometric_pressure(cayenne_lpp_t *lpp, uint8_t channel, float hpa);
void cayenne_lpp_add_gyrometer(cayenne_lpp_t *lpp, uint8_t channel, float x, float y, float z);
void cayenne_lpp_add_gps(cayenne_lpp_t *lpp, uint8_t channel, float latitude, float longitude, float meters);

#ifdef __cplusplus
}
#endif

#endif /* CAYENNE_LPP_H */
