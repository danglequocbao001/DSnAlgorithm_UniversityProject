#include "test_frame.h"

void test_seperater() {
    #ifdef _WIN32 || _WIN64
        assert(SEPERATER == "\\");
    #elif __linux__
        assert(SEPERATER == "/");
    #endif
}

void test_pwd() {
    char* temp = pwd();
    assert(temp != "");
    free(temp);
}

void test_join_path() {
    char* temp = join_path((char*)"a", (char*)"b");
    assert(temp != "");
    free(temp);
}

int main() {
    test_pwd();
    test_join_path();
}

