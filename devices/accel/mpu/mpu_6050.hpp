//
// Created by claiff on 13.08.22.
//

#pragma once

#include <vector>

#include "types/i2c.hpp"
#include "configurator.hpp"

namespace devices::accel::mpu
{
	struct DeviceData
	{
		uint16_t x;
		uint16_t y;
		uint16_t z;
	};

	struct AccelData
	{
		DeviceData gyro;
		DeviceData accel;
	};

	using AccelDataSet = std::vector < AccelData >;

	class Mpu6050
	{
	public:
		Mpu6050( periphery::types::I2CPtr const& i2c, Configurator const& configurator );
		~Mpu6050() = default;

		[[nodiscard]] bool IsOnline() const;
		[[nodiscard]] AccelDataSet GetData() const;
	private:
		void ApplyData( uint8_t const buffer[12], AccelData& data ) const;
		[[nodiscard]] uint16_t GetCountData() const;

		periphery::types::I2CPtr mI2c;
		Configurator mConfigurator;


	};
}


