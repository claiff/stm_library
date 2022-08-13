//
// Created by claiff on 13.08.22.
//

#include "odr_100.hpp"

namespace devices::compass::gy::odr
{
	uint8_t Odr100::Get() const
	{
		static constexpr uint8_t ODR_VALUE = 0x02;
		return ODR_VALUE;
	}
}