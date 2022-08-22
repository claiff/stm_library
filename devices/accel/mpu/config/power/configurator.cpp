//
// Created by claiff on 14.08.22.
//

#include "configurator.hpp"

namespace devices::accel::mpu::config::power
{
	Configurator::Configurator( periphery::types::I2CPtr const& i2c )
			: mI2c( i2c )
	{

	}

	void Configurator::Config() const
	{
		static constexpr uint8_t MPU_ADDRESS = 0xD0;

		static constexpr uint8_t USER_CTRL_REG = 0x6A;
		static constexpr uint8_t PWR_MGMT_1_REG = 0x6B;

		static constexpr uint8_t DEVICE_RESET_BIT = 7;
		static constexpr uint8_t TEMP_DIS_BIT = 3;
		static constexpr uint8_t SIG_COND_BIT = 0;

		uint8_t buffer = 0;

		buffer = 1 << DEVICE_RESET_BIT;
		mI2c->WriteData( MPU_ADDRESS, PWR_MGMT_1_REG, &buffer, sizeof( buffer ));
		DelayMs(100);
		buffer = 1 << TEMP_DIS_BIT;
		mI2c->WriteData( MPU_ADDRESS, PWR_MGMT_1_REG, &buffer, sizeof( buffer ));
		DelayMs(100);
		buffer = 1 << SIG_COND_BIT;
		mI2c->WriteData( MPU_ADDRESS, USER_CTRL_REG, &buffer, sizeof( buffer ));
		DelayMs(100);
	}

	void Configurator::DelayMs( uint16_t time ) const
	{
		for( volatile uint16_t i = 0; i< time; ++i )
		{
			for( volatile uint16_t j = 0; j< 10; ++j );
		}
	}

}