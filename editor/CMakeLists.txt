cmake_minimum_required (VERSION 3.13)

project("Editor")

add_executable(AxialEditor 
	"AxialEditor.cpp"
)

target_include_directories(AxialEditor PUBLIC "${CMAKE_SOURCE_DIR}/core/include")

target_link_libraries(AxialEditor PUBLIC AxialEngine)