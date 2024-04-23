cmake_minimum_required(VERSION 3.0.0)
project(FillAttributes VERSION 1.0.0)

set(FILLATTRIBUTES_SRC ${CMAKE_CURRENT_SOURCE_DIR}/FillAttributes.cpp)

add_library(FillAttributes SHARED ${FILLATTRIBUTES_SRC})

target_include_directories(FillAttributes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})