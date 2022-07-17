//
// Created by claiff on 6/13/21.
//

#include "output_mode.hpp"

namespace gpio::mode
{
	void OutputMode::SetMode( GPIO_TypeDef* gpio, uint16_t pin ) noexcept
	{
		static const int OUTPUT_MODE = 0x01;

		mMode = OUTPUT_MODE;
		GpioMode::SetMode( gpio, pin );
	}
}