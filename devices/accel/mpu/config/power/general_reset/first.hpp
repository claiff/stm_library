//
// Created by claiff on 14.08.22.
//

#pragma once

#include "accel/mpu/types/iconfig.hpp"

namespace devices::accel::mpu::config::power::general_reset
{
	//
	//Device_Reset=1
	//SLEEP=0
	//CYCLE=0
	//TEMP_DIS=1
	//CLKSEL=0
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



