#include "Entry.h"

namespace Cast{
    
    int Entry::Run(int argc, char *argv[]){
        


        CAST_DEBUG("Engine starting");
        Cast::EngineCore core_engine{};
        Cast::EngineCore::StartState startingState = Cast::EngineCore::StartState::OpenGL;
        if(argc >= 2){
            if(strcmp(argv[1], "OpenGL") == 0)startingState = Cast::EngineCore::StartState::OpenGL;
            if(strcmp(argv[1], "Vulkan") == 0)startingState = Cast::EngineCore::StartState::Vulkan;
        }
        CAST_LOG("Starting state: {}", startingState);
        core_engine.load(startingState);
        double prevTime = glfwGetTime();
        int frameCount = 0;
        double elapsed = 0;
        double loopTime = 0;
        while(!core_engine.closeRequested()){
            double curTime = glfwGetTime();
            frameCount++;
            if(curTime - prevTime >= 1.0){
                prevTime = curTime;
                std::stringstream ss;
                std::string api;
                switch(RenderContext::GetAPI()){
                    case RenderContext::API::OpenGL:{api = "OpenGL";break;};
                    case RenderContext::API::Vulkan:{api = "Vulkan";break;};
                    default: api = "NO_API";
                }
                ss << "[" << api << "] " << "Cast Engine : " << frameCount << " FPS, " << elapsed * 1000 << " ms";

                glfwSetWindowTitle(core_engine._renderContext->getWindow()->getWindowHandle(), ss.str().c_str());
                frameCount = 0;

            }
            loopTime = glfwGetTime();
            core_engine.update();
            core_engine.render();
            elapsed = glfwGetTime() - loopTime;
        }
        CAST_WARN("Closing engine");
        core_engine.unload();
        
        return 0;
    }

}