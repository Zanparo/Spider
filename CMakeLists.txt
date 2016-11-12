###########################################################
##  SPIDER PROJECT
###########################################################

cmake_minimum_required(VERSION 2.6)

project("Spider")


include_directories(
	"include/DLLoader"
	"include/sayHello"
	"include/dataHandler"
	"include/network"
	"include"
	)

if (WIN32)
  set(BUILD_FOLDER build/windows)
endif (WIN32)

if (UNIX)
  set(BUILD_FOLDER build/unix)
endif (UNIX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_FOLDER})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_FOLDER})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_FOLDER})

# Build Models
add_subdirectory(model)

###########################################################
##  SPIDER CLIENT
###########################################################

add_executable (
	client
	include/client.h
	include/IInfoClient.h
	include/WorkQueue.h
	launcher/client.cpp
	controller/clientController/clientController.cpp
	controller/clientController/WorkQueue.cpp
)

target_link_libraries(client DLLoader)

#
#  Add additionnal libraries
#

if (WIN32)
  # Silence is golden
endif (WIN32)

if (UNIX)
  target_link_libraries(client dl)
endif (UNIX)

###########################################################
##  SPIDER SERVER
###########################################################