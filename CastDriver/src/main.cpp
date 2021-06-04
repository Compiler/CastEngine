#include <stdio.h>
#include <Cast/Core/Debug/Logging.h>
#define TESTER1(...) printf(ANSI_COLOR_BOLD_GREEN "LOG::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_GREEN __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
#define TESTER(...) fmt::print(fmt::emphasis::bold | fg(fmt::color::red), __VA_ARGS__)
int main(){
    std::string message = fmt::format("The answer is {}", 42);
    TESTER("The answer is {}", 42);

}