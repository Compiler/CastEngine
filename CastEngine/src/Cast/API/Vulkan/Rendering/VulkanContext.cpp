#include "VulkanContext.h"

namespace Cast{

    VulkanContext::VulkanContext(){
        _vulkanInstance = new VulkanInstance();
        m_window = new VulkanWindow(1920, 1080, "Cast Engine");
        CAST_DEBUG("Loading vulkan instance");
    }

    void VulkanContext::Load(){
        RenderContext::Load();
        _vulkanInstance->load(this->m_window->getWindowHandle());
       // LoadImGUI();
    }
    void VulkanContext::Update(){
        RenderContext::Update();
        this->m_window->update();
    }
    void VulkanContext::Render(){
        RenderContext::Render();
        this->m_window->render();
        _vulkanInstance->render();
        //RenderImGUI();
    }
    void VulkanContext::Unload(){
        RenderContext::Unload();
        this->m_window->destroy();
    }


    void VulkanContext::LoadImGUI(){
        IMGUI_CHECKVERSION();


        VkDescriptorPoolSize pool_sizes[] =
        {
            { VK_DESCRIPTOR_TYPE_SAMPLER, 1000 },
            { VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1000 },
            { VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, 1000 },
            { VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, 1000 },
            { VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER, 1000 },
            { VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER, 1000 },
            { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1000 },
            { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, 1000 },
            { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC, 1000 },
            { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC, 1000 },
            { VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, 1000 }
        };

        VkDescriptorPoolCreateInfo pool_info = {};
        pool_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
        pool_info.flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
        pool_info.maxSets = 1000;
        pool_info.poolSizeCount = std::size(pool_sizes);
        pool_info.pPoolSizes = pool_sizes;

        VkDescriptorPool imguiPool;
        vkCreateDescriptorPool(_vulkanInstance->_logicalDevice, &pool_info, nullptr, &imguiPool);

        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui::StyleColorsDark();

        //ImGui_ImplGlfw_InitForVulkan(m_window->getWindowHandle(), true);
        ImGui_ImplVulkan_InitInfo init_info;
        init_info.Instance = _vulkanInstance->_vulkanInstance;
        init_info.PhysicalDevice = _vulkanInstance->_physicalDevice;
        init_info.Device = _vulkanInstance->_logicalDevice;
        init_info.Queue = _vulkanInstance->_graphicsQueue;
        init_info.DescriptorPool = imguiPool;
        init_info.MinImageCount = 3;
        init_info.ImageCount = 3;
        init_info.MSAASamples = VK_SAMPLE_COUNT_1_BIT;

        ImGui_ImplVulkan_Init(&init_info, _vulkanInstance->_renderPass);





    }

    void VulkanContext::RenderImGUI(){
         // Our state
        bool show_demo_window = true;
        bool show_another_window = false;
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
        ImGui_ImplVulkan_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        ImGui::ShowDemoWindow(&show_demo_window);


        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }


        ImGui::Render();
       // ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData() );
    }

}