#include "GraphicsPipeline.h"

namespace Cast{


    GraphicsPipeline::GraphicsPipeline(VkDevice logicalDevice, const char* name, VulkanShaderProgram program){
        load(logicalDevice, name, program);
    }

    void GraphicsPipeline::load(VkDevice logicalDevice, const char* name, VulkanShaderProgram program){
        _name = name;
        _shaderProgram = program;

        // if(!_shaderProgram.isSet()){
        //     CAST_WARN("Loading default passthrough shaders");
        //     _shaderInfo = _shaderProgram.load(logicalDevice, CAST_INTERNAL_SHADER("passthrough_vert.spv"), CAST_INTERNAL_SHADER("passthrough_frag.spv"));
        //     _shaderStages[0] = _shaderInfo.vert_data;
        //     _shaderStages[1] = _shaderInfo.frag_data;
        // }else{
        //     _shaderInfo = _shaderProgram.getPipeLineShaderInfo();
        //     _shaderStages[0] = _shaderInfo.vert_data;
        //     _shaderStages[1] = _shaderInfo.frag_data;
        // }

        // auto bindingDescription = Vertex_Tmp::getBindingDescription();
        // auto attributeDescriptions = Vertex_Tmp::getAttributeDescriptions();

        // VkPipelineVertexInputStateCreateInfo vertexInputInfo{};
        // vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
        // vertexInputInfo.vertexBindingDescriptionCount = 1;
        // vertexInputInfo.vertexAttributeDescriptionCount = (uint32_t)(attributeDescriptions.size());
        // vertexInputInfo.pVertexBindingDescriptions = &bindingDescription; 
        // vertexInputInfo.pVertexAttributeDescriptions = attributeDescriptions.data(); 

        // VkPipelineInputAssemblyStateCreateInfo inputAssembly{};
        // inputAssembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
        // inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
        // inputAssembly.primitiveRestartEnable = VK_FALSE;

        // VkViewport viewport{};
        // viewport.x = 0.0f;
        // viewport.y = 0.0f;
        // viewport.width = (float) _swapChainExtent.width;
        // viewport.height = (float) _swapChainExtent.height;
        // viewport.minDepth = 0.0f;
        // viewport.maxDepth = 1.0f;

        // VkRect2D scissor{};
        // scissor.offset = {0, 0};
        // scissor.extent = _swapChainExtent;


        // VkPipelineViewportStateCreateInfo viewportState{};
        // viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
        // viewportState.viewportCount = 1;
        // viewportState.pViewports = &viewport;
        // viewportState.scissorCount = 1;
        // viewportState.pScissors = &scissor;

        // VkPipelineRasterizationStateCreateInfo rasterizer{};
        // rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
        // rasterizer.depthClampEnable = VK_FALSE;
        // rasterizer.rasterizerDiscardEnable = VK_FALSE;
        // rasterizer.polygonMode = VK_POLYGON_MODE_FILL;
        // rasterizer.lineWidth = 1.0f;

        // rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;
        // rasterizer.frontFace = VK_FRONT_FACE_CLOCKWISE;

        // rasterizer.depthBiasEnable = VK_FALSE;
        // rasterizer.depthBiasConstantFactor = 0.0f; // Optional
        // rasterizer.depthBiasClamp = 0.0f; // Optional
        // rasterizer.depthBiasSlopeFactor = 0.0f; // Optional

        // VkPipelineMultisampleStateCreateInfo multisampling{};
        // multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
        // multisampling.sampleShadingEnable = VK_FALSE;
        // multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
        // multisampling.minSampleShading = 1.0f; // Optional
        // multisampling.pSampleMask = nullptr; // Optional
        // multisampling.alphaToCoverageEnable = VK_FALSE; // Optional
        // multisampling.alphaToOneEnable = VK_FALSE; // Optional


        // VkPipelineColorBlendAttachmentState colorBlendAttachment{};
        // colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
        // colorBlendAttachment.blendEnable = VK_FALSE;
        // colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_ONE; // Optional
        // colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ZERO; // Optional
        // colorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD; // Optional
        // colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE; // Optional
        // colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO; // Optional
        // colorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD; // Optional

        // VkPipelineColorBlendStateCreateInfo colorBlending{};
        // colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
        // colorBlending.logicOpEnable = VK_FALSE;
        // colorBlending.logicOp = VK_LOGIC_OP_COPY; // Optional
        // colorBlending.attachmentCount = 1;
        // colorBlending.pAttachments = &colorBlendAttachment;
        // colorBlending.blendConstants[0] = 0.0f; // Optional
        // colorBlending.blendConstants[1] = 0.0f; // Optional
        // colorBlending.blendConstants[2] = 0.0f; // Optional
        // colorBlending.blendConstants[3] = 0.0f; // Optional


        // //for runtime pipeline features
        // VkDynamicState dynamicStates[] = {
        //     VK_DYNAMIC_STATE_VIEWPORT,
        //     VK_DYNAMIC_STATE_LINE_WIDTH
        // };

        // VkPipelineDynamicStateCreateInfo dynamicState{};
        // dynamicState.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
        // dynamicState.dynamicStateCount = 2;
        // dynamicState.pDynamicStates = dynamicStates;




        // VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
        // pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        // pipelineLayoutInfo.setLayoutCount = 0; // Optional
        // pipelineLayoutInfo.pSetLayouts = nullptr; // Optional
        // pipelineLayoutInfo.pushConstantRangeCount = 0; // Optional
        // pipelineLayoutInfo.pPushConstantRanges = nullptr; // Optional

        // if (vkCreatePipelineLayout(logicalDevice, &pipelineLayoutInfo, nullptr, &_pipelineLayout) != VK_SUCCESS) {
        //     CAST_ERROR("failed to create pipeline layout!");
        // }


        // VkGraphicsPipelineCreateInfo pipelineInfo{};
        // pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
        // pipelineInfo.stageCount = 2;
        // pipelineInfo.pStages = _shaderStages;
        // pipelineInfo.pVertexInputState = &vertexInputInfo;
        // pipelineInfo.pInputAssemblyState = &inputAssembly;
        // pipelineInfo.pViewportState = &viewportState;
        // pipelineInfo.pRasterizationState = &rasterizer;
        // pipelineInfo.pMultisampleState = &multisampling;
        // pipelineInfo.pDepthStencilState = nullptr; // Optional
        // pipelineInfo.pColorBlendState = &colorBlending;
        // pipelineInfo.pDynamicState = nullptr; // Optional
        // pipelineInfo.layout = _pipelineLayout;
        // pipelineInfo.renderPass = _renderPass;
        // pipelineInfo.subpass = 0;
        // pipelineInfo.basePipelineHandle = VK_NULL_HANDLE; // Optional
        // pipelineInfo.basePipelineIndex = -1; // Optional        

        // if (vkCreateGraphicsPipelines(logicalDevice, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &_graphicsPipeline) != VK_SUCCESS) {
        //     CAST_ERROR("failed to create graphics pipeline!");
        // }

        // vkDestroyShaderModule(logicalDevice, _shaderInfo.vert_module, nullptr);
        // vkDestroyShaderModule(logicalDevice, _shaderInfo.frag_module, nullptr);
    }


}