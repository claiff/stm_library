//
// Created by claiff on 01.08.22.
//

#pragma once

#include "types/i2c.hpp"
#include "pressure/bmp/compensation/compensator.hpp"
#include "types/isettings.hpp"
#include "compensation/dig_holder.hpp"

namespace devices::pressure::bmp
{
	class Bmp280
	{
	public:
		Bmp280( periphery::types::I2CPtr const& i2c, types::ISettingsPtr const& settings );
		~Bmp280() = default;

		[[nodiscard]] bool IsOnline() const;
		[[nodiscard]] int32_t GetTemperature() const;
		[[nodiscard]] uint32_t GetPressure() const;
		[[nodiscard]] uint32_t GetHumidity() const;

	private:
		void Reset() const;
		void SetupSensor() const;
		[[nodiscard]] int32_t GetRawP() const;
		void WaitUntilFinishedMeasuring() const;
		int32_t ConvertTwentyBitData( uint8_t const buffer[3] ) const;
		int32_t ConvertSixteenBitData( uint8_t const buffer[2] ) const;
		[[nodiscard]] bool IsDataReady( uint8_t data ) const;
		[[nodiscard]] int32_t GetRawT() const;
		[[nodiscard]] int32_t GetRawH() const;

		periphery::types::I2CPtr mI2c;
		compensation::Compensator mCompensator;
		types::ISettingsPtr mSettings;

	};
}

