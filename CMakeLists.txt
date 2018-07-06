# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (list)

# Add an executable with the above sources
add_executable(exec include/list.h src/driver_list.cpp)

# Set the direcoties that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(exec
	PRIVATE 
	${PROJECT_SOURCE_DIR}/include
	)

target_compile_features(exec PRIVATE cxx_range_for)

# Generate compile flags
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
