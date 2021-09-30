#include "VulkanContext.h"

namespace Cast{

    VulkanContext::VulkanContext(){
        m_window = new VulkanWindow(1920, 1080, "Cast Engine");
        _vulkanInstance.load(this->m_window->getWindowHandle());
    }

    void VulkanContext::clearColor(float r, float g, float b, float a){
    }
    void VulkanContext::clearDepthBit(){}
    void VulkanContext::clearColorBit(){}

}