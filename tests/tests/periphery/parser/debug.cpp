//
// Created by claiff on 17.07.22.
//

#include "gtest/gtest.h"
#include "utils/parser/debug.hpp"

namespace test::paeriphery::parser
{
	class Debug
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
		Debug()
				: Test()
		{
		}

		~Debug() override = default;

		utils::parser::Debug mParser;
	};

	TEST_F( Debug, NoneData )
	{
		auto result = mParser.ProcessAndGetData();
		EXPECT_EQ( result.has_value(), false );
	}

	TEST_F( Debug, ZeroData )
	{
		mParser.PushData( 0x00 );
		mParser.PushData( 0x00 );
		mParser.PushData( 0x00 );
		mParser.PushData( 0x00 );
		mParser.PushData( 0x00 );

		auto result = mParser.ProcessAndGetData();
		EXPECT_EQ( result.has_value(), false );
	}

	TEST_F( Debug, GoodOnlyCommand )
	{
		mParser.PushData( 0x5A );
		mParser.PushData( 0x00 );
		mParser.PushData( 0x01 );
		mParser.PushData( 0x00 );
		mParser.PushData( 0x00 );

		auto result = mParser.ProcessAndGetData();

		EXPECT_EQ( result.has_value(), true );
		EXPECT_EQ( result->size(), 1 );

		auto element = result->at( 0 );
		auto command = element.first;
		auto command_data = element.second;
		EXPECT_EQ( command, 0x01 );
		EXPECT_EQ( command_data.empty(), true );
	}

	TEST_F( Debug, ManyCommands )
	{
		mParser.PushData( 0x5A );
		mParser.PushData( 0x00 );
		mParser.PushData( 0x01 );
		mParser.PushData( 0x5A );
		mParser.PushData( 0x00 );
		mParser.PushData( 0x02 );
		mParser.PushData( 0x5A );
		mParser.PushData( 0x00 );
		mParser.PushData( 0x03 );

		auto result = mParser.ProcessAndGetData();

		EXPECT_EQ( result.has_value(), true );
		EXPECT_EQ( result->size(), 3 );
	}

	TEST_F( Debug, DataCommands )
	{
		mParser.PushData( 0x5A );
		mParser.PushData( 0x05 );
		mParser.PushData( 0x01 );
		mParser.PushData( 0x01 );
		auto result = mParser.ProcessAndGetData();

		EXPECT_EQ( result.has_value(), false );

		mParser.PushData( 0x01 );
		mParser.PushData( 0x01 );
		mParser.PushData( 0x01 );
		mParser.PushData( 0x01 );
		result = mParser.ProcessAndGetData();
		EXPECT_EQ( result.has_value(), true );
		EXPECT_EQ( result->size(), 1 );

		auto element = result->at( 0 );
		auto command_data = element.second;
		EXPECT_EQ( command_data.size(), 5 );
	}
}