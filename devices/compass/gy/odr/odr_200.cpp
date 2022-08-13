//
// Created by claiff on 13.08.22.
//

#include "odr_200.hpp"

namespace devices::compass::gy::odr
{

	uint8_t Odr200::Get() const
	{
		static constexpr uint8_t ODR_VALUE = 0x03;
		return ODR_VALUE;
	}
}