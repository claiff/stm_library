//
// Created by claiff on 03.07.22.
//

#include "uart.hpp"

namespace devices::debug
{
	Uart::Uart( Sender const& sender, utils::parser::Debug const& parser )
			: mIsNeedRadioData( false )
			, mSender( sender )
			, mParser( parser )
	{

	}

	void Uart::AddData( uint8_t data )
	{
		mParser.PushData( data );
	}

	void Uart::ProcessData()
	{
		auto commands = mParser.ProcessAndGetData();
		if( !commands )
		{
			return;
		}
		for(const auto& command : *commands)
		{
			if( command.first == SEND_RADIO_DATA )
			{
				mIsNeedRadioData = !mIsNeedRadioData;
			}
		}
	}

	void Uart::SendRadioData( uint8_t* data, size_t count )
	{
		mSender.Send( data, count );
	}

	bool Uart::IsNeedRadioData() const
	{
		return mIsNeedRadioData;
	}


}