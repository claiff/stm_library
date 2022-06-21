//
// Created by claiff on 6/13/21.
//

#include "very_high_speed.hpp"

namespace gpio::speed
{
	static constexpr int VERY_HIGH_SPEED = 0x03;

	VeryHighSpeed::VeryHighSpeed()
			: GpioSpeed( VERY_HIGH_SPEED )
	{
	}
}