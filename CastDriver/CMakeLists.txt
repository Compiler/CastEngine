set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(CastDriver src/main.cpp)
target_link_libraries(CastDriver PRIVATE CastEngine)
