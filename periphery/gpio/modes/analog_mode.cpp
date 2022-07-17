//
// Created by claiff on 6/13/21.
//

#include "analog_mode.hpp"

namespace gpio::mode
{
	void AnalogMode::SetMode( GPIO_TypeDef* gpio, uint16_t pin )
	{
		static const int ANALOG_MODE = 0x03;
		mMode = ANALOG_MODE;
		GpioMode::SetMode( gpio, pin );
	}

}