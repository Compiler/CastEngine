#include <Cast/Core/Debug/LoggingHeaderOnly.h>
#include <Cast/Core/EngineCore.h>

int main(){
    CAST_DEBUG("Engine starting");
    Cast::EngineCore core_engine{};
    core_engine.load();
    while(!core_engine.closeRequested()){
        core_engine.update();
        core_engine.render();
    }
    CAST_WARN("Closing engine");
    core_engine.unload();

    return 0;


}