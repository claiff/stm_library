//
// Created by claiff on 6/13/21.
//

#include "alternative_function.hpp"

namespace gpio::alternative_func
{

	AlternativeFunction::AlternativeFunction( uint8_t function )
			: mFunction( function )
	{
	}

	void AlternativeFunction::SetFunction( GPIO_TypeDef* gpio, uint16_t pin )
	{
		static constexpr uint8_t AFR_BITS = 4;
		uint32_t read_data = gpio->AFR[0];

		for( auto i = 0; i < gpio::types::COUNT_PINS / 2 - 1; ++i )
		{
			if( IsActivePin( pin, i ))
			{
				read_data |= mFunction << i * AFR_BITS;
			}
		}
		gpio->AFR[0] = read_data;

		read_data = gpio->AFR[1];
		for( uint8_t i = gpio::types::COUNT_PINS / 2; i < gpio::types::COUNT_PINS; ++i )
		{
			if( IsActivePin( pin, i ))
			{
				uint8_t shift = (i - gpio::types::COUNT_PINS / 2) * AFR_BITS;
				read_data |= mFunction << shift;
			}
		}
		gpio->AFR[1] = read_data;
	}

}