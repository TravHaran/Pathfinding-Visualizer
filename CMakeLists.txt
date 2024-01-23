cmake_minimum_required(VERSION 3.24)
project(
    pathfindingVisualizer
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(SOURCES
    src/core/Application.cpp 
    src/Main.cpp 
)


include_directories(
    ${PROJECT_SOURCE_DIR}/src 
)

add_executable(pathfindingVisualizer ${SOURCES})

target_link_libraries(pathfindingVisualizer OpenGL::GL GLUT::GLUT)

set_target_properties(pathfindingVisualizer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})