//
// Created by claiff on 14.08.22.
//

#pragma once

#include "types/iconfig.hpp"
#include "config/fifo/configurator.hpp"
#include "config/power/configurator.hpp"
#include "config/devices/configurator.hpp"

namespace devices::accel::mpu
{
	class Configurator
	{
	public:
		Configurator( config::fifo::Configurator const& fifo, config::power::Configurator const& power,
					  config::devices::Configurator const& devices );
		~Configurator() = default;

		void ConfigAll() const;
	private:
		config::fifo::Configurator mFifo;
		config::power::Configurator mPower;
		config::devices::Configurator mDevices;
	};
}

