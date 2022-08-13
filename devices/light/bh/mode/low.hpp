//
// Created by claiff on 13.08.22.
//

#pragma once

#include "light/bh/types/imode.hpp"

namespace devices::light::bh::mode
{
	class Low
			: public types::IMode
	{
	public:
		Low() = default;
		~Low() override = default;

		types::ModeData Get() const override;
	};
}
