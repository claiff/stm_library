//
// Created by claiff on 9/18/21.
//

#pragma once

namespace utils::types
{
	template<typename T>
	class Parser
	{
	public:
		virtual ~Parser() = default;

		virtual void ProcessData( uint8_t data ) = 0;
		virtual T GetField( uint8_t number ) const = 0;

		bool IsParsed()
		{
			return mDataParsed;
		}

	protected:
		bool mDataParsed;
		T mData;
		bool mIsFound;
	};
}