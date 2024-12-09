/*
 * global.h
 *
 *  Created on: Oct 27, 2024
 *      Author: admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "i2c-lcd.h"
#include <stdio.h>


#define INIT        1
#define State1    	2
#define State2  	3
#define State3 		4
#define State4		5

#define MAN_RED     12
#define MAN_GREEN   13
#define MAN_YELLOW  14

extern int status;
extern int redTime ;
extern int greenTime ;
extern int yellowTime ;
extern int tmpTimeRed;
extern int tmpTimeGreen;
extern int tmpTimeYellow;
extern int tmpTimeRed1;
extern int tmpTimeGreen1;
extern int tmpTimeYellow1;

#endif /* INC_GLOBAL_H_ */
