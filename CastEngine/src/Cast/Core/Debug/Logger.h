#pragma once
#include <cassert>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/format.h>
#if __INTELLISENSE__
#pragma diag_suppress 2486
#endif
#include<stdio.h>

#ifdef CAST_DEBUG_MODE
//#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
//#define __FILENAME__ strrchr("\\" __FILE__, '\\') + 1
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define ANSI_COLOR_RED          "\x1b[31m"
#define ANSI_COLOR_BOLD_RED     "\x1b[1;31m"
#define ANSI_COLOR_GREEN        "\x1b[32m"
#define ANSI_COLOR_BOLD_GREEN   "\x1b[1;32m"
#define ANSI_COLOR_YELLOW       "\x1b[33m"
#define ANSI_COLOR_BOLD_YELLOW  "\x1b[1;33m"
#define ANSI_COLOR_BLUE         "\x1b[34m"
#define ANSI_COLOR_BOLD_BLUE    "\x1b[1;34m"
#define ANSI_COLOR_MAGENTA      "\x1b[35m"
#define ANSI_COLOR_BOLD_MAGENTA "\x1b[1;35m"
#define ANSI_COLOR_CYAN         "\x1b[36m"
#define ANSI_COLOR_BOLD_CYAN    "\x1b[1;36m"
#define ANSI_COLOR_RESET        "\x1b[0m"

#define STR_FROM_INT(x) #x
#define STR(x) STR_FROM_INT(x)
#define test(...) printf(ANSI_COLOR_BOLD_RED "TEST::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_RED __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
#define PF_CAST_ERROR(...) printf(ANSI_COLOR_BOLD_RED "ERROR::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_RED __VA_ARGS__); printf(ANSI_COLOR_RESET "\n"); assert(false)
#define PF_CAST_NON_FATAL_ERROR(...) printf(ANSI_COLOR_BOLD_RED "ERROR::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_RED __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
#define PF_CAST_LOG(...) printf(ANSI_COLOR_BOLD_CYAN "LOG::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_CYAN __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
#define PF_CAST_DEBUG(...) printf(ANSI_COLOR_BOLD_GREEN "LOG::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_GREEN __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
#define PF_CAST_WARN(...) printf(ANSI_COLOR_BOLD_YELLOW "WARN::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_YELLOW __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
#define PF_CAST_INIT_LOG(...) printf(ANSI_COLOR_BOLD_BLUE "INIT::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_BLUE __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
#define PF_CAST_UNLOAD_LOG(...) printf(ANSI_COLOR_BOLD_MAGENTA "UNLOAD::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_MAGENTA __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")


/*  TODO
  - colored intermediate text
*/
inline void vlog(const fmt::text_style style, const char* file, int line, fmt::string_view format, fmt::format_args args) {
    auto thing = fmt::emphasis::bold | fg(fmt::color::lime_green);
    fmt::print(style, "{}:{} : ", file, line);
    fmt::vprint(format, args);
    fmt::print("\n");
}

inline void f_vlog(const fmt::text_style style, const char* file, int line, fmt::string_view format, fmt::format_args args) {
    auto thing = fmt::emphasis::bold | fg(fmt::color::lime_green);
    fmt::print(fmt::emphasis::italic | fg(fmt::color::indian_red), "!FATAL!\t");
    fmt::print(style, "{}:{} : ", file, line);
    fmt::vprint(format, args);
    fmt::print("\n");
}


template <typename S, typename... Args>
inline void log(const fmt::text_style style, const char* file, int line, const S& format, Args&&... args) {
  vlog(style, file, line, format, fmt::make_args_checked<Args...>(format, args...));
}

template <typename S, typename... Args>
inline void assert_log(bool exp, const char* file, int line, const S& format, Args&&... args) {
  f_vlog(fmt::emphasis::bold | fg(fmt::color::red), file, line, format, fmt::make_args_checked<Args...>(format, args...));
  assert(exp);
}


//#define FULL_PATHS
#define CAST_LOG(format, ...) log(fmt::emphasis::bold | fg(fmt::color::mint_cream), __FILENAME__, __LINE__, FMT_STRING(format)  __VA_OPT__(,) __VA_ARGS__)
#define CAST_DEBUG(format, ...) log(fmt::emphasis::bold | fg(fmt::color::lime_green), __FILENAME__, __LINE__, FMT_STRING(format)  __VA_OPT__(,) __VA_ARGS__)
#define CAST_WARN(format, ...) log(fmt::emphasis::bold | fg(fmt::color::yellow), __FILENAME__, __LINE__, FMT_STRING(format)  __VA_OPT__(,) __VA_ARGS__)
#define CAST_ERROR(format, ...) log(fmt::emphasis::bold | fg(fmt::color::red), __FILENAME__, __LINE__, FMT_STRING(format)  __VA_OPT__(,) __VA_ARGS__)
#define CAST_FATAL(format, ...) assert_log(false, __FILENAME__, __LINE__, FMT_STRING(format)  __VA_OPT__(,) __VA_ARGS__)
#define CAST_ASSERT(exp) assert(exp)


#define NA_CAST_LOG(...) fmt::print(fmt::emphasis::bold | fg(fmt::color::mint_cream), "{}:" STR(__LINE__) " " __VA_ARGS__ "\n", __FILENAME__)
#define NA_CAST_DEBUG(...) fmt::print(fmt::emphasis::bold | fg(fmt::color::lime_green), "{}:{}" __FILENAME__, STR(__LINE__), __VA_ARGS__)
#define NA_CAST_WARNING(...) fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow), "{}:" STR(__LINE__) " " __VA_ARGS__ "\n", __FILENAME__)
#define NA_CAST_ERROR(...) fmt::print(fmt::emphasis::bold | fg(fmt::color::red), "{}:" STR(__LINE__) " " __VA_ARGS__ "\n", __FILENAME__)
#define NA_CAST_DEBUG_NNL(...) fmt::print(fmt::emphasis::bold | fg(fmt::color::lime_green), "{}:" STR(__LINE__) " " __VA_ARGS__, __FILENAME__)
#define NA_CAST_LOG_NNL(...) fmt::print(fmt::emphasis::bold | fg(fmt::color::mint_cream), "{}:" STR(__LINE__) " " __VA_ARGS__, __FILENAME__)
#define NA_CAST_WARNING_NNL(...) fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow), "{}:" STR(__LINE__) " " __VA_ARGS__, __FILENAME__)
#define NA_CAST_ERROR_NNL(...) fmt::print(fmt::emphasis::bold | fg(fmt::color::red), "{}:" STR(__LINE__) " " __VA_ARGS__, __FILENAME__)

#else
#undef CAST_LOG
#define CAST_LOG(format, ...) 

#undef CAST_DEBUG
#define CAST_DEBUG(format, ...) 

#undef CAST_WARN
#define CAST_WARN(format, ...) 

#undef CAST_ERROR
#define CAST_ERROR(format, ...) 

#undef CAST_FATAL
#define CAST_FATAL(format, ...) 

#undef CAST_LOG
#define CAST_LOG(...) 

#undef CAST_DEBUG
#define CAST_DEBUG(...) 

#undef CAST_WARN
#define CAST_WARN(...) 

#undef CAST_ERROR
#define CAST_ERROR(...) 

#undef CAST_FATAL
#define CAST_FATAL(...) 

#undef CAST_ASSERT
#define CAST_ASSERT(...) 


#endif