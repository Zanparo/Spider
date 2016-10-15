#!/bin/sh

g++ client.cpp -o client -lboost_system -lboost_thread -lcrypto -lssl -lpthread 2> error.compil

if [ $? -eq 0 ]; then
	echo "\033[32mCompilation sucessfull\033[0m"
	./client $1 $2
else
	echo "Error have been made. Do you want to print the compilation \033[31merrors\033[0m ? [y/N] "
	read -r response
	case $response in
	    [yY][eE][sS]|[yY]) 
		less error.compil
	        ;;
	    *)
	        echo "Have fun... :^D"
	        ;;
	esac
fi
