#include "Entry.h"

namespace Cast{
    
    int Entry::Run(int argc, char *argv[]){
        


        CAST_DEBUG("Engine starting");
        Cast::EngineCore core_engine{};
        Cast::EngineCore::StartState startingState = Cast::EngineCore::StartState::Vulkan;
        if(argc != 0){
            if(*argv[0] == 0)startingState = Cast::EngineCore::StartState::OpenGL;
            if(*argv[0] == 1)startingState = Cast::EngineCore::StartState::Vulkan;
        }
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