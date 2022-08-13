//
// Created by claiff on 13.08.22.
//

#include "osr_64.hpp"

namespace devices::compass::gy::osr
{

	uint8_t Osr64::Get() const
	{
		static constexpr uint8_t OSR_VALUE = 0x03;
		return OSR_VALUE;
	}
}