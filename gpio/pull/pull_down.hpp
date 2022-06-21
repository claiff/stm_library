//
// Created by claiff on 6/13/21.
//
#pragma once

#include "gpio/types/gpio_pull.hpp"

namespace gpio::pull
{
	class PullDown
			: public gpio::types::GpioPull
	{
	public:
		PullDown() = default;
		~PullDown() override = default;

		void SetPull( GPIO_TypeDef* gpio, uint8_t pin ) override;
	};

}