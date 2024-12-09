/*
 * fsm_setting.c
 *
 *  Created on: Oct 28, 2024
 *      Author: admin
 */

#include "fsm_setting.h"

int tmp3 = 0;

int fsm_setting_run(int curT){
    if (isButton2Pressed() == 1) {
        curT = curT + 100;
        if (curT > 9900) {
            curT = 100;
        }

    }

    return curT;
}


