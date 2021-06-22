#include "./__init__.h"

#ifndef _MUONTRA_H
#define _MUONTRA_H


enum MuonTraStatus { BORROWING, RETURNED, LOST };
struct MuonTraSchema {
    char* code;
    int borrowedDate;
    int returnedDate;
    int status;
};


enum MuonTraAttirbutes { MT_code, MT_status, MT_borrowedDate, MT_returnedDate, };


struct MuonTraSchema MuonTraInit(struct string_2d);
struct string_2d DanhMucSachToArray(struct MuonTraSchema);

char* mt_codeToString(char*);
char* mt_borrowedDateToString(int);
char* mt_returnedDateToString(int);
char* mt_statusToString(int);

char* mt_stringToCode(char*);
int mt_stringToBorrowedDate(char*);
int mt_stringToReturnedDate(char*);
int mt_stringToStatus(char*);

struct MuonTraSchema MuonTraInit(struct string_2d values) {
    return (struct MuonTraSchema) {
        .code = mt_stringToCode(values.array[MT_code]),
        .borrowedDate = mt_stringToBorrowedDate(values.array[MT_borrowedDate]),
        .returnedDate = mt_stringToReturnedDate(values.array[MT_returnedDate]),
        .status = mt_stringToStatus(values.array[MT_status]),
    };
}

struct string_2d MuonTraToArray(struct MuonTraSchema value) {
    char **str_array = (char**)malloc(4*POINTER_SIZE);
    str_array[MT_code] = mt_codeToString(value.code);
    str_array[MT_borrowedDate] = mt_borrowedDateToString(value.borrowedDate);
    str_array[MT_returnedDate] = mt_returnedDateToString(value.returnedDate);
    str_array[MT_status] = mt_statusToString(value.status);
    return (struct string_2d){ .array = str_array, .size = 4 };
}


char* mt_codeToString(char* code) {
    return code;
};
char* mt_borrowedDateToString(int borrowedDate) {
    return numer_to_string(borrowedDate);
};
char* mt_returnedDateToString(int returnedDate) {
    return numer_to_string(returnedDate);
};
char* mt_statusToString(int status) {
    return numer_to_string(status);
};


char* mt_stringToCode(char* code) {
    return code;
};
int mt_stringToBorrowedDate(char* borrowedDate) {
    return stoi(borrowedDate);
};
int mt_stringToReturnedDate(char* returnedDate) {
    return stoi(returnedDate);
};
int mt_stringToStatus(char* status) {
    return stoi(status);
};

#endif /*_MUONTRA_H*/
