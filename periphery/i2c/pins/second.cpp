//
// Created by claiff on 6/13/21.
//
#include "second.hpp"

#include "gpio/modes/alternative_mode.hpp"
#include "gpio/output_type/push_pull.hpp"
#include "gpio/speed/very_high_speed.hpp"
#include "gpio/pull/pull_up.hpp"

namespace periphery::i2c::pins
{

	Second::Second( types::IRCC_Ptr const& rcc )
			: mRcc( rcc )
	{
	}

	void Second::InitPeriphery() const
	{
		mRcc->SetGpioBClock();
		//TODO enum class uint16_t
		auto pins = static_cast<uint16_t>(gpio::types::GPIO_PIN::PIN10) +
					static_cast<uint16_t>(gpio::types::GPIO_PIN::PIN11);
		mGpioInit.SetGpio(GPIOB,
						  pins,
						  new gpio::mode::AlternativeMode(),
						  new gpio::output_type::PushPullType(),
						  new gpio::pull::PullUp(),
						  new gpio::speed::VeryHighSpeed(),
						  new gpio::alternative_func::AlternativeFunction( types::FUNC_BITS_I2C ));
	}

}