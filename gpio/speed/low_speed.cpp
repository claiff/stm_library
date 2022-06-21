//
// Created by claiff on 6/13/21.
//

#include "low_speed.hpp"

namespace gpio::speed
{
	static const int LOW_SPEED = 0x00;

	LowSpeed::LowSpeed()
			:
			GpioSpeed( LOW_SPEED )
	{
	}
}