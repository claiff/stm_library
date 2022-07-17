//
// Created by claiff on 04.07.22.
//

#include <algorithm>
#include <optional>

#include "debug.hpp"

namespace utils::parser
{
	//
	//Constructors
	//

	Debug::Debug()
			: mIsFound{false}
	{

	}

	//
	//Public methods
	//

	void Debug::PushData( uint8_t data )
	{
		mData.push_back( data );
	}

	types::ResultType Debug::ProcessAndGetData()
	{
		if( !mIsFound && !IsFindHeader())
		{
			return {};
		}
		if( !IsFullSizeData())
		{
			return {};
		}
		return ParseData();
	}

	//
	//Private methods
	//

	bool Debug::IsFindHeader()
	{
		if( !IsEnoughData())
		{
			return mIsFound;
		}
		auto position = GetHeaderPosition();
		if( !position )
		{
			mData.clear();
			return mIsFound;
		}
		ClearOnPosition( *position );
		mIsFound = true;

		return mIsFound;
	}

	bool Debug::IsEnoughData() const
	{
		return mData.size() >= sizeof( Header );
	}

	std::optional < uint8_t > Debug::GetHeaderPosition() const
	{
		static constexpr uint8_t START_BYTE = 0x5A;
		auto find = std::find_if( mData.begin(), mData.end(), []( uint8_t element )
		{ return element == START_BYTE; } );
		if( find == mData.end())
		{
			return {};
		}
		return find - mData.begin();
	}

	void Debug::ClearOnPosition( uint8_t position )
	{
		static constexpr uint8_t FIRST_POSITION = 0;
		mData.erase( mData.begin(), mData.begin() + position );
	}

	bool Debug::IsFullSizeData() const
	{
		static constexpr uint8_t SIZE_POSITION = 1;

		return mData.size() >= mData[SIZE_POSITION] + sizeof( Header );
	}

	types::ResultType Debug::ParseData()
	{
		types::ResultType result = std::vector<types::DataType>{};
		auto header_size = sizeof( Header );
		while( mData.size() >= header_size)
		{
			std::vector < uint8_t > command_data;
			auto header = reinterpret_cast<Header*>(mData.data());
			auto command = header->command;
			auto size = header->size;
			std::copy_n( mData.begin() + header_size, size, std::back_inserter( command_data ));
			result->push_back( {command, command_data} );
			mData.erase( mData.begin(), mData.begin() + header_size + command_data.size());
		}
		return result;
	}
}