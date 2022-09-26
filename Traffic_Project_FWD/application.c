/*
 * Traffic_Project_FWD.c
 *
 * Created: 9/25/2022 11:46:11 PM
 * Author : Kareem Taha
 */ 


#include "application.h"

STD_ReturnType ret = 0x00;

led_t led_1 = {
	.port_name = PORTC_INDEX,
	.pin_number = GPIO_PIN0,
	.led_status = LED_LOW
};

led_t led_2 = {
	.port_name = PORTC_INDEX,
	.pin_number = GPIO_PIN1,
	.led_status = LED_LOW
};

led_t led_3 = {
	.port_name = PORTC_INDEX,
	.pin_number = GPIO_PIN2,
	.led_status = LED_LOW
};


led_t led_4 = {
	.port_name = PORTC_INDEX,
	.pin_number = GPIO_PIN3,
	.led_status = LED_LOW
};

led_t led_5 = {
	.port_name = PORTC_INDEX,
	.pin_number = GPIO_PIN4,
	.led_status = LED_LOW
};

led_t led_6 = {
	.port_name = PORTC_INDEX,
	.pin_number = GPIO_PIN5,
	.led_status = LED_LOW
};

button_t btn_1 = {
	.button_pin.pin = GPIO_PIN0,
	.button_pin.port = PORTA_INDEX,
	.button_pin.logic = GPIO_LOW,
	.button_pin.direction = GPIO_OUTPUT_DIRECTION,
	.button_state = BUTTON_RELEASED,
	.button_connection = BUTTON_ACTIVE_HIGH
};



button_state_t button_1 = BUTTON_RELEASED;

void app_Start(){
	application_initialize();
	while (1)
	{
		int flag1 = 0, flag2 = 0, flag3 = 0;
		led_turn_on(&led_1);
		for(int i = 0; i < 20; i++){
			int flag_green = 0;
			for(int j = 0; j < 250; j++){
				button_read_state(&btn_1, &button_1);
				if(button_1 == BUTTON_PRESSED) flag_green++;
				_delay_ms(1);
			}
			if(flag_green > 0 && flag_green < 50 && flag1 == 0){
				led_turn_on(&led_6);
				_delay_ms(500);
				flag1 = 1;
				break;
			}
		}
		led_turn_off(&led_1);
		for(int i = 0; i < 10; i++){
			led_toggle_logic(&led_2);
			if(flag1 == 1) led_toggle_logic(&led_5);
			int flag_yellow = 0;
			for(int j = 0; j < 500; j++){
				button_read_state(&btn_1, &button_1);
				if(button_1 == BUTTON_PRESSED) flag_yellow++;
				_delay_ms(1);
			}
			if(flag_yellow > 0 && flag_yellow < 100 && flag2 == 0){
				led_turn_on(&led_6);
				_delay_ms(500);
				for(int k = 0; k < 10; k++){
					led_toggle_logic(&led_2);
					led_toggle_logic(&led_5);
					_delay_ms(500);
				}
				flag2 = 1;
				break;
			}
		}
		led_turn_off(&led_2);
		if(flag1 == 1 || flag2 == 1) led_turn_off(&led_5);
		if(flag1 == 1 || flag2 == 1) led_turn_off(&led_6);
		led_turn_on(&led_3);
		if(flag1 == 1 || flag2 == 1) led_turn_on(&led_4);
		for(int i = 0; i < 20; i++){
			int flag_red = 0;
			for(int j = 0; j < 250; j++){
				button_read_state(&btn_1, &button_1);
				if(button_1 == BUTTON_PRESSED) flag_red++;
				_delay_ms(1);
			}
			if(flag_red > 0 && flag_red < 50 && flag3 == 0){
				led_turn_on(&led_4);
				_delay_ms(5000);
				flag3 = 1;
				break;
			}
		}
		led_turn_off(&led_3);
		if(flag3 == 1) led_turn_off(&led_4);
		if(flag1 == 1 || flag2 == 1) led_turn_off(&led_4);
	}
}

int main(void)
{
	app_Start();
}

void application_initialize(void){
	led_initialize(&led_1);
	led_initialize(&led_2);
	led_initialize(&led_3);
	led_initialize(&led_4);
	led_initialize(&led_5);
	led_initialize(&led_6);
	button_initialize(&btn_1);
}
