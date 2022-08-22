//
// Created by claiff on 14.08.22.
//

#include "first.hpp"

namespace devices::accel::mpu::config::devices::general
{
	uint8_t First::Get() const
	{
		static constexpr uint8_t DLPF_CFG = 0;

		return DLPF_CFG;
	}
}