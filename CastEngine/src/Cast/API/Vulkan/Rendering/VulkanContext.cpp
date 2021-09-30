#include "VulkanContext.h"

namespace Cast{

    VulkanContext::VulkanContext(){
        m_window = new VulkanWindow(1920, 1080, "Cast Engine");
        CAST_DEBUG("Loading vulkan instance");
    }

    void VulkanContext::Load(){
        RenderContext::Load();
        _vulkanInstance.load(this->m_window->getWindowHandle());
    }
    void VulkanContext::Update(){
        RenderContext::Update();
        this->m_window->update();
    }
    void VulkanContext::Render(){
        RenderContext::Render();
        this->m_window->render();
        _vulkanInstance.render();
    }
    void VulkanContext::Unload(){
        RenderContext::Unload();
        this->m_window->destroy();
    }

    void VulkanContext::clearColor(float r, float g, float b, float a){
    }
    void VulkanContext::clearDepthBit(){}
    void VulkanContext::clearColorBit(){}

}