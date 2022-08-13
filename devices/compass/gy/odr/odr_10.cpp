//
// Created by claiff on 13.08.22.
//

#include "odr_10.hpp"

namespace devices::compass::gy::odr
{
	uint8_t Odr10::Get() const
	{
		static constexpr uint8_t ODR_VALUE = 0x00;
		return ODR_VALUE;
	}
}