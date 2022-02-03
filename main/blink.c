/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.*/
//
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "../testable/Include/test.h"
 //Can use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   //or you can edit the following line and set a number here.

#define BLINK_GPIO 2

void app_main()
{
   /*  Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. Consult the
       Technical Reference for a list of pads and their default
       functions.)*/

    gpio_pad_select_gpio(BLINK_GPIO);
   //  Set the GPIO as a push/pull output
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    while(1) {
        // Blink off (output low)
	printf("Turning off the LED %i \n", test(0));
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
      //   Blink on (output high)
	printf("Turning on the LED %i \n",test(1));
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

/*
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include <sys/times.h>
#include <time.h>
#include "esp_system.h"
#include <sys/time.h>
#include <stdlib.h>

#define TRIG 18
#define ECHO 19
void app_main()
{
    gpio_pad_select_gpio(TRIG);
    gpio_pad_select_gpio(ECHO);
    gpio_set_direction(TRIG,GPIO_MODE_OUTPUT);
    gpio_set_direction(ECHO,GPIO_MODE_INPUT);
    while(1){
        gpio_set_level(TRIG,1);
        ets_delay_us(100);
        gpio_set_level(TRIG, 0);
        uint32_t startTime = esp_timer_get_time ();
// Wait for echo to go high and THEN start the time
        while (gpio_get_level(ECHO) == 0 &&
               (esp_timer_get_time () - startTime) < 500 * 1000) {
        }
        startTime = esp_timer_get_time ();
        while (gpio_get_level(ECHO) == 1 &&
               (esp_timer_get_time () - startTime) < 500 * 1000) {
// Do nothing;
        }
        if (gpio_get_level(ECHO) == 0) {
            uint32_t diff = esp_timer_get_time () - startTime; // Diff time in uSecs
// Distance is TimeEchoInSeconds * SpeedOfSound / 2
            double distance = 340.29 * diff / (1000 * 1000 * 2); // Distance in meters
            printf("Distance is %f cm\n", distance * 100);
        } else {
// No value
            printf("Did not receive a response!\n");
        }
// Delay and re run.
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }

}*/
//#include <stdio.h>
//#include "freertos/FreeRTOS.h"
//#include "freertos/task.h"
//#include "driver/gpio.h"
//#include "sdkconfig.h"
//#include <sys/times.h>
//#include <time.h>
//#include "esp_system.h"
//#include <sys/time.h>
//#include <stdlib.h>
//
//#define TRIG 18
//#define ECHO 19
////xSemaphoreHandle xMutex;
////
////double height = 0;
////void task1(void *pvParameter) {
////    while (1) {
////        double height_temp = 0;
////        if (xSemaphoreTake( xMutex, portMAX_DELAY ) == pdTRUE) {
////            height_temp = height;
////        }
////        xSemaphoreGive(xMutex);
////        printf(
////                "*****************************************************************************************************\n");
////        printf("La variable confiable es %f \n", height_temp);
////        printf(
////                "**************************************************************************************************** \n");
////        vTaskDelay(1000 / portTICK_PERIOD_MS);
////    }
////}
//double rto = 0;
//double prom = 0;
//double s[5];
//int i;
//double height_1(){
//    gpio_pad_select_gpio(TRIG);
//    gpio_pad_select_gpio(ECHO);
//    gpio_set_direction(TRIG, GPIO_MODE_OUTPUT);
//    gpio_set_direction(ECHO, GPIO_MODE_INPUT);
//
//    while (1) {
//        for (i = 0; i <= 4; i++) {
//            gpio_set_level(TRIG, 1);
//            ets_delay_us(100);
//            gpio_set_level(TRIG, 0);
//            uint32_t start_time = esp_timer_get_time();
//            //  capturamos el tiempo inicial de echo y luego el tiempo final para convertirse a 1 restamos y capturamos el tiempo de 0 a 1 ese tiempo lo guardamos en una variable y capturamos el total luego restamos total - tiempo inicial y obtenemos solo el tiempo desde que echo es 1 y se convierte a 0
//            // Wait for echo to go high and THEN start the time
//            while (gpio_get_level(ECHO) == 0
//                   && (esp_timer_get_time() - start_time) < 500 * 1000) {
//            }
//            start_time = esp_timer_get_time();                //ssss
//            while (gpio_get_level(ECHO) == 1
//                   && (esp_timer_get_time() - start_time) < 500 * 1000) {
//            }
//            if (gpio_get_level(ECHO) == 0) {
//                uint32_t diff = esp_timer_get_time() - start_time;
//                double distance = 340.2 * diff / (1000 * 1000 * 2); // Distance in meters
//                double a = distance * 100;
//                printf("Distance is %f cm\n", a);
//                s[i] = a;
//                printf("S[%i] = %f \n", i, s[i]);
//            } else {
//                printf("Did not receive a response!\n");
//            }
//            // Delay and re run.
//            vTaskDelay(1000 / portTICK_PERIOD_MS);
//            // ets_delay_us(500);
//        }
//    }
//}
//
//void app_main()
//{
//
//    double h=height_1();
//    if (h<=s[1]||h<=s[2]){
//        printf("todo bien \n");
//    }
//
////    rto = s[0] + s[1] + s[2] + s[3] + s[4];
////    prom = rto / 5; // 15 *20%
////    double promf = rto * 0.205;
////    double promi = rto * 0.195;
////    printf("promf %f \n", promf);
////    printf("promi %f \n", promi);
//////		double Prcn=20/100 *rto;
////    if (reliable_variable(s[0], s[1], s[2], s[3], s[4], prom, 10)) {
////        if (xSemaphoreTake( xMutex, portMAX_DELAY ) == pdTRUE) {
////            height = prom;
////            printf("The media is %f \n", prom);
////        }
////        xSemaphoreGive(xMutex);
////        vTaskDelay(2000 / portTICK_PERIOD_MS);
////    }
////    vTaskDelay(3000 / portTICK_PERIOD_MS);
//}

//    gpio_pad_select_gpio(TRIG);
//    gpio_pad_select_gpio(ECHO);
//    gpio_set_direction(TRIG,GPIO_MODE_OUTPUT);
//    gpio_set_direction(ECHO,GPIO_MODE_INPUT);
//    while(1){
//        gpio_set_level(TRIG,1);
//        ets_delay_us(100);
//        gpio_set_level(TRIG, 0);
//        uint32_t startTime = esp_timer_get_time ();
//// Wait for echo to go high and THEN start the time
//        while (gpio_get_level(ECHO) == 0 &&
//               (esp_timer_get_time () - startTime) < 500 * 1000) {
//        }
//        startTime = esp_timer_get_time ();
//        while (gpio_get_level(ECHO) == 1 &&
//               (esp_timer_get_time () - startTime) < 500 * 1000) {
//// Do nothing;
//        }
//        if (gpio_get_level(ECHO) == 0) {
//            uint32_t diff = esp_timer_get_time () - startTime; // Diff time in uSecs
//// Distance is TimeEchoInSeconds * SpeedOfSound / 2
//            double distance = 340.29 * diff / (1000 * 1000 * 2); // Distance in meters
//            //printf("Distance is %f cm\n", distance * 100);
//            return distance*100;
//        } else {
//// No value
//           // printf("Did not receive a response!\n");
//           return 0;
//        }
//// Delay and re run.
//        vTaskDelay(1000 / portTICK_PERIOD_MS);
//
//    }

