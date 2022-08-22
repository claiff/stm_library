//
// Created by claiff on 14.08.22.
//

#pragma once

#include "accel/mpu/mpu_6050.hpp"

namespace devices::accel::mpu::builder
{
	class First
	{
	public:
		First() = default;
		~First() = default;

		[[nodiscard]] Mpu6050 Build(periphery::types::I2CPtr const& i2c) const;
	};
}
