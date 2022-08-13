//
// Created by claiff on 11.08.22.
//

#include "bmp_280.hpp"

namespace devices::pressure::bmp
{
	static constexpr uint8_t ADDRESS = 0xEC;

	//
	// Constructors
	//

	Bmp280::Bmp280( periphery::types::I2CPtr const& i2c, types::ISettingsPtr const& settings )
			: mI2c( i2c )
			, mCompensator( compensation::DigHolder{i2c} )
			, mSettings( settings )
	{
		Reset();
		SetupSensor();
	}

	//
	// Public methods
	//

	bool Bmp280::IsOnline() const
	{
		static constexpr uint8_t WHO_I_AM_REG = 0xD0;
		static constexpr uint8_t BMP_ID = 0x60;

		uint8_t result = 0x00;
		mI2c->ReadData( ADDRESS, WHO_I_AM_REG, &result, sizeof( result ));
		return result == BMP_ID;
	}

	int32_t Bmp280::GetTemperature() const
	{
		return mCompensator.CompensateT( GetRawT()) / 100;
	}

	uint32_t Bmp280::GetPressure() const
	{
		return mCompensator.CompensateP( GetRawP(), GetRawT()) / 256;
	}

	uint32_t Bmp280::GetHumidity() const
	{
		return mCompensator.CompensateH( GetRawH(), GetRawT())/1024;
	}

	//
	//Private methods
	//

	void Bmp280::Reset() const
	{
		static constexpr uint8_t RESET_REG = 0xE0;

		uint8_t buffer{};
		mI2c->WriteData( ADDRESS, RESET_REG, &buffer, sizeof( buffer ));
	}

	void Bmp280::SetupSensor() const
	{
		static constexpr uint8_t CTRL_HUM_REG = 0xF2;
		static constexpr uint8_t CTRL_MEAS_REG = 0xF4;
		static constexpr uint8_t CONFIG_REG = 0xF5;

		uint8_t buffer = 0;

		buffer = mSettings->GetOversamplingHumidity() & 0x07;
		mI2c->WriteData( ADDRESS, CTRL_HUM_REG, &buffer, sizeof( buffer ));

		buffer = (mSettings->GetMode() & 0x03) | ((mSettings->GetOversamplingPressure() & 0x07) << 2) |
				 ((mSettings->GetOversamplingTemperature() & 0x07) << 5);
		mI2c->WriteData( ADDRESS, CTRL_MEAS_REG, &buffer, sizeof( buffer ));

		buffer = ((mSettings->GetFilter() & 0x07) << 2) | ((mSettings->GetStandBy() & 0x07) << 5);
		mI2c->WriteData( ADDRESS, CONFIG_REG, &buffer, sizeof( buffer ));
	}

	int32_t Bmp280::GetRawP() const
	{
		static constexpr uint8_t PRESSURE_MSB_REG = 0xF7;
		uint8_t buffer[3]{};

		WaitUntilFinishedMeasuring();
		mI2c->ReadData( ADDRESS, PRESSURE_MSB_REG, buffer, sizeof( buffer ));
		return ConvertTwentyBitData( buffer );
	}

	void Bmp280::WaitUntilFinishedMeasuring() const
	{
		static constexpr uint8_t STATUS_REG = 0xF3;
		static constexpr uint8_t ONE_BYTE_BUFFER = 0x01;

		uint8_t data = 0x08;
		//TODO Loop
		while( IsDataReady( data ))
		{
			mI2c->ReadData( ADDRESS, STATUS_REG, &data, ONE_BYTE_BUFFER );
		}
	}

	int32_t Bmp280::ConvertTwentyBitData( const uint8_t buffer[3] ) const
	{
		int32_t result = buffer[0] << 16 | buffer[1] << 8 | buffer[2];
		return result >> 4;
	}

	int32_t Bmp280::ConvertSixteenBitData( const uint8_t buffer[2] ) const
	{
		return buffer[0] << 8 | buffer[1];
	}

	bool Bmp280::IsDataReady( uint8_t data ) const
	{
		static constexpr uint8_t MEASURING_BIT = 3;

		return (data & 1 << MEASURING_BIT) == (1 << MEASURING_BIT);
	}

	int32_t Bmp280::GetRawT() const
	{
		static constexpr uint8_t TEMP_MSB_REG = 0xFA;
		uint8_t buffer[3]{};

		WaitUntilFinishedMeasuring();

		mI2c->ReadData( ADDRESS, TEMP_MSB_REG, buffer, sizeof( buffer ));
		return ConvertTwentyBitData( buffer );
	}

	int32_t Bmp280::GetRawH() const
	{
		static constexpr uint8_t HUM_MSB_REG = 0xFD;
		uint8_t buffer[2]{};

		WaitUntilFinishedMeasuring();

		mI2c->ReadData( ADDRESS, HUM_MSB_REG, buffer, sizeof( buffer ));
		return ConvertSixteenBitData( buffer );
	}
}
