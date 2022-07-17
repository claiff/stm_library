//
// Created by claiff on 8/15/21.
//
#include "subject.hpp"
#include "pins.hpp"
#include "rcc/simple_rcc.hpp"


namespace uart
{

	//TODO !!!!Разобраться с этим!!!!

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

	Subject::Subject()
	{
		InitUART();
		mInstance = this;
	}

	extern "C" void USART1_IRQHandler()
	{
		USART1->SR &= ~USART_SR_RXNE;
	}

	//
	//Private methods
	//

	void Subject::InitUART()
	{
		rcc::SimpleRCC rcc;
        ${
            InitPins( $uart, &rcc );

            rcc.SetUart( $uart );
            USART1->CR1 |= USART_CR1_RXNEIE;
            USART1->CR1 |= USART_CR1_RE;
            USART1->CR1 |= USART_CR1_UE;
            USART1->BRR = GetBRR( $baud );
            NVIC_EnableIRQ( USART1_IRQn );
        $}
	}

	void Subject::InitPins( types::IRCC_Ptr rcc )
	{
		Pins pins{rcc};
		pins.Init();
	}

	uint32_t Subject::GetBRR( uint32_t baud_rate )
	{
		uint32_t pclk = 16000000;
		volatile auto temp = UART_BRR_SAMPLING16( pclk, baud_rate );

		return temp;
	}
}
