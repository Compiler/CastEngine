#include "Entry.h"

namespace Cast{
    
    int Entry::Run(int argc, char *argv[]){
        


        CAST_DEBUG("Engine starting");
        Cast::EngineCore core_engine{};
        Cast::EngineCore::StartState startingState = Cast::EngineCore::StartState::Vulkan;
        CAST_LOG("{}", argc);
        CAST_LOG("{}", argv[1]);
        if(argc != 0){
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
            if(curTime - prevTime >= 1.0){
                CAST_LOG("{}", frameCount);
                frameCount = 0;
                prevTime = curTime;
            }
            core_engine.update();
            core_engine.render();
        }
        CAST_WARN("Closing engine");
        core_engine.unload();
        
        return 0;
    }

}