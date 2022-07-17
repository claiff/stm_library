//
// Created by claiff on 6/13/21.
//
#pragma once

#include "gpio/types/gpio_speed.hpp"

namespace gpio::speed
{
	class HighSpeed
			: public gpio::types::GpioSpeed
	{
	public:
		HighSpeed();
		HighSpeed( uint8_t speed );
		~HighSpeed() override = default;
	};
}