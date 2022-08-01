//
// Created by claiff on 6/13/21.
//

#pragma once

#include "gpio/gpio_init.hpp"
#include "types/ircc.hpp"
#include "types/periphery_init.hpp"

namespace periphery::i2c::pins
{
	class Third
			: public types::PeripheryInit
	{
	public:
		explicit Third( types::IRCC_Ptr const& rcc );
		~Third() override = default;

		void InitPeriphery() const override;
	private:
		types::IRCC_Ptr mRcc;
	};

}