cmake_minimum_required(VERSION 3.0.0)
project(FileOperations VERSION 1.0.0)

set(FILEOPERATIONS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/FileOperations.cpp)

add_library(FileOperations SHARED ${FILEOPERATIONS_SRC})

target_include_directories(FileOperations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                                 ${GEOMETRICSHAPES_SRC_DIR}/libs/ExceptionHandler)
target_link_libraries(FileOperations ${ExceptionHandler})