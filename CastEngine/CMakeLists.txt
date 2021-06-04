set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
	CastEngine SHARED 
	src/Cast/TestFile.cpp
	src/Cast/TestFile.h
	)


add_custom_command(TARGET CastEngine PRE_BUILD        
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  
    "${VULKAN_ROOT}/Lib/vulkan-1.lib"      
    "${EXECUTABLE_OUTPUT_PATH}")                 

add_custom_command(TARGET CastEngine PRE_BUILD        
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  
    "${GLFW_ABS_LIB}/glfw3dll.lib"      
    "${EXECUTABLE_OUTPUT_PATH}")  

add_custom_command(TARGET CastEngine PRE_BUILD        
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  
    "${GLFW_ABS_LIB}/glfw3.dll"      
    "${EXECUTABLE_OUTPUT_PATH}")  


target_compile_definitions(CastEngine PUBLIC CAST_DEBUG_MODE=1)

target_include_directories(CastEngine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(CastEngine PUBLIC "${ENTT_ABS_ROOT}")
target_include_directories(CastEngine PUBLIC "${GLFW_ABS_INCLUDE}")
target_include_directories(CastEngine PUBLIC "${EXTERN_DIR}/glm")
target_include_directories(CastEngine PUBLIC "${EXTERN_DIR}/stbimage")
target_include_directories(CastEngine PUBLIC "${VULKAN_INCLUDE}")

target_link_directories(CastEngine PUBLIC "${GLFW_ABS_LIB}")
target_link_directories(CastEngine PUBLIC "${VULKAN_LIB}")
target_link_libraries(CastEngine glfw3dll)
target_link_libraries(CastEngine vulkan-1)
target_link_libraries(CastEngine pthread)

find_package(OpenGL REQUIRED)
target_link_libraries(CastEngine OpenGL::GL)