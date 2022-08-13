//
// Created by claiff on 11.08.22.
//

#include "gaming.hpp"

namespace devices::pressure::bmp::settings
{
	uint8_t Gaming::GetMode() const
	{
		static constexpr uint8_t NORMAL_MODE = 0x03;
		return NORMAL_MODE;
	}

	uint8_t Gaming::GetOversamplingPressure() const
	{
		static constexpr uint8_t OVERSAMPLE_4 = 0x03;
		return OVERSAMPLE_4;
	}

	uint8_t Gaming::GetOversamplingTemperature() const
	{
		static constexpr uint8_t OVERSAMPLE_1 = 0x01;
		return OVERSAMPLE_1;
	}

	uint8_t Gaming::GetOversamplingHumidity() const
	{
		static constexpr uint8_t OVERSAMPLE_SKIPPED = 0x00;
		return OVERSAMPLE_SKIPPED;
	}

	uint8_t Gaming::GetFilter() const
	{
		static constexpr uint8_t FILTER_16 = 0x04;
		return FILTER_16;
	}

	uint8_t Gaming::GetStandBy() const
	{
		static constexpr uint8_t STAND_BY_0_5 = 0x00;
		return STAND_BY_0_5;
	}
}