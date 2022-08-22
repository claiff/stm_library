//
// Created by claiff on 14.08.22.
//

#pragma once

#include "accel/mpu/types/iconfig.hpp"

namespace devices::accel::mpu::config::fifo::enable
{
	//
	//TEMP_FIFO_EN=0
	//XG_FIFO_EN=1
	//YG_FIFO_EN=1
	//ZG_FIFO_EN=1
	//ACCEL_FIFO_EN=1
	//SLV2_FIFO_EN=0
	//SLV1_FIFO_EN=0
	//SLV0_FIFO_EN=0
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