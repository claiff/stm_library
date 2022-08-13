//
// Created by claiff on 13.08.22.
//

#include "stand_by.hpp"

namespace devices::compass::gy::mode
{
	uint8_t StandBy::Get() const
	{
		static constexpr uint8_t MODE_VALUE = 0x00;
		return MODE_VALUE;
	}
}