//
// Created by claiff on 11.08.22.
//

#include "compensator.hpp"

namespace devices::pressure::bmp::compensation
{

	//
	//Constructors
	//

	Compensator::Compensator( const DigHolder& dig_holder )
			: mDigHolder( dig_holder )
	{

	}

	//
	//Public methods
	//

	uint32_t Compensator::CompensateH( int32_t raw_h, int32_t raw_t ) const
	{
		using BME280_S32_t = int32_t;
		using BME280_U32_t = uint32_t;

		BME280_S32_t v_x1_u32r;
		v_x1_u32r = (GetFineData( raw_t ) - (( BME280_S32_t ) 76800));
		v_x1_u32r = (((((raw_h << 14) - ((( BME280_S32_t ) mDigHolder.mDigH4) << 20) - ((( BME280_S32_t ) mDigHolder.mDigH5) *
																			 v_x1_u32r)) + (( BME280_S32_t ) 16384))
				>> 15) * (((((((v_x1_u32r *
								(( BME280_S32_t ) mDigHolder.mDigH6)) >> 10) * (((v_x1_u32r * (( BME280_S32_t ) mDigHolder.mDigH3)) >> 11) +
																	 (( BME280_S32_t ) 32768))) >> 10) +
							(( BME280_S32_t ) 2097152)) * (( BME280_S32_t ) mDigHolder.mDigH2) +
						   8192) >> 14));
		v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) *
								   (( BME280_S32_t ) mDigHolder.mDigH1)) >> 4));
		v_x1_u32r = (v_x1_u32r < 0 ? 0 : v_x1_u32r);
		v_x1_u32r = (v_x1_u32r > 419430400 ? 419430400 : v_x1_u32r);
		return ( BME280_U32_t ) (v_x1_u32r >> 12);

	}

	int32_t Compensator::CompensateT( int32_t raw_t ) const
	{
		auto fine_data = GetFineData( raw_t );
		return (fine_data * 5 + 128) >> 8;
	}

	uint32_t Compensator::CompensateP( int32_t raw_p, int32_t raw_t ) const
	{
		using BME280_S64_t = int64_t;
		using BME280_U32_t = uint32_t;
		BME280_S64_t var1, var2, p;
		var1 = (( BME280_S64_t ) GetFineData( raw_t )) - 128000;
		var2 = var1 * var1 * ( BME280_S64_t ) mDigHolder.mDigP6;
		var2 = var2 + ((var1 * ( BME280_S64_t ) mDigHolder.mDigP5) << 17);
		var2 = var2 + ((( BME280_S64_t ) mDigHolder.mDigP4) << 35);
		var1 = ((var1 * var1 * ( BME280_S64_t ) mDigHolder.mDigP3) >> 8) +
			   ((var1 * ( BME280_S64_t ) mDigHolder.mDigP2) << 12);
		var1 = ((((( BME280_S64_t ) 1) << 47) + var1)) * (( BME280_S64_t ) mDigHolder.mDigP1) >> 33;
		if( var1 == 0 )
		{
			return 0; // avoid exception caused by division by zero
		}
		p = 1048576 - raw_p;
		p = (((p << 31) - var2) * 3125) / var1;
		var1 = ((( BME280_S64_t ) mDigHolder.mDigP9) * (p >> 13) * (p >> 13)) >> 25;
		var2 = ((( BME280_S64_t ) mDigHolder.mDigP8) * p) >> 19;
		p = ((p + var1 + var2) >> 8) + ((( BME280_S64_t ) mDigHolder.mDigP7) << 4);
		return ( BME280_U32_t ) p;
	}

	//
	//Private methods
	//

	int32_t Compensator::GetFineData( int32_t raw_t ) const
	{
		using BME280_S32_t = int32_t;

		BME280_S32_t var1, var2;
		BME280_S32_t t_fine;

		var1 = ((((raw_t >> 3) - (( BME280_S32_t ) mDigHolder.mDigT1 << 1))) * (( BME280_S32_t ) mDigHolder.mDigT2))
				>> 11;
		var2 = (((((raw_t >> 4) - (( BME280_S32_t ) mDigHolder.mDigT1)) *
				  ((raw_t >> 4) - (( BME280_S32_t ) mDigHolder.mDigT1)))
				>> 12) *
				(( BME280_S32_t ) mDigHolder.mDigT3)) >> 14;
		t_fine = var1 + var2;
		return t_fine;
	}
}