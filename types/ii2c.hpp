//
// Created by claiff on 6/13/21.
//

#pragma once

#include <memory>

#include "main/stm32f407xx.h"

namespace periphery::types
{
  class II2C
  {
  public:
	II2C() = default;
	virtual ~II2C() = default;

	virtual void ReadData( uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t count ) const noexcept = 0;
	virtual void WriteData( uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t count ) const noexcept = 0;
  };
  using I2CPtr = std::shared_ptr<II2C>;
}