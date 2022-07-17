//
// Created by claiff on 6/13/21.
//

#include "gpio_output_type.hpp"

namespace types::gpio
{
  GpioOutputType::GpioOutputType( uint8_t output_type ) :
	  mOutputType( output_type )
  {

  }

  void GpioOutputType::SetOutputType( GPIO_TypeDef *gpio, uint16_t group_pins ) noexcept
  {
	static const uint8_t OUTPUT_TYPE_COUNT_BITS = 1;
	auto read_data = gpio->OTYPER;

	for( uint8_t i = 0; i < COUNT_PINS; ++i )
	{
	  if( IsActivePin( group_pins, i ) )
	  {
		read_data |= mOutputType << ( i * OUTPUT_TYPE_COUNT_BITS );
	  }
	}
	gpio->OTYPER = read_data;
  }
}