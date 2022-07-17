//
// Created by claiff on 6/13/21.
//

#pragma once

#include "gpio_general.hpp"

namespace types::gpio
{
  class GpioPull : public GpioGeneral
  {
  public:
	GpioPull() :
		mPull( 0 )
	{
	}
	~GpioPull() override = default;

	virtual void SetPull( GPIO_TypeDef *gpio, uint8_t pin ) noexcept
	{
	  const uint8_t PULL_BITS = 2;
	  auto read_data = gpio->PUPDR;

	  for( uint8_t i = 0; i < COUNT_PINS; ++i )
	  {
		if( IsActivePin( pin, i ) )
		{
		  read_data |= mPull << i * PULL_BITS;
		}
	  }
	  gpio->PUPDR = read_data;
	}

  protected:
	uint8_t mPull;
  };
  using GpioPullPtr = GpioPull*;
}