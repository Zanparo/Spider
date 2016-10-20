cmake_minimum_required(VERSION 3.2.2.)

project(Spider)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_executable(
	server
	src.cpp
	header.h
)

add_executable(
	client
	src.cpp
	header.h
)