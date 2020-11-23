#ifndef __USR_CONFIG_H__
#define __USR_CONFIG_H__

// <<< Use Configuration Wizard in Context Menu >>>\n
#include <stdint.h>
#include <string.h>
#include "nordic_common.h"
#include "nrf.h"
#include "ble_hci.h"
#include "ble_advdata.h"
#include "ble_advertising.h"
#include "ble_conn_params.h"
#include "nrf_sdh.h"
#include "nrf_sdh_soc.h"
#include "nrf_sdh_ble.h"
#include "nrf_ble_gatt.h"
#include "nrf_ble_qwr.h"
#include "app_timer.h"
#include "app_scheduler.h"
#include "ble_nus.h"
#include "app_uart.h"
#include "app_util_platform.h"
#include "bsp_btn_ble.h"
#include "nrf_pwr_mgmt.h"

#if defined (UART_PRESENT)
#include "nrf_uart.h"
#endif
#if defined (UARTE_PRESENT)
#include "nrf_uarte.h"
#endif

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "sdk_config.h"
#include "nrf_delay.h"

#include "nrf_drv_twi.h"
#include "nrf_drv_saadc.h"

//#include "main.h"
#include "m_ble.h"
#include "m_coms.h"
#include "m_ble_advertising.h"

#include "drv_sensor_bh1750.h"
#include "drv_dht11.h"
#include "drv_saadc_det.h"

#define SCHED_MAX_EVENT_DATA_SIZE        APP_TIMER_SCHED_EVENT_DATA_SIZE       	/**< Maximum size of scheduler events. */
#define SCHED_QUEUE_SIZE                 30       								/**< Maximum number of events in the scheduler queue. */

#define APP_BLE_CONN_CFG_TAG            1                                           /**< A tag identifying the SoftDevice BLE configuration. */
#define DEVICE_NAME                     "Nordic_UART"                               /**< Name of device. Will be included in the advertising data. */
#define NUS_SERVICE_UUID_TYPE           BLE_UUID_TYPE_VENDOR_BEGIN                  /**< UUID type for the Nordic UART Service (vendor specific). */

#define APP_BLE_OBSERVER_PRIO           3                                           /**< Application's BLE observer priority. You shouldn't need to modify this value. */

#define APP_ADV_INTERVAL                64                                          /**< The advertising interval (in units of 0.625 ms. This value corresponds to 40 ms). */

#define APP_ADV_DURATION                18000                                       /**< The advertising duration (180 seconds) in units of 10 milliseconds. */

#define MIN_CONN_INTERVAL               MSEC_TO_UNITS(20, UNIT_1_25_MS)             /**< Minimum acceptable connection interval (20 ms), Connection interval uses 1.25 ms units. */
#define MAX_CONN_INTERVAL               MSEC_TO_UNITS(75, UNIT_1_25_MS)             /**< Maximum acceptable connection interval (75 ms), Connection interval uses 1.25 ms units. */
#define SLAVE_LATENCY                   0                                           /**< Slave latency. */
#define CONN_SUP_TIMEOUT                MSEC_TO_UNITS(4000, UNIT_10_MS)             /**< Connection supervisory timeout (4 seconds), Supervision Timeout uses 10 ms units. */
#define FIRST_CONN_PARAMS_UPDATE_DELAY  APP_TIMER_TICKS(5000)                       /**< Time from initiating event (connect or start of notification) to first time sd_ble_gap_conn_param_update is called (5 seconds). */
#define NEXT_CONN_PARAMS_UPDATE_DELAY   APP_TIMER_TICKS(30000)                      /**< Time between each call to sd_ble_gap_conn_param_update after the first call (30 seconds). */
#define MAX_CONN_PARAMS_UPDATE_COUNT    3                                           /**< Number of attempts before giving up the connection parameter negotiation. */

#define DEAD_BEEF                       0xDEADBEEF                                  /**< Value used as error code on stack dump, can be used to identify stack location on stack unwind. */

// <h> I/O Configuration
// <i> This section contains configuration for the I/O pin assignment.
// <h> UART gpio control
// <i> Configure the Uart pins.
// <o> Uart TX Pin
//  <0=>P0.0   <1=>P0.1   <2=>P0.2   <3=>P0.3   <4=>P0.4   <5=>P0.5   <6=>P0.6   <7=>P0.7
//  <8=>P0.8   <9=>P0.9   <10=>P0.10 <11=>P0.11 <12=>P0.12 <13=>P0.13 <14=>P0.14 <15=>P0.15
//  <16=>P0.16 <17=>P0.17 <18=>P0.18 <19=>P0.19 <20=>P0.20 <21=>P0.21 <22=>P0.22 <23=>P0.23
//  <24=>P0.24 <25=>P0.25 <26=>P0.26 <27=>P0.27 <28=>P0.28 <29=>P0.29 <30=>P0.30 <31=>P0.31
//  <0xFFFFFFFF=>Disable
#define CONFIG_IO_UART_TX 0x00000008

// <o> Uart RX Pin
//  <0=>P0.0   <1=>P0.1   <2=>P0.2   <3=>P0.3   <4=>P0.4   <5=>P0.5   <6=>P0.6   <7=>P0.7
//  <8=>P0.8   <9=>P0.9   <10=>P0.10 <11=>P0.11 <12=>P0.12 <13=>P0.13 <14=>P0.14 <15=>P0.15
//  <16=>P0.16 <17=>P0.17 <18=>P0.18 <19=>P0.19 <20=>P0.20 <21=>P0.21 <22=>P0.22 <23=>P0.23
//  <24=>P0.24 <25=>P0.25 <26=>P0.26 <27=>P0.27 <28=>P0.28 <29=>P0.29 <30=>P0.30 <31=>P0.31
//  <0xFFFFFFFF=>Disable
#define CONFIG_IO_UART_RX 0x00000006

// <o> Uart CTS Pin
//  <0=>P0.0   <1=>P0.1   <2=>P0.2   <3=>P0.3   <4=>P0.4   <5=>P0.5   <6=>P0.6   <7=>P0.7
//  <8=>P0.8   <9=>P0.9   <10=>P0.10 <11=>P0.11 <12=>P0.12 <13=>P0.13 <14=>P0.14 <15=>P0.15
//  <16=>P0.16 <17=>P0.17 <18=>P0.18 <19=>P0.19 <20=>P0.20 <21=>P0.21 <22=>P0.22 <23=>P0.23
//  <24=>P0.24 <25=>P0.25 <26=>P0.26 <27=>P0.27 <28=>P0.28 <29=>P0.29 <30=>P0.30 <31=>P0.31
//  <0xFFFFFFFF=>Disable
#define CONFIG_IO_UART_CTS 0xFFFFFFFF

// <o> Uart RTS Pin
//  <0=>P0.0   <1=>P0.1   <2=>P0.2   <3=>P0.3   <4=>P0.4   <5=>P0.5   <6=>P0.6   <7=>P0.7
//  <8=>P0.8   <9=>P0.9   <10=>P0.10 <11=>P0.11 <12=>P0.12 <13=>P0.13 <14=>P0.14 <15=>P0.15
//  <16=>P0.16 <17=>P0.17 <18=>P0.18 <19=>P0.19 <20=>P0.20 <21=>P0.21 <22=>P0.22 <23=>P0.23
//  <24=>P0.24 <25=>P0.25 <26=>P0.26 <27=>P0.27 <28=>P0.28 <29=>P0.29 <30=>P0.30 <31=>P0.31
//  <0xFFFFFFFF=>Disable
#define CONFIG_IO_UART_RTS 0xFFFFFFFF
// </h>

// <h> Sensor pin config
// <i> Configure the Sensor output, Alert pin, used for indicate data is ready.
// <o> Sensor output pin
//  <0=>P0.0   <1=>P0.1   <2=>P0.2   <3=>P0.3   <4=>P0.4   <5=>P0.5   <6=>P0.6   <7=>P0.7
//  <8=>P0.8   <9=>P0.9   <10=>P0.10 <11=>P0.11 <12=>P0.12 <13=>P0.13 <14=>P0.14 <15=>P0.15
//  <16=>P0.16 <17=>P0.17 <18=>P0.18 <19=>P0.19 <20=>P0.20 <21=>P0.21 <22=>P0.22 <23=>P0.23
//  <24=>P0.24 <25=>P0.25 <26=>P0.26 <27=>P0.27 <28=>P0.28 <29=>P0.29 <30=>P0.30 <31=>P0.31
//  <0xFFFFFFFF=>Disable
/**@brief Sensor alert Pin */
#define CONFIG_IO_SENSOR_INTR 0x00000015

// <i> Configure the Sensor scl pin.
// <o> Sensor scl pin
//  <0=>P0.0   <1=>P0.1   <2=>P0.2   <3=>P0.3   <4=>P0.4   <5=>P0.5   <6=>P0.6   <7=>P0.7
//  <8=>P0.8   <9=>P0.9   <10=>P0.10 <11=>P0.11 <12=>P0.12 <13=>P0.13 <14=>P0.14 <15=>P0.15
//  <16=>P0.16 <17=>P0.17 <18=>P0.18 <19=>P0.19 <20=>P0.20 <21=>P0.21 <22=>P0.22 <23=>P0.23
//  <24=>P0.24 <25=>P0.25 <26=>P0.26 <27=>P0.27 <28=>P0.28 <29=>P0.29 <30=>P0.30 <31=>P0.31
//  <0xFFFFFFFF=>Disable
/**@brief Sensor alert Pin */
#define CONFIG_IO_SENSOR_SCL 0x0000001B

// <i> Configure the Sensor sda pin.
// <o> Sensor sda pin
//  <0=>P0.0   <1=>P0.1   <2=>P0.2   <3=>P0.3   <4=>P0.4   <5=>P0.5   <6=>P0.6   <7=>P0.7
//  <8=>P0.8   <9=>P0.9   <10=>P0.10 <11=>P0.11 <12=>P0.12 <13=>P0.13 <14=>P0.14 <15=>P0.15
//  <16=>P0.16 <17=>P0.17 <18=>P0.18 <19=>P0.19 <20=>P0.20 <21=>P0.21 <22=>P0.22 <23=>P0.23
//  <24=>P0.24 <25=>P0.25 <26=>P0.26 <27=>P0.27 <28=>P0.28 <29=>P0.29 <30=>P0.30 <31=>P0.31
//  <0xFFFFFFFF=>Disable
/**@brief Sensor alert Pin */
#define CONFIG_IO_SENSOR_SDA 0x0000001A
// </h>

// <h> DHT11 pin config
// <i> Configure the dht11 pin.
// <o> DHT11 io pin
//  <0=>P0.0   <1=>P0.1   <2=>P0.2   <3=>P0.3   <4=>P0.4   <5=>P0.5   <6=>P0.6   <7=>P0.7
//  <8=>P0.8   <9=>P0.9   <10=>P0.10 <11=>P0.11 <12=>P0.12 <13=>P0.13 <14=>P0.14 <15=>P0.15
//  <16=>P0.16 <17=>P0.17 <18=>P0.18 <19=>P0.19 <20=>P0.20 <21=>P0.21 <22=>P0.22 <23=>P0.23
//  <24=>P0.24 <25=>P0.25 <26=>P0.26 <27=>P0.27 <28=>P0.28 <29=>P0.29 <30=>P0.30 <31=>P0.31
//  <0xFFFFFFFF=>Disable
/**@brief Sensor alert Pin */
#define CONFIG_IO_DHT11 0x0000003

// </h>

// <<< end of configuration section >>>
#endif /* END __USR_CONFIG_H__ */

