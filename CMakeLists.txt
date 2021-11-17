cmake_minimum_required(VERSION 3.8) #version as of 2021
project(CastEngineProject VERSION 1.0.0) #check for C and C++ extensions
#set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})


if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()



if(LINUX)
    message("LINUX MACHINE")
	set(OpenGL_GL_PREFERENCE "GLVND")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    set( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fPIC" )
    set(VULKAN_ROOT "$ENV{VULKAN_SDK}")
    set(VULKAN_LIB "${VULKAN_ROOT}/lib/")
    set(VULKAN_INCLUDE "${VULKAN_ROOT}/include/")
    set(VULKAN_LIB_NAME "vulkan")
    
else()
    set(VULKAN_ROOT "$ENV{VULKAN_SDK}")
    set(VULKAN_LIB "${VULKAN_ROOT}/Lib/")
    set(VULKAN_INCLUDE "${VULKAN_ROOT}/Include")
    set(VULKAN_LIB_NAME "vulkan-1")

endif()

set(RESOURCES_PATH "CastEngine/src/Resources/")
set(RESOURCES_ABSOLUTE_PATH "${CMAKE_SOURCE_DIR}/${RESOURCES_PATH}")
    
message(STATUS "${VULKAN_ROOT}")
message(STATUS "${VULKAN_LIB}")
message(STATUS "${VULKAN_INCLUDE}")
message(STATUS "${RESOURCES_ABSOLUTE_PATH}")


set( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -O3 -fPIC" )
set(EXE_FINAL_NAME "CastEngine_Driver")

find_package(OpenGL REQUIRED)
option(GLFW_BUILD_EXAMPLES "" OFF)
option(GLFW_INSTALL "" OFF)
option(GLFW_BUILD_TESTS "" OFF)
option(BUILD_SHARED_LIBS "" OFF)

set(ROOT "${CMAKE_SOURCE_DIR}")
set(DEPENDENCIES "${CMAKE_SOURCE_DIR}/Dependencies")


set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")


set(LIBRARY_PROJECT_NAME "CastEngine")
add_subdirectory("${LIBRARY_PROJECT_NAME}")
add_subdirectory(CastDriver)
add_subdirectory(Dependencies/glfw)
add_subdirectory(Dependencies/glad)
add_subdirectory(Dependencies/glm)
add_subdirectory(Dependencies/fmt EXCLUDE_FROM_ALL)



if(LINUX)
    target_compile_definitions("${LIBRARY_PROJECT_NAME}" PUBLIC UNIX=1)
else()
    target_compile_definitions("${LIBRARY_PROJECT_NAME}" PUBLIC UNIX=0)
endif()

target_compile_definitions("${LIBRARY_PROJECT_NAME}" PUBLIC CAST_RESOURCES_ABSOLUTE_PATH="${RESOURCES_ABSOLUTE_PATH}")
    