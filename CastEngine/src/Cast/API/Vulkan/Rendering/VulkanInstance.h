#pragma once
#define GLFW_INCLUDE_VULKAN
#include <Cast/API/Vulkan/VulkanIncludeWrapper.h>
#include <glm/glm.hpp>
#include <Cast/Core/Utils/Files/FileLoaderFactory.h>
#include <Cast/API/Vulkan/DebugUtils/VkDebugUtils.h>
#include <Cast/API/Vulkan/Rendering/VulkanShaderProgram.h>
#include <Cast/API/Vulkan/Rendering/GraphicsPipeline.h>
#include <Cast/API/Vulkan/Memory/VulkanBuffer.h>

#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
#include <unordered_map>


#include <Cast/Core/Rendering/Shader/UniformBufferObject.h>
#include <Cast/Core/Rendering/Camera.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <chrono>


#ifdef CAST_DEBUG_MODE
const bool enableValidationLayers = true;
#else
const bool enableValidationLayers = false;
#endif

#include <Cast/Core/Rendering/Window.h>

#define DEBUG_FUNC(x) CAST_LOG("----\tStarting {}", #x); x; CAST_LOG("----\tEnding {}", #x)
namespace Cast{

    class GraphicsPipeline;

    struct Vertex_Tmp{  
        glm::vec4 position;
        glm::vec4 color;

        static VkVertexInputBindingDescription getBindingDescription(){
            VkVertexInputBindingDescription bindingInfo{};

            bindingInfo.binding = 0;
            bindingInfo.stride = sizeof(Vertex_Tmp);
            bindingInfo.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

            return bindingInfo;

        }


        static std::array<VkVertexInputAttributeDescription, 2> getAttributeDescriptions() {
            std::array<VkVertexInputAttributeDescription, 2> attributeDescriptions{};

            attributeDescriptions[0].binding = 0;
            attributeDescriptions[0].location = 0;
            attributeDescriptions[0].format = VK_FORMAT_R32G32B32A32_SFLOAT;
            attributeDescriptions[0].offset = offsetof(Vertex_Tmp, position);//((::size_t)&reinterpret_cast<char const volatile&>((((Vertex_Tmp*)0)->position)));

            attributeDescriptions[1].binding = 0;
            attributeDescriptions[1].location = 1;
            attributeDescriptions[1].format = VK_FORMAT_R32G32B32A32_SFLOAT;
            attributeDescriptions[1].offset = offsetof(Vertex_Tmp, color);//((::size_t)&reinterpret_cast<char const volatile&>((((Vertex_Tmp*)0)->color)));

            return attributeDescriptions;
        }

    };



    
    struct OptionalPair{
        uint32_t index;
        bool set = false;
    };
    struct QueueFamilyIndices {
        OptionalPair graphicsFamily;
        OptionalPair presentationFamily;
        
        bool isComplete() {
            return graphicsFamily.set && presentationFamily.set;
        }
    };

    struct SwapChainSupportDetails {
        VkSurfaceCapabilitiesKHR capabilities;
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> presentModes;
    };

    class VulkanInstance{
        friend class VulkanRenderer;
        private:

            VulkanShaderProgram _shaderProgram;
            VkInstance _vulkanInstance;
            VkPhysicalDevice _physicalDevice;
            VkDevice _logicalDevice;
            VkQueue _graphicsQueue, _presentationQueue;
            VkSurfaceKHR _surface;
            VkDebugUtilsMessengerEXT _debugMessenger;
            VkSwapchainKHR _swapChain;
            std::vector<VkImage> _swapChainImages;
            std::vector<VkImageView> _swapChainImageViews;
            VkFormat _swapChainImageFormat;
            VkExtent2D _swapChainExtent;
            VkPipelineLayout _pipelineLayout;
            VkRenderPass _renderPass;
            Cast::GraphicsPipeline* _pipeline;
            std::vector<VkFramebuffer> _swapChainFramebuffers;
            VkCommandPool _graphicsCommandPool;
            VulkanBuffer vertexBuffer;
            std::vector<VulkanBuffer> uboBuffers;
            VkDescriptorPool _descriptorPool;
            std::vector<VkDescriptorSet> _descriptorSets;


            inline void _createInstance(const char* appName, const char* engineName);
            inline void _createDebugMessenger();
            inline bool _validatationLayersAssert();
            inline void _setPhysicalDevice();
            inline bool _isRTXEnabledGPU(VkPhysicalDevice);
            inline void _createLogicalDevice();
            inline void _createSurface();
            inline bool _deviceSupportsExtensions(VkPhysicalDevice device);
            inline void _createSwapChain();
            inline void _createImageViews();
            inline void _createRenderPass();
            inline void _createGraphicsPipeline();
            inline void _createFrameBuffers();
            inline void _createGraphicsCommandPool();
            inline void _createGraphicsCommandBuffers();
            inline void _createSyncObjects();
            inline void _cleanupSwapChain();
            inline void _createVertexBuffers();
            inline void _createUniformBuffers();
            inline void _createDescriptorPool();
            inline void _createDescriptorSets();
            inline void _updateUniformBuffer(uint32_t currentImage);

            const int _MAX_FRAMES_IN_FLIGHT = 2;
            size_t _currentFrame = 0;
            std::vector<VkSemaphore> _s_imagesAvailable;
            std::vector<VkSemaphore> _s_rendersFinished;
            std::vector<VkFence> _f_inFlightFences;
            std::vector<VkFence> _f_imagesInFlight;



            VkShaderModule _createShaderModule(const std::vector<char>& code);
            SwapChainSupportDetails _querySwapChainSupport(VkPhysicalDevice device);
            VkSurfaceFormatKHR _chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
            VkPresentModeKHR _chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
            VkExtent2D _chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

            QueueFamilyIndices _getQueueFamilies(VkPhysicalDevice);

            std::vector<VkCommandBuffer> _graphicsCommandBuffers;
            const std::vector<const char*> _validationLayers = {
                "VK_LAYER_KHRONOS_validation"
            };

            const std::vector<const char*> _deviceExtensions = {
                VK_KHR_SWAPCHAIN_EXTENSION_NAME,
               // VK_NV_RAY_TRACING_EXTENSION_NAME,
                //VK_KHR_ACCELERATION_STRUCTURE_EXTENSION_NAME, 
                //VK_KHR_RAY_TRACING_PIPELINE_EXTENSION_NAME, 
                //VK_KHR_MAINTENANCE3_EXTENSION_NAME,
                //VK_KHR_PIPELINE_LIBRARY_EXTENSION_NAME, 
                //VK_KHR_DEFERRED_HOST_OPERATIONS_EXTENSION_NAME, 
                //VK_KHR_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME
            };
            const std::vector<const char*> _instanceExtensions = {
                //VK_KHR_RAY_TRACING_PIPELINE_EXTENSION_NAME

            };



            VkClearValue _clearColor = {255.0f / 255.0f, 105.0f / 255.0f, 180.0f / 255.0f, 1.0f};
            GLFWwindow* _windowRef;


        public:
            inline static float sz = 0.95;
            static std::vector<Vertex_Tmp> vertices;

            void load(GLFWwindow* window, VulkanShaderProgram shader = {});

            void render();

            void unload();

            void recreateSwapChain();

            GraphicsPipeline createDefaultPipeline();
        private:
            std::vector<const char*> getRequiredExtensions() {
                uint32_t glfwExtensionCount = 0;
                const char** glfwExtensions;
                glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

                std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

                if (enableValidationLayers) {
                    CAST_LOG("Added debug tools ");
                    extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
                }

                return extensions;
        }


            static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
                if(messageSeverity == VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) {
                    CAST_WARN("validation layer: {}", pCallbackData->pMessage);
                }
                if(messageSeverity > VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) {
                    CAST_ERROR("validation layer: {}", pCallbackData->pMessage);
                }
                return VK_FALSE;
            }

            void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo) {
                createInfo = {};
                createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
                createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
                createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
                createInfo.pfnUserCallback = debugCallback;
            }

            VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
                auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
                if (func != nullptr) {
                    return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
                } else {
                    return VK_ERROR_EXTENSION_NOT_PRESENT;
                }
            }

            void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
                auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
                if (func != nullptr) {
                    func(instance, debugMessenger, pAllocator);
                }
            }

            

        };


}