cmake_minimum_required(VERSION 3.0.0)
project(GeometricShapes VERSION 1.0.0)

set(GEOMETRICSHAPES_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(GEOMETRICSHAPES_LIBS_DIR ${GEOMETRICSHAPES_SRC_DIR}/build/libs)
set(GEOMETRICSHAPES_MAIN main.cpp)

set(GEOMETRICSHAPES_SRC 
    ${GEOMETRICSHAPES_SRC_DIR}/GeometricShapes.cpp
    ${GEOMETRICSHAPES_SRC_DIR}/components/Point/Point.cpp
    ${GEOMETRICSHAPES_SRC_DIR}/components/Line/Line.cpp
    ${GEOMETRICSHAPES_SRC_DIR}/components/Triangle/Triangle.cpp)

add_executable(GeometricShapes ${GEOMETRICSHAPES_MAIN} ${GEOMETRICSHAPES_SRC})

set_property(TARGET GeometricShapes PROPERTY CXX_STANDARD 20)
target_include_directories(GeometricShapes PUBLIC 
                                                  ${GEOMETRICSHAPES_SRC_DIR}
                                                  ${GEOMETRICSHAPES_SRC_DIR}/components
                                                  ${GEOMETRICSHAPES_SRC_DIR}/libs/FillAttributes
                                                  ${GEOMETRICSHAPES_SRC_DIR}/libs/FileOperations
                                                  ${GEOMETRICSHAPES_SRC_DIR}/libs/Logging
                                                  ${GEOMETRICSHAPES_SRC_DIR}/libs/ExceptionHandler)
                                                  
target_link_libraries(GeometricShapes FillAttributes FileOperations Logging ExceptionHandler)

add_subdirectory(${GEOMETRICSHAPES_SRC_DIR}/libs/FillAttributes)
add_subdirectory(${GEOMETRICSHAPES_SRC_DIR}/libs/FileOperations)
add_subdirectory(${GEOMETRICSHAPES_SRC_DIR}/libs/Logging)
add_subdirectory(${GEOMETRICSHAPES_SRC_DIR}/libs/ExceptionHandler)