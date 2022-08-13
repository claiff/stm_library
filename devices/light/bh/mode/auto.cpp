//
// Created by claiff on 13.08.22.
//

#include "auto.hpp"

namespace devices::light::bh::mode
{
	types::ModeData Auto::Get() const
	{
		//NOTE wait 180ms min
		static constexpr uint8_t AUTO_RESOLUTION_REG = 0x10;

		types::ModeData result;

		result.command = AUTO_RESOLUTION_REG;
		result.data.push_back( 0x20 );

		return result;
	}
}