//
// Created by claiff on 6/13/21.
//

#pragma once

#include "gpio_general.hpp"

namespace gpio::types
{
	class GpioOutputType
			: public GpioGeneral
	{
	public:
		explicit GpioOutputType( uint8_t output_type );
		~GpioOutputType() override = default;

		virtual void SetOutputType( GPIO_TypeDef* gpio, uint16_t group_pins );
	private:

		uint8_t mOutputType;
	};

	using GpioOutputTypePtr = GpioOutputType*;
}