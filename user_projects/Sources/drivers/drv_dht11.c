#include "drv_dht11.h"
#include "nrf_gpio.h"

unsigned long int Count_micro_second = 0;

unsigned char DHT11_READ_1_BYTES_DATA(void)
{

	unsigned int i=0;
	unsigned char Return_Value=0;

	for(i=0;i<8;i++)
	{
		Return_Value = Return_Value << 1;

		while((nrf_gpio_pin_read(CONFIG_IO_DHT11)) == 0)
		{
			nrf_delay_us(5);
		}
		Count_micro_second = 0;

		while((nrf_gpio_pin_read(CONFIG_IO_DHT11))==1)
		{
			Count_micro_second++;
			nrf_delay_us(5);
		}

		if(Count_micro_second<7)
		{	

			Return_Value = Return_Value | 0;
		}
		else
		{
			Return_Value = Return_Value | 1;
		}		
	}

	return Return_Value;

}


char DHT11_READ_5_BYTES_DATA(void)
{
	uint8_t err = 0;
	uint8_t Humidity_Int = DHT11_READ_1_BYTES_DATA();
	uint8_t Humidity_DEC = DHT11_READ_1_BYTES_DATA();
	uint8_t TEMPERATURE_Int = DHT11_READ_1_BYTES_DATA();
	uint8_t TEMPERATURE_DEC = DHT11_READ_1_BYTES_DATA();
	uint8_t CHECKSUM = DHT11_READ_1_BYTES_DATA();

	if (((Humidity_Int + Humidity_DEC + TEMPERATURE_Int + TEMPERATURE_DEC) & 0xff) != CHECKSUM) 
	{

		NRF_LOG_INFO("got wrong values\n");
		return 1;
	}
	else
	{
		NRF_LOG_INFO("got values\n");
		return err;
	}
}

DHT11_STATE_E drv_sht11_get_value(DHT11_DATA_T *data_out)
{
	uint16_t count = 0;
	uint8_t temp_data[5] = {0x00, 0x00, 0x00, 0x00, 0x00};
	// Send out start signal. low for 18 ms.
	nrf_gpio_cfg_output(CONFIG_IO_DHT11);
	nrf_gpio_pin_clear(CONFIG_IO_DHT11);
	nrf_delay_ms(25);
	nrf_gpio_pin_set(CONFIG_IO_DHT11);
	nrf_delay_us(30);

	nrf_gpio_cfg_input(CONFIG_IO_DHT11, NRF_GPIO_PIN_NOPULL);

	while(nrf_gpio_pin_read(CONFIG_IO_DHT11) == false)
	{
		count ++;
		nrf_delay_us(1);
		if (count > 100)
			return DHT11_STATE_ERROR_INTERNAL;
		
	}
	count = 0;
	while(nrf_gpio_pin_read(CONFIG_IO_DHT11) == true)
	{
		count ++;
		nrf_delay_us(1);
		if (count > 100)
			return DHT11_STATE_ERROR_INTERNAL;
	}

	uint8_t i, j = 0;
	for (j = 0; j < 5; ++ j)
	{
		for (i = 0; i < 8; ++ i)
		{
			
			//temp_data[j] = temp_data[j] << 1;
			while(nrf_gpio_pin_read(CONFIG_IO_DHT11) == false)	continue;
			count = 0;
			while(nrf_gpio_pin_read(CONFIG_IO_DHT11) == true)
			{
				count ++;
				nrf_delay_us(5);
				if (count > 100)
					return DHT11_STATE_ERROR_INTERNAL;
			}

//			if ( count < 7)
//			{
//				temp_data[j] = temp_data[j] | 0;
//			}
//			else
//			{
//				temp_data[j] = temp_data[j] | 1;
//			}

			//shift 0
			temp_data[j] = temp_data[j] << 1;
			
			//if > 30us it's 1
			if(count > 8)
				temp_data[j] = temp_data[j]+1;
			
		}
	}

	if(temp_data[4] != (temp_data[0] + temp_data[1] + temp_data[2] + temp_data[3]))
	{
		return DHT11_STATE_ERROR_CHECKSUM;
	}
	data_out->humidity = temp_data[0];
	data_out->temparature= temp_data[2];

	return DHT11_STATE_DONE;
}

int32_t drv_dht11_init(void)
{
	nrf_gpio_cfg_output(CONFIG_IO_DHT11);
	nrf_gpio_pin_set(CONFIG_IO_DHT11);
	return 0;
}
