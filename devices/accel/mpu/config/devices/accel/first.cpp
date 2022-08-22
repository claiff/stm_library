//
// Created by claiff on 14.08.22.
//

#include "first.hpp"

namespace devices::accel::mpu::config::devices::accel
{

	uint8_t First::Get() const
	{
		static constexpr uint8_t AFS_SEL_BIT = 0x03;
		static constexpr uint8_t DATA = 0x03;

		return (DATA << AFS_SEL_BIT);
	}
}