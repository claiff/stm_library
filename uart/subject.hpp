//
// Created by claiff on 8/15/21.
//

#pragma once

#include "misc/stm32f407xx.h"
#include "types/ircc.hpp"
#include "gpio/types/periphery_init.hpp"

namespace uart
{
	class Subject final
	{
	public:
		Subject();
		static Subject* mInstance;
	private:
		void InitUART();
		void InitPins( types::IRCC_Ptr rcc );
		uint32_t GetBRR( uint32_t baud_rate );
	};
}

