//
// Created by claiff on 6/13/21.
//

#pragma once

#include <memory>

#include "misc/stm32f407xx.h"

namespace periphery::types
{
  class I2C
  {
  public:
	  I2C() = default;
	virtual ~I2C() = default;

	virtual void ReadData( uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t count ) const = 0;
	virtual void WriteData( uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t count ) const = 0;
  };
  using I2CPtr = I2C*;
}