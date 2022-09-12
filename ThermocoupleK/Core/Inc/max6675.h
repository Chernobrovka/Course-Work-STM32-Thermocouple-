#ifndef _MAX6675_H
#define _MAX6675_H

// Interface
#define MAX6675_SPI		&hspi1

// Macros for control Chip Selector
#define MAX6675_CS_SET()	( HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET))
#define MAX6675_CS_RESET()	( HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET))

// Aliases
#define MAX6675_OK	1
#define MAX6675_ERROR	0

// Functions for return value of microchip
uint8_t max6675ReadReg(uint16_t *reg);

// Transform input signal to temperature
float max6675Temp(uint16_t reg);

#endif /* _MAX6675_H */
