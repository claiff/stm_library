//
// Created by claiff on 6/13/21.
//
#pragma once

#include "gpio/types/gpio_mode.hpp"

namespace gpio::mode
{
  class AlternativeMode : public gpio::types::GpioMode
  {
  public:
	AlternativeMode();
	~AlternativeMode() override = default;
  };

}