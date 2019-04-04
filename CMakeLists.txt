cmake_minimum_required(VERSION 2.8.9)
project(linkedlist)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors \
-D_POSIX_C_SOURCE=200112L -std=c11")

if(CMAKE_BUILD_TYPE EQUAL "Debug")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Og")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
endif()

include_directories(include)
add_library(linkedlist SHARED "src/linked_list.c")
set_property(TARGET linkedlist PROPERTY POSITION_INDEPENDENT_CODE ON)
export(TARGETS linkedlist FILE linkedlist.cmake)
