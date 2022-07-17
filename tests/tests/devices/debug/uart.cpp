//
// Created by claiff on 17.07.22.
//

#include "gtest/gtest.h"
#include "debug/uart.hpp"

class DebugUart
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
	DebugUart()
			: Test()
	{
		devices::debug::Sender sender{USART1};
		utils::parser::Debug parser;
		mDebug = new devices::debug::Uart{sender, parser};
	}
	~DebugUart() override
	{
		delete mDebug;
	}

	devices::debug::Uart* mDebug;
};

TEST_F(DebugUart, ZeroData)
{
	mDebug->AddData(0x00);
	mDebug->AddData(0x00);
	mDebug->AddData(0x00);
	mDebug->AddData(0x00);
	mDebug->AddData(0x00);
	EXPECT_EQ(mDebug->IsNeedRadioData(), false);
}

