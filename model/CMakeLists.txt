###########################################################
##  MODEL - EXTERNAL LIBRARIES
###########################################################

if (WIN32)

	###########################################################
	##  WINDOWS
	###########################################################

	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../build/windows)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../build/windows)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../build/windows)
	
	set(DISTRIB_LETTER W)

endif (WIN32)

if (UNIX)

	###########################################################
	##  UNIX
	###########################################################
	
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../build/unix)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../build/unix)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../build/unix)
	
	set(DISTRIB_LETTER U)

endif (UNIX)

	# Load external libraries dynamically
    add_library (
		DLLoader
		STATIC
		../include/DLLoader/DLDictionary.h
		../include/DLLoader/DLibrary.h
		../include/DLLoader/CWDLibrary.h
		DLLoader/DLibrary.cpp
		DLLoader/C${DISTRIB_LETTER}DLibrary.cpp
	)
	
	# WorkQueue
	add_library (
		workQueueManager
		SHARED
		../include/workQueueManager/workQueueManager.h
		../include/workQueueManager/CUMutex.h
		../include/workQueueManager/CWMutex.h # To join
		../include/workQueueManager/workQueue.h
		workQueueManager/CUMutex.cpp
		workQueueManager/CWMutex.cpp # To join
		workQueueManager/workQueue.cpp
		workQueueManager/workQueueManager.cpp
	)

	# Say Hello
	add_library (
		sayHello
		SHARED
		../include/DLLoader/DLDictionary.h
		../include/sayHello/sayHello.h
		sayHello/sayHello.cpp
	)
	
	# Info Client
	add_library (
	    infoClient
		SHARED
		../include/IInfoClient.h
		infoClient/InfoClient.cpp
		infoClient/InfoClient.hpp
	)
	
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
		../include/keylogger_dll/KeyboardEvent.h
		../include/keylogger_dll/KeyboardHook.h
		../include/keylogger_dll/Keylogger.h
		../include/keylogger_dll/MouseEvent.h
		../include/keylogger_dll/MouseHook.h
		../include/keylogger_dll/IKeylogger.h
		../include/keylogger_dll/IHookObserver.h
		../include/keylogger_dll/MouseHookObserver.h
		../include/keylogger_dll/KeyboardHookObserver.h
		../include/keylogger_dll/AHookObserver.h
		../include/keylogger_dll/IAnalyser.h
		../include/keylogger_dll/Analyser.h
		keylogger_dll/AEvent.cpp
		keylogger_dll/AHook.cpp
		keylogger_dll/EventFactory.cpp
		keylogger_dll/EventManager.cpp
		keylogger_dll/HookHandler.cpp
		keylogger_dll/KeyboardEvent.cpp
		keylogger_dll/KeyboardHook.cpp
		keylogger_dll/Keylogger.cpp
		keylogger_dll/MouseEvent.cpp
		keylogger_dll/MouseHook.cpp
		keylogger_dll/instantiate.cpp
		keylogger_dll/AHookObserver.cpp
		keylogger_dll/KeyboardHookObserver.cpp
		keylogger_dll/MouseHookObserver.cpp
		keylogger_dll/Analyser.cpp
	) 

	# dataHandler
	add_library (
		dataHandler
		SHARED
		../include/dataHandler/DataHandler.h
		../include/dataHandler/C${DISTRIB_LETTER}File.h
		../include/dataHandler/FileHandler.h
		../include/dataHandler/C${DISTRIB_LETTER}FileHandler.h
		../include/dataHandler/Serializer.h
		../include/dataHandler/XMLSerializer.h
		dataHandler/DataHandler.cpp
		dataHandler/C${DISTRIB_LETTER}File.cpp
		dataHandler/C${DISTRIB_LETTER}FileHandler.cpp
		dataHandler/XMLSerializer.cpp
	)
