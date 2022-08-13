//
// Created by claiff on 13.08.22.
//

#include "odr_50.hpp"

namespace devices::compass::gy::odr
{
	uint8_t Odr50::Get() const
	{
		static constexpr uint8_t ODR_VALUE = 0x01;
		return ODR_VALUE;
	}
}