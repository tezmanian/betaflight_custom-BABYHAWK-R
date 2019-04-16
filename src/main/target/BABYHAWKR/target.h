/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#undef USE_DSHOT_DMAR           // OMNIBUS (F3) does not benefit from burst Dshot
#undef USE_GYRO_OVERFLOW_CHECK

#define TARGET_BOARD_IDENTIFIER "OMNI" // https://en.wikipedia.org/wiki/Omnibus

#define LED0_PIN                PB3

#define USE_BEEPER
#define BEEPER_PIN              PC15
#define BEEPER_INVERTED

#define USE_EXTI
#define USE_GYRO_EXTI
#define GYRO_1_EXTI_PIN         PC13
#define USE_MPU_DATA_READY_SIGNAL

#define GYRO_1_SPI_INSTANCE     SPI1
#define GYRO_1_CS_PIN           PA4

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define GYRO_1_ALIGN            CW90_DEG

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define ACC_1_ALIGN             CW90_DEG

#undef USE_BARO
#undef USE_BARO_BMP280
#undef USE_BARO_SPI_BMP280

#undef USE_MAG
#undef USE_VTX_COMMON

#undef USE_PPM
#undef USE_PWM
#undef USE_SERIALRX_CRSF
#undef USE_SERIALRX_IBUS
#undef USE_SERIALRX_JETIEXBUS
#undef USE_SERIALRX_SPEKTRUM
#undef USE_SERIALRX_SUMD
#undef USE_SERIALRX_SUMH
#undef USE_SERIALRX_XBUS

#undef USE_CRSF_CMS_TELEMETRY
#undef USE_TELEMETRY_CRSF
#undef USE_TELEMETRY_HOTT
#undef USE_TELEMETRY_IBUS
#undef USE_TELEMETRY_IBUS_EXTENDED
#undef USE_TELEMETRY_JETIEXBUS
#undef USE_TELEMETRY_LTM
#undef USE_TELEMETRY_MAVLINK
#undef USE_TELEMETRY_SRXL
#undef USE_TELEMETRY_FRSKY_HUB
#undef USE_TELEMETRY_SMARTPORT

#undef USE_SERIALRX_FPORT
#define USE_SERIALRX_SBUS
#undef USE_LED_STRIP

#define USE_GYRO_LPF2

#undef GPS
#undef USE_GPS_NMEA
#undef USE_GPS_UBLOX
#undef USE_GPS_RESCUE

#undef USE_BLACKBOX
#undef USE_TELEMETRY

#define USE_LAUNCH_CONTROL
#define USE_DYN_LPF
#define USE_D_MIN

#define USE_THROTTLE_BOOST
#define USE_INTEGRATED_YAW_CONTROL

#define USE_ITERM_RELAX
#define USE_RC_SMOOTHING_FILTER
#define USE_THRUST_LINEARIZATION
#define USE_TPA_MODE

#define USE_ACRO_TRAINER
#define USE_AIRMODE_LPF
#define USE_DASHBOARD
#define USE_OSD
#define USE_OSD_OVER_MSP_DISPLAYPORT
#define USE_ABSOLUTE_CONTROL
#define USE_OSD_PROFILES
#define USE_OSD_STICK_OVERLAY
#define USE_SMART_FEEDFORWARD
#define USE_RC_SMOOTHING_FILTER

#undef USE_SERVOS
#undef USE_BRUSHED_ESC_AUTODETECT
//#define USE_RANGEFINDER
//#define USE_RANGEFINDER_HCSR04
//#define RANGEFINDER_HCSR04_ECHO_PIN          PB1
//#define RANGEFINDER_HCSR04_TRIGGER_PIN       PB0

#define USB_DETECT_PIN          PB5

#define USE_VCP
#define USE_UART1
#define USE_UART2
#define USE_UART3
#define USE_SOFTSERIAL1
#define USE_SOFTSERIAL2

#define SERIAL_PORT_COUNT       6

#define UART1_TX_PIN            PA9
#define UART1_RX_PIN            PA10

#define UART2_TX_PIN            PA14 // PA14 / SWCLK
#define UART2_RX_PIN            PA15

#define UART3_TX_PIN            PB10 // PB10 (PWM5)
#define UART3_RX_PIN            PB11 // PB11 (PWM6)

#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C1_SCL                NONE // PB6 (PWM8)
#define I2C1_SDA                NONE // PB7 (PWM7)
#define I2C_DEVICE              (I2CDEV_1)

#define USE_ESCSERIAL
#define ESCSERIAL_TIMER_TX_PIN  PB4  // (HARDARE=0,PPM)

#define USE_SPI
#define USE_SPI_DEVICE_1

#define SPI1_NSS_PIN            PA4
#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN           PA6
#define SPI1_MOSI_PIN           PA7
//#define SPI1_TX_DMA_OPT         0 // DMA1_Channel3
//#define SPI1_RX_DMA_OPT         0 // DMA1_Channel2

// OSD define info:
//   feature name (includes source) -> MAX_OSD, used in target.mk

// include the max7456 driver
#define USE_MAX7456
#define MAX7456_SPI_INSTANCE    SPI1
#define MAX7456_SPI_CS_PIN      PB1
#define MAX7456_SPI_CLK         (SPI_CLOCK_STANDARD) // 10MHz
#define MAX7456_RESTORE_CLK     (SPI_CLOCK_FAST)
//#define MAX7456_DMA_IRQ_HANDLER_ID        DMA1_CH3_HANDLER

#define USE_SPI
#define USE_SPI_DEVICE_2 // PB12,13,14,15 on AF5

#define SPI2_NSS_PIN            PB12
#define SPI2_SCK_PIN            PB13
#define SPI2_MISO_PIN           PB14
#define SPI2_MOSI_PIN           PB15

#undef USE_SDCARD
#undef USE_SDCARD_SPI
// DSHOT output 4 uses DMA1_Channel5, so don't use it for the SDCARD until we find an alternative

#ifndef USE_DSHOT
#define SDCARD_SPI_DMA_OPT                  0    // DMA 1 Channel 5
#endif

// Performance logging for SD card operations:
// #define AFATFS_USE_INTROSPECTIVE_LOGGING

#define USE_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define VBAT_ADC_PIN                PA0
#define CURRENT_METER_ADC_PIN       PA1
#define ADC_INSTANCE                ADC1

//#define RSSI_ADC_PIN                PB1
//#define ADC_INSTANCE                ADC3

#undef USE_TRANSPONDER
#undef REDUCE_TRANSPONDER_CURRENT_DRAW_WHEN_USB_CABLE_PRESENT

#define ENABLE_BLACKBOX_LOGGING_ON_SDCARD_BY_DEFAULT

#define DEFAULT_RX_FEATURE      FEATURE_RX_PPM
#define DEFAULT_FEATURES        (FEATURE_OSD)

// Disable rarely used buttons in favor of flash space
//#define USE_BUTTONS
//#define BUTTON_A_PIN            PB1
//#define BUTTON_B_PIN            PB0

//#define AVOID_UART3_FOR_PWM_PPM // Disable this for using UART3

#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         (BIT(13)|BIT(14)|BIT(15))
#define TARGET_IO_PORTF         (BIT(0)|BIT(1)|BIT(4))

#define USABLE_TIMER_CHANNEL_COUNT 8 // PPM + 6 Outputs (2 shared with UART3)
#define USED_TIMERS             (TIM_N(1) | TIM_N(2) | TIM_N(3) | TIM_N(4) | TIM_N(8) | TIM_N(15))