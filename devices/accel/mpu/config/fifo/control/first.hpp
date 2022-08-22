//
// Created by claiff on 14.08.22.
//

#pragma once

#include "accel/mpu/types/iconfig.hpp"

namespace devices::accel::mpu::config::fifo::control
{
	//
	//FIFO_EN=1
	//I2C_MASTER_EN=0
	//I2C_IF_DIS=0
	//FIFO_RESET=1
	//I2C_MST_RESET=0
	//SIG_COND_RESET=0
	//
	class First
			: public types::IConfig
	{
	public:
		First() = default;
		~First() override = default;

		[[nodiscard]] uint8_t Get() const override;
	};
}