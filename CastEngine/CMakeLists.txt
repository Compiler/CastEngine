set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
	CastEngine SHARED 
	src/Cast/API/GLFW/GLFWInputKeyStore.h
	src/Cast/API/Vulkan/VulkanIncludeWrapper.h
	src/Cast/API/Vulkan/Memory/VulkanBuffer.h
	src/Cast/API/Vulkan/Rendering/VulkanRenderer.h
	src/Cast/API/Vulkan/Rendering/VulkanWindow.cpp
	src/Cast/API/Vulkan/Rendering/VulkanShaderProgram.cpp
	src/Cast/API/Vulkan/Rendering/GraphicsPipeline.h
	src/Cast/API/Vulkan/Rendering/VulkanRenderer.cpp
	src/Cast/API/Vulkan/Rendering/VulkanInstance.h
	src/Cast/API/Vulkan/Rendering/GraphicsPipeline.cpp
	src/Cast/API/Vulkan/Rendering/VulkanShaderProgram.h
	src/Cast/API/Vulkan/Rendering/VulkanContext.cpp
	src/Cast/API/Vulkan/Rendering/VulkanContext.h
	src/Cast/API/Vulkan/Rendering/Vertex.h
	src/Cast/API/Vulkan/Rendering/VulkanWindow.h
	src/Cast/API/Vulkan/Rendering/VulkanInstance.cpp
	src/Cast/API/Vulkan/DebugUtils/VkDebugUtils.h
	src/Cast/API/Vulkan/DebugUtils/VkDebugUtils.cpp
	src/Cast/API/OpenGL/OpenGLWindow.cpp
	src/Cast/API/OpenGL/OpenGLCallbacks.cpp
	src/Cast/API/OpenGL/OpenGLCallbacks.h
	src/Cast/API/OpenGL/OpenGLWindow.h
	src/Cast/API/OpenGL/Rendering/OpenGLTexture.h
	src/Cast/API/OpenGL/Rendering/OpenGLRenderer.h
	src/Cast/API/OpenGL/Rendering/OpenGLContext.cpp
	src/Cast/API/OpenGL/Rendering/OpenGLTexture.cpp
	src/Cast/API/OpenGL/Rendering/OpenGLRenderer.cpp
	src/Cast/API/OpenGL/Rendering/OpenGLContext.h
	src/Cast/API/OpenGL/Rendering/OpenGLVertexArray.h
	src/Cast/API/OpenGL/Rendering/OpenGLVertexBuffer.h
	src/Cast/API/OpenGL/Rendering/OpenGLVertexBuffer.cpp
	src/Cast/API/OpenGL/Rendering/OpenGLVertexArray.cpp
	src/Cast/API/OpenGL/Rendering/Shading/OpenGLShaderProgram.h
	src/Cast/API/OpenGL/Rendering/Shading/OpenGLShaderProgram.cpp
	src/Cast/Core/Entry.cpp
	src/Cast/Core/EngineCore.cpp
	src/Cast/Core/EngineCore.h
	src/Cast/Core/Entry.h
	src/Cast/Core/ECS/Components/Components.h
	src/Cast/Core/Input/InputManager.h
	src/Cast/Core/Input/InputManager.cpp
	src/Cast/Core/Debug/LoggingUserFormatter.h
	src/Cast/Core/Debug/Logger.h
	src/Cast/Core/Utils/MathUtils.h
	src/Cast/Core/Utils/Files/FileLoaderFactory.cpp
	src/Cast/Core/Utils/Files/FileLoaderFactory.h
	src/Cast/Core/Scenes/DebugScene.cpp
	src/Cast/Core/Scenes/StressTestScene.h
	src/Cast/Core/Scenes/StressTestScene.cpp
	src/Cast/Core/Scenes/DebugScene.h
	src/Cast/Core/Rendering/WindowCallbacks.h
	src/Cast/Core/Rendering/Window.h
	src/Cast/Core/Rendering/PerspectiveCamera.h
	src/Cast/Core/Rendering/RenderContext.cpp
	src/Cast/Core/Rendering/Window.cpp
	src/Cast/Core/Rendering/Camera.h
	src/Cast/Core/Rendering/Renderer.cpp
	src/Cast/Core/Rendering/Texture.h
	src/Cast/Core/Rendering/PerspectiveCamera.cpp
	src/Cast/Core/Rendering/RenderContext.h
	src/Cast/Core/Rendering/Renderer.h
	src/Cast/Core/Rendering/WindowCallbacks.cpp
	src/Cast/Core/Rendering/Texture.cpp
	src/Cast/Core/Rendering/Shader/Shader.h
	src/Cast/Core/Rendering/Shader/ShaderParser.h
	src/Cast/Core/Rendering/Shader/ShaderProgram.h
	src/Cast/Core/Rendering/Shader/ShaderParser.cpp
	src/Cast/Core/Rendering/Shader/UniformBufferObject.h
	src/Cast/Core/Rendering/Shapes/Cube.cpp
	src/Cast/Core/Rendering/Shapes/Cube.h
	src/Cast/Core/Rendering/Shapes/Shape.h
	src/Cast/Core/GUI/MainGUi.h
	src/Cast/Vendor/entt/fwd.hpp
	src/Cast/Vendor/entt/entt.hpp
	src/Cast/Vendor/entt/process/process.hpp
	src/Cast/Vendor/entt/process/scheduler.hpp
	src/Cast/Vendor/entt/container/dense_hash_set.hpp
	src/Cast/Vendor/entt/container/fwd.hpp
	src/Cast/Vendor/entt/container/dense_hash_map.hpp
	src/Cast/Vendor/entt/poly/fwd.hpp
	src/Cast/Vendor/entt/poly/poly.hpp
	src/Cast/Vendor/entt/signal/dispatcher.hpp
	src/Cast/Vendor/entt/signal/fwd.hpp
	src/Cast/Vendor/entt/signal/delegate.hpp
	src/Cast/Vendor/entt/signal/sigh.hpp
	src/Cast/Vendor/entt/signal/emitter.hpp
	src/Cast/Vendor/entt/locator/locator.hpp
	src/Cast/Vendor/entt/platform/android-ndk-r17.hpp
	src/Cast/Vendor/entt/meta/utility.hpp
	src/Cast/Vendor/entt/meta/policy.hpp
	src/Cast/Vendor/entt/meta/factory.hpp
	src/Cast/Vendor/entt/meta/resolve.hpp
	src/Cast/Vendor/entt/meta/fwd.hpp
	src/Cast/Vendor/entt/meta/container.hpp
	src/Cast/Vendor/entt/meta/ctx.hpp
	src/Cast/Vendor/entt/meta/range.hpp
	src/Cast/Vendor/entt/meta/pointer.hpp
	src/Cast/Vendor/entt/meta/meta.hpp
	src/Cast/Vendor/entt/meta/type_traits.hpp
	src/Cast/Vendor/entt/meta/template.hpp
	src/Cast/Vendor/entt/meta/adl_pointer.hpp
	src/Cast/Vendor/entt/meta/node.hpp
	src/Cast/Vendor/entt/config/config.h
	src/Cast/Vendor/entt/config/version.h
	src/Cast/Vendor/entt/entity/utility.hpp
	src/Cast/Vendor/entt/entity/helper.hpp
	src/Cast/Vendor/entt/entity/observer.hpp
	src/Cast/Vendor/entt/entity/storage.hpp
	src/Cast/Vendor/entt/entity/fwd.hpp
	src/Cast/Vendor/entt/entity/poly_storage.hpp
	src/Cast/Vendor/entt/entity/view.hpp
	src/Cast/Vendor/entt/entity/component.hpp
	src/Cast/Vendor/entt/entity/handle.hpp
	src/Cast/Vendor/entt/entity/organizer.hpp
	src/Cast/Vendor/entt/entity/group.hpp
	src/Cast/Vendor/entt/entity/snapshot.hpp
	src/Cast/Vendor/entt/entity/registry.hpp
	src/Cast/Vendor/entt/entity/runtime_view.hpp
	src/Cast/Vendor/entt/entity/entity.hpp
	src/Cast/Vendor/entt/entity/sparse_set.hpp
	src/Cast/Vendor/entt/core/utility.hpp
	src/Cast/Vendor/entt/core/monostate.hpp
	src/Cast/Vendor/entt/core/hashed_string.hpp
	src/Cast/Vendor/entt/core/any.hpp
	src/Cast/Vendor/entt/core/ident.hpp
	src/Cast/Vendor/entt/core/fwd.hpp
	src/Cast/Vendor/entt/core/algorithm.hpp
	src/Cast/Vendor/entt/core/enum.hpp
	src/Cast/Vendor/entt/core/type_traits.hpp
	src/Cast/Vendor/entt/core/iterator.hpp
	src/Cast/Vendor/entt/core/family.hpp
	src/Cast/Vendor/entt/core/memory.hpp
	src/Cast/Vendor/entt/core/compressed_pair.hpp
	src/Cast/Vendor/entt/core/tuple.hpp
	src/Cast/Vendor/entt/core/type_info.hpp
	src/Cast/Vendor/entt/core/attribute.h
	src/Cast/Vendor/entt/resource/cache.hpp
	src/Cast/Vendor/entt/resource/fwd.hpp
	src/Cast/Vendor/entt/resource/handle.hpp
	src/Cast/Vendor/entt/resource/loader.hpp
	src/Cast/Vendor/ImGui/imgui_demo.cpp
	src/Cast/Vendor/ImGui/imgui_impl_opengl3.cpp
	src/Cast/Vendor/ImGui/imgui_widgets.cpp
	src/Cast/Vendor/ImGui/imgui_draw.cpp
	src/Cast/Vendor/ImGui/imstb_rectpack.h
	src/Cast/Vendor/ImGui/imgui_impl_glfw.h
	src/Cast/Vendor/ImGui/imstb_textedit.h
	src/Cast/Vendor/ImGui/imstb_truetype.h
	src/Cast/Vendor/ImGui/imgui_impl_vulkan.cpp
	src/Cast/Vendor/ImGui/imconfig.h
	src/Cast/Vendor/ImGui/imgui_impl_opengl3.h
	src/Cast/Vendor/ImGui/imgui_impl_glfw.cpp
	src/Cast/Vendor/ImGui/imgui.cpp
	src/Cast/Vendor/ImGui/imgui.h
	src/Cast/Vendor/ImGui/imgui_impl_vulkan.h
	src/Cast/Vendor/ImGui/imgui_tables.cpp
	src/Cast/Vendor/ImGui/imgui_internal.h
	src/Cast/Vendor/ImGui/imgui_impl_opengl3_loader.h
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

#delete this?
find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )
target_link_libraries("${LIBRARY_PROJECT_NAME}" PRIVATE ${OPENGL_LIBRARIES})
####



find_package(Vulkan REQUIRED FATAL_ERROR)
message("DKLFSJD : ${Vulkan_INCLUDE_DIRS}")

get_filename_component(VULKAN_LIBRARY_PATH ${Vulkan_LIBRARIES} DIRECTORY)

target_include_directories("${LIBRARY_PROJECT_NAME}" PUBLIC ${VULKAN_INCLUDE})
target_link_directories("${LIBRARY_PROJECT_NAME}" PRIVATE ${VULKAN_LIB})
target_link_libraries("${LIBRARY_PROJECT_NAME}" PRIVATE ${VULKAN_LIB_NAME} shaderc_shared SPIRV-Tools-shared)


