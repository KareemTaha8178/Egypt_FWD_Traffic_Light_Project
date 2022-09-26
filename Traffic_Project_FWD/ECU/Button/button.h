/*
 * button.h
 *
 * Created: 9/26/2022 2:25:24 PM
 *  Author: Kareem Taha
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

/* Section : Includes */
#include "/Embedded System/Traffic_Project_FWD/Traffic_Project_FWD/MCAL/gpio/gpio_hal.h"

/* Section : Macros Definition */

/* Section : Macros Functions Declaration */

/* Section : Data Types Declaration */
typedef enum{
	BUTTON_PRESSED = 0,
	BUTTON_RELEASED
}button_state_t;

typedef enum{
	BUTTON_ACTIVE_HIGH,
	BUTTON_ACTIVE_LOW
}button_active_t;

typedef struct{
	pin_config_t button_pin;
	button_state_t button_state;
	button_active_t button_connection;
}button_t;


/* Section : Function Declaration */


/**
 * @brief Initialize the assigned pin to be Input.
 * @param btn pointer to the button configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
STD_ReturnType button_initialize(const button_t *btn);

/**
 * @brief Read the state of the button
 * @param btn pointer to the button configurations
 * @param btn_state button state @ref button_state_t
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
STD_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state);


#endif /* BUTTON_H_ */