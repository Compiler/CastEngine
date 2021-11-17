#include "Entry.h"

namespace Cast{
    
    int Entry::Run(int argc, char *argv[]){
        


        CAST_DEBUG("Engine starting");
        Cast::EngineCore core_engine{};
        Cast::EngineCore::StartState startingState = Cast::EngineCore::StartState::Vulkan;
        if(argc >= 2){
            if(strcmp(argv[1], "OpenGL") == 0)startingState = Cast::EngineCore::StartState::OpenGL;
            if(strcmp(argv[1], "Vulkan") == 0)startingState = Cast::EngineCore::StartState::Vulkan;
        }
        CAST_LOG("Starting state: {}", startingState);
        core_engine.load(startingState);
        double prevTime = glfwGetTime();
        int frameCount = 0;
        while(!core_engine.closeRequested()){
            double curTime = glfwGetTime();
            frameCount++;
            if(frameCount == 60 || curTime - prevTime >= 1.0){
                //CAST_LOG("{}", frameCount);
                //while(curTime - prevTime < 1.0) curTime = glfwGetTime();
                prevTime = curTime;
                std::stringstream ss;
                std::string api;
                switch(RenderContext::GetAPI()){
                    case RenderContext::API::OpenGL:{api = "OpenGL";break;};
                    case RenderContext::API::Vulkan:{api = "Vulkan";break;};
                    default: api = "NO_API";
                }
                ss << "[" << api << "] " << "Cast Engine : " << frameCount << " FPS";

                glfwSetWindowTitle(core_engine._renderContext->getWindow()->getWindowHandle(), ss.str().c_str());
                frameCount = 0;

            }

            core_engine.update();
            core_engine.render();
        }
        CAST_WARN("Closing engine");
        core_engine.unload();
        
        return 0;
    }

}