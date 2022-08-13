#include "rcc/simple_rcc.hpp"

#include "pressure/bmp/bmp_280.hpp"
#include "i2c/i2c_max_speed.hpp"
#include "pressure/bmp/compensation/dig_holder.hpp"
#include "pressure/bmp/settings/indoor_navigation.hpp"

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
	auto settings = new devices::pressure::bmp::settings::IndoorNavigation();
	devices::pressure::bmp::compensation::DigHolder dig_holder{i2c};

	devices::pressure::bmp::Bmp280 bmp{i2c, settings};
	auto data = bmp.IsOnline();
	auto t = bmp.GetTemperature();
	auto p = bmp.GetPressure();
	auto h = bmp.GetHumidity();
	while( 1 )
	{

	}
}

