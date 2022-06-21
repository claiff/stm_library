//
// Created by claiff on 6/13/21.
//
#pragma once

#include "gpio/types/gpio_output_type.hpp"

namespace gpio::output_type
{

	class PushPullType
			: public gpio::types::GpioOutputType
	{
	public:
		PushPullType();
		~PushPullType() override = default;

		void SetOutputType( GPIO_TypeDef* gpio, uint16_t group_pins ) override;
	};

}