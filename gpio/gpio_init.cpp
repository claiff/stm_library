//
// Created by claiff on 6/13/21.
//
#include "gpio_init.hpp"

namespace gpio
{
	void GpioInit::SetGpio( GPIO_TypeDef* gpio,
							uint16_t group_pins,
							const gpio::types::GPIO_ModePtr& gpio_mode,
							const gpio::types::GpioOutputTypePtr& output_type,
							const gpio::types::GpioPullPtr& pull,
							const gpio::types::GpioSpeedPtr& speed,
							alternative_func::AlternativeFunctionPtr const& func ) const
	{
		gpio_mode->SetMode( gpio, group_pins );
		output_type->SetOutputType( gpio, group_pins );
		pull->SetPull( gpio, group_pins );
		speed->SetSpeed( gpio, group_pins );
		func->SetFunction( gpio, group_pins );
	}
}


