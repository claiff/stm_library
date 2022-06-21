//
// Created by claiff on 6/13/21.
//
#pragma once

#include "gpio/types/gpio_speed.hpp"

namespace gpio::speed
{
	class MediumSpeed
			: public gpio::types::GpioSpeed
	{
	public:
		MediumSpeed();
		~MediumSpeed() override = default;
	};

}