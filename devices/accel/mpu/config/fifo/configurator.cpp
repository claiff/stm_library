//
// Created by claiff on 14.08.22.
//

#include "configurator.hpp"

namespace devices::accel::mpu::config::fifo
{
	Configurator::Configurator( periphery::types::I2CPtr const& i2c )
			: mI2c( i2c )
	{

	}

	void Configurator::Config() const
	{
		static constexpr uint8_t MPU_ADDRESS = 0xD0;

		static constexpr uint8_t USER_CTRL_REG = 0x6A;
		static constexpr uint8_t FIFO_ENABLE_REG = 0x23;

		static constexpr uint8_t FIFO_EN_BIT = 6;
		static constexpr uint8_t FIFO_RESET_BIT = 2;
		static constexpr uint8_t XG_FIFO_EN_BIT = 0x06;
		static constexpr uint8_t YG_FIFO_EN_BIT = 0x05;
		static constexpr uint8_t ZG_FIFO_EN_BIT = 0x04;
		static constexpr uint8_t ACCEL_FIFO_EN_BIT = 0x03;

		uint8_t buffer = 0;

		buffer = 1 << FIFO_RESET_BIT;
		mI2c->WriteData( MPU_ADDRESS, USER_CTRL_REG, &buffer, sizeof( buffer ));
		DelayMs(200);
		buffer = 1 << FIFO_EN_BIT;
		mI2c->WriteData( MPU_ADDRESS, USER_CTRL_REG, &buffer, sizeof( buffer ));
		DelayMs(100);
		buffer = (1 << XG_FIFO_EN_BIT) | (1 << YG_FIFO_EN_BIT) | (1 << ZG_FIFO_EN_BIT) | (1 << ACCEL_FIFO_EN_BIT);
		mI2c->WriteData( MPU_ADDRESS, FIFO_ENABLE_REG, &buffer, sizeof( buffer ));
	}

	void Configurator::DelayMs( uint16_t time ) const
	{
		for( volatile uint16_t i = 0; i< time; ++i )
		{
			for( volatile uint16_t j = 0; j< 10; ++j );
		}
	}
}