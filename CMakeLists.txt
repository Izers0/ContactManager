cmake_minimum_required(VERSION 4.1)
project(ContactManager)

set(CMAKE_CXX_STANDARD 20)

add_executable(ContactManager main.cpp
        contactFunctionHeader.h
        contactFunctions.cpp
        contactClass.h
        validation.cpp
        validation.h
)
