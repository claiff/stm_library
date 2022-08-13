//
// Created by claiff on 10.08.22.
//

#pragma once

#include <cstdint>

namespace devices::pressure::bmp::types
{
	class ISettings
	{
	public:
		virtual ~ISettings() = default;

		virtual uint8_t GetMode() const = 0;
		virtual uint8_t GetOversamplingPressure() const = 0;
		virtual uint8_t GetOversamplingTemperature() const = 0;
		virtual uint8_t GetOversamplingHumidity() const = 0;
		virtual uint8_t GetFilter() const = 0;
		virtual uint8_t GetStandBy() const = 0;
	};
	using ISettingsPtr = ISettings*;
}