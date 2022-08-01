//
// Created by claiff on 8/15/21.
//
#include "subject.hpp"
#include "pins.hpp"

namespace periphery::uart
{
#define UART_DIV_SAMPLING16( _PCLK_, _BAUD_ )            ((uint32_t)((((uint64_t)(_PCLK_))*25U)/(4U*((uint64_t)(_BAUD_)))))
#define UART_DIVMANT_SAMPLING16( _PCLK_, _BAUD_ )        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING16( _PCLK_, _BAUD_ )        ((((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U)\
                                                         + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
#define UART_BRR_SAMPLING16( _PCLK_, _BAUD_ )            ((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

	Subject* Subject::mInstance = nullptr;

	Subject::Subject( USART_TypeDef* uart, types::IRCC_Ptr const& rcc,
					  std::vector < utils::IObserverPtr > const& registrator )
			:
			mUart( uart )
			, mRcc( rcc )
			, mRegistrator( registrator )
	{
		InitPeriphery();
		InitUART();
		mInstance = this;
	}

	extern "C"
	{
	void USART1_IRQHandler()
	{
		auto& registrator = Subject::mInstance->mRegistrator;
		auto data = USART1->DR;
		USART1->SR &= ~USART_SR_RXNE;
		for( auto& observer: registrator )
		{
			observer->AddData( data );
		}
	}
	}

	//
	//Private methods
	//

	void Subject::InitPeriphery()
	{
		if( mUart == USART1)
		{
			mPeripheryInit = new uart::UART1_ISR( mRcc );
			mRcc->SetGpioUart1Clock();
		}
	}

	void Subject::InitUART()
	{
		mPeripheryInit->InitPeriphery();

		mUart->CR1 |= USART_CR1_RXNEIE;
		mUart->CR1 |= USART_CR1_RE;
		mUart->CR1 |= USART_CR1_UE;
		mUart->BRR = GetBRR( 9600 );
		NVIC_EnableIRQ( USART1_IRQn );
	}

	uint32_t Subject::GetBRR( uint32_t baud_rate )
	{
		uint32_t pclk = 16000000;
		volatile auto temp = UART_BRR_SAMPLING16( pclk, baud_rate );

		return temp;
	}
}
