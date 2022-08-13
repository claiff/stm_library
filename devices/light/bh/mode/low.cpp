//
// Created by claiff on 13.08.22.
//

#include "low.hpp"

namespace devices::light::bh::mode
{

	types::ModeData Low::Get() const
	{
		//NOTE wait 16ms min
		static constexpr uint8_t LOW_RESOLUTION_REG = 0x13;

		types::ModeData result;

		result.command = LOW_RESOLUTION_REG;
		result.data.push_back( 0x16 );
		result.data.push_back( 0x23 );
		result.data.push_back( 0x26 );

		return result;
	}
}