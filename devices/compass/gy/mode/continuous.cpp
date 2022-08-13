//
// Created by claiff on 13.08.22.
//

#include "continuous.hpp"

namespace devices::compass::gy::mode
{

	uint8_t Continuous::Get() const
	{
		static constexpr uint8_t MODE_VALUE = 0x01;
		return MODE_VALUE;
	}
}