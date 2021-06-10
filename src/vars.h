#ifndef VARS
#define VARS

#include <cstdint>
#include <dirent.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifdef _WIN32
    // set seperater
    #define SEPERATER "\\"
    // get current work direction
    #include <direct.h>
    #define _pwd _getcwd
    // compile code for dev-c of windows
    #define compile_string(path) "g++ " #path " -o abc && .\\abc && del abc"

#elif __linux__
    // set seperater
    #define SEPERATER "/"
    // get current work direction
    #include <unistd.h>
    #define _pwd getcwd
    // compile code for linux
    #define compile_string(path) "g++ " #path " -o abc && ./abc && rm abc"
#endif

#define STDIN stdin
#define STDOUT stdout

struct string_2d {
    char** array;
    int size;
};

#endif /*VARS*/

