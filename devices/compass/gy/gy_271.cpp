//
// Created by claiff on 13.08.22.
//

#include "gy_271.hpp"
#include <cstdint>

namespace devices::compass::gy
{
	static constexpr uint8_t ADDRESS_GY = 0x1A;

	Gy271::Gy271( periphery::types::I2CPtr const& i2c, Configurator const& configurator )
			: mI2c( i2c )
			, mConfigurator( configurator )
	{
		Reset();
		SetMode();
	}

	CompassData Gy271::Get() const
	{
		//TODO loop
		while( !IsDataReady());
		return GetCompassData();
	}

	void Gy271::Reset() const
	{
		static constexpr uint8_t CONTROL2_REG = 0x0A;
		static constexpr uint8_t RESET_BIT = 0x07;

		uint8_t buffer = 1 << RESET_BIT;

		mI2c->WriteData( ADDRESS_GY, CONTROL2_REG, &buffer, sizeof( buffer ));
	}

	void Gy271::SetMode() const
	{
		static constexpr uint8_t CONTROL1_REG = 0x09;
		auto buffer = mConfigurator.GetRegData();

		mI2c->WriteData( ADDRESS_GY, CONTROL1_REG, &buffer, sizeof( buffer ));
	}

	bool Gy271::IsDataReady() const
	{
		static constexpr uint8_t STATUS_REG = 0x06;
		static constexpr uint8_t DRDY_BIT = 0x00;
		uint8_t buffer = 0;

		mI2c->ReadData( ADDRESS_GY, STATUS_REG, &buffer, sizeof( buffer ));
		return (buffer & (1 << DRDY_BIT)) == (1 << DRDY_BIT);
	}

	CompassData Gy271::GetCompassData() const
	{
		static constexpr uint8_t DATA_X_LSB_REG = 0x00;
		static constexpr uint8_t DATA_Y_LSB_REG = 0x02;
		static constexpr uint8_t DATA_Z_LSB_REG = 0x04;

		CompassData result{};

		result.data_x = ReadOutputReg( DATA_X_LSB_REG );
		result.data_y = ReadOutputReg( DATA_Y_LSB_REG );
		result.data_z = ReadOutputReg( DATA_Z_LSB_REG );
		return result;
	}

	uint16_t Gy271::ReadOutputReg( uint8_t reg ) const
	{
		uint8_t buffer[2]{};
		mI2c->ReadData( ADDRESS_GY, reg, buffer, sizeof( buffer ));
		return buffer[1] << 8 | buffer[0];
	}


}