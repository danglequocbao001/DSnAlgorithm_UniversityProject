#include "test_frame.h"
#include "../models/schemas/danhmucsach.h"
#include "../models/structures/linkedlist.h"
#include "../models/schemas/dausach.h"
#include "../models/schemas/docgia.h"
#include "../models/schemas/muontra.h"

void test_danhmucsach() {
    DanhMucSachSchema a = {
        .code = (char*)"123",
        .status = BORROWED,
        .position = 0,
    };
    dm_stringToCode(dm_codeToString(a.code));
    dm_stringToStatus(dm_statusToString(a.status));
    dm_stringToPosition(dm_positionToString(a.position));

    struct string_2d _a = {
        .array = (char**) malloc(POINTER_SIZE*3),
        .size = 3
    };
    _a.array[DM_code] = (char*)"123";
    _a.array[DM_status] = (char*)"24123";
    _a.array[DM_position] = 0;

    struct DanhMucSachSchema dms = DanhMucSachInit(_a);
    _a = DanhMucSachToArray(dms);
}

void test_dausach() {
    DauSachSchema a = {
        .ISBN = (char*)"kasghwer",
        .name = (char*)"kergwlerg",
        .numberOfPages = 123,
        .author = (char*)"wkjgwrt",
        .publishingYear = 1213423,
        .type = (char*)"sjgkw4g",
        .DanhMucSach = NULL,
    };
    ds_stringToISBN(ds_ISBNToString(a.ISBN));
    ds_stringToName(ds_nameToString(a.name));
    ds_stringToNumberOfPages(ds_numberOfPagesToString(a.numberOfPages));
    ds_stringToAuthor(ds_authorToString(a.author));
    ds_stringToPublishingYear(ds_publishingYearToString(a.publishingYear));
    ds_stringToType(ds_typeToString(a.type));

    struct string_2d _a = {
        .array = (char**) malloc(POINTER_SIZE*6),
        .size = 6
    };
    _a.array[DS_ISBN] = (char*)"24123";
    _a.array[DS_name] = (char*)"24123";
    _a.array[DS_numberOfPages] = (char*)"24123";
    _a.array[DS_author] = (char*)"24123";
    _a.array[DS_publishingYear] = (char*)"24123";
    _a.array[DS_type] = (char*)"24123";

    struct DauSachSchema dms = DauSachInit(_a);
    _a = DauSachToArray(dms);
}


void test_docgia() {
    TheDocGiaSchema a = {
        .code = 1,
        .firstName = (char*)"",
        .lastName = (char*)"",
        .sex = MALE,
        .status = ACTIVE,
    };
    dg_stringToCode(dg_codeToString(a.code));
    dg_stringToFirstName(dg_firstNameToString(a.firstName));
    dg_stringToLastName(dg_lastNameToString(a.lastName));
    dg_stringToSex(dg_sexToString(a.sex));
    dg_stringToStatus(dg_statusToString(a.status));

    struct string_2d _a = {
        .array = (char**) malloc(POINTER_SIZE*5),
        .size = 5
    };
    _a.array[DG_code] = (char*)"123";
    _a.array[DG_firstName] = (char*)"123";
    _a.array[DG_lastName] = (char*)"123";
    _a.array[DG_sex] = (char*)"0";
    _a.array[DG_status] = (char*)"24123";

    struct TheDocGiaSchema dms = TheDocGiaInit(_a);
    _a = TheDocGiaToArray(dms);
}

void test_muontra() {
    MuonTraSchema a = {
        .code = (char*)"shjgwrt",
        .borrowedDate = 123123,
        .returnedDate = 4213412,
        .status = LOST,
    };
    mt_stringToCode(mt_codeToString(a.code));
    mt_stringToBorrowedDate(mt_borrowedDateToString(a.borrowedDate));
    mt_stringToReturnedDate(mt_returnedDateToString(a.returnedDate));
    mt_stringToStatus(mt_statusToString(a.status));

    struct string_2d _a = {
        .array = (char**) malloc(POINTER_SIZE*4),
        .size = 4
    };
    _a.array[MT_code] = (char*)"shjgwrt";
    _a.array[MT_borrowedDate] = (char*)"123123";
    _a.array[MT_returnedDate] = (char*)"4213412";
    _a.array[MT_status] = 0;

    struct MuonTraSchema dms = MuonTraInit(_a);
    _a = MuonTraToArray(dms);
}

int main() {
    // test_danhmucsach();
    // test_dausach();
    // test_docgia();
    // test_muontra();
}
