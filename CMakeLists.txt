cmake_minimum_required(VERSION 3.10)
project(main)

set(CMAKE_CXX_STANDARD 14)
# Gather all .hpp files in the current directory
set(INC_DIR "code/inc")
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${INC_DIR}/*.hpp")
include_directories(code/inc)

set(SRC_DIR "code/src")
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${SRC_DIR}/*.cpp")
# set(SOURCES SOURCE_LIST)
add_executable(main ${SOURCE_LIST})


