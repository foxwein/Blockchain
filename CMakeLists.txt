cmake_minimum_required(VERSION 3.20)

project(Blockchain VERSION 1.0.0 LANGUAGES CXX)

add_executable(blockchain src/main.cpp src/Block.cpp src/simdjson.cpp)

target_include_directories(blockchain 
	PUBLIC
	#/usr/include
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
