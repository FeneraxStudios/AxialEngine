cmake_minimum_required (VERSION 3.13)

project("Core")

add_library(AxialEngine "")

add_subdirectory("include")
add_subdirectory("system")

target_include_directories(AxialEngine PUBLIC ${PROJECT_SOURCE_DIR})
