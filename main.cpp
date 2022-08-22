#include "rcc/simple_rcc.hpp"
#include "i2c/i2c_max_speed.hpp"
#include "accel/mpu/builder/first.hpp"

int main()
{
	auto clock_control = new periphery::rcc::SimpleRCC{};
	clock_control->SetDefaultRCC();
//TODO need builder for senders
	auto i2c = new periphery::i2c::I2cMaxSpeed{I2C1, clock_control};
	devices::accel::mpu::builder::First accel_builder{};
	auto accel = accel_builder.Build(i2c);
	auto is_online = accel.IsOnline();
	auto data = accel.GetData();
	while( 1 )
	{

	}
}

