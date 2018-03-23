/*
 * Copyright (C) 2018 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    cayenne-lpp Interface of the Cayenne LPP library in C
 * @brief       Interface of the C library for generating Cayenne LPP
 * @{
 * @file
 * @brief       Cayenne LPP interface and definitions
 *
 * @author      Alexandre Abadie <alexandre.abadie@inria.fr>
 */

#ifndef CAYENNE_LPP_H
#define CAYENNE_LPP_H

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Max Cayenne LPP buffer size allowed
 */
#ifndef CAYENNE_LPP_MAX_BUFFER_SIZE
#define CAYENNE_LPP_MAX_BUFFER_SIZE          (42U)
#endif

/**
 * @name Cayenne LPP data type
 * @{
 */
#define CAYENNE_LPP_DIGITAL_INPUT            (0U)   /**< 1 byte */
#define CAYENNE_LPP_DIGITAL_OUTPUT           (1U)   /**< 1 byte */
#define CAYENNE_LPP_ANALOG_INPUT             (2U)   /**< 2 bytes, 0.01 signed */
#define CAYENNE_LPP_ANALOG_OUTPUT            (3U)   /**< 2 bytes, 0.01 signed */
#define CAYENNE_LPP_LUMINOSITY               (101U) /**< 2 bytes, 1 lux unsigned */
#define CAYENNE_LPP_PRESENCE                 (102U) /**< 1 byte, 1 */
#define CAYENNE_LPP_TEMPERATURE              (103U) /**< 2 bytes, 0.1°C signed */
#define CAYENNE_LPP_RELATIVE_HUMIDITY        (104U) /**< 1 byte, 0.5% unsigned */
#define CAYENNE_LPP_ACCELEROMETER            (113U) /**< 2 bytes per axis, 0.001G */
#define CAYENNE_LPP_BAROMETRIC_PRESSURE      (115U) /**< 2 bytes 0.1 hPa Unsigned */
#define CAYENNE_LPP_GYROMETER                (134U) /**< 2 bytes per axis, 0.01 °/s */
#define CAYENNE_LPP_GPS                      (136U) /**< 3 byte lon/lat 0.0001 °, 3 bytes alt 0.01 meter */
/** @} */

/**
 * @name Cayenne LPP data size
 *
 * @note Contains Data ID + Data Type + Data Size
 * @{
 */
#define CAYENNE_LPP_DIGITAL_INPUT_SIZE       (3U)   /**< 1 byte */
#define CAYENNE_LPP_DIGITAL_OUTPUT_SIZE      (3U)   /**< 1 byte */
#define CAYENNE_LPP_ANALOG_INPUT_SIZE        (4U)   /**< 2 bytes, 0.01 signed */
#define CAYENNE_LPP_ANALOG_OUTPUT_SIZE       (4U)   /**< 2 bytes, 0.01 signed */
#define CAYENNE_LPP_LUMINOSITY_SIZE          (4U)   /**< 2 bytes, 1 lux unsigned */
#define CAYENNE_LPP_PRESENCE_SIZE            (3U)   /**< 1 byte, 1 */
#define CAYENNE_LPP_TEMPERATURE_SIZE         (4U)   /**< 2 bytes, 0.1°C signed */
#define CAYENNE_LPP_RELATIVE_HUMIDITY_SIZE   (3U)   /**< 1 byte, 0.5% unsigned */
#define CAYENNE_LPP_ACCELEROMETER_SIZE       (8U)   /**< 2 bytes per axis, 0.001G */
#define CAYENNE_LPP_BAROMETRIC_PRESSURE_SIZE (4U)   /**< 2 bytes 0.1 hPa Unsigned */
#define CAYENNE_LPP_GYROMETER_SIZE           (8U)   /**< 2 bytes per axis, 0.01 °/s */
#define CAYENNE_LPP_GPS_SIZE                 (11U)  /**< 3 byte lon/lat 0.0001 °, 3 bytes alt 0.01 meter */
/** @} */

/**
 * @brief Cayenne LPP descriptor
 */
typedef struct {
    uint8_t buffer[CAYENNE_LPP_MAX_BUFFER_SIZE];    /**< payload buffer */
    uint8_t cursor;                                 /**< current position in buffer */
} cayenne_lpp_t;

/**
 * @brief Clears the lpp buffer and reset the cursor
 *
 * @param[in] lpp          the cayenne lpp descriptor
 */
void cayenne_lpp_reset(cayenne_lpp_t *lpp);

/**
 * @brief Add an encoded digital input value to the buffer
 *
 * @param[in] lpp          the cayenne lpp descriptor
 * @param[in] channel      the data channel
 * @param[in] value        the digital input value
 */
void cayenne_lpp_add_digital_input(cayenne_lpp_t *lpp, uint8_t channel,
                                   uint8_t value);

/**
 * @brief Add an encoded digital output value to the buffer
 *
 * @param[in] lpp          the cayenne lpp descriptor
 * @param[in] channel      the data channel
 * @param[in] value        the digital output value
 */
void cayenne_lpp_add_digital_output(cayenne_lpp_t *lpp, uint8_t channel,
                                    uint8_t value);

/**
 * @brief Add an encoded analog input value to the buffer
 *
 * @param[in] lpp          the cayenne lpp descriptor
 * @param[in] channel      the data channel
 * @param[in] value        the analog input value
 */
void cayenne_lpp_add_analog_input(cayenne_lpp_t *lpp, uint8_t channel,
                                  float value);

/**
 * @brief Add an encoded analog output value to the buffer
 *
 * @param[in] lpp          the cayenne lpp descriptor
 * @param[in] channel      the data channel
 * @param[in] value        the analog output value
 */
void cayenne_lpp_add_analog_output(cayenne_lpp_t *lpp, uint8_t channel,
                                   float value);

/**
 * @brief Add an encoded luminosity value to the buffer
 *
 * @param[in] lpp          the cayenne lpp descriptor
 * @param[in] channel      the data channel
 * @param[in] lux          the luminosity value in lux
 */
void cayenne_lpp_add_luminosity(cayenne_lpp_t *lpp, uint8_t channel,
                                uint16_t lux);

/**
 * @brief Add an encoded presence value to the buffer
 *
 * @param[in] lpp          the cayenne lpp descriptor
 * @param[in] channel      the data channel
 * @param[in] value        the presence value
 */
void cayenne_lpp_add_presence(cayenne_lpp_t *lpp, uint8_t channel,
                              uint8_t value);

/**
 * @brief Add an encoded temperature value to the buffer
 *
 * @param[in] lpp          the cayenne lpp descriptor
 * @param[in] channel      the data channel
 * @param[in] celsius      the temperature in celsius (1 digit precision)
 */
void cayenne_lpp_add_temperature(cayenne_lpp_t *lpp, uint8_t channel,
                                 float celsius);

/**
 * @brief Add an encoded relative humidity value to the buffer
 *
 * @param[in] lpp          the cayenne lpp descriptor
 * @param[in] channel      the data channel
 * @param[in] rh           the relative humidity value (in %)
 */
void cayenne_lpp_add_relative_humidity(cayenne_lpp_t *lpp, uint8_t channel,
                                       float rh);

/**
 * @brief Add an encoded accelerometer value to the buffer
 *
 * @param[in] lpp          the cayenne lpp descriptor
 * @param[in] channel      the data channel
 * @param[in] x            the acceloremeter value in X axis
 * @param[in] y            the acceloremeter value in Y axis
 * @param[in] z            the acceloremeter value in Z axis
 */
void cayenne_lpp_add_accelerometer(cayenne_lpp_t *lpp, uint8_t channel,
                                   float x, float y, float z);

/**
 * @brief Add an encoded barometric pressure value to the buffer
 *
 * @param[in] lpp          the cayenne lpp descriptor
 * @param[in] channel      the data channel
 * @param[in] hpa          the barometric pressure value in HPa
 */
void cayenne_lpp_add_barometric_pressure(cayenne_lpp_t *lpp, uint8_t channel,
                                         float hpa);

/**
 * @brief Add an encoded gyrometer value to the buffer
 *
 * @param[in] lpp          the cayenne lpp descriptor
 * @param[in] channel      the data channel
 * @param[in] x            the gyrometer value in X axis
 * @param[in] y            the gyrometer value in Y axis
 * @param[in] z            the gyrometer value in Z axis
 */
void cayenne_lpp_add_gyrometer(cayenne_lpp_t *lpp, uint8_t channel,
                               float x, float y, float z);

/**
 * @brief Add an encoded gps value to the buffer
 *
 * @param[in] lpp          the cayenne lpp descriptor
 * @param[in] channel      the data channel
 * @param[in] latitude     the latitude
 * @param[in] longitude    the longitude
 * @param[in] meters       the altitude in meters
 */
void cayenne_lpp_add_gps(cayenne_lpp_t *lpp, uint8_t channel,
                         float latitude, float longitude, float meters);

#ifdef __cplusplus
}
#endif

#endif /* CAYENNE_LPP_H */
/** @} */
