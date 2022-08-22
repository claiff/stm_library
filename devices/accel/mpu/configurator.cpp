//
// Created by claiff on 14.08.22.
//

#include "configurator.hpp"


namespace devices::accel::mpu
{

	Configurator::Configurator( config::fifo::Configurator const& fifo, config::power::Configurator const& power,
								config::devices::Configurator const& devices )
			: mFifo( fifo )
			, mPower( power )
			, mDevices( devices )
	{

	}

	void Configurator::ConfigAll() const
	{
		mPower.Config();
		mDevices.Config();
		mFifo.Config();
	}
}