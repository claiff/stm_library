//
// Created by claiff on 14.08.22.
//

#include "first.hpp"

namespace devices::accel::mpu::config::power::device_reset
{

	uint8_t First::Get() const
	{
		static constexpr uint8_t GYRO_RESET_BIT = 0x02;
		static constexpr uint8_t ACCEL_RESET_BIT = 0x01;

		return (1 << GYRO_RESET_BIT) | (1 << ACCEL_RESET_BIT);
	}
}