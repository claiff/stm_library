//
// Created by claiff on 6/13/21.
//

#include "input_mode.hpp"

namespace gpio::mode
{
	static const int INPUT_MODE = 0x00;

	InputMode::InputMode()
			:
			gpio::types::GpioMode( INPUT_MODE )
	{
	}

}