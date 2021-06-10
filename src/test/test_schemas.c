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
    dm_stringToCode(dm_codeToString(a.code));
    dm_stringToStatus(dm_statusToString(a.status));
    dm_stringToPosition(dm_positionToString(a.position));
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
}

int main() {
    test_danhmucsach();
    test_dausach();
    test_docgia();
    test_muontra();
}
