//
// Created by claiff on 31.07.22.
//

#include "gtest/gtest.h"
#include "types/i2c.hpp"
#include "light/bh/bh1721.hpp"

class MockBhI2c : public periphery::types::I2C
{
public:
	void ReadData( uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t count ) const override
	{
		*buffer++ = 0x83;
		*buffer++ = 0x90;
	}
	void WriteData( uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t count ) const override
	{

	}
};

class BH1721
		: public ::testing::Test
{
protected:
	void TearDown() override
	{
	}

	void SetUp() override
	{
	}

public:
	BH1721()
			: Test()
	{
		auto i2c = new MockBhI2c{};
		light = new devices::light::BH1721{i2c};
	}

	~BH1721() override
	{
		delete light;
	}

	devices::light::BH1721* light;
};

::testing::AssertionResult IsBetweenInclusive(int val, int a, int b)
{
	if((val >= a) && (val <= b))
		return ::testing::AssertionSuccess();
	else
		return ::testing::AssertionFailure()
				<< val << " is outside the range " << a << " to " << b;
}

TEST_F(BH1721, GetData)
{
	auto result = light->Get();
	EXPECT_TRUE((result >= 28066) && (result <= 28067));
}