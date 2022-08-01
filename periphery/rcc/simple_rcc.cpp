//
// Created by claiff on 6/12/21.
//

#include "simple_rcc.hpp"

namespace periphery::rcc
{
	static int const DEFAULT_CLOCK = 168;

	SimpleRCC::SimpleRCC()
			:
			mClock( DEFAULT_CLOCK )
	{
	}

	void SimpleRCC::SetDefaultRCC() const noexcept
	{
		if( !InitHSE())
		{
			//TODO Error
		}
		if( !InitPLL())
		{
			//TODO Error
		}
		//InitSW();
	}

	bool SimpleRCC::InitHSE() noexcept
	{
//TODO add PWR
		FLASH->ACR = FLASH_ACR_LATENCY_5WS;
		RCC->CR |= RCC_CR_HSEON;

		if( !CheckRegister( &RCC->CR, RCC_CR_HSERDY ))
		{
			return false;
		}

		RCC->CFGR &= ~RCC_CFGR_SW;

		if( !UnCheckRegister( &RCC->CFGR, RCC_CFGR_SWS ))
		{
			return false;
		}

		RCC->CR &= ~RCC_CR_PLLON;

		if( !UnCheckRegister( &RCC->CR, RCC_CR_PLLRDY ))
		{
			return false;
		}
		return true;
	}

	bool SimpleRCC::InitPLL() noexcept
	{
		static const uint8_t ZERO = 0x00;

		RCC->PLLCFGR = ZERO;
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLQ_2;
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLM_2;
		RCC->PLLCFGR |= (RCC_PLLCFGR_PLLN_3 | RCC_PLLCFGR_PLLN_5 | RCC_PLLCFGR_PLLN_7);
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;
		RCC->CR |= RCC_CR_PLLON;

		if( !CheckRegister( &RCC->CR, RCC_CR_PLLRDY ))
		{
			return false;
		}
		return true;
	}

	void SimpleRCC::InitSW() const noexcept
	{
		static const uint8_t ZERO = 0x00;

		RCC->CFGR = ZERO;
		RCC->CFGR |= RCC_CFGR_PPRE1;
		RCC->CFGR |= RCC_CFGR_PPRE2;
		RCC->CFGR |= RCC_CFGR_SW_1;
		RCC->CFGR &= ~RCC_CFGR_PPRE1_1;
		RCC->CFGR &= ~(RCC_CFGR_PPRE2_0 | RCC_CFGR_PPRE2_1);

		RCC->CR &= ~RCC_CR_HSION;
	}

	bool SimpleRCC::CheckRegister( const volatile uint32_t* base_reg, uint32_t check_reg ) noexcept
	{
		static const uint16_t TIMER_FULL = 0xFFFF;
		volatile uint16_t timer = 0;

		while(((*base_reg & check_reg) != check_reg) && timer != TIMER_FULL )
		{
			timer++;
		}
		if( timer == TIMER_FULL )
		{
			return false;
			//TODO ERROR
		}
		return true;
	}

	bool SimpleRCC::UnCheckRegister( const volatile uint32_t* base_reg, unsigned long check_reg ) noexcept
	{
		static const uint8_t TIMER_FULL = 0xFF;
		uint8_t timer = 0;

		while(((*base_reg & check_reg) == check_reg) && timer != TIMER_FULL )
		{
			timer++;
		}
		if( timer == TIMER_FULL )
		{
			return false;
			//TODO ERROR
		}
		return true;
	}

	uint8_t SimpleRCC::GetClock() const noexcept
	{
		return mClock;
	}

}