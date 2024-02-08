#include "pico/stdlib.h"
#include <stdio.h>
#include "pico/time.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"
#include "pico/binary_info.h"

const uint LED_PIN = 25;

uint32_t gpio_get_events(uint gpio){
  int32_t mask = 0xF << 4 * (gpio % 8);
  return (iobank0_hw->intr[gpio / 8] & mask) >> 4 * (gpio % 8);
}

void gpio_clear_events(uint gpio, uint32_t events){
  gpio_acknowledge_irq(gpio, events);
}

int main() {
  bi_decl(bi_program_description("This is a dumbass binary"));
  bi_decl(bi_1pin_with_name(LED_PIN, "Baby on-board"));

  stdio_init_all();

  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  gpio_set_function(25, GPIO_FUNC_SIO);
  gpio_set_dir(25, false);
  gpio_set_function(26, GPIO_FUNC_SIO);
  gpio_set_dir(26, false);
  gpio_set_function(27, GPIO_FUNC_SIO);
  gpio_set_dir(27, false);




  while(1){
    printf("runnin");	  
    int32_t event25 = gpio_get_events(25);
    int32_t event26 = gpio_get_events(26);
    int32_t event27 = gpio_get_events(27);

    printf(event25);
    gpio_put(LED_PIN, 1);
    gpio_clear_events(25, GPIO_IRQ_EDGE_RISE);
    gpio_clear_events(26, GPIO_IRQ_EDGE_RISE);
    gpio_clear_events(27, GPIO_IRQ_EDGE_RISE);
    sleep_ms(1000);
  }

}
