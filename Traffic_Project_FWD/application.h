/*
 * application.h
 *
 * Created: 9/26/2022 1:28:04 PM
 *  Author: Kareem Taha
 */ 


#ifndef application_H_
#define application_H_


 /* Section : Includes */
 #include "Types.h"
 #include "libraries.h"
 #include "MCAL/gpio/gpio_hal.h"
 #include "ECU/LED/led.h"
 #include "ECU/Button/button.h"

 /* Section : Macros Definition */

 /* Section : Macros Functions Declaration */

 /* Section : Data Types Declaration */

 

 /* Section : Function Declaration */

void application_initialize(void);
void app_Start(void);

#endif /* application_H_ */