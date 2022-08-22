//
// Created by claiff on 14.08.22.
//

#include "first.hpp"

namespace devices::accel::mpu::config::fifo::control
{
	uint8_t First::Get() const
	{
		static constexpr uint8_t FIFO_EN_BIT = 0x06;
		//static constexpr uint8_t FIFO_RESET_BIT = 0x02;

		return (1 << FIFO_EN_BIT);// | (1 << FIFO_RESET_BIT);
	}
}