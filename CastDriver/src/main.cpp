#include <stdio.h>
#include <Cast/Core/Debug/LoggingHeaderOnly.h>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Debug/LoggingUserFormatter.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <string.h>
// #define debug(fmt, ...) printf("%s:%d: " fmt, __FILE__, __LINE__, __VA_ARGS__)
// #define TESTER1(...) printf(ANSI_COLOR_BOLD_GREEN "LOG::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_GREEN __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
// //#define TESTER2(...) printf(ANSI_COLOR_BOLD_GREEN "LOG::" __FILENAME__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_GREEN __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
// #define TESTER(...) fmt::print(fmt::emphasis::bold | fg(fmt::color::red), __VA_ARGS__)
// #define __CAST_DEBUG(...) Cast::Logger::Debug(__VA_ARGS__, __FILE__, __LINE__)
// #define __CAST_LOG(...) fmt::print(fmt::emphasis::bold | fg(fmt::color::mint_cream), "{}:" STR(__LINE__) " " __VA_ARGS__ "\n", __FILENAME__)
// #define TESTER2(...) printf(ANSI_COLOR_BOLD_GREEN "LOG::%s" ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_GREEN __VA_ARGS__, __FILENAME__); printf(ANSI_COLOR_RESET "\n")

int main(){
    CAST_LOG("glm::vec2 = {}\nglm::vec3 = {}\nglm::vec4 = {}\n", glm::vec2(1.2, 3.4), glm::vec3(1.2, 3.4, 5.6), glm::vec4(1.2, 3.4, 5.6, 7.8));
    //CAST_DEBUG("CAST_DEBUG");
    //CAST_ERROR("CAST_ERROR");
    //CAST_WARNING("CAST_WARNING");

}