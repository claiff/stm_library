//
// Created by claiff on 6/13/21.
//

#pragma once

#include "types/i2c.hpp"
#include "types/periphery_init.hpp"
#include "types/ircc.hpp"

namespace periphery::i2c
{
  class I2cMaxSpeed : public types::I2C
  {
  public:
	I2cMaxSpeed( I2C_TypeDef *i2c, periphery::types::IRCC_Ptr const& rcc );
	~I2cMaxSpeed() override = default;

	void InitI2C() const;
	void ReadData( uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t count ) const override;
	void WriteData( uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t count ) const override;
  private:
	I2C_TypeDef* mI2c;
	types::IRCC_Ptr mRcc;
	types::PeripheryInitPtr mPeripheryInit;
  };
}