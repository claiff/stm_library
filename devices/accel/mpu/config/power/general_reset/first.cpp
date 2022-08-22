//
// Created by claiff on 14.08.22.
//

#include "first.hpp"

namespace devices::accel::mpu::config::power::general_reset
{
	uint8_t First::Get() const
	{
		//TODO
		//static constexpr uint8_t DEVICE_RESET_BIT = 0x07;
		static constexpr uint8_t TEMP_DIS_BIT = 0x03;

		return (1 << TEMP_DIS_BIT);
	}
}