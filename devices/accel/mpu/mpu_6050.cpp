//
// Created by claiff on 13.08.22.
//

#include "mpu_6050.hpp"

namespace devices::accel::mpu
{
	static constexpr uint8_t MPU_ADDRESS = 0xD0;

	//
	// Constructors
	//

	Mpu6050::Mpu6050( periphery::types::I2CPtr const& i2c, Configurator const& configurator )
			: mI2c( i2c )
			, mConfigurator( configurator )
	{
		mConfigurator.ConfigAll();
	}

	//
	// Public methods
	//

	bool Mpu6050::IsOnline() const
	{
		static constexpr uint8_t WHO_I_AM_REG = 0x75;
		static constexpr uint8_t MPU_ID = 0x68;

		uint8_t result = 0x00;
		mI2c->ReadData( MPU_ADDRESS, WHO_I_AM_REG, &result, sizeof( result ));
		return result == MPU_ID;
	}

	AccelDataSet Mpu6050::GetData() const
	{
		static constexpr uint8_t FIFO_READ_REG = 0x74;

		uint8_t buffer[12]{};
		AccelDataSet result{};

		auto count = GetCountData();
		auto i = sizeof( buffer );

		while( i < count )
		{
			AccelData data{};

			mI2c->ReadData( MPU_ADDRESS, FIFO_READ_REG, buffer, sizeof( buffer ));
			ApplyData( buffer, data );

			result.push_back( data );
			i += sizeof( buffer );
		}
		return result;
	}

	void Mpu6050::ApplyData( uint8_t const buffer[12], AccelData& data ) const
	{
		data.accel.x = buffer[0] << 8 | buffer[1];
		data.accel.y = buffer[2] << 8 | buffer[3];
		data.accel.z = buffer[4] << 8 | buffer[5];

		data.gyro.x = buffer[6] << 8 | buffer[7];
		data.gyro.y = buffer[8] << 8 | buffer[9];
		data.gyro.z = buffer[10] << 8 | buffer[11];
	}

	//
	// Private methods
	//

	uint16_t Mpu6050::GetCountData() const
	{
		static constexpr uint8_t FIFO_COUNT_H_REG = 0x72;

		uint8_t buffer[2]{};

		mI2c->ReadData( MPU_ADDRESS, FIFO_COUNT_H_REG, buffer, sizeof( buffer ));
		return buffer[0] << 8 | buffer[1];
	}
}