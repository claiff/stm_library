//
// Created by claiff on 11.08.22.
//

#include "humidity_only.hpp"

namespace devices::pressure::bmp::settings
{
	uint8_t HumidityOnly::GetMode() const
	{
		static constexpr uint8_t FORCED_MODE = 0x01;
		return FORCED_MODE;
	}

	uint8_t HumidityOnly::GetOversamplingPressure() const
	{
		static constexpr uint8_t OVERSAMPLE_SKIPPED = 0x00;
		return OVERSAMPLE_SKIPPED;
	}

	uint8_t HumidityOnly::GetOversamplingTemperature() const
	{
		static constexpr uint8_t OVERSAMPLE_1 = 0x01;
		return OVERSAMPLE_1;
	}

	uint8_t HumidityOnly::GetOversamplingHumidity() const
	{
		static constexpr uint8_t OVERSAMPLE_1 = 0x01;
		return OVERSAMPLE_1;
	}

	uint8_t HumidityOnly::GetFilter() const
	{
		static constexpr uint8_t FILTER_OFF = 0x00;
		return FILTER_OFF;
	}

	uint8_t HumidityOnly::GetStandBy() const
	{
		static constexpr uint8_t STAND_BY_1000 = 0x05;
		return STAND_BY_1000;
	}
}