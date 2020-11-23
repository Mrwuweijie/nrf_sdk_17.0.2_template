#ifndef __DRV_DHT11_H__
#define __DRV_DHT11_H__

#include "usr_config.h"

typedef struct {
	uint8_t 	temparature;
	uint8_t 	humidity;
} DHT11_DATA_T;

typedef enum {
	DHT11_STATE_DONE,
	DHT11_STATE_ERROR_CHECKSUM,
	DHT11_STATE_ERROR_INTERNAL,
	DHT11_STATE_MAX,
} DHT11_STATE_E;

int32_t drv_dht11_init(void);
DHT11_STATE_E drv_sht11_get_value(DHT11_DATA_T *data_out);

#endif /* END __DRV_DHT11_H__ */

