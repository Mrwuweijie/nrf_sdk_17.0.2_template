#include "drv_saadc_det.h"

nrf_saadc_value_t det_value;

 static void saadc_callback(nrf_drv_saadc_evt_t const * p_event)
{
    if (p_event->type == NRF_DRV_SAADC_EVT_DONE)
    {
		
    }
}

uint32_t drv_saadc_get_value(int16_t *detect_value)
{
	return nrfx_saadc_sample_convert(0, detect_value);
}

int32_t drv_saadc_det_init(void)
{
	ret_code_t err_code;
    nrf_saadc_channel_config_t channel_config = NRF_DRV_SAADC_DEFAULT_CHANNEL_CONFIG_SE(NRF_SAADC_INPUT_AIN0);
    channel_config.acq_time = NRF_SAADC_ACQTIME_15US;

    err_code = nrf_drv_saadc_init(NULL, saadc_callback);
    APP_ERROR_CHECK(err_code);

    err_code = nrf_drv_saadc_channel_init(0, &channel_config);
    APP_ERROR_CHECK(err_code);

//    err_code = nrf_drv_saadc_buffer_convert(m_buffer_pool[0], SAMPLES_IN_BUFFER);
//    APP_ERROR_CHECK(err_code);
	return 0;
}
