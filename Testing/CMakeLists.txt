### MUST RUN COMMAND FOR LINUX: "export PICO_SDK_PATH=/full/path/to/pico-sdk-master/from/github"
cmake_minimum_required(VERSION 3.22)# minimum version
set(PICO_BOARD pico) # sets board because w exists
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake) # main sdk /home/daniel/pico-sdk-master/external/pico_sdk_import.cmake
project(Testing C CXX ASM) # (name of project, languages to include)
set(CMAKE_C_STANDARD 11) # default for pico c
set(CMAKE_CXX_STANDARD 17) # default for pico cpp
pico_sdk_init() # pico libraries
add_executable(${PROJECT_NAME} testing.cpp)#list all files to include in build
pico_add_extra_outputs(${PROJECT_NAME}) #allows for other file times on output (.map, .bin, .hex, .uf2)
target_link_libraries(${PROJECT_NAME}
    pico_stdlib #pico standard library
)