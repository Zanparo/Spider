# Project

project(sayHello)

# includes

INCLUDE_DIRECTORIES (
  headers/
)

# Sources

file(
  GLOB_RECURSE
  FILES
  srcs/*
)

# Exec

add_executable(
  say_hello
  ${FILES}
)