#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <driver/adc.h>


void app_main(void)
{

    adc1_config_width(ADC_WIDTH_12Bit);
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11);

    while (1) {
        
        uint32_t adcRawVal = adc1_get_raw(ADC1_CHANNEL_0);
        float voltage = adcRawVal * (3.3 / 4095.0);
        printf("Raw: %d, Voltage: %f \n", adcRawVal, voltage);
        vTaskDelay(50 / portTICK_PERIOD_MS);

	}
}