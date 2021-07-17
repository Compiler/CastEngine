set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
	CastEngine SHARED 
	src/Cast/Core/EngineCore.cpp
	src/Cast/Core/EngineCore.h
	src/Cast/Core/Components/Transform.h
	src/Cast/Core/Debug/Logger.h
	src/Cast/Core/Debug/LoggingHeaderOnly.h
	src/Cast/Core/Debug/LoggingUserFormatter.h
	src/Cast/Core/Input/InputManager.cpp
	src/Cast/Core/Input/InputManager.h
	src/Cast/Core/Rendering/RenderContext.cpp
	src/Cast/Core/Rendering/RenderContext.h
	src/Cast/Core/Rendering/Renderer.h
	src/Cast/Core/Rendering/Window.cpp
	src/Cast/Core/Rendering/Window.h
	src/Cast/Core/Rendering/Shader/OpenGLShaderProgram.cpp
	src/Cast/Core/Rendering/Shader/OpenGLShaderProgram.h
	src/Cast/Core/Rendering/Shader/ShaderParser.cpp
	src/Cast/Core/Rendering/Shader/ShaderParser.h
	src/Cast/Core/Utils/DebugScene.cpp
	src/Cast/Core/Utils/DebugScene.h
	src/Cast/Core/Utils/Files/FileLoaderFactory.cpp
	src/Cast/Core/Utils/Files/FileLoaderFactory.h
	src/Cast/Platform/GLFW/GLFWInputKeyStore.h
	src/Cast/Platform/OpenGL/OpenGLCallbacks.cpp
	src/Cast/Platform/OpenGL/OpenGLCallbacks.h
	src/Cast/Platform/OpenGL/OpenGLContext.cpp
	src/Cast/Platform/OpenGL/OpenGLContext.h
	src/Cast/Platform/OpenGL/OpenGLWindow.cpp
	src/Cast/Platform/OpenGL/OpenGLWindow.h
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
#target_compile_definitions(CastEngine PUBLIC GLFW_INCLUDE_NONE)
 
target_compile_definitions(CastEngine PUBLIC CAST_ENGINE_NAME=CastEngine)

target_include_directories(CastEngine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(CastEngine PUBLIC "${ENTT_ABS_ROOT}")
target_include_directories(CastEngine PUBLIC "${GLFW_ABS_INCLUDE}")
target_include_directories(CastEngine PUBLIC "${EXTERN_DIR}/glm")
target_include_directories(CastEngine PUBLIC "${EXTERN_DIR}/stbimage")
target_include_directories(CastEngine PUBLIC "${VULKAN_INCLUDE}")
target_include_directories(CastEngine PUBLIC "${FMT_ROOT}/include")
target_include_directories(CastEngine PUBLIC "${GLAD_INC}")

find_package(OpenGL REQUIRED)
target_link_libraries(CastEngine OpenGL::GL)
target_link_directories(CastEngine PUBLIC "${GLFW_ABS_LIB}")
target_link_directories(CastEngine PUBLIC "${VULKAN_LIB}")
target_link_directories(CastEngine PUBLIC "${FMT_ROOT}/")
target_link_libraries(CastEngine glfw3dll)
target_link_libraries(CastEngine vulkan-1)
target_link_libraries(CastEngine pthread)
target_link_libraries(CastEngine fmt::fmt-header-only)
target_link_libraries(CastEngine glad)



