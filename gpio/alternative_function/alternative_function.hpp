//
// Created by claiff on 6/13/21.
//

#pragma once

#include "gpio/types/gpio_general.hpp"

namespace gpio::alternative_func
{
  class AlternativeFunction : public gpio::types::GpioGeneral
  {
  public:
	explicit AlternativeFunction( uint8_t function );
	~AlternativeFunction() override = default;

	void SetFunction( GPIO_TypeDef *gpio, uint16_t pin );

  private:
	uint8_t mFunction;
  };
  using AlternativeFunctionPtr = AlternativeFunction*;
}