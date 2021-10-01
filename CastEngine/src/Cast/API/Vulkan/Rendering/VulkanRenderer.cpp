#include "VulkanRenderer.h"

namespace Cast{
    
    VulkanRenderer::VulkanRenderer(){

    }
    void VulkanRenderer::SubmitTriangle(glm::vec3 vertices[3], glm::vec3 color[3]){
        VulkanInstance::vertices.push_back({glm::vec4(vertices[0].x, vertices[0].y, vertices[0].z, 1.0), glm::vec4(color[0].x, color[0].y, color[0].z, 1.0) });
    }
    void VulkanRenderer::SubmitTriangle(float bottomLeftX, float bottomLeftY, float size){
        VulkanInstance::vertices.push_back({glm::vec4(bottomLeftX, bottomLeftY, 1, 1.0), glm::vec4(1,0,1,1) });
        VulkanInstance::vertices.push_back({glm::vec4(bottomLeftX + size, bottomLeftY, 1, 1.0), glm::vec4(1,0,1,1) });
        VulkanInstance::vertices.push_back({glm::vec4(bottomLeftX + size / 2.0, bottomLeftY + size, 1, 1.0), glm::vec4(1,0,1,1) });
    }
    void VulkanRenderer::Draw(){
        
        VulkanInstance::vertices.clear();
    }

}