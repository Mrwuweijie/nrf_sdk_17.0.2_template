#ifndef __DRV_SENSOR_BH1750_H__
#define __DRV_SENSOR_BH1750_H__

#include "usr_config.h"

#define SENSOR_BH1750_ADDR					0X23	

int32_t drv_sensor_light_init(void);
uint16_t drv_sensor_get_light(void);

#endif /* END __DRV_SENSOR_BH1750_H__ */

