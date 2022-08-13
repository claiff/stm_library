//
// Created by claiff on 13.08.22.
//

#pragma once

#include <cstdint>

#include "configurator.hpp"
#include "types/i2c.hpp"

namespace devices::compass::gy
{
	struct CompassData
	{
		uint16_t data_x;
		uint16_t data_y;
		uint16_t data_z;
	};

	class Gy271
	{
	public:
		explicit Gy271( periphery::types::I2CPtr const& i2c, Configurator const& configurator );
		~Gy271() = default;

		CompassData Get() const;
	private:
		void Reset() const;
		void SetMode() const;
		[[nodiscard]] bool IsDataReady() const;
		CompassData GetCompassData() const;
		uint16_t ReadOutputReg( uint8_t reg ) const;

		periphery::types::I2CPtr mI2c;
		Configurator mConfigurator;
	};
}