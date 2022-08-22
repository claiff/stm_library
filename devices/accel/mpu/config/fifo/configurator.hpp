//
// Created by claiff on 14.08.22.
//

#pragma once

#include "accel/mpu/types/iconfig.hpp"
#include "types/i2c.hpp"

namespace devices::accel::mpu::config::fifo
{
	//
	//FIFO_EN=1
	//I2C_MASTER_EN=0
	//I2C_IF_DIS=0
	//FIFO_RESET=1
	//I2C_MST_RESET=0
	//SIG_COND_RESET=0
	//
	class Configurator
	{
	public:
		explicit Configurator( periphery::types::I2CPtr const& i2c );
		~Configurator() = default;

		void Config() const;
	private:
		void DelayMs( uint16_t time ) const;

		periphery::types::I2CPtr const& mI2c;
	};
}