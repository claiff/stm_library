//
// Created by claiff on 13.08.22.
//

#include "osr_128.hpp"

namespace devices::compass::gy::osr
{

	uint8_t Osr128::Get() const
	{
		static constexpr uint8_t OSR_VALUE = 0x02;
		return OSR_VALUE;
	}
}