//
// Created by claiff on 13.08.22.
//

#include "configurator.hpp"

namespace devices::compass::gy
{

	Configurator::Configurator( types::IModePtr const& mode, types::IOsrPtr const& osr, types::IOdrPtr const& odr,
								types::IRngPtr const& rng )
			: mMode( mode )
			, mOsr( osr )
			, mOdr( odr )
			, mRng( rng )
	{

	}

	uint8_t Configurator::GetRegData() const
	{
		static constexpr uint8_t MODE_POSITION = 0x00;
		static constexpr uint8_t ODR_POSITION = 0x02;
		static constexpr uint8_t RNG_POSITION = 0x04;
		static constexpr uint8_t OSR_POSITION = 0x06;
		static constexpr uint8_t BITS_2 = 0x03;

		uint8_t result;
		result = (mMode->Get() & BITS_2) << MODE_POSITION |
				 (mOdr->Get() & BITS_2) << ODR_POSITION |
				 (mRng->Get() & BITS_2) << RNG_POSITION |
				 (mOsr->Get() & BITS_2) << OSR_POSITION;
		return result;
	}
}