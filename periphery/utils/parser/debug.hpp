//
// Created by claiff on 04.07.22.
//

#pragma once

#include "utils/types/debug_uart_parser.hpp"

namespace utils::parser
{
	struct Header
	{
		uint8_t start_byte;
		uint8_t size;
		uint8_t command;
	};

	class Debug
			: public types::DebugUartParser
	{
	public:
		Debug();
		~Debug() override = default;

		void PushData( uint8_t data ) override;
		types::ResultType ProcessAndGetData() override;
	private:
		bool IsFindHeader();
		[[nodiscard]] bool IsEnoughData() const;
		[[nodiscard]] std::optional < uint8_t > GetHeaderPosition() const;
		void ClearOnPosition( uint8_t position );
		[[nodiscard]] bool IsFullSizeData() const;
		types::ResultType ParseData();

		bool mIsFound;
	};
}
