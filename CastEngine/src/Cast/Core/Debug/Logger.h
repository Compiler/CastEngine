#pragma once
#include <cassert>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/format.h>
#if __INTELLISENSE__
#pragma diag_suppress 2486
#endif    


/*
#include <fmt/format.h>

void vlog(const char* file, int line, fmt::string_view format,
          fmt::format_args args) {
  fmt::print("{}: {}: ", file, line);
  fmt::vprint(format, args);
}

template <typename S, typename... Args>
void log(const char* file, int line, const S& format, Args&&... args) {
  vlog(file, line, format,
      fmt::make_args_checked<Args...>(format, args...));
}

#define MY_LOG(format, ...) \
  log(__FILE__, __LINE__, FMT_STRING(format), __VA_ARGS__)

MY_LOG("invalid squishiness: {}", 42);
*/

namespace Cast{

    class Logger{
        //static void Debug(const char* fmt, )
    };

}