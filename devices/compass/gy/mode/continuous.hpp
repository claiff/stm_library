//
// Created by claiff on 13.08.22.
//

#pragma once

#include "compass/gy/types/imode.hpp"

namespace devices::compass::gy::mode
{
	class Continuous
			: public types::IMode
	{
	public:
		Continuous() = default;
		~Continuous() override = default;
		uint8_t Get() const override;
	};
}