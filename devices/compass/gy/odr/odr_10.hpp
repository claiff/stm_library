//
// Created by claiff on 13.08.22.
//

#pragma once

#include "compass/gy/types/iodr.hpp"

namespace devices::compass::gy::odr
{
	class Odr10
			: public types::IOdr
	{
	public:
		Odr10() = default;
		~Odr10() override = default;

		uint8_t Get() const override;
	};
}