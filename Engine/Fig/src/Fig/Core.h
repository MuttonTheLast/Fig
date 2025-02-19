#ifdef PLATFORM_WINDOWS
    #ifdef FIG_BUILD_SHARED_LIB
        #define FIG_API __declspec(dllexport)
    #else
        #define FIG_API __declspec(dllimport)
    #endif // FIG_BUILD_SHARED_LIB
#else // Non-Windows platforms
    #ifdef FIG_BUILD_SHARED_LIB
        #define FIG_API __attribute__((visibility("default")))
    #else
        #define FIG_API
    #endif // FIG_BUILD_SHARED_LIB
#endif // PLATFORM_WINDOWS

#define BIT(x) (1 << x)


#if defined(PLATFORM_WINDOWS) || defined(PLATFORM_LINUX) || defined(PLATFORM_MACOS)
#define SDL_SUPPORTED
#define KEY_CHAR(key) (key+32)
#else
#define KEY_CHAR(key) (key)
#endif 
