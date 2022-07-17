//
// Created by claiff on 9/18/21.
//

#pragma once

#include <string>
#include <vector>

#include "utils/types/parser.hpp"

namespace utils::parser
{
	class GpsHeader
			: public utils::types::Parser < std::string >
	{
	public:
		//TODO нужен не std::string а registrator
		GpsHeader( std::string const& field, uint8_t count_field );
		void ProcessData( uint8_t data ) override;
		[[nodiscard]] std::string GetField( uint8_t number ) const override;
	private:
		bool FindHeader();
		[[nodiscard]] bool IsEnoughData() const;
		[[nodiscard]] unsigned int GetHeaderPosition() const;
		void ClearOnPosition( uint8_t position );
		[[nodiscard]] uint8_t GetCountFields() const;
		void ParseData();

		std::string mField;
		uint8_t mCountField;

		std::vector < std::string > mParsedData;

	};

}