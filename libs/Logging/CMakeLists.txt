cmake_minimum_required(VERSION 3.0.0)
project(Logging VERSION 1.0.0)

set(LOGGING_SRC ${CMAKE_CURRENT_SOURCE_DIR}/Logging.cpp)

add_library(Logging SHARED ${LOGGING_SRC})

set_property(TARGET Logging PROPERTY CXX_STANDARD 20)
target_include_directories(Logging PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                          ${GEOMETRICSHAPES_SRC_DIR}/libs/FileOperations)

target_link_libraries(Logging ${FileOperations})