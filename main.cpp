#include "rcc/simple_rcc.hpp"
#include "uart/subject.hpp"
#include "utils/parser/debug.hpp"

#include "devices/debug/sender.hpp"
#include "devices/debug/uart.hpp"

int main()
{
	auto clock_control = new rcc::SimpleRCC{};
	clock_control->SetDefaultRCC();

	devices::debug::Sender sender{USART1};
	utils::parser::Debug parser;
	auto debug = new devices::debug::Uart{sender, parser};

	std::vector < utils::IObserverPtr > registrator;
	registrator.push_back( debug );
	uart::Subject uart{USART1, clock_control, registrator};


	while( 1 )
	{

	}
}

