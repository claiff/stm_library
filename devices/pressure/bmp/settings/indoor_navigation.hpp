//
// Created by claiff on 11.08.22.
//

#pragma once

#include "pressure/bmp/types/isettings.hpp"

namespace devices::pressure::bmp::settings
{
	class IndoorNavigation
			: public types::ISettings
	{
	public:
		IndoorNavigation() = default;
		~IndoorNavigation() override = default;

		[[nodiscard]] uint8_t GetMode() const override;
		[[nodiscard]] uint8_t GetOversamplingPressure() const override;
		[[nodiscard]] uint8_t GetOversamplingTemperature() const override;
		[[nodiscard]] uint8_t GetOversamplingHumidity() const override;
		[[nodiscard]] uint8_t GetFilter() const override;
		[[nodiscard]] uint8_t GetStandBy() const override;
	};
}