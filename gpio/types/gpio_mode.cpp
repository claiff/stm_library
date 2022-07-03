//
// Created by claiff on 8/15/21.
//
#include "gpio_mode.hpp"

namespace gpio::types
{
	GpioMode::GpioMode( uint8_t mode )
			: mMode( mode )
	{
	}

	void GpioMode::SetMode( GPIO_TypeDef* gpio, uint16_t pin )
	{
		const uint8_t MODE_BITS = 2;
		auto read_data = gpio->MODER;

		for( uint8_t i = 0; i < COUNT_PINS; ++i )
		{
			if( IsActivePin( pin, i ))
			{
				read_data |= mMode << i * MODE_BITS;
			}
		}
		gpio->MODER = read_data;
	}
}