//
// Created by claiff on 13.08.22.
//

#pragma once

#include "light/bh/types/imode.hpp"

namespace devices::light::bh::mode
{
	class Auto
			: public types::IMode
	{
	public:
		Auto() = default;
		~Auto() override = default;

		types::ModeData Get() const override;
	};
}
