//
// Created by claiff on 31.07.22.
//

#include <vector>

#include "bh1721.hpp"

namespace devices::light::bh
{
	static constexpr uint8_t ADDRESS_BH = 0x46;

	//
	//Constructs
	//
	BH1721::BH1721( periphery::types::I2CPtr const& i2c, types::IModePtr const& mode )
			: mI2c( i2c )
			, mSensitivity( 1 )
			, mMode( mode )
	{
		ResetPower();
		ChangeSensitivity( 1 );
		SetMode( );
	}

	//
	//Public methods
	//
	uint16_t BH1721::Get() const
	{
		auto lx = ReadData();

		uint16_t result = lx / 1.2;
		return result / mSensitivity;
	}

	//
	//Private methods
	//
	void BH1721::ResetPower() const
	{
		static const uint8_t ZERO_SIZE = 0;
		static constexpr uint8_t POWER_DOWN_REG = 0x00;
		static constexpr uint8_t POWER_ON_REG = 0x01;

		uint8_t* buffer{};

		mI2c->WriteData( ADDRESS_BH, POWER_DOWN_REG, buffer, ZERO_SIZE );
		mI2c->WriteData( ADDRESS_BH, POWER_ON_REG, buffer, ZERO_SIZE );
	}

	void BH1721::ChangeSensitivity( float sensitivity )
	{
		//TODO todo
		mSensitivity = sensitivity;
	}

	void BH1721::SetMode() const
	{
		auto mode = mMode->Get();
		mI2c->WriteData( ADDRESS_BH, mode.command, mode.data.data(), mode.data.size());
	}

	uint16_t BH1721::ReadData() const
	{
		static constexpr uint8_t DATA_REG = 0x23;

		uint8_t buffer[2];

		mI2c->ReadData( ADDRESS_BH, DATA_REG, buffer, sizeof( buffer ));
		return buffer[0] << 8 | buffer[1];
	}
}