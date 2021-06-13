#include "../libraries/utils.h"

void* processing_string(char* string) {
    printf("%s\n", compile_string(string));
    return 0;
}

int main() {
    list_dir((char*)".", processing_string);
    return 0;
}

