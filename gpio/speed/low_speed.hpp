//
// Created by claiff on 6/13/21.
//
#pragma once

#include "gpio/types/gpio_speed.hpp"

namespace gpio::speed
{
	class LowSpeed
			: public gpio::types::GpioSpeed
	{
	public:
		LowSpeed();
		~LowSpeed() override = default;
	};

}