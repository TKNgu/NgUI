#Cmake version.
cmake_minimum_required(VERSION 3.20.0)
include(ExternalProject)

# C++ std 20.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-no-pie")

# OpenCL
project(NgUI VERSION 0.1.0 LANGUAGES CXX C DESCRIPTION "Simple lin GUI C++")

# Local folder install lib
set(LOCAL_LIB ${PROJECT_SOURCE_DIR}/local/)

# GLFW
ExternalProject_Add(GLFW
	PREFIX  ${PROJECT_SOURCE_DIR}/lib/
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG 3.3.8
	CMAKE_ARGS
		-DCMAKE_INSTALL_PREFIX:PATH=${LOCAL_LIB})

# STB
ExternalProject_Add(stb
	PREFIX  ${PROJECT_SOURCE_DIR}/lib
	GIT_REPOSITORY https://github.com/nothings/stb.git
	CONFIGURE_COMMAND ""
	BUILD_COMMAND ""
	INSTALL_COMMAND "")

# GLM
ExternalProject_Add(GLM
	PREFIX  ${PROJECT_SOURCE_DIR}/lib
	GIT_REPOSITORY https://github.com/g-truc/glm.git
	GIT_TAG 0.9.9.8
	CONFIGURE_COMMAND ""
	BUILD_COMMAND ""
	INSTALL_COMMAND "")

# Include
include_directories(
	local/include/
	lib/src/stb/	
	lib/src/GLM/	
	src/glad/include/
	src/Graphic/)

# Link
link_directories(local/lib)

# Source code
file(GLOB SRC
	src/glad/src/glad.c
    src/Graphic/*.cpp
	src/*.cpp)

# Build sample
add_executable(${CMAKE_PROJECT_NAME} ${SRC})

# Target
target_link_libraries(${CMAKE_PROJECT_NAME} glfw3 X11)

# Run 
add_custom_target(run ${CMAKE_PROJECT_NAME}
    DEPENDS ${SAMPLE}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
