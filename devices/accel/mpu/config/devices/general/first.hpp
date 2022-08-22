//
// Created by claiff on 14.08.22.
//

#pragma once

#include "accel/mpu/types/iconfig.hpp"

namespace devices::accel::mpu::config::devices::general
{
	//
	//ACCEL
	//Bandwidth=260
	//Delay=0
	//GYRO
	//Bandwidth=256
	//Delay=0.98
	//Fs=8
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