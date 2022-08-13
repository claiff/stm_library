//
// Created by claiff on 13.08.22.
//

#include "rng_2.hpp"

namespace devices::compass::gy::rng
{
	uint8_t Rng2::Get() const
	{
		static constexpr uint8_t RNG_VALUE = 0x00;
		return RNG_VALUE;
	}
}