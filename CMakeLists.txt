cmake_minimum_required(VERSION 3.20)

project(Blockchain VERSION 1.0.0 LANGUAGES CXX)
find_package(jsoncpp REQUIRED)

add_executable(blockchain src/main.cpp src/Block.cpp)
target_link_libraries(blockchain jsoncpp)

target_include_directories(blockchain 
	PUBLIC
	#/usr/include
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
