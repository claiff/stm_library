//
// Created by claiff on 14.08.22.
//

#pragma once

#include "accel/mpu/types/iconfig.hpp"

namespace devices::accel::mpu::config::devices::gyro
{
	//
	//Full scale range=2000
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
