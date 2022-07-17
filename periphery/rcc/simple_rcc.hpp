//
// Created by claiff on 6/12/21.
//

#pragma once

#include "types/ircc.hpp"

namespace rcc
{
	class SimpleRCC
			: public types::IRCC
	{
	public:
		SimpleRCC();
		SimpleRCC( uint32_t mClock );
		~SimpleRCC() override = default;
		void SetDefaultRCC() const noexcept override;
		uint8_t GetClock() const noexcept override;
	private:
		static bool InitHSE() noexcept;
		static bool InitPLL() noexcept;
		void InitSW() const noexcept;
		static bool CheckRegister( const volatile uint32_t* base_reg, uint32_t check_reg ) noexcept;
		static bool UnCheckRegister( const volatile uint32_t* base_reg, unsigned long check_reg ) noexcept;

		uint8_t mClock;
	};
}

