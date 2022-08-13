//
// Created by claiff on 13.08.22.
//

#pragma once

#include <cstdint>
#include "types/imode.hpp"
#include "types/iodr.hpp"
#include "types/iosr.hpp"
#include "types/irng.hpp"

namespace devices::compass::gy
{
	class Configurator
	{
	public:
		Configurator( types::IModePtr const& mode, types::IOsrPtr const& osr, types::IOdrPtr const& odr,
					  types::IRngPtr const& rng );
		~Configurator() = default;

		[[nodiscard]] uint8_t GetRegData() const;
	private:
		types::IModePtr mMode;
		types::IOsrPtr mOsr;
		types::IOdrPtr mOdr;
		types::IRngPtr mRng;
	};

}