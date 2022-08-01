//
// Created by claiff on 6/13/21.
//

#include "first.hpp"
#include "gpio/modes/alternative_mode.hpp"
#include "gpio/output_type/open_drain.hpp"
#include "gpio/speed/very_high_speed.hpp"
#include "gpio/pull/pull_up.hpp"

namespace periphery::i2c::pins
{
	First::First( types::IRCC_Ptr const& rcc )
			: mRcc( rcc )
	{
	}

	void First::InitPeriphery() const
	{
		mRcc->SetGpioBClock();
		//TODO enum class uint16_t
		auto pins =
				static_cast<uint16_t>(gpio::types::GPIO_PIN::PIN6) + static_cast<uint16_t>(gpio::types::GPIO_PIN::PIN7);
		mGpioInit.SetGpio(GPIOB,
						  pins,
						  new gpio::mode::AlternativeMode(),
						  new gpio::output_type::OpenDrainType(),
						  new gpio::pull::PullUp(),
						  new gpio::speed::VeryHighSpeed(),
						  new gpio::alternative_func::AlternativeFunction( types::FUNC_BITS_I2C ));
	}

}