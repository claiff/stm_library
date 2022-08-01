//
// Created by claiff on 31.07.22.
//

#pragma once

#include "types/i2c.hpp"

namespace devices::light
{
	enum class PowerState
	{
		On,
		Off
	};
	enum class ResolutionMode
	{
		High,
		Low,
		Auto
	};

	class BH1721
	{
	public:
		explicit BH1721( periphery::types::I2CPtr const& i2c );
		~BH1721() = default;

		[[nodiscard]] uint16_t Get() const;
	private:
		void SetPower( PowerState state ) const;
		void ChangeSensitivity( float sensitivity );
		void SetMode( ResolutionMode mode ) const;
		[[nodiscard]] uint16_t ReadData() const;

		periphery::types::I2CPtr mI2c;
		float mSensitivity;
	};
}

