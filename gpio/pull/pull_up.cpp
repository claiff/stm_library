//
// Created by claiff on 6/13/21.
//

#include "pull_up.hpp"

namespace gpio::pull
{
	void PullUp::SetPull( GPIO_TypeDef* gpio, uint8_t pin )
	{
		static const int PULL_UP = 0x01;
		mPull = PULL_UP;
		GpioPull::SetPull( gpio, pin );
	}
}