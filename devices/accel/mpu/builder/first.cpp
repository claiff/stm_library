//
// Created by claiff on 14.08.22.
//

#include "first.hpp"

#include "accel/mpu/configurator.hpp"

namespace devices::accel::mpu::builder
{
	Mpu6050 First::Build( periphery::types::I2CPtr const& i2c ) const
	{
		devices::accel::mpu::Configurator configurator{config::fifo::Configurator{i2c}, config::power::Configurator{i2c}, config::devices::Configurator{i2c}};

		return devices::accel::mpu::Mpu6050{i2c, configurator};
	}
}