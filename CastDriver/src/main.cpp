#include <Cast/Core/Debug/LoggingHeaderOnly.h>
#include <Cast/Core/EngineCore.h>

int main(){
    CAST_DEBUG("Engine starting");
    Cast::EngineCore core_engine{};
    core_engine.init();
    while(!core_engine.closeRequested()){
        core_engine.update();
        core_engine.render();
    }
    CAST_WARN("Closing engine");
    core_engine.destroy();

    return 0;


}