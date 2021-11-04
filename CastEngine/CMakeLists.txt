set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
	CastEngine SHARED 
	src/Cast/API/GLFW/GLFWInputKeyStore.h
	src/Cast/API/OpenGL/OpenGLCallbacks.cpp
	src/Cast/API/OpenGL/OpenGLCallbacks.h
	src/Cast/API/OpenGL/OpenGLWindow.cpp
	src/Cast/API/OpenGL/OpenGLWindow.h
	src/Cast/API/OpenGL/Rendering/OpenGLContext.cpp
	src/Cast/API/OpenGL/Rendering/OpenGLContext.h
	src/Cast/API/OpenGL/Rendering/OpenGLRenderer.cpp
	src/Cast/API/OpenGL/Rendering/OpenGLRenderer.h
	src/Cast/API/OpenGL/Rendering/OpenGLTexture.cpp
	src/Cast/API/OpenGL/Rendering/OpenGLTexture.h
	src/Cast/API/OpenGL/Rendering/OpenGLVertexArray.cpp
	src/Cast/API/OpenGL/Rendering/OpenGLVertexArray.h
	src/Cast/API/OpenGL/Rendering/OpenGLVertexBuffer.cpp
	src/Cast/API/OpenGL/Rendering/OpenGLVertexBuffer.h
	src/Cast/API/OpenGL/Rendering/Shading/OpenGLShaderProgram.cpp
	src/Cast/API/OpenGL/Rendering/Shading/OpenGLShaderProgram.h
	src/Cast/API/Vulkan/DebugUtils/VkDebugUtils.cpp
	src/Cast/API/Vulkan/DebugUtils/VkDebugUtils.h
	src/Cast/API/Vulkan/Rendering/GraphicsPipeline.cpp
	src/Cast/API/Vulkan/Rendering/GraphicsPipeline.h
	src/Cast/API/Vulkan/Rendering/Vertex.h
	src/Cast/API/Vulkan/Rendering/VulkanContext.cpp
	src/Cast/API/Vulkan/Rendering/VulkanContext.h
	src/Cast/API/Vulkan/Rendering/VulkanInstance.cpp
	src/Cast/API/Vulkan/Rendering/VulkanInstance.h
	src/Cast/API/Vulkan/Rendering/VulkanRenderer.cpp
	src/Cast/API/Vulkan/Rendering/VulkanRenderer.h
	src/Cast/API/Vulkan/Rendering/VulkanShaderProgram.cpp
	src/Cast/API/Vulkan/Rendering/VulkanShaderProgram.h
	src/Cast/API/Vulkan/Rendering/VulkanWindow.cpp
	src/Cast/API/Vulkan/Rendering/VulkanWindow.h
	src/Cast/Core/EngineCore.cpp
	src/Cast/Core/EngineCore.h
	src/Cast/Core/Components/Transform.h
	src/Cast/Core/Debug/Logger.h
	src/Cast/Core/Debug/LoggingUserFormatter.h
	src/Cast/Core/Input/InputManager.cpp
	src/Cast/Core/Input/InputManager.h
	src/Cast/Core/Rendering/RenderContext.cpp
	src/Cast/Core/Rendering/RenderContext.h
	src/Cast/Core/Rendering/Renderer.cpp
	src/Cast/Core/Rendering/Renderer.h
	src/Cast/Core/Rendering/Texture.cpp
	src/Cast/Core/Rendering/Texture.h
	src/Cast/Core/Rendering/Window.cpp
	src/Cast/Core/Rendering/Window.h
	src/Cast/Core/Rendering/Shader/Shader.h
	src/Cast/Core/Rendering/Shader/ShaderParser.cpp
	src/Cast/Core/Rendering/Shader/ShaderParser.h
	src/Cast/Core/Rendering/Shader/ShaderProgram.h
	src/Cast/Core/Scenes/DebugScene.cpp
	src/Cast/Core/Scenes/DebugScene.h
	src/Cast/Core/Utils/Files/FileLoaderFactory.cpp
	src/Cast/Core/Utils/Files/FileLoaderFactory.h
	)


add_definitions(-D_DEBUG_MODE_ -DCAST_DEBUG_MODE)
target_compile_definitions(${LIBRARY_PROJECT_NAME} PUBLIC "CAST_ENGINE_NAME=${LIBRARY_PROJECT_NAME}")

target_include_directories("${LIBRARY_PROJECT_NAME}" PUBLIC "${DEPENDENCIES}/glfw/include")
target_include_directories("${LIBRARY_PROJECT_NAME}" PUBLIC "${DEPENDENCIES}/glad/include")
target_include_directories("${LIBRARY_PROJECT_NAME}" PUBLIC "${DEPENDENCIES}/fmt/include")
target_include_directories("${LIBRARY_PROJECT_NAME}" PUBLIC "${DEPENDENCIES}/glm")
target_include_directories("${LIBRARY_PROJECT_NAME}" PUBLIC "${DEPENDENCIES}/stbimage")
target_include_directories("${LIBRARY_PROJECT_NAME}" PUBLIC "${VULKAN_INCLUDE}")

target_include_directories("${LIBRARY_PROJECT_NAME}" PUBLIC "${ROOT}/${LIBRARY_PROJECT_NAME}/src/")#link the root

message("\n\n\n=======================\n${ROOT}/${LIBRARY_PROJECT_NAME}/src/")

target_link_directories("${LIBRARY_PROJECT_NAME}" PUBLIC "${VULKAN_LIB}")

target_link_libraries("${LIBRARY_PROJECT_NAME}" PRIVATE glad)
target_link_libraries("${LIBRARY_PROJECT_NAME}" PRIVATE glfw ${GLFW_LIBRARIES})
target_link_libraries("${LIBRARY_PROJECT_NAME}" PRIVATE fmt)
target_link_libraries("${LIBRARY_PROJECT_NAME}" PRIVATE vulkan-1)

