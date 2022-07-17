//
// Created by claiff on 6/14/21.
//
#pragma once

#include "misc/stm32f407xx.h"

namespace types::gpio
{
  const static uint8_t COUNT_PINS = 16;

  enum class GPIO_PIN : uint16_t
  {
	PIN0 = 1 << 0,
	PIN1 = 1 << 1,
	PIN2 = 1 << 2,
	PIN3 = 1 << 3,
	PIN4 = 1 << 4,
	PIN5 = 1 << 5,
	PIN6 = 1 << 6,
	PIN7 = 1 << 7,
	PIN8 = 1 << 8,
	PIN9 = 1 << 9,
	PIN10 = 1 << 10,
	PIN11 = 1 << 11,
	PIN12 = 1 << 12,
	PIN13 = 1 << 13,
	PIN14 = 1 << 14,
	PIN15 = 1 << 15,
  };

  class GpioGeneral
  {
  public:
	GpioGeneral() = default;
	virtual ~GpioGeneral() = default;
  protected:
	bool IsActivePin( uint16_t pin, uint8_t chosen_pin );
  };
}