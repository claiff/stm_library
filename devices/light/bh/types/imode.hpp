//
// Created by claiff on 13.08.22.
//

#pragma once

#include <vector>
#include <cstdint>

namespace devices::light::bh::types
{
	struct ModeData
	{
		uint8_t command;
		std::vector < uint8_t > data;
	};

	class IMode
	{
	public:
		virtual ~IMode() = default;

		virtual ModeData Get() const = 0;
	};
	using IModePtr = IMode*;
}