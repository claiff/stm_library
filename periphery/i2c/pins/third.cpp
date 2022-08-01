//
// Created by claiff on 6/13/21.
//
#include "third.hpp"
#include "gpio/modes/alternative_mode.hpp"
#include "gpio/output_type/push_pull.hpp"
#include "gpio/speed/very_high_speed.hpp"
#include "gpio/pull/pull_up.hpp"

namespace periphery::i2c::pins
{
	Third::Third( types::IRCC_Ptr const& rcc )
			: mRcc( rcc )
	{
	}

	void Third::InitPeriphery() const
	{
		gpio::GpioInit gpio_init;
		mRcc->SetGpioAClock();
		mRcc->SetGpioCClock();
		//TODO enum class uint16_t
		auto pins = static_cast<uint16_t>(gpio::types::GPIO_PIN::PIN8);
		gpio_init.SetGpio(GPIOA,
						  pins,
						  new gpio::mode::AlternativeMode(),
						  new gpio::output_type::PushPullType(),
						  new gpio::pull::PullUp(),
						  new gpio::speed::VeryHighSpeed(),
						  new gpio::alternative_func::AlternativeFunction(
								  types::FUNC_BITS_I2C ));

		pins = static_cast<uint16_t>(gpio::types::GPIO_PIN::PIN9);
		gpio_init.SetGpio(GPIOC,
						  pins,
						  new gpio::mode::AlternativeMode(),
						  new gpio::output_type::PushPullType(),
						  new gpio::pull::PullUp(),
						  new gpio::speed::VeryHighSpeed(),
						  new gpio::alternative_func::AlternativeFunction(
								  types::FUNC_BITS_I2C ));
	}
}