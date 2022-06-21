//
// Created by claiff on 6/13/21.
//
#pragma once

#include "misc/stm32f407xx.h"
#include "gpio/types/gpio_mode.hpp"
#include "gpio/types/gpio_output_type.hpp"
#include "gpio/types/gpio_pull.hpp"
#include "gpio/types/gpio_speed.hpp"
#include "gpio/alternative_function/alternative_function.hpp"

namespace gpio
{
	class GpioInit
	{
	public:
		GpioInit() = default;
		virtual ~GpioInit() = default;

		void SetGpio( GPIO_TypeDef* gpio,
					  uint16_t group_pins,
					  gpio::types::GPIO_ModePtr const& gpio_mode,
					  gpio::types::GpioOutputTypePtr const& output_type,
					  gpio::types::GpioPullPtr const& pull,
					  gpio::types::GpioSpeedPtr const& speed,
					  alternative_func::AlternativeFunctionPtr const& func ) const;
	};

}