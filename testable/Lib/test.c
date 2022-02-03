//
// Created by User on 22/04/2020.
//
#include "../Include/test.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
int test(int count)
{
    if (count ==0)
    {
        return 0;
    }
    else
        return 1;

}
