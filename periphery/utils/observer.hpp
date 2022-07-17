//
// Created by claiff on 9/18/21.
//

#pragma once

#include <cstdint>

namespace utils
{
	class Observer
	{
	public:
		virtual ~Observer() = default;

		virtual void AddData( uint8_t data ) = 0;
	};

	using IObserverPtr = Observer*;
}