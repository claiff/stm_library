//
// Created by claiff on 13.08.22.
//

#pragma once

#include <cstdint>

namespace devices::compass::gy::types
{
	class IOsr
	{
	public:
		virtual ~IOsr() = default;

		virtual uint8_t Get() const = 0;
	};
	using IOsrPtr = IOsr*;
}