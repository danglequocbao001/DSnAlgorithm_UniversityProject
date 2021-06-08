#include "test_frame.h"

void test_seperater() {
    #ifdef _WIN32
        assert(SEPERATER == "\\");
    #elif __linux__
        assert(SEPERATER == "/");
    #endif
}

int main() {
    test_seperater();
}
