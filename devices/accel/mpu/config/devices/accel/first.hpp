//
// Created by claiff on 14.08.22.
//

#pragma once

#include "accel/mpu/types/iconfig.hpp"

namespace devices::accel::mpu::config::devices::accel
{
	//
	//Full scale range=16
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