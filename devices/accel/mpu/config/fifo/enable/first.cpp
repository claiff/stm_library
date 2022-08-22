//
// Created by claiff on 14.08.22.
//

#include "first.hpp"

namespace devices::accel::mpu::config::fifo::enable
{

	uint8_t First::Get() const
	{
		static constexpr uint8_t XG_FIFO_EN_BIT = 0x06;
		static constexpr uint8_t YG_FIFO_EN_BIT = 0x05;
		static constexpr uint8_t ZG_FIFO_EN_BIT = 0x04;
		static constexpr uint8_t ACCEL_FIFO_EN_BIT = 0x03;

		return  0;
	}
}