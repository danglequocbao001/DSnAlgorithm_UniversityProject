#include "test_frame.h"
#include "../models/schemas/danhmucsach.h"
#include "../models/schemas/dausach.h"
#include "../models/schemas/docgia.h"
#include "../models/schemas/muontra.h"

void test_danhmucsach() {
    DanhMucSachSchema a = {
        .code = (char*)"123",
        .status = BORROWED,
        .position = 0,
    };
    printf("%s\n", codeToString(a.code));
    printf("%s\n", statusToString(a.status));
    printf("%s\n", positionToString(a.position));
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
    ISBNToString(a.ISBN);
    nameToString(a.name);
    numberOfPagesToString(a.numberOfPages);
    authorToString(a.author);
    publishingYearToString(a.publishingYear);
    typeToString(a.type);
}


void test_docgia() {
    TheDocGiaSchema a = {
        .code = 1,
        .firstName = (char*)"",
        .lastName = (char*)"",
        .sex = MALE,
        .status = ACTIVE,
    };
    codeToString(a.code);
    firstNameToString(a.firstName);
    lastNameToString(a.lastName);
    sexToString(a.sex);
    dg_statusToString(a.status);
}

void test_muontra() {
    MuonTraSchema a = {
        .code = (char*)"shjgwrt",
        .borrowedDate = 123123,
        .returnedDate = 4213412,
        .status = LOST,
    };
    mt_codeToString(a.code);
    borrowedDateToString(a.borrowedDate);
    returnedDateToString(a.returnedDate);
    mt_statusToString(a.status);
}

int main() {
    test_danhmucsach();
    test_dausach();
    test_docgia();
    test_muontra();
}
