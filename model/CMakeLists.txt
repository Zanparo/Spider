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
<<<<<<< HEAD

	# Info Client
	add_library (
	        infoClient
		SHARED
		../include/IInfoClient.h
		infoClient/InfoClient.cpp
		infoClient/InfoClient.hpp
	)
=======
	
	# Keylogger_dll
	add_library (
		keylogger_dll
		SHARED
		../include/keylogger_dll/AEvent.h
		../include/keylogger_dll/AHook.h
		../include/keylogger_dll/Context.h
		../include/keylogger_dll/EventFactory.h
		../include/keylogger_dll/EventManager.h
		../include/keylogger_dll/HookHandler.h
		../include/keylogger_dll/HookObserver.h
		../include/keylogger_dll/KeyboardEvent.h
		../include/keylogger_dll/KeyboardHook.h
		../include/keylogger_dll/Keylogger.h
		../include/keylogger_dll/KeyloggerDLL.h
		../include/keylogger_dll/MouseEvent.h
		../include/keylogger_dll/MouseHook.h
		keylogger_dll/AEvent.cpp
		keylogger_dll/AHook.cpp
		keylogger_dll/EventFactory.cpp
		keylogger_dll/EventManager.cpp
		keylogger_dll/HookHandler.cpp
		keylogger_dll/HookObserver.cpp
		keylogger_dll/KeyboardEvent.cpp
		keylogger_dll/KeyboardHook.cpp
		keylogger_dll/Keylogger.cpp
		keylogger_dll/MouseEvent.cpp
		keylogger_dll/MouseHook.cpp
		keylogger_dll/instantiate.cpp
	) 

##	# DataHandler
##	add_library (
##		dataHandler
##		SHARED
##		../include/datahandler/AFile.h
##		../include/datahandler/CUFile.h
##		../include/datahandler/CWFile.h
##		../include/datahandler/DataHandler.h
##		../include/datahandler/DataModel.h
##		../include/datahandler/DataModelFactory.h
##		../include/datahandler/DataModelHandler.h
##		../include/datahandler/FileHandler.h
##		../include/datahandler/FileManager.h
##		../include/datahandler/IFile.h
##		../include/datahandler/ISerializer.h
##		../include/datahandler/XMLSerializer.h
##		datahandler/AFile.cpp
##		datahandler/CUFile.cpp
##		datahandler/CWFile.cpp
##		datahandler/DataHandler.cpp
##		datahandler/DataModel.cpp
##		datahandler/DataModelFactory.cpp
##		datahandler/DataModelHandler.cpp
##		datahandler/FileHandler.cpp
##		datahandler/FileManager.cpp
##		datahandler/IFile.cpp
##		datahandler/main.cpp
##		datahandler/Tester.cpp
##		datahandler/XMLSerializer.cpp
##	)
>>>>>>> keylogger_test
