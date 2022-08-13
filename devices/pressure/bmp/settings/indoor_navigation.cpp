//
// Created by claiff on 11.08.22.
//

#include "indoor_navigation.hpp"

namespace devices::pressure::bmp::settings
{
	uint8_t IndoorNavigation::GetMode() const
	{
		static constexpr uint8_t NORMAL_MODE = 0x03;
		return NORMAL_MODE;
	}

	uint8_t IndoorNavigation::GetOversamplingPressure() const
	{
		static constexpr uint8_t OVERSAMPLE_16 = 0x05;
		return OVERSAMPLE_16;
	}

	uint8_t IndoorNavigation::GetOversamplingTemperature() const
	{
		static constexpr uint8_t OVERSAMPLE_2 = 0x02;
		return OVERSAMPLE_2;
	}

	uint8_t IndoorNavigation::GetOversamplingHumidity() const
	{
		static constexpr uint8_t OVERSAMPLE_1 = 0x01;
		return OVERSAMPLE_1;
	}

	uint8_t IndoorNavigation::GetFilter() const
	{
		static constexpr uint8_t FILTER_16 = 0x04;
		return FILTER_16;
	}

	uint8_t IndoorNavigation::GetStandBy() const
	{
		static constexpr uint8_t STAND_BY_0_5 = 0x00;
		return STAND_BY_0_5;
	}
}