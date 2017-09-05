cmake_minimum_required(VERSION 3.8)
project(gtk2cod3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES gtk2cod3.cpp gtkread.cpp gtkread.h node.cpp node.h)
add_executable(gtk2cod3 ${SOURCE_FILES})
