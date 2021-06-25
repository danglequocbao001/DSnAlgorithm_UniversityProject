#include "test_frame.h"

void test_seperater() {
    #ifdef _WIN32
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

void test_numer_to_string() {
    assert(strcmp("123", numer_to_string(123)) == 0);
}

void test_stoi() {
    assert(stoi((char*)"12312142") == 12312142);
}

int main() {
    test_pwd();
    test_join_path();
    test_numer_to_string();
    test_stoi();
}

