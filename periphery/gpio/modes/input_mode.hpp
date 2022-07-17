//
// Created by claiff on 6/13/21.
//
#pragma once

#include "gpio/types/gpio_mode.hpp"

namespace gpio::mode
{
	class InputMode
			: public gpio::types::GpioMode
	{
	public:
		InputMode();
		~InputMode() override = default;
	};

}