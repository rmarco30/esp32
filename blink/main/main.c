#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


#define GPIO_NUM_2		(2)

void app_main(void) {

  gpio_pad_select_gpio(GPIO_NUM_2);
  gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);

  int isOn = 0;

  while (true) {
    isOn = !isOn;
    gpio_set_level(GPIO_NUM_2, isOn);

    (isOn) ? printf("LED is On\n") : printf("LED is Off\n");

    vTaskDelay(1000 / portTICK_PERIOD_MS);    
  }
}