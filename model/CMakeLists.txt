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
		../include/DLLoader/DLDictionary.h
		../include/DLLoader/DLibrary.h
		../include/DLLoader/CWDLibrary.h
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
		../include/DLLoader/DLDictionary.h
		../include/DLLoader/DLibrary.h
		../include/DLLoader/CUDLibrary.h
		DLLoader/DLibrary.cpp
		DLLoader/CUDLibrary.cpp
	)

endif (UNIX)

	# Say Hello
	add_library (
		sayHello
		SHARED
		../include/DLLoader/DLDictionary.h
		../include/sayHello/sayHello.h
		sayHello/sayHello.cpp
	)

	# dataHandler
	add_library (
		dataHandler
		SHARED
		../include/dataHandler/CUFile.h
		../include/dataHandler/CWFile.h
		../include/dataHandler/dataHandler.h
		../include/dataHandler/DataModel.h
		../include/dataHandler/DataModelFactory.h
		../include/dataHandler/DataModelHandler.h
		../include/dataHandler/FileHandler.h
		../include/dataHandler/ISerializer.h
		../include/dataHandler/XMLSerializer.h
		dataHandler/CUFile.cpp
		dataHandler/CWFile.cpp
		dataHandler/dataHandler.cpp
		dataHandler/DataModel.cpp
		dataHandler/DataModelFactory.cpp
		dataHandler/DataModelHandler.cpp
		dataHandler/FileHandler.cpp
		dataHandler/XMLSerializer.cpp
	)