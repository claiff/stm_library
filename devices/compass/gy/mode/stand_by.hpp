//
// Created by claiff on 13.08.22.
//

#pragma once

#include "compass/gy/types/imode.hpp"

namespace devices::compass::gy::mode
{
	class StandBy
			: public types::IMode
	{
	public:
		StandBy() = default;
		~StandBy() override = default;
		uint8_t Get() const override;
	};
}