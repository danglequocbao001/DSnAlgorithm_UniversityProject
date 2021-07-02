#include "../libraries/utils.h"
#include "./test_frame.h"
/*#include "./test_model.h"*/
#include "./test_schemas.h"
#include "./test_structures.h"
#include "./test_utils.h"
#include "./test_vars.h"

int main() {
    // test_models();
    test_schemas();
    test_structures();
    test_utils();
    // test_vars();
    return 0;
}

