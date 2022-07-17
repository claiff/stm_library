//
// Created by claiff on 6/13/21.
//

#include "push_pull.hpp"

namespace gpio::output_type
{
	static constexpr int PUSH_PULL_TYPE = 0x00;

	PushPullType::PushPullType()
			: gpio::types::GpioOutputType( PUSH_PULL_TYPE )
	{

	}

	void PushPullType::SetOutputType( GPIO_TypeDef* gpio, uint16_t group_pins )
	{
		GpioOutputType::SetOutputType( gpio, group_pins );
	}
}