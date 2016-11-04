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

	# DataHandler
	add_library (
		dataHandler
		SHARED
		../include/datahandler/AFile.h
		../include/datahandler/CUFile.h
		../include/datahandler/CWFile.h
		../include/datahandler/DataHandler.h
		../include/datahandler/DataModel.h
		../include/datahandler/DataModelFactory.h
		../include/datahandler/DataModelHandler.h
		../include/datahandler/FileHandler.h
		../include/datahandler/FileManager.h
		../include/datahandler/IFile.h
		../include/datahandler/ISerializer.h
		../include/datahandler/XMLSerializer.h
		datahandler/AFile.cpp
		datahandler/CUFile.cpp
		datahandler/CWFile.cpp
		datahandler/DataHandler.cpp
		datahandler/DataModel.cpp
		datahandler/DataModelFactory.cpp
		datahandler/DataModelHandler.cpp
		datahandler/FileHandler.cpp
		datahandler/FileManager.cpp
		datahandler/IFile.cpp
		datahandler/main.cpp
		datahandler/Tester.cpp
		datahandler/XMLSerializer.cpp
	)