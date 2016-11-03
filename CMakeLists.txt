###########################################################
##  SPIDER PROJECT
###########################################################

cmake_minimum_required(VERSION 2.6)

project("Spider")

include_directories("include")

add_subdirectory(model)

if (WIN32)

	###########################################################
	##  WINDOWS
	###########################################################
	
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY build/windows)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY build/windows)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build/windows)

endif (WIN32)

if (UNIX)

	###########################################################
	##  UNIX
	###########################################################
	
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY build/unix)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY build/unix)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build/unix)

endif (UNIX)

add_executable (
	client
	include/client.h
	launcher/client.cpp
	controller/clientController/clientController.cpp
)

target_link_libraries(client DLLoader)

