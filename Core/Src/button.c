/*
 * button.c
 *
 *  Created on: Oct 27, 2024
 *      Author: admin
 */

#include "button.h"

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

//Button1
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

int KeyReg3 = NORMAL_STATE;
int TimerForKeyPress = 200;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
//Button1

//Button2
int KeyReg0_2 = NORMAL_STATE;
int KeyReg1_2 = NORMAL_STATE;
int KeyReg2_2 = NORMAL_STATE;

int KeyReg3_2 = NORMAL_STATE;
int TimerForKeyPress_2 = 200;

int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
//Button2

//Button3
int KeyReg0_3 = NORMAL_STATE;
int KeyReg1_3 = NORMAL_STATE;
int KeyReg2_3 = NORMAL_STATE;

int KeyReg3_3 = NORMAL_STATE;
int TimerForKeyPress_3 = 200;

int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}
//Button3


void subKeyProcess(){
	//TODO
	button1_flag = 1;
}

void subKeyProcess_2(){
	//TODO
	button2_flag = 1;
}

void subKeyProcess_3(){
	//TODO
	button3_flag = 1;
}

void getKeyInput(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		if(KeyReg3 != KeyReg2){
            KeyReg3 = KeyReg2;
            if(KeyReg2 == PRESSED_STATE){
            	//TODO
            	subKeyProcess();
            	TimerForKeyPress = 200;
            }
		}else{
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				//TODO
				KeyReg3 = NORMAL_STATE;
			}
		}
	}

	KeyReg0_2 = KeyReg1_2;
	KeyReg1_2 = KeyReg2_2;
	KeyReg2_2 = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
	if((KeyReg0_2 == KeyReg1_2) && (KeyReg1_2 == KeyReg2_2)){
		if(KeyReg3_2 != KeyReg2_2){
            KeyReg3_2 = KeyReg2_2;
            if(KeyReg2_2 == PRESSED_STATE){
            	//TODO
            	subKeyProcess_2();
            	TimerForKeyPress_2 = 200;
            }
		}else{
			TimerForKeyPress_2--;
			if(TimerForKeyPress_2 == 0){
				//TODO
				KeyReg3_2 = NORMAL_STATE;
			}
		}
	}

	KeyReg0_3 = KeyReg1_3;
	KeyReg1_3 = KeyReg2_3;
	KeyReg2_3 = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
	if((KeyReg0_3 == KeyReg1_3) && (KeyReg1_3 == KeyReg2_3)){
		if(KeyReg3_3 != KeyReg2_3){
            KeyReg3_3 = KeyReg2_3;
            if(KeyReg2_3 == PRESSED_STATE){
            	//TODO
            	subKeyProcess_3();
            	TimerForKeyPress_3 = 200;
            }
		}else{
			TimerForKeyPress_3--;
			if(TimerForKeyPress_3 == 0){
				//TODO
				KeyReg3_3 = NORMAL_STATE;
			}
		}
	}

}
