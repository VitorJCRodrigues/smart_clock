# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(smart_clock C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Define the destination directory in the build output
set(DESTINATION_DIR ${CMAKE_BINARY_DIR})

# Define the destination directory in the build output
set(SSD1306_DIR ${CMAKE_CURRENT_LIST_DIR}/ssd1306)

# Define the includes and sources directories in the build output
set(INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/inc)
set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)


# Add executable. Default name is the project name, version 0.1
add_executable(smart_clock 
            smart_clock.c 
            ${SSD1306_DIR}/ssd1306.c
            ${SOURCE_DIR}/media_player.c
            )

pico_set_program_name(smart_clock "smart_clock")
pico_set_program_version(smart_clock "0.1")

# Generate PIO header
pico_generate_pio_header(smart_clock ${CMAKE_CURRENT_LIST_DIR}/blink.pio ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio)

# Add the standard library to the build
target_link_libraries(smart_clock
        pico_stdlib
        pico_stdio
        hardware_i2c
        hardware_adc
        )

# Add the standard include files to the build
target_include_directories(smart_clock PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${SSD1306_DIR}
        ${INCLUDE_DIR}
        ${SOURCE_DIR}
)

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(smart_clock 0)
pico_enable_stdio_usb(smart_clock 1)

# Add any user requested libraries
target_link_libraries(smart_clock 
        hardware_spi
        hardware_i2c
        hardware_pio
        hardware_timer
        hardware_watchdog
        hardware_clocks
        hardware_pwm
        hardware_adc
        )

# Add extra outputs (UF2, bin, etc.)
pico_add_extra_outputs(smart_clock)
