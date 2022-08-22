//
// Created by claiff on 14.08.22.
//

#pragma once

#include "accel/mpu/types/iconfig.hpp"
#include "types/i2c.hpp"

namespace devices::accel::mpu::config::power
{
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