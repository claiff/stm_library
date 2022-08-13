//
// Created by claiff on 13.08.22.
//

#include "osr_512.hpp"

namespace devices::compass::gy::osr
{

	uint8_t Osr512::Get() const
	{
		static constexpr uint8_t OSR_VALUE = 0x00;
		return OSR_VALUE;
	}
}