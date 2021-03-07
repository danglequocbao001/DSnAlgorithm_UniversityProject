#ifndef VARS
#define VARS

#include <stdlib.h>
#include <string.h>

#define FILENAME_MAX 125

#ifdef _WIN32 || _WIN64
    // set seperater
    #define SEPERATER "\\"
    // get current work direction
    #include <direct.h>
    #define _pwd _getcwd

#elif __linux__
    // set seperater
    #define SEPERATER "/"
    // get current work direction
    #include <unistd.h>
    #define _pwd getcwd
#endif


char* pwd(void) {
    char* path = (char*) malloc(FILENAME_MAX);
    _pwd(path, FILENAME_MAX);
    return path;
}

char* join_path(char* path1, char* path2) {
    char* result = (char*) malloc(strlen(path1) + strlen(path2) + 2);
    strcpy(result, path1);
    strcat(result, SEPERATER);
    strcat(result, path2);
    return result;
}

#endif /*VARS*/

