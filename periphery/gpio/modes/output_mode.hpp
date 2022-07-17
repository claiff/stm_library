//
// Created by claiff on 6/13/21.
//
#pragma once

#include "gpio/types/gpio_mode.hpp"

namespace gpio::mode
{

	class OutputMode
			: public gpio::types::GpioMode
	{
	public:
		//TODO Ерунда GPIOMODE конструктор не пустой
		OutputMode() = default;
		~OutputMode() override = default;

		void SetMode( GPIO_TypeDef* gpio, uint16_t pin ) noexcept override;
	};

}