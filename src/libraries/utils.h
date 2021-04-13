#ifndef UTILS
#define UTILS

#include "../vars.h"

char* pwd(void);
char* join_path(char *, char *);
int is_regular_file(char *);
void list_dir(char *, void* (*)(char *));

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

int is_regular_file(char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

void list_dir(char *base_path, void* (*processing_string)(char *)) {
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(base_path);
    if (!dir) return;
    while ((dp = readdir(dir)) != NULL) {
        if ( strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            strcpy(path, base_path);
            strcat(path, "/");
            strcat(path, dp->d_name);
            if (is_regular_file(path)) processing_string(path);
            list_dir(path, processing_string);
        }
    }

    closedir(dir);
}

#endif /*UTILS*/

