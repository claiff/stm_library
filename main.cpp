#include "rcc/simple_rcc.hpp"
#include "i2c/i2c_max_speed.hpp"
#include "light/bh/bh1721.hpp"
#include "light/bh/mode/low.hpp"

int main()
{
	auto clock_control = new periphery::rcc::SimpleRCC{};
	clock_control->SetDefaultRCC();
//TODO need builder for senders
	auto i2c = new periphery::i2c::I2cMaxSpeed{I2C1, clock_control};
	auto mode = new devices::light::bh::mode::Low{};
	devices::light::bh::BH1721 light{i2c, mode};
	auto value = light.Get();
	while( 1 )
	{

	}
}

