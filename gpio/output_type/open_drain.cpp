//
// Created by claiff on 6/13/21.
//

#include "open_drain.hpp"

namespace gpio::output_type
{
	static const int OPEN_DRAIN_TYPE = 0x01;

	OpenDrainType::OpenDrainType()
			: gpio::types::GpioOutputType( OPEN_DRAIN_TYPE )
	{

	}

}