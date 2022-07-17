//
// Created by claiff on 03.07.22.
//

#pragma once

#include "utils/observer.hpp"
#include "utils/parser/debug.hpp"
#include "sender.hpp"

namespace devices::debug
{
	static constexpr uint8_t SEND_RADIO_DATA = 0x01;
	class Uart
			: public utils::Observer
	{
	public:
		Uart( Sender const& sender, utils::parser::Debug const& parser );
		~Uart() override = default;

		void AddData( uint8_t data ) override;
		void ProcessData();

		void SendRadioData( uint8_t* data, size_t count );
		[[nodiscard]] bool IsNeedRadioData() const;

	private:
		bool mIsNeedRadioData;
		Sender mSender;
		utils::parser::Debug mParser;
	};

}


