#ifndef UTILS
#define UTILS

#include "../vars.h"

char* pwd(void);
char* join_path(char *, char *);
int is_regular_file(char *);
void list_dir(char *, void* (*)(char *));
char* numer_to_string(int);
int stoi(char*);


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

char* numer_to_string(int number) {
    int size = 0;
    if (number > 0) {
        size = (int)log10(number+0.000001)+1;
    } else {
        size = abs(number) + 1;
        size = (int)log10(size)+1;
    }
    char* buffer = (char*)malloc(sizeof(char*) * size);
    snprintf(buffer, sizeof(buffer), "%d", number);
    return buffer;
}

int stoi(char *str) {
    int result = 0;
    int puiss = 1;

    while (('-' == (*str)) || ((*str) == '+')) {
        if (*str == '-')
            puiss = puiss * -1;
        str++;
    }
    while ((*str >= '0') && (*str <= '9')) {
        result = (result * 10) + ((*str) - '0');
        str++;
    }
    return (result * puiss);
}

void readline_file() {
    FILE *file = fopen("/tmp/abc", "r");
    char line[1000]; int index = 0;
    while((line[index++] = (char)getc(file)) != EOF) {
        if (line[index - 1] == '\n') {
            line[index - 1] = 0;
            memset(line, 0, index - 1);
            index = 0;
        }
    }
    fclose(file);
}

void writeline_file() {
    FILE *file = fopen("/tmp/ccc", "w");
    for (int index = 0; index < 10; index++ ) {
        fprintf(file, "abc\n");
    }
    fclose(file);
}


#endif /*UTILS*/

