//
// Created by claiff on 6/13/21.
//

#pragma once

#include "gpio/gpio_init.hpp"
#include "types/ircc.hpp"
#include "gpio/types/periphery_init.hpp"

namespace uart
{
  class Pins : public gpio::types::PeripheryInit
  {
  public:
	explicit Pins( types::IRCC_Ptr const& rcc );
	~Pins() override = default;

	void Init() const override;

  private:
	types::IRCC_Ptr mRcc;
	gpio::GpioInit mGpioInit;
  };

}