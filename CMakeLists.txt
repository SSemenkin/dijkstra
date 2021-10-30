cmake_minimum_required(VERSION 3.5)

project(dijkstra LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_subdirectory(myvector)

add_executable(dijkstra main.cpp)

#subdirs("${PROJECT_SOURCE_DIR}/myvector")
include_directories('myvector')
