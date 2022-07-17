//
// Created by claiff on 6/13/21.
//

#pragma once

#include "gpio_general.hpp"

namespace types::gpio
{
  class GpioSpeed : public GpioGeneral
  {
  public:
	explicit GpioSpeed( uint8_t speed );
	~GpioSpeed() override = default;

	virtual void SetSpeed( GPIO_TypeDef *gpio, uint16_t pin ) noexcept;

  protected:
	uint8_t mSpeed;
  };
  using GpioSpeedPtr = GpioSpeed*;
}