#include "Entry.h"

namespace Cast{
    
    int Entry::Run(){
        
        CAST_DEBUG("Engine starting");
        Cast::EngineCore core_engine{};
        core_engine.load();
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