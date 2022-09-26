/*
 * led.h
 *
 * Created: 9/26/2022 2:10:55 PM
 *  Author: Kareem Taha
 */ 


#ifndef LED_H_
#define LED_H_


 /* Section : Includes */
 #include "/Embedded System/Traffic_Project_FWD/Traffic_Project_FWD/MCAL/gpio/gpio_hal.h"

 /* Section : Macros Definition */

 /* Section : Macros Functions Declaration */

 /* Section : Data Types Declaration */
 
 typedef enum{
	 LED_LOW,
	 LED_HIGH
 }led_status_t;

 typedef struct{
	 uint8 port_name: 4;
	 uint8 pin_number: 3;
	 uint8 led_status: 1;
 }led_t;


 

 /* Section : Function Declaration */
 
 STD_ReturnType led_initialize(const led_t *led);


 STD_ReturnType led_turn_on(const led_t *led);


 STD_ReturnType led_turn_off(const led_t *led);


 STD_ReturnType led_toggle_logic(const led_t *led);



#endif /* LED_H_ */