//
// Created by claiff on 6/13/21.
//
#include "pins.hpp"
#include "gpio/modes/alternative_mode.hpp"
#include "gpio/modes/input_mode.hpp"
#include "gpio/output_type/push_pull.hpp"
#include "gpio/speed/very_high_speed.hpp"
#include "gpio/pull/pull_up.hpp"
#include "gpio/pull/no_pull.hpp"

namespace periphery::uart
{

	UART1_ISR::UART1_ISR( types::IRCC_Ptr const& rcc )
			:
			mRcc( rcc )
	{
	}

	void UART1_ISR::InitPeriphery() const noexcept
	{
		mRcc->SetGpioAClock();
		//TODO enum class uint16_t намутить приведение
		auto pins = static_cast<uint16_t>(gpio::types::GPIO_PIN::PIN9);
		mGpioInit.SetGpio(GPIOA,
						  pins,
						  new gpio::mode::AlternativeMode(),
						  new gpio::output_type::PushPullType(),
						  new gpio::pull::PullUp(),
						  new gpio::speed::VeryHighSpeed(),
						  new gpio::alternative_func::AlternativeFunction( types::FUNC_BITS_UART ));
		pins = static_cast<uint16_t>(gpio::types::GPIO_PIN::PIN10);
		mGpioInit.SetGpio(GPIOA,
						  pins,
						  new gpio::mode::AlternativeMode(),
						  new gpio::output_type::PushPullType(),
						  new gpio::pull::PullNo(),
						  new gpio::speed::VeryHighSpeed(),
						  new gpio::alternative_func::AlternativeFunction( types::FUNC_BITS_UART ));
	}

}