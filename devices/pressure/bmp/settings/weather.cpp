//
// Created by claiff on 10.08.22.
//

#include "weather.hpp"

namespace devices::pressure::bmp::settings
{
	uint8_t Weather::GetMode() const
	{
		static constexpr uint8_t FORCED_MODE = 0x01;
		return FORCED_MODE;
	}

	uint8_t Weather::GetOversamplingPressure() const
	{
		static constexpr uint8_t OVERSAMPLE_1 = 0x01;
		return OVERSAMPLE_1;
	}

	uint8_t Weather::GetOversamplingTemperature() const
	{
		static constexpr uint8_t OVERSAMPLE_1 = 0x01;
		return OVERSAMPLE_1;
	}

	uint8_t Weather::GetOversamplingHumidity() const
	{
		static constexpr uint8_t OVERSAMPLE_1 = 0x01;
		return OVERSAMPLE_1;
	}

	uint8_t Weather::GetFilter() const
	{
		static constexpr uint8_t FILTER_OFF = 0x00;
		return FILTER_OFF;
	}

	uint8_t Weather::GetStandBy() const
	{
		static constexpr uint8_t STAND_BY_1000 = 0x05;
		return STAND_BY_1000;
	}
}