#ifndef _DAUSACH_H
#define _DAUSACH_H

#include "./danhmucsach.h"
#include "../../libraries/utils.h"


struct DauSachSchema {
    // struct DauSachSchema *id;
    // int ISBN;
    char* ISBN;
    char* name;
    int numberOfPages;
    char* author;
    int publishingYear;
    char* type;
    struct DanhMucSachSchema *DanhMucSach;
};


enum DauSachAttirbutes {
    DS_ISBN,
    DS_name,
    DS_numberOfPages,
    DS_author,
    DS_publishingYear,
    DS_type,
    DS_DanhMucSach,
};

char* ds_ISBNToString(char* ISBN) {
    return ISBN;
};
char* ds_nameToString(char* name) {
    return name;
};
char* ds_numberOfPagesToString(int numberOfPages) {
    return numer_to_string(numberOfPages);
};
char* ds_authorToString(char* author) {
    return author;
};
char* ds_publishingYearToString(int publishingYear) {
    return numer_to_string(publishingYear);
};
char* ds_typeToString(char* type) {
    return type;
};


char* ds_stringToISBN(char* ISBN) {
    return ISBN;
};
char* ds_stringToName(char* name) {
    return name;
};
int ds_stringToNumberOfPages(char* numberOfPages) {
    return stoi(numberOfPages);
};
char* ds_stringToAuthor(char* author) {
    return author;
};
int ds_stringToPublishingYear(char* publishingYear) {
    return stoi(publishingYear);
};
char* ds_stringToType(char* type) {
    return type;
};

// char* ds_DanhMucSachToString(char* DanhMucSach) { };

#endif /*_DAUSACH_H*/
