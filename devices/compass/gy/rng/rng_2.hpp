//
// Created by claiff on 13.08.22.
//

#pragma once

#include "compass/gy/types/irng.hpp"

namespace devices::compass::gy::rng
{
	class Rng2
			: public types::IRng
	{
	public:
		Rng2() = default;
		~Rng2() override = default;

		uint8_t Get() const override;
	};
}