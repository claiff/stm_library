//
// Created by claiff on 11.08.22.
//

#include "dig_holder.hpp"

namespace devices::pressure::bmp::compensation
{
	static constexpr uint8_t ADDRESS = 0xEC;
	DigHolder::DigHolder( periphery::types::I2CPtr const& i2c )
			: mI2c( i2c )
	{
		GetDigP();
		GetDigT();
		GetDigH();
	}

	void DigHolder::GetDigT()
	{
		static constexpr uint8_t DIG_T1_LSB_REG = 0x88;
		static constexpr uint8_t DIG_T2_LSB_REG = 0x8A;
		static constexpr uint8_t DIG_T3_LSB_REG = 0x8C;

		uint8_t buffer[2]{};
		mI2c->ReadData( ADDRESS, DIG_T1_LSB_REG, buffer, sizeof( buffer ));
		mDigT1 = buffer[0] | (buffer[1] << 8);

		mI2c->ReadData( ADDRESS, DIG_T2_LSB_REG, buffer, sizeof( buffer ));
		mDigT2 = buffer[0] | (buffer[1] << 8);

		mI2c->ReadData( ADDRESS, DIG_T3_LSB_REG, buffer, sizeof( buffer ));
		mDigT3 = buffer[0] | (buffer[1] << 8);
	}

	void DigHolder::GetDigP()
	{
		static constexpr uint8_t DIG_P1_LSB_REG = 0x8E;
		static constexpr uint8_t DIG_P2_LSB_REG = 0x90;
		static constexpr uint8_t DIG_P3_LSB_REG = 0x92;
		static constexpr uint8_t DIG_P4_LSB_REG = 0x94;
		static constexpr uint8_t DIG_P5_LSB_REG = 0x96;
		static constexpr uint8_t DIG_P6_LSB_REG = 0x98;
		static constexpr uint8_t DIG_P7_LSB_REG = 0x9A;
		static constexpr uint8_t DIG_P8_LSB_REG = 0x9C;
		static constexpr uint8_t DIG_P9_LSB_REG = 0x9E;

		uint8_t buffer[2]{};
		mI2c->ReadData( ADDRESS, DIG_P1_LSB_REG, buffer, sizeof( buffer ));
		mDigP1 = buffer[0] | (buffer[1] << 8);

		mI2c->ReadData( ADDRESS, DIG_P2_LSB_REG, buffer, sizeof( buffer ));
		mDigP2 = static_cast<int16_t>(buffer[0] | (buffer[1] << 8));

		mI2c->ReadData( ADDRESS, DIG_P3_LSB_REG, buffer, sizeof( buffer ));
		mDigP3 = static_cast<int16_t>(buffer[0] | (buffer[1] << 8));

		mI2c->ReadData( ADDRESS, DIG_P4_LSB_REG, buffer, sizeof( buffer ));
		mDigP4 = static_cast<int16_t>(buffer[0] | (buffer[1] << 8));

		mI2c->ReadData( ADDRESS, DIG_P5_LSB_REG, buffer, sizeof( buffer ));
		mDigP5 = static_cast<int16_t>(buffer[0] | (buffer[1] << 8));

		mI2c->ReadData( ADDRESS, DIG_P6_LSB_REG, buffer, sizeof( buffer ));
		mDigP6 = static_cast<int16_t>(buffer[0] | (buffer[1] << 8));

		mI2c->ReadData( ADDRESS, DIG_P7_LSB_REG, buffer, sizeof( buffer ));
		mDigP7 = static_cast<int16_t>(buffer[0] | (buffer[1] << 8));

		mI2c->ReadData( ADDRESS, DIG_P8_LSB_REG, buffer, sizeof( buffer ));
		mDigP8 = static_cast<int16_t>(buffer[0] | (buffer[1] << 8));

		mI2c->ReadData( ADDRESS, DIG_P9_LSB_REG, buffer, sizeof( buffer ));
		mDigP9 = static_cast<int16_t>(buffer[0] | (buffer[1] << 8));
	}

	void DigHolder::GetDigH()
	{
		static constexpr uint8_t DIG_H1_REG = 0xA1;
		static constexpr uint8_t DIG_H2_LSB_REG = 0xE1;
		static constexpr uint8_t DIG_H3_REG = 0xE3;
		static constexpr uint8_t DIG_H4_LSB_REG = 0xE4;
		static constexpr uint8_t DIG_H5_LSB_REG = 0xE5;
		static constexpr uint8_t DIG_H6_REG = 0xE7;

		static constexpr uint8_t H1_H3_H6_SIZE = 1;

		uint8_t buffer[2]{};
		mI2c->ReadData( ADDRESS, DIG_H1_REG, buffer, H1_H3_H6_SIZE );
		mDigH1 = buffer[0];

		mI2c->ReadData( ADDRESS, DIG_H2_LSB_REG, buffer, sizeof( buffer ));
		mDigH2 = buffer[0] | (buffer[1] << 8);

		mI2c->ReadData( ADDRESS, DIG_H3_REG, buffer, H1_H3_H6_SIZE );
		mDigH3 = buffer[0];

		mI2c->ReadData( ADDRESS, DIG_H4_LSB_REG, buffer, sizeof( buffer ));
		mDigH4 = (buffer[0] << 4) | (buffer[1] & 0x07);

		mI2c->ReadData( ADDRESS, DIG_H5_LSB_REG, buffer, sizeof( buffer ));
		mDigH5 = (buffer[0] & 0x07) | (buffer[1] << 4);

		mI2c->ReadData( ADDRESS, DIG_H6_REG, buffer, H1_H3_H6_SIZE );
		mDigH6 = buffer[0];
	}
}