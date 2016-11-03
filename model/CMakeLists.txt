###########################################################
##  MODEL - EXTERNAL LIBRARIES
###########################################################

include_directories("../include")


if (WIN32)

	###########################################################
	##  WINDOWS
	###########################################################

	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../build/windows)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../build/windows)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../build/windows)

	# Load external libraries dynamically
    add_library (
		DLLoader
		STATIC
		../include/DLDictionary.h
		../include/DLibrary.h
		../include/CWDLibrary.h
		DLLoader/DLibrary.cpp
		DLLoader/CWDLibrary.cpp
	)

endif (WIN32)

if (UNIX)

	###########################################################
	##  UNIX
	###########################################################

	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../build/unix)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../build/unix)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../build/unix)

	# Load external libraries dynamically
    add_library (
		DLLoader
		STATIC
		../include/DLDictionary.h
		../include/DLibrary.h
		../include/CUDLibrary.h
		DLLoader/DLibrary.cpp
		DLLoader/CUDLibrary.cpp
	)

endif (UNIX)

# Say Hello
add_library (
  sayHello
  SHARED
  ../include/DLDictionary.h
  ../include/sayHello.h
  sayHello/sayHello.cpp
)

# Say Hello
add_library (
  network
  SHARED
  ../include/network.h
  network/network.cpp
)