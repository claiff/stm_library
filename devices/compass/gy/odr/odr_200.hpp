//
// Created by claiff on 13.08.22.
//

#pragma once

#include "compass/gy/types/iodr.hpp"

namespace devices::compass::gy::odr
{
	class Odr200
			: public types::IOdr
	{
	public:
		Odr200() = default;
		~Odr200() override = default;

		uint8_t Get() const override;
	};
}