#include "stm32f1xx_hal.h"
#include "max6675.h"
#include "spi.h"
#include "gpio.h"


// Functions for return value of microchip
uint8_t max6675ReadReg(uint16_t *reg){

	// return value of function HAL
	 HAL_StatusTypeDef hal_answer = HAL_ERROR;

	// Array for received data
	uint8_t temp[2] = {0};

	// ON chip
	MAX6675_CS_SET();

	// read on chip
	hal_answer = HAL_SPI_Receive(MAX6675_SPI, temp, 2, 100);

	//OFF chip
	MAX6675_CS_RESET();

	if ( hal_answer == HAL_OK){
		// checking for sensor connect
		if(temp[1] & 0x04) return MAX6675_ERROR;		// logical multiply

		// Transform received data
		*reg = (uint16_t)(temp[1] >> 3);
		*reg |= (uint16_t)(temp[0] << 5);

		return MAX6675_OK;
 	}

	return MAX6675_ERROR;
}

// Transform input signal to temperature
float max6675Temp(uint16_t reg){
	return reg * 0.25;
}
