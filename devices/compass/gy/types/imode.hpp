//
// Created by claiff on 13.08.22.
//

#pragma once

#include <cstdint>

namespace devices::compass::gy::types
{
	class IMode
	{
	public:
		virtual ~IMode() = default;

		virtual uint8_t Get() const = 0;
	};
	using IModePtr = IMode*;
}