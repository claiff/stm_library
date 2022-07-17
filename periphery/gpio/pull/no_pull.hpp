//
// Created by claiff on 6/13/21.
//
#pragma once

#include "gpio/types/gpio_pull.hpp"

namespace gpio::pull
{
	class PullNo
			: public gpio::types::GpioPull
	{
	public:
		PullNo() = default;
		~PullNo() override = default;

		void SetPull( GPIO_TypeDef* gpio, uint8_t pin ) override;
	};

}