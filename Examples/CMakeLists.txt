add_executable(InvertedPendulum InvertedPendulum.cpp)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(InvertedPendulum PRIVATE pico_stdlib rotary_encoder stepperDriver)

pico_enable_stdio_usb(InvertedPendulum 1)
pico_enable_stdio_uart(InvertedPendulum 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(InvertedPendulum)

# add_executable(InvertedPendulumObject InvertedPendulum.cpp)

# # Pull in our pico_stdlib which pulls in commonly used features
# target_link_libraries(InvertedPendulumObject PRIVATE pico_stdlib rotary_encoder stepperDriverObject)

# # create map/bin/hex file etc.
# pico_add_extra_outputs(InvertedPendulumObject)
