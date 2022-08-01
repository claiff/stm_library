//
// Created by claiff on 31.07.22.
//

#include <vector>

#include "bh1721.hpp"

namespace devices::light
{
	static constexpr uint8_t ADDRESS_BH = 0x23;

	//
	//Constructs
	//
	BH1721::BH1721( periphery::types::I2CPtr const& i2c )
			: mI2c( i2c )
			, mSensitivity( 1 )
	{
		SetPower( PowerState::Off );
		SetPower( PowerState::On );
		ChangeSensitivity( 1 );
		SetMode( ResolutionMode::High );
	}

	//
	//Public methods
	//
	uint16_t BH1721::Get() const
	{
		auto lx = ReadData();

		uint16_t result = lx/1.2;
		return result / mSensitivity;
	}

	//
	//Private methods
	//
	void BH1721::SetPower( PowerState state ) const
	{
		static const uint8_t ZERO_SIZE = 0;
		static constexpr uint8_t POWER_DOWN_REG = 0x00;
		static constexpr uint8_t POWER_ON_REG = 0x01;
		uint8_t* buffer = nullptr;

		state == PowerState::On ? mI2c->WriteData( ADDRESS_BH, POWER_ON_REG, buffer, sizeof( buffer )) :
		mI2c->WriteData( ADDRESS_BH, POWER_DOWN_REG, buffer, ZERO_SIZE);
	}

	void BH1721::ChangeSensitivity( float sensitivity )
	{
		//TODO todo
		mSensitivity = sensitivity;
	}

	void BH1721::SetMode( ResolutionMode mode ) const
	{
		static constexpr uint8_t HIGH_RESOLUTION_REG = 0x12;
		static constexpr uint8_t LOW_RESOLUTION_REG = 0x13;
		static constexpr uint8_t AUTO_RESOLUTION_REG = 0x10;

		uint8_t command = 0;
		std::vector < uint8_t > buffer;

		if( mode == ResolutionMode::Auto )
		{
			command = AUTO_RESOLUTION_REG;
			buffer.push_back( 0x20 );
		}
		else if( mode == ResolutionMode::High )
		{
			command = HIGH_RESOLUTION_REG;
			buffer.push_back( 0x22 );
		}
		else if( mode == ResolutionMode::Low )
		{
			command = HIGH_RESOLUTION_REG;
			buffer.push_back( 0x16 );
			buffer.push_back( 0x23 );
			buffer.push_back( 0x26 );
		}
		else
		{
			return;
		}
		mI2c->WriteData( ADDRESS_BH, command, buffer.data(), buffer.size());
	}

	uint16_t BH1721::ReadData() const
	{
		static constexpr uint8_t DATA_REG = 0x23;

		uint8_t buffer[2];

		mI2c->ReadData( ADDRESS_BH, DATA_REG, buffer, sizeof( buffer ));
		return buffer[0] << 8 |  buffer[1];
	}
}