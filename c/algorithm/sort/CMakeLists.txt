cmake_minimum_required(VERSION 2.8)
project (main C)
add_definitions (-Wall -Werror)

#static link
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

#c99
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -g")

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.c")
add_executable(main  ${SOURCES})
