#pragma once
#include <string>
#include <fstream>
#include <streambuf>
#include <Cast/Core/Debug/Logger.h>
#define CAST_INTERNAL(x)         "../CastEngine/src/Resources/" x
#define CAST_INTERNAL_SHADER(x)  CAST_INTERNAL("Shaders/") x
#define CAST_INTERNAL_TEXTURE(x) CAST_INTERNAL("Textures/") x
#define CAST_INTERNAL_MODEL(x)   CAST_INTERNAL("Models/") x
#define CAST_INTERNAL_SOUNDS(x)  CAST_INTERNAL("Sounds/") x


namespace Cast {

    namespace FileLoaderFactory{
        extern void loadTextFromFile(const char fileName[], std::string& dst);
        //rgba default composition
        extern unsigned char* loadImage(const char name[], int* width, int* height, int* numOfColChannels, int req_comp = 4/*STBI_rgb_alpha = 4*/);
        extern void free(void* data);
    }
}