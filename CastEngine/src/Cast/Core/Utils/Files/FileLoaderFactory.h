#pragma once
#include <string>
#include <fstream>
#include <streambuf>
#include <Cast/Core/Debug/Logger.h>
#include <vector>

#ifndef CAST_RESOURCES_ABSOLUTE_PATH
#define CAST_RESOURCES_ABSOLUTE_PATH "../"
CAST_FATAL("Absolute path is relative. Did CMAKE forget to add the include?");
#endif

#define CAST_INTERNAL(x)         CAST_RESOURCES_ABSOLUTE_PATH x
#define CAST_INTERNAL_SHADER(x)  CAST_INTERNAL("Shaders/") x
#define CAST_INTERNAL_TEXTURE(x) CAST_INTERNAL("Textures/") x
#define CAST_INTERNAL_FONTS(x) CAST_INTERNAL("Fonts/") x
#define CAST_INTERNAL_MODEL(x)   CAST_INTERNAL("Models/") x
#define CAST_INTERNAL_SOUNDS(x)  CAST_INTERNAL("Sounds/") x


namespace Cast {

    namespace FileLoaderFactory{
        extern void loadTextFromFile(const char fileName[], std::string& dst);
        extern std::vector<char> readSPV(const char* fileName);
        //rgba default composition
        extern unsigned char* loadImage(const char name[], int* width, int* height, int* numOfColChannels, int req_comp = 4/*STBI_rgb_alpha = 4*/);
        extern void free(void* data);

        extern bool file_exists(const std::string& name);
    }
}