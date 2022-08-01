//
// Created by claiff on 6/12/21.
//

#pragma once

#include <memory>

#include "misc/stm32f407xx.h"

namespace periphery::types
{
	class IRCC
	{
	public:
		virtual ~IRCC() = default;

		virtual void SetDefaultRCC() const noexcept = 0;
		virtual void SetGpioAClock() const noexcept;
		virtual void SetGpioBClock() const noexcept;
		virtual void SetGpioCClock() const noexcept;
		virtual void SetGpioEClock() const noexcept;
		virtual void SetGpioI2C1Clock() const noexcept;
		virtual void SetGpioI2C2Clock() const noexcept;
		virtual void SetGpioI2C3Clock() const noexcept;
		virtual void SetGpioUart1Clock() const noexcept;
		virtual void SetGpioTim1Clock() const noexcept;
		virtual uint8_t GetClock() const noexcept = 0;
	};

	using IRCC_Ptr = IRCC*;
}


