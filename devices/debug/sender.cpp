//
// Created by claiff on 11.07.22.
//

#include "sender.hpp"

namespace devices::debug
{

	Sender::Sender( USART_TypeDef* usart )
			: mUsart( usart )
	{

	}

	void Sender::Send( uint8_t* data, size_t size ) const
	{
		for( auto i = 0; i < size; ++i )
		{
			mUsart->DR = data[i];
			if((mUsart->SR & USART_SR_TC) != USART_SR_TC)
			{
			}
		}
	}
}