cmake_minimum_required(VERSION 3.0.0)
project(ExceptionHandler VERSION 1.0.0)

set(EXCEPTIONHANDLER_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ExceptionHandler.cpp)

add_library(ExceptionHandler SHARED ${EXCEPTIONHANDLER_SRC})

target_include_directories(ExceptionHandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})