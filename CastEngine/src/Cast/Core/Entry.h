#pragma once

#include <Cast/Core/EngineCore.h>

namespace Cast{

    class Entry{
        public:
            Entry() = default;
            int Run(int argc, char *argv[]);
    };
}