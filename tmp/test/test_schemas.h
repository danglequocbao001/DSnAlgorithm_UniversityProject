#ifndef TEST_SCHEMAS_H
#define TEST_SCHEMAS_H

#include "test_frame.h"
#include "../models/schemas/danhmucsach.h"
#include "../models/structures/linkedlist.h"
#include "../models/schemas/dausach.h"
#include "../models/schemas/docgia.h"
#include "../models/schemas/muontra.h"

void test_danhmucsach() {
    struct string_2d _a = {
        .array = (char**) malloc(POINTER_SIZE*3),
        .size = 3
    };
    _a.array[DM_code] = (char*)"125345234523423";
    _a.array[DM_status] = (char*)"125345234523423";
    _a.array[DM_position] = (char*)"125345234523423";

    struct DanhMucSachSchema dms = DanhMucSachInit(_a);
    free(_a.array);
    _a = DanhMucSachToArray(dms);

    for(int index = 0 ; index < _a.size; index ++) {
        printf("%d-%s\n", index, _a.array[index]);
    }
    free(_a.array);
}

void test_dausach() {
    struct string_2d _a = {
        .array = (char**) malloc(sizeof(char**)*6),
        .size = 6
    };
    _a.array[DS_ISBN] = (char*)"24123";
    _a.array[DS_name] = (char*)"24123";
    _a.array[DS_numberOfPages] = (char*)"24123";
    _a.array[DS_author] = (char*)"24123";
    _a.array[DS_publishingYear] = (char*)"24123";
    _a.array[DS_type] = (char*)"24123";

    struct DauSachSchema dms = DauSachInit(_a);
    free(_a.array);
    _a = DauSachToArray(dms);

    for(int index = 0 ; index < _a.size; index ++) {
        printf("%d-%s\n", index, _a.array[index]);
    }
    free(_a.array);
}


void test_docgia() {
    struct string_2d _a = {
        .array = (char**) malloc(sizeof(char**)*5),
        .size = 5
    };
    _a.array[DG_code] = (char*)"123";
    _a.array[DG_firstName] = (char*)"123";
    _a.array[DG_lastName] = (char*)"123";
    _a.array[DG_sex] = (char*)"0";
    _a.array[DG_status] = (char*)"24123";

    struct TheDocGiaSchema dms = TheDocGiaInit(_a);
    free(_a.array);
    _a = TheDocGiaToArray(dms);

    for(int index = 0 ; index < _a.size; index ++) {
        printf("%d-%s\n", index, _a.array[index]);
    }
    free(_a.array);
}

void test_muontra() {
    struct string_2d _a = {
        .array = (char**) malloc(sizeof(char**)*4),
        .size = 4
    };
    _a.array[MT_code] = (char*)"shjgwrt";
    _a.array[MT_borrowedDate] = (char*)"123123";
    _a.array[MT_returnedDate] = (char*)"4213412";
    _a.array[MT_status] = (char*)"4213412";

    struct MuonTraSchema dms = MuonTraInit(_a);
    free(_a.array);
    _a = MuonTraToArray(dms);

    for(int index = 0 ; index < _a.size; index ++) {
        printf("%d-%s\n", index, _a.array[index]);
    }
    free(_a.array);
}

void test_schemas() {
    test_danhmucsach();
    test_dausach();
    test_docgia();
    test_muontra();
}

#endif /*TEST_SCHEMAS_H*/
