//
// Created by claiff on 9/18/21.
//

#include <algorithm>
#include <sstream>
#include <iomanip>

#include "gps_header.hpp"

namespace utils::parser
{
	//
	// Constructors
	//

	GpsHeader::GpsHeader( std::string const& field, uint8_t count_field )
			:
			mField( field )
			, mCountField( count_field )
	{
		mDataParsed = false;
	}

	//
	//Public methods
	//

	void GpsHeader::ProcessData( uint8_t data )
	{
		mData.push_back( data );

		if( !mIsFound && !FindHeader())
		{
			return;
		}
		if( GetCountFields() < mCountField )
		{
			return;
		}
		ParseData();
	}

	std::string GpsHeader::GetField( uint8_t number ) const
	{
		if( number > mParsedData.size())
		{
			return {};
		}
		return mParsedData[number];
	}

	//
	//Private methods
	//

	bool GpsHeader::FindHeader()
	{
		if( !IsEnoughData())
		{
			return mIsFound;
		}
		auto position = GetHeaderPosition();
		if( position == std::string::npos )
		{
			mData.clear();
			return mIsFound;
		}
		ClearOnPosition( position );
		mIsFound = true;

		return mIsFound;
	}

	bool GpsHeader::IsEnoughData() const
	{
		static constexpr int MINIMUM_DATA = 20;
		return mData.size() >= MINIMUM_DATA;
	}

	unsigned int GpsHeader::GetHeaderPosition() const
	{
		return mData.find( mField );
	}

	void GpsHeader::ClearOnPosition( uint8_t position )
	{
		static uint8_t const FIRST_POSITION = 0;
		mData.erase( FIRST_POSITION, position );
	}

	uint8_t GpsHeader::GetCountFields() const
	{
		uint8_t count = std::count_if( mData.begin(), mData.end(), []( unsigned char element )
		{ return element == ','; } );
		return count;
	}

	void GpsHeader::ParseData()
	{
		static constexpr uint8_t ZERO_POSITION = 0;
		std::string delimiter = ",";
		auto buffer_copy = mData;

		size_t pos = ZERO_POSITION;
		mParsedData.clear();
		while((pos = buffer_copy.find( delimiter )) != std::string::npos )
		{
			mParsedData.push_back( buffer_copy.substr( ZERO_POSITION, pos ));
			buffer_copy.erase( ZERO_POSITION, pos + delimiter.length());
		}
		mData.clear();
		mIsFound = false;
	}
}