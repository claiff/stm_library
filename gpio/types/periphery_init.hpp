//
// Created by claiff on 6/13/21.
//

#pragma once

#include "misc/stm32f407xx.h"

namespace gpio::types
{
	static const int FUNC_BITS_SYS = 0x00;
	static const int FUNC_BITS_I2C = 0x04;
	static const int FUNC_BITS_UART = 0x07;

	static const int FUNC_BITS_TIM_IC = 0x01;

	class PeripheryInit
	{
	public:
		virtual ~PeripheryInit() = default;
		virtual void Init() const = 0;
	};

	using PeripheryInitPtr = PeripheryInit*;
}