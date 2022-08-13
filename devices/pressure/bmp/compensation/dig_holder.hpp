//
// Created by claiff on 11.08.22.
//

#pragma once

#include "types/i2c.hpp"

namespace devices::pressure::bmp::compensation
{
	class DigHolder
	{
	public:
		explicit DigHolder( periphery::types::I2CPtr const& i2c );
		~DigHolder() = default;

		uint16_t mDigT1;
		int16_t mDigT2;
		int16_t mDigT3;

		uint16_t mDigP1;
		int16_t mDigP2;
		int16_t mDigP3;
		int16_t mDigP4;
		int16_t mDigP5;
		int16_t mDigP6;
		int16_t mDigP7;
		int16_t mDigP8;
		int16_t mDigP9;

		uint8_t mDigH1;
		int16_t mDigH2;
		uint8_t mDigH3;
		int16_t mDigH4;
		int16_t mDigH5;
		int8_t mDigH6;
	private:
		void GetDigT();
		void GetDigP();
		void GetDigH();

		periphery::types::I2CPtr mI2c;
	};
}