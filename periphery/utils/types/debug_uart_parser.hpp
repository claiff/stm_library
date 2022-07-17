//
// Created by claiff on 11.07.22.
//

#pragma once

#include <cstdint>
#include <optional>
#include <vector>

namespace utils::types
{ ;
	using DataType = std::pair < uint8_t, std::vector < uint8_t > >;
	using ResultType = std::optional < std::vector < DataType > >;

	class DebugUartParser
	{
	public:
		virtual ~DebugUartParser() = default;

		virtual void PushData( uint8_t data ) = 0;
		virtual ResultType ProcessAndGetData() = 0;
	protected:
		std::vector < uint8_t > mData;
	};
}