//
// Created by claiff on 8/29/21.
//

#include "gpio_speed.hpp"

namespace types::gpio
{
  GpioSpeed::GpioSpeed( uint8_t speed ) :
	  mSpeed( speed )
  {
  }

  void GpioSpeed::SetSpeed( GPIO_TypeDef *gpio, uint16_t pin ) noexcept
  {
	const uint8_t SPEED_BITS_COUNT = 2;
	auto read_data = gpio->OSPEEDR;

	for( uint8_t i = 0; i < COUNT_PINS; ++i )
	{
	  if( IsActivePin( pin, i ) )
	  {
		read_data |= mSpeed << i * SPEED_BITS_COUNT;
	  }
	}
	gpio->OSPEEDR = read_data;
  }
}