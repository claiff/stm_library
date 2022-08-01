//
// Created by claiff on 6/13/21.
//

#pragma once

#include "gpio/gpio_init.hpp"
#include "types/ircc.hpp"
#include "types/periphery_init.hpp"

namespace periphery::uart
{
  class UART1_ISR : public periphery::types::PeripheryInit
  {
  public:
	explicit UART1_ISR( types::IRCC_Ptr const& rcc );
	~UART1_ISR() override = default;

	void InitPeriphery() const noexcept override;

  private:
	  types::IRCC_Ptr mRcc;
	gpio::GpioInit mGpioInit;
  };

}