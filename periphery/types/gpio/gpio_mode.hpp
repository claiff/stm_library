//
// Created by claiff on 6/13/21.
//

#pragma once

#include "gpio_general.hpp"

namespace types::gpio
{
  class GpioMode : public GpioGeneral
  {
  public:
	explicit GpioMode( uint8_t mode );
	~GpioMode() override = default;

	virtual void SetMode( GPIO_TypeDef *gpio, uint16_t pin ) noexcept;
  protected:
	uint8_t mMode;
  };
  using GPIO_ModePtr = GpioMode*;
}