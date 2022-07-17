//
// Created by claiff on 6/13/21.
//

#include "no_pull.hpp"

namespace gpio::pull
{
	void PullNo::SetPull( GPIO_TypeDef* gpio, uint8_t pin )
	{
		static const int PULL_NO = 0x00;
		mPull = PULL_NO;
		GpioPull::SetPull( gpio, pin );
	}
}