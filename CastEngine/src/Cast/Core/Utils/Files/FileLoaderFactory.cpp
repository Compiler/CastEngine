#include "FileLoaderFactory.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
namespace Cast { namespace FileLoaderFactory{


    void loadTextFromFile(const char fileName[], std::string& dst){
        std::ifstream t(fileName);
        std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
        dst = str;
        if(dst.empty()){
            CAST_WARN("Couldn't open : '{}'", fileName);
        }
    }
	unsigned char* loadImage(const char name[], int* width, int* height, int* numOfColChannels, int req_comp) {
		stbi_set_flip_vertically_on_load(true);
		return stbi_load(name, width, height, numOfColChannels, req_comp);
	}
    std::vector<char> readSPV(const char* fileName){
        std::ifstream file(fileName, std::ios::ate | std::ios::binary);
        if(!file.is_open()){CAST_ERROR("Couldn't open file '{}'", fileName);}
        size_t fileSize = (size_t) file.tellg();
        std::vector<char> buffer(fileSize);
        file.seekg(0);
        file.read(buffer.data(), fileSize);
        file.close();

        return buffer;

    }

	void free(void* data) { stbi_image_free(data); }

}}