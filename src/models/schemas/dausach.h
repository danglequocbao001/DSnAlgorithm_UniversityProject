#ifndef _DAUSACH_H
#define _DAUSACH_H

#include "./danhmucsach.h"
#include "../../libraries/utils.h"
#include "../../vars.h"


struct DauSachSchema { char* ISBN;
                       char* name;
                       int numberOfPages;
                       char* author;
                       int publishingYear;
                       char* type;
                       struct DanhMucSachSchema *DanhMucSach; };

enum DauSachAttirbutes { DS_ISBN, DS_name, DS_numberOfPages, DS_author, DS_publishingYear, DS_type, DS_DanhMucSach, };

struct DauSachSchema DauSachInit(struct string_2d);
struct string_2d DauSachToArray(struct DauSachSchema);

char* ds_ISBNToString(char*);
char* ds_nameToString(char*);
char* ds_numberOfPagesToString(int);
char* ds_authorToString(char*);
char* ds_publishingYearToString(int);
char* ds_typeToString(char*);

char* ds_stringToISBN(char*);
char* ds_stringToName(char*);
int ds_stringToNumberOfPages(char*);
char* ds_stringToAuthor(char*);
int ds_stringToPublishingYear(char*);
char* ds_stringToType(char*);


struct DauSachSchema DauSachInit(struct string_2d values) {
    return (struct DauSachSchema) {
        .ISBN = ds_stringToISBN(values.array[DS_ISBN]),
        .name = ds_stringToName(values.array[DS_name]),
        .numberOfPages = ds_stringToNumberOfPages(values.array[DS_numberOfPages]),
        .author = ds_stringToAuthor(values.array[DS_author]),
        .publishingYear = ds_stringToPublishingYear(values.array[DS_publishingYear]),
        .type = ds_stringToType(values.array[DS_type]),
    };
}

struct string_2d DauSachToArray(struct DauSachSchema value) {
    char **str_array = (char**)malloc(6*sizeof(char**));

    str_array[DS_ISBN] = ds_ISBNToString(value.ISBN);
    str_array[DS_name] = ds_nameToString(value.name);
    str_array[DS_numberOfPages] = ds_numberOfPagesToString(value.numberOfPages);
    str_array[DS_author] = ds_authorToString(value.author);
    str_array[DS_publishingYear] = ds_publishingYearToString(value.publishingYear);
    str_array[DS_type] = ds_typeToString(value.type);

    return (struct string_2d){
        .array = str_array,
        .size = 6
    };
}


char* ds_ISBNToString(char* ISBN) { return ISBN; };
char* ds_nameToString(char* name) { return name; };
char* ds_authorToString(char* author) { return author; };
char* ds_typeToString(char* type) { return type; };
char* ds_numberOfPagesToString(int numberOfPages) { return numer_to_string(numberOfPages); };
char* ds_publishingYearToString(int publishingYear) { return numer_to_string(publishingYear); };


char* ds_stringToISBN(char* ISBN) { return ISBN; };
char* ds_stringToName(char* name) { return name; };
char* ds_stringToAuthor(char* author) { return author; };
char* ds_stringToType(char* type) { return type; };
int ds_stringToNumberOfPages(char* numberOfPages) { return stoi(numberOfPages); };
int ds_stringToPublishingYear(char* publishingYear) { return stoi(publishingYear); };

// char* ds_DanhMucSachToString(char* DanhMucSach) { };

#endif /*_DAUSACH_H*/
