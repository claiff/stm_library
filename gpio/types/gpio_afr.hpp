//
// Created by claiff on 6/13/21.
//

#pragma once

#include "misc/stm32f407xx.h"

namespace gpio::types
{
	class GpioMode
	{
	public:
		GpioMode()
				: mMode( 0 )
		{
		}

		virtual ~GpioMode() = default;

		virtual void SetMode( GPIO_TypeDef* gpio, uint16_t pin )
		{
			auto read_data = gpio->MODER;
			read_data |= mMode << pin;
			gpio->MODER = read_data;
		}

	protected:
		uint8_t mMode;
	};

	using GPIO_MODEPtr = GpioMode*;
}