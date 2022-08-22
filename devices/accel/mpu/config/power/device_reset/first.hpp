//
// Created by claiff on 14.08.22.
//

#pragma once

#include "accel/mpu/types/iconfig.hpp"

namespace devices::accel::mpu::config::power::device_reset
{
	//
	//Gyro_reset=1
	//Accel_reset=1
	//Temp_reset=0
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
