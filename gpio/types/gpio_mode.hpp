//
// Created by claiff on 6/13/21.
//

#pragma once

#include "gpio_general.hpp"

namespace gpio::types
{
	class GpioMode
			: public GpioGeneral
	{
	public:
		explicit GpioMode( uint8_t mode );
		~GpioMode() override = default;

		virtual void SetMode( GPIO_TypeDef* gpio, uint16_t pin );
	protected:
		uint8_t mMode;
	};

	using GPIO_ModePtr = GpioMode*;
}