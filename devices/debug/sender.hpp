//
// Created by claiff on 11.07.22.
//

#pragma once

#include <cstddef>
#include "misc/stm32f407xx.h"

namespace devices::debug
{
	class Sender
	{
	public:
		explicit Sender( USART_TypeDef* usart );
		~Sender() = default;

		void Send( uint8_t* data, size_t size ) const;
	private:
		USART_TypeDef* mUsart;
	};
}