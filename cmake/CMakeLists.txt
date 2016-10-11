# Project

project(sayHello)


# Sources

file(

        GLOB_RECURSE

        source_files

        srcs/*
		
		includes/*

)

# Exec

add_executable(

        say_hello

        $(source_files)

)