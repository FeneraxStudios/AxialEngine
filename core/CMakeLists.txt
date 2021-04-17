cmake_minimum_required (VERSION 3.13)

project("Core")

add_library(AxialEngine "")

add_subdirectory("include")
add_subdirectory("system")
add_subdirectory("input")
add_subdirectory("rendering")
add_subdirectory("platform/windows")
add_subdirectory("graphics/opengl")

target_include_directories(AxialEngine PUBLIC
"${PROJECT_SOURCE_DIR}"
"${CMAKE_SOURCE_DIR}/extern/glfw/include"
)

target_link_libraries(AxialEngine glfw ${GLFW_LIBARIES})
