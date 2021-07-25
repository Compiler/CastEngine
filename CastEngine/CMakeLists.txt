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


add_definitions(-D_DEBUG_MODE_ -DCAST_DEBUG_MODE)
target_compile_definitions(${LIBRARY_PROJECT_NAME} PUBLIC "CAST_ENGINE_NAME=${LIBRARY_PROJECT_NAME}")

target_include_directories("${LIBRARY_PROJECT_NAME}" PUBLIC "${DEPENDENCIES}/glfw/include")
target_include_directories("${LIBRARY_PROJECT_NAME}" PUBLIC "${DEPENDENCIES}/glad/include")
target_include_directories("${LIBRARY_PROJECT_NAME}" PUBLIC "${DEPENDENCIES}/fmt/include")
target_include_directories("${LIBRARY_PROJECT_NAME}" PUBLIC "${DEPENDENCIES}/glm")
target_include_directories("${LIBRARY_PROJECT_NAME}" PUBLIC "${DEPENDENCIES}/stbimage")

target_include_directories("${LIBRARY_PROJECT_NAME}" PUBLIC "${ROOT}/${LIBRARY_PROJECT_NAME}/src/")#link the root

message("\n\n\n=======================\n${ROOT}/${LIBRARY_PROJECT_NAME}/src/")


target_link_libraries("${LIBRARY_PROJECT_NAME}" PRIVATE glad)
target_link_libraries("${LIBRARY_PROJECT_NAME}" PRIVATE glfw ${GLFW_LIBRARIES})
target_link_libraries("${LIBRARY_PROJECT_NAME}" PRIVATE fmt)

