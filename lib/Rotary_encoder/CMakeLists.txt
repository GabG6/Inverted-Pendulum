add_library(rotary_encoder pio_rotary_encoder.cpp pio_rotary_encoder.h pio_rotary_encoder.pio.h)

pico_generate_pio_header(rotary_encoder ${CMAKE_CURRENT_LIST_DIR}/pio_rotary_encoder.pio)

#add_library(rotary_encoder pio_rotary_encoder.pio.h)

#target_sources(rotary_encoder PRIVATE pio_rotary_encoder.cpp)


target_link_libraries(rotary_encoder pico_stdlib hardware_pio)

target_include_directories(rotary_encoder PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

pico_enable_stdio_usb(rotary_encoder 1)
pico_enable_stdio_uart(rotary_encoder 0)