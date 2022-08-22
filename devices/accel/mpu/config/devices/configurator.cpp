//
// Created by claiff on 14.08.22.
//

#include "configurator.hpp"

namespace devices::accel::mpu::config::devices
{

	Configurator::Configurator( periphery::types::I2CPtr const& i2c )
			: mI2c( i2c )
	{

	}

	void Configurator::Config() const
	{
		static constexpr uint8_t MPU_ADDRESS = 0xD0;

		static constexpr uint8_t CONFIG_REG = 0x1A;
		static constexpr uint8_t CONFIG_DATA = 0x01;

		static constexpr uint8_t GYRO_CONFIG_REG = 0x1B;
		static constexpr uint8_t FS_SEL_BIT = 0x03;
		static constexpr uint8_t GYRO_DATA = 0x03;

		static constexpr uint8_t ACCEL_CONFIG_REG = 0x1C;
		static constexpr uint8_t AFS_SEL_BIT = 0x03;
		static constexpr uint8_t ACCEL_DATA = 0x03;

		uint8_t buffer = CONFIG_DATA;

		mI2c->WriteData( MPU_ADDRESS, CONFIG_REG, &buffer, sizeof( buffer ));
		buffer = GYRO_DATA << FS_SEL_BIT;
		mI2c->WriteData( MPU_ADDRESS, GYRO_CONFIG_REG, &buffer, sizeof( buffer ));
		buffer = ACCEL_DATA << AFS_SEL_BIT;
		mI2c->WriteData( MPU_ADDRESS, ACCEL_CONFIG_REG, &buffer, sizeof( buffer ));
	}
}