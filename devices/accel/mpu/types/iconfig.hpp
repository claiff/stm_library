//
// Created by claiff on 14.08.22.
//

#pragma once

#include <cstdint>

namespace devices::accel::mpu::types
{
	class IConfig
	{
	public:
		virtual ~IConfig() = default;

		[[nodiscard]] virtual uint8_t Get() const = 0;
	};
	using IConfigPtr = IConfig*;
}