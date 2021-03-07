#ifndef VARS
#define VARS

#define FILENAME_MAX 125

#ifdef _WIN32 || _WIN64
    // set seperater
    #define SEPERATER "\\"
    // get current work direction
    #include <direct.h>
    #define pwd _getcwd

#elif __linux__
    // set seperater
    #define SEPERATER "/"
    // get current work direction
    #include <unistd.h>
    #define pwd getcwd
#endif


char* pwd(void) {
    char PATH[FILENAME_MAX];
}

#endif /*VARS*/
