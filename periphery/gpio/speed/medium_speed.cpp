//
// Created by claiff on 6/13/21.
//

#include "medium_speed.hpp"

namespace gpio::speed
{
	static const int MEDIUM_SPEED = 0x01;

	MediumSpeed::MediumSpeed()
			:
			GpioSpeed( MEDIUM_SPEED )
	{
	}
}