//
// Created by claiff on 6/13/21.
//

#include "i2c_max_speed.hpp"
#include "pins/first.hpp"
#include "pins/second.hpp"
#include "pins/third.hpp"

namespace periphery::i2c
{
	I2cMaxSpeed::I2cMaxSpeed( I2C_TypeDef* i2c, periphery::types::IRCC_Ptr const& rcc )
			: mI2c( i2c )
			, mRcc( rcc )
	{
		if( mI2c == I2C1)
		{
			mPeripheryInit = new pins::First( mRcc );
			mRcc->SetGpioI2C1Clock();
		}
		else if( mI2c == I2C2)
		{
			mPeripheryInit = new pins::Second( mRcc );
			mRcc->SetGpioI2C2Clock();
		}
		else if( mI2c == I2C3)
		{
			mPeripheryInit = new pins::Third( mRcc );
			mRcc->SetGpioI2C3Clock();
		}
		InitI2C();
	}

	void I2cMaxSpeed::InitI2C() const
	{
		if( !mPeripheryInit )
		{
			// TODO Error
		}
		mPeripheryInit->InitPeriphery();
		mI2c->CR1 |= I2C_CR1_SWRST;
		mI2c->CR1 &= ~I2C_CR1_SWRST;

		auto read_data = mI2c->CCR;
		read_data &= 0xF000;
		read_data |= 0xD2;
		mI2c->CCR = read_data;

		mI2c->TRISE |= I2C_TRISE_TRISE;
		mI2c->CR2 |= (I2C_CR2_FREQ_1 | I2C_CR2_FREQ_3 | I2C_CR2_FREQ_5);
		mI2c->CR1 |= I2C_CR1_PE;
	}

	void I2cMaxSpeed::ReadData( uint8_t address, uint8_t reg, uint8_t* buffer,
								uint8_t count ) const
	{
		(count > 1) ? (mI2c->CR1 |= I2C_CR1_ACK) : (mI2c->CR1 &= ~I2C_CR1_ACK);
		//стартуем
		mI2c->CR1 |= I2C_CR1_START;
		//TODO реагировать на бесконечный цикл
		while( !(mI2c->SR1 & I2C_SR1_SB));
		( void ) mI2c->SR1;

		//передаем адрес устройства
		mI2c->DR = address;
		while( !(mI2c->SR1 & I2C_SR1_ADDR));
		( void ) mI2c->SR1;
		( void ) mI2c->SR2;

		//передаем адрес регистра
		mI2c->DR = reg;
		while( !(mI2c->SR1 & I2C_SR1_TXE));
		mI2c->CR1 |= I2C_CR1_STOP;

		//рестарт!!!
		mI2c->CR1 |= I2C_CR1_START;
		while( !(mI2c->SR1 & I2C_SR1_SB));
		( void ) mI2c->SR1;

		//передаем адрес устройства, но теперь для чтения
		mI2c->DR = address + 1;
		while( !(mI2c->SR1 & I2C_SR1_ADDR));
		( void ) mI2c->SR1;
		( void ) mI2c->SR2;

		//читаем
		for( int i = 0; i < count - 1; i++ )
		{
			while( !(mI2c->SR1 & I2C_SR1_RXNE));
			*buffer++ = mI2c->DR;
		}
		//последний байт без ack
		mI2c->CR1 &= ~I2C_CR1_ACK;
		mI2c->CR1 |= I2C_CR1_STOP;
		while( !(mI2c->SR1 & I2C_SR1_RXNE));
		*buffer++ = mI2c->DR;
	}

	void I2cMaxSpeed::WriteData( uint8_t address, uint8_t reg, uint8_t* buffer,
								 uint8_t count ) const
	{
		mI2c->CR1 |= I2C_CR1_ACK;
		//стартуем
		mI2c->CR1 |= I2C_CR1_START;
		while((mI2c->SR1 & I2C_SR1_SB) != I2C_SR1_SB);
		( void ) mI2c->SR1;

		//передаем адрес устройства
		mI2c->DR = address;
		while((mI2c->SR1 & I2C_SR1_ADDR) != I2C_SR1_ADDR);
		( void ) mI2c->SR1;
		( void ) mI2c->SR2;

		//пишем данные
		for( int i = 0; i < count; i++ )
		{
			//передаем адрес регистра
			mI2c->DR = reg++;
			while( (mI2c->SR1 & I2C_SR1_TXE) != I2C_SR1_TXE);
			mI2c->DR = *buffer++;
			while( (mI2c->SR1 & I2C_SR1_BTF)!= I2C_SR1_BTF);
		}
		mI2c->CR1 |= I2C_CR1_STOP;
	}
}
