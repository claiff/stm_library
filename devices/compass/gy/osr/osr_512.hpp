//
// Created by claiff on 13.08.22.
//

#pragma once

#include "compass/gy/types/iosr.hpp"

namespace devices::compass::gy::osr
{
	class Osr512
			: public types::IOsr
	{
	public:
		Osr512() = default;
		~Osr512() override = default;

		uint8_t Get() const override;
	};
}