#include "drv_sensor_bh1750.h"

/* TWI instance ID. */
#define TWI_INSTANCE_ID     0

/* TWI instance. */
static const nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(TWI_INSTANCE_ID);

static uint8_t bh1750_config[] = { 0x10 };
/**
 * @brief TWI events handler.
 */
void twi_handler(nrf_drv_twi_evt_t const * p_event, void * p_context)
{
    switch (p_event->type)
    {
        case NRF_DRV_TWI_EVT_DONE:
            if (p_event->xfer_desc.type == NRF_DRV_TWI_XFER_RX)
            {
                //data_handler(m_sample);
            }
            //m_xfer_done = true;
            break;
        default:
            break;
    }
}

uint16_t drv_sensor_get_light(void)
{
	ret_code_t err_code;
	uint8_t read_temp[2] = {0};
	err_code = nrf_drv_twi_rx(&m_twi, SENSOR_BH1750_ADDR, read_temp, sizeof(read_temp));
//	APP_ERROR_CHECK(err_code);

	return ((read_temp[0]  << 8) & 0xFF00) | (read_temp[1] & 0x00FF); 
}

int32_t drv_sensor_light_init(void)
{
	ret_code_t err_code;

    const nrf_drv_twi_config_t twi_bh1750_config = {
       .scl                = CONFIG_IO_SENSOR_SCL,
       .sda                = CONFIG_IO_SENSOR_SDA,
       .frequency          = NRF_DRV_TWI_FREQ_100K,
       .interrupt_priority = APP_IRQ_PRIORITY_HIGH,
       .clear_bus_init     = false
    };

    err_code = nrf_drv_twi_init(&m_twi, &twi_bh1750_config, NULL, NULL);
    APP_ERROR_CHECK(err_code);

    nrf_drv_twi_enable(&m_twi);
	
	err_code = nrf_drv_twi_tx(&m_twi, SENSOR_BH1750_ADDR, bh1750_config, sizeof(bh1750_config), false);
	APP_ERROR_CHECK(err_code);
	
	return 0;
}

