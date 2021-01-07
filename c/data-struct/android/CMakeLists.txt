cmake_minimum_required(VERSION 2.8)
project (test)

add_definitions (
	-o2
)

set(SOURCES
 ${PROJECT_SOURCE_DIR}/test.c
)

#static link
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

include_directories (${PROJECT_SOURCE_DIR}/)

add_executable(test ${SOURCES})
