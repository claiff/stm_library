//
// Created by claiff on 13.08.22.
//

#include "osr_256.hpp"

namespace devices::compass::gy::osr
{

	uint8_t Osr256::Get() const
	{
		static constexpr uint8_t OSR_VALUE = 0x01;
		return OSR_VALUE;
	}
}