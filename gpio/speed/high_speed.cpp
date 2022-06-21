//
// Created by claiff on 6/13/21.
//

#include "high_speed.hpp"

namespace gpio::speed
{
	static constexpr int HIGH_SPEED = 0x02;

	HighSpeed::HighSpeed()
			: GpioSpeed( HIGH_SPEED )
	{
	}
}