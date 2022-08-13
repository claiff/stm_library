//
// Created by claiff on 13.08.22.
//

#include "high.hpp"

namespace devices::light::bh::mode
{

	types::ModeData High::Get() const
	{
		//NOTE wait 120ms min
		static constexpr uint8_t HIGH_RESOLUTION_REG = 0x12;

		types::ModeData result;

		result.command = HIGH_RESOLUTION_REG;
		result.data.push_back( 0x22 );

		return result;
	}
}