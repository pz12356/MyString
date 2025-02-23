cmake_minimum_required(VERSION 3.5.0)
project(MyString VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(./src DIR_SRCS)

add_executable(MyString main.cpp ${DIR_SRCS})

