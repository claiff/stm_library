//
// Created by claiff on 8/15/21.
//

#pragma once

#include <vector>

#include "misc/stm32f407xx.h"
#include "types/ircc.hpp"
#include "types/periphery_init.hpp"
#include "utils/observer.hpp"

namespace periphery::uart
{
	class Subject final
	{
	public:
		Subject( USART_TypeDef* uart, types::IRCC_Ptr const& rcc,
				   std::vector < utils::IObserverPtr > const& registrator );
		static Subject* mInstance;
		std::vector < utils::IObserverPtr > mRegistrator;
	private:
		void InitPeriphery();
		void InitUART();
		uint32_t GetBRR( uint32_t baud_rate );

		USART_TypeDef* mUart;
		types::IRCC_Ptr mRcc;
		types::PeripheryInitPtr mPeripheryInit;
	};
}

