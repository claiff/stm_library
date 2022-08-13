//
// Created by claiff on 13.08.22.
//

#pragma once

#include "light/bh/types/imode.hpp"

namespace devices::light::bh::mode
{
	class High
			: public types::IMode
	{
	public:
		High() = default;
		~High() override = default;

		types::ModeData Get() const override;
	};
}
