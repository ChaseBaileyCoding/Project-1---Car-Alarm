#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"

#define DRIVER_GPIO GPIO_NUM_10
#define PASSENGER_GPIO GPIO_NUM_11
#define DRIVER_SEATBELT_GPIO GPIO_NUM_12
#define PASSENGER_SEATBELT_GPIO GPIO_NUM_13
#define IGNITION_GPIO GPIO_NUM_14

#define GREENLED_GPIO GPIO_NUM_4
#define BLUELED_GPIO GPIO_NUM_5
#define BUZZER_GPIO GPIO_NUM_6


void app_main(void)
{
    gpio_reset_pin(DRIVER_GPIO);
    gpio_set_direction(DRIVER_GPIO, GPIO_MODE_INPUT);
    gpio_pulldown_en(DRIVER_GPIO);

    gpio_reset_pin(PASSENGER_GPIO);
    gpio_set_direction(PASSENGER_GPIO, GPIO_MODE_INPUT);
    gpio_pulldown_en(PASSENGER_GPIO);

    gpio_reset_pin(DRIVER_SEATBELT_GPIO);
    gpio_set_direction(DRIVER_SEATBELT_GPIO, GPIO_MODE_INPUT);
    gpio_pulldown_en(DRIVER_SEATBELT_GPIO);

    gpio_reset_pin(PASSENGER_SEATBELT_GPIO);
    gpio_set_direction(PASSENGER_SEATBELT_GPIO, GPIO_MODE_INPUT);
    gpio_pulldown_en(PASSENGER_SEATBELT_GPIO);

    gpio_reset_pin(IGNITION_GPIO);
    gpio_set_direction(IGNITION_GPIO, GPIO_MODE_INPUT);
    gpio_pulldown_en(IGNITION_GPIO);

    gpio_reset_pin(GREENLED_GPIO);
    gpio_set_direction(GREENLED_GPIO, GPIO_MODE_OUTPUT);

    gpio_reset_pin(BLUELED_GPIO);
    gpio_set_direction(BLUELED_GPIO, GPIO_MODE_OUTPUT);

    gpio_reset_pin(BUZZER_GPIO);
    gpio_set_direction(BUZZER_GPIO, GPIO_MODE_OUTPUT);

    while(1) {
        if(gpio_get_level(IGNITION_GPIO)){
            if (gpio_get_level(DRIVER_GPIO) && gpio_get_level(PASSENGER_GPIO) && gpio_get_level(PASSENGER_SEATBELT_GPIO) && gpio_get_level(DRIVER_SEATBELT_GPIO)){
                while(1){
                    gpio_set_level(GREENLED_GPIO, 0);
                    gpio_set_level(BLUELED_GPIO, 1);
                    vTaskDelay(25/  portTICK_PERIOD_MS);
                }
            }
            else{
                while(1){
                    gpio_set_level(BUZZER_GPIO, 1);
                    vTaskDelay(25/  portTICK_PERIOD_MS);
                }
            }
        }
        else if((gpio_get_level(DRIVER_GPIO)) && (gpio_get_level(PASSENGER_GPIO)) && (gpio_get_level(PASSENGER_SEATBELT_GPIO)) && (gpio_get_level(DRIVER_SEATBELT_GPIO))){
            gpio_set_level(GREENLED_GPIO, 1);
            if(gpio_get_level(DRIVER_GPIO)){
                printf("driver \n");
            }
            if(gpio_get_level(PASSENGER_GPIO)){
                printf("passenger \n");
            }
            if (gpio_get_level(PASSENGER_SEATBELT_GPIO))
            {
                printf("passenger seatbelt \n");
            }
            if (gpio_get_level(DRIVER_SEATBELT_GPIO))
            {
                printf("driver seatbelt \n");
            }
            vTaskDelay(1000/ portTICK_PERIOD_MS);
        }
        else{
            gpio_set_level(GREENLED_GPIO, 0);
        }
        vTaskDelay(25/  portTICK_PERIOD_MS);
    }
}   
