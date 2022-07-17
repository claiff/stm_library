//
// Created by claiff on 6/13/21.
//
#pragma once

#include "gpio/types/gpio_output_type.hpp"

namespace gpio::output_type
{
	class OpenDrainType
			: public gpio::types::GpioOutputType
	{
	public:
		OpenDrainType();
		~OpenDrainType() override = default;

		//void SetOutputType(GPIO_TypeDef* gpio, uint8_t pin) noexcept override;
	};

}