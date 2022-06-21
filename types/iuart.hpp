//
// Created by claiff on 8/15/21.
//

#pragma once

namespace periphery::types
{
  class IUArt
  	{
  	public:
  	  IUArt() = default;
  	  virtual ~IUArt() = default;

  	  virtual void ReadData(uint8_t address, uint8_t reg, uint8_t* buffer, uint8_t count) const noexcept = 0;
  	  virtual void WriteData(uint8_t address, uint8_t reg, uint8_t* buffer, uint8_t count) const noexcept = 0;
  	protected:
  	};
  using I2CPtr = std::shared_ptr<II2C>;
}