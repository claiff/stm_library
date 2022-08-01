#include "rcc/simple_rcc.hpp"

#include "light/bh1721.hpp"
#include "i2c/i2c_max_speed.hpp"

int main()
{
	auto clock_control = new periphery::rcc::SimpleRCC{};
	clock_control->SetDefaultRCC();
//TODO need builder for senders

//	devices::debug::Sender sender{USART1};
//	utils::parser::Debug parser;
//	auto debug = new devices::debug::Uart{sender, parser};
//
//	std::vector < utils::IObserverPtr > registrator;
//	registrator.push_back( debug );
//	uart::Subject uart{USART1, clock_control, registrator};
	auto i2c = new periphery::i2c::I2cMaxSpeed{I2C1, clock_control};
	devices::light::BH1721 light{i2c};
	auto data = light.Get();
	while( 1 )
	{

	}
}

