cmake_minimum_required(VERSION 3.0)
#set(CMAKE_BUILD_TYPE Debug )
set(CMAKE_CXX_STANDARD 17)
project(h)

set(SOURCES solving.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})