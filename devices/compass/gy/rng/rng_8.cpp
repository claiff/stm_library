//
// Created by claiff on 13.08.22.
//

#include "rng_8.hpp"

namespace devices::compass::gy::rng
{

	uint8_t Rng8::Get() const
	{
		static constexpr uint8_t RNG_VALUE = 0x01;
		return RNG_VALUE;
	}
}