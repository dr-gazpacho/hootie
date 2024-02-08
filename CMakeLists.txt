cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(hootie C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(hootie
  hootie.c
)
pico_enable_stdio_usb(hootie 1)
pico_enable_stdio_uart(hootie 1)
pico_add_extra_outputs(hootie)
target_link_libraries(hootie pico_stdlib hardware_pwm pico_time hardware_irq)
