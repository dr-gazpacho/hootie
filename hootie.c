#include "pico/stdlib.h"
#include <stdio.h>
#include "pico/time.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"
#include "pico/binary_info.h"

const uint LED_PIN = 25;

int main() {
  bi_decl(bi_program_description("This is a dumbass binary"));
  bi_decl(bi_1pin_with_name(LED_PIN, "Baby on-board"));

  stdio_init_all();

  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  while(1){
    gpio_put(LED_PIN, 0);
    sleep_ms(250);
    gpio_put(LED_PIN, 1);
    puts("I AM ALIVE\n");
    sleep_ms(1000);
  }

}
