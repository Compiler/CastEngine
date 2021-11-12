#ifndef VULKAN_INCLUDE_WRAPPER
#define VULKAN_INCLUDE_WRAPPER


#ifdef UNIX
    #if(UNIX == 1)
        #include <vulkan/vulkan.h>
    #else 
        #include <Vulkan/vulkan.h>
    #endif
#else
    #include <Vulkan/vulkan.h>
#endif


#endif