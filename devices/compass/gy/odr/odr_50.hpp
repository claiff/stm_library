//
// Created by claiff on 13.08.22.
//

#pragma once

#include "compass/gy/types/iodr.hpp"

namespace devices::compass::gy::odr
{
	class Odr50
			: public types::IOdr
	{
	public:
		Odr50() = default;
		~Odr50() override = default;

		uint8_t Get() const override;
	};
}