/*
 * fsm_manual.c
 *
 *  Created on: Oct 27, 2024
 *      Author: admin
 */

#include "fsm_manual.h"
#include "global.h"
#include "i2c-lcd.h"
const int MAX_LED = 2;
int index_led = 0;
int index_led_t =0;
int mode = 2;
void fsm_manual_run(){

	switch(status){

	case MAN_RED:
		//TODO
		lcd_goto_XY(0, 0);
		lcd_send_string("RED");
		lcd_goto_XY(1, 0);
		lcd_send_num(tmpTimeRed/100);

		if (timer1_flag == 1){
			HAL_GPIO_TogglePin(led1_bit1_GPIO_Port,led1_bit1_Pin);
			HAL_GPIO_TogglePin(led1_bit2_GPIO_Port,led1_bit2_Pin);

			HAL_GPIO_TogglePin(led2_bit1_GPIO_Port,led2_bit1_Pin);
			HAL_GPIO_TogglePin(led2_bit2_GPIO_Port,led2_bit2_Pin);

			setTimer1(50);
		}

		if(isButton1Pressed() == 1){
			mode = 3;
			HAL_GPIO_WritePin(led1_bit1_GPIO_Port, led1_bit1_Pin, 0);
			HAL_GPIO_WritePin(led1_bit2_GPIO_Port, led1_bit2_Pin, 0);

			HAL_GPIO_WritePin(led2_bit1_GPIO_Port, led2_bit1_Pin, 0);
			HAL_GPIO_WritePin(led2_bit2_GPIO_Port, led2_bit2_Pin, 0);
			lcd_clear_display();
			status = MAN_YELLOW;

			setTimer1(50);
		}

		tmpTimeRed = fsm_setting_run(tmpTimeRed);

		if(isButton3Pressed() == 1){
			redTime = tmpTimeRed;
		}

		break;
	case MAN_YELLOW:
		//TODO
		HAL_GPIO_WritePin(led1_bit1_GPIO_Port, led1_bit1_Pin, 0);
		HAL_GPIO_WritePin(led2_bit1_GPIO_Port, led2_bit1_Pin, 0);
		lcd_goto_XY(0, 0);
				lcd_send_string("YELLOW");
				lcd_goto_XY(1, 0);
				lcd_send_num(tmpTimeYellow/100);
		if (timer1_flag == 1){

			HAL_GPIO_TogglePin(led1_bit2_GPIO_Port,led1_bit2_Pin);
			HAL_GPIO_TogglePin(led2_bit2_GPIO_Port,led2_bit2_Pin);

			setTimer1(50);
		}

		if(isButton1Pressed() == 1){
			mode = 4;
			HAL_GPIO_WritePin(led1_bit1_GPIO_Port, led1_bit1_Pin, 0);
			HAL_GPIO_WritePin(led1_bit2_GPIO_Port, led1_bit2_Pin, 0);

			HAL_GPIO_WritePin(led2_bit1_GPIO_Port, led2_bit1_Pin, 0);
			HAL_GPIO_WritePin(led2_bit2_GPIO_Port, led2_bit2_Pin, 0);
			lcd_clear_display();
			status = MAN_GREEN;
			setTimer1(50);
		}

		tmpTimeYellow = fsm_setting_run(tmpTimeYellow);

		if(isButton3Pressed() == 1){
			yellowTime = tmpTimeYellow;
		}

		break;

	case MAN_GREEN:
		//TODO
		HAL_GPIO_WritePin(led1_bit2_GPIO_Port, led1_bit2_Pin, 0);
		HAL_GPIO_WritePin(led2_bit2_GPIO_Port, led2_bit2_Pin, 0);
		lcd_goto_XY(0, 0);
						lcd_send_string("GREEN");
						lcd_goto_XY(1, 0);
						lcd_send_num(tmpTimeGreen/100);
		if (timer1_flag == 1){
			HAL_GPIO_TogglePin(led1_bit1_GPIO_Port,led1_bit1_Pin);
			HAL_GPIO_TogglePin(led2_bit1_GPIO_Port,led2_bit1_Pin);

			setTimer1(50);
		}
		if(isButton1Pressed() == 1){
			lcd_clear_display();
			status = INIT;
			setTimer1(50);
		}

		tmpTimeGreen = fsm_setting_run(tmpTimeGreen);

       if(isButton3Pressed() == 1){
    	   greenTime = tmpTimeGreen;
       }

		break;
	default:
		break;
	}
}
