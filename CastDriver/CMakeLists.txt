set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CastDriver src/main.cpp)
set_target_properties(CastDriver PROPERTIES OUTPUT_NAME "${EXE_FINAL_NAME}")
target_link_libraries(CastDriver PRIVATE "${LIBRARY_PROJECT_NAME}")