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
    gpio_pullup_en(DRIVER_GPIO);

    gpio_reset_pin(PASSENGER_GPIO);
    gpio_set_direction(PASSENGER_GPIO, GPIO_MODE_INPUT);
    gpio_pullup_en(PASSENGER_GPIO);

    gpio_reset_pin(DRIVER_SEATBELT_GPIO);
    gpio_set_direction(DRIVER_SEATBELT_GPIO, GPIO_MODE_INPUT);
    gpio_pullup_en(DRIVER_SEATBELT_GPIO);

    gpio_reset_pin(PASSENGER_SEATBELT_GPIO);
    gpio_set_direction(PASSENGER_SEATBELT_GPIO, GPIO_MODE_INPUT);
    gpio_pullup_en(PASSENGER_SEATBELT_GPIO);

    gpio_reset_pin(IGNITION_GPIO);
    gpio_set_direction(IGNITION_GPIO, GPIO_MODE_INPUT);
    gpio_pullup_en(IGNITION_GPIO);

    gpio_reset_pin(GREENLED_GPIO);
    gpio_set_direction(GREENLED_GPIO, GPIO_MODE_OUTPUT);

    gpio_reset_pin(BLUELED_GPIO);
    gpio_set_direction(BLUELED_GPIO, GPIO_MODE_OUTPUT);

    gpio_reset_pin(BUZZER_GPIO);
    gpio_set_direction(BUZZER_GPIO, GPIO_MODE_OUTPUT);

    
}
