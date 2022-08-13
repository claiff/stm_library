#include "rcc/simple_rcc.hpp"
#include "i2c/i2c_max_speed.hpp"
#include "compass/gy/gy_271.hpp"
#include "compass/gy/configurator.hpp"
#include "compass/gy/mode/continuous.hpp"
#include "compass/gy/odr/odr_10.hpp"
#include "compass/gy/osr/osr_512.hpp"
#include "compass/gy/rng/rng_8.hpp"

int main()
{
	auto clock_control = new periphery::rcc::SimpleRCC{};
	clock_control->SetDefaultRCC();
//TODO need builder for senders
	auto i2c = new periphery::i2c::I2cMaxSpeed{I2C1, clock_control};

	auto mode = new devices::compass::gy::mode::Continuous{};
	auto odr = new devices::compass::gy::odr::Odr10{};
	auto osr = new devices::compass::gy::osr::Osr512{};
	auto rng = new devices::compass::gy::rng::Rng8{};

	devices::compass::gy::Configurator configurator{mode, osr, odr, rng};
	devices::compass::gy::Gy271 compass{i2c, configurator};
	auto data = compass.Get();
	while( 1 )
	{

	}
}

