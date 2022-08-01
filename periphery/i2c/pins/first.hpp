//
// Created by claiff on 6/13/21.
//

#pragma once

#include "gpio/gpio_init.hpp"
#include "types/ircc.hpp"
#include "types/periphery_init.hpp"

namespace periphery::i2c::pins
{
	class First : public types::PeripheryInit
	{
	public:
		explicit First( types::IRCC_Ptr const& rcc );
		~First() override = default;

		void InitPeriphery() const override;

	private:
		types::IRCC_Ptr mRcc;
		gpio::GpioInit mGpioInit;
	};

}