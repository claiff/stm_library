//
// Created by claiff on 31.07.22.
//

#pragma once

#include "types/i2c.hpp"
#include "types/imode.hpp"

namespace devices::light::bh
{
	class BH1721
	{
	public:
		BH1721( periphery::types::I2CPtr const& i2c, types::IModePtr const& mode );
		~BH1721() = default;

		[[nodiscard]] uint16_t Get() const;
	private:
		void ResetPower() const;
		void ChangeSensitivity( float sensitivity );
		void SetMode() const;
		[[nodiscard]] uint16_t ReadData() const;

		periphery::types::I2CPtr mI2c;
		float mSensitivity;
		types::IModePtr mMode;
	};
}

