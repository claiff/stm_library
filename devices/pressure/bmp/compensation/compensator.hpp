//
// Created by claiff on 09.08.22.
//

#pragma once

#include <cstdint>
#include "dig_holder.hpp"

namespace devices::pressure::bmp::compensation
{
	class Compensator
	{
	public:
		explicit Compensator( DigHolder const& dig_holder );
		~Compensator() = default;

		[[nodiscard]]uint32_t CompensateH( int32_t raw_h, int32_t raw_t ) const;
		[[nodiscard]] int32_t CompensateT( int32_t raw_t ) const;
		[[nodiscard]] uint32_t CompensateP( int32_t raw_p, int32_t raw_t ) const;
	private:
		[[nodiscard]] int32_t GetFineData( int32_t raw_t ) const;

		DigHolder mDigHolder;
	};
}

