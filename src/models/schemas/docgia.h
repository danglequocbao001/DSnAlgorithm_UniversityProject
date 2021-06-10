#ifndef _DOCGIA_H
#define _DOCGIA_H

#include "./docgia.h"
#include "string.h"

enum SEX {MALE, FEMALE};
enum TheDocGiaStatus {DEACTIVE, ACTIVE};
struct TheDocGiaSchema {
    // struct TheDocGiaSchema *id
    int code;
    char* firstName;
    char* lastName;
    enum SEX sex;
    enum TheDocGiaStatus status;
    struct DanhMucSachSchema *DanhMucSachSchema;
};


enum TheDocGiaAttirbutes {
    DG_code,
    DG_firstName,
    DG_lastName,
    DG_sex,
    DG_status,
};

char* dg_codeToString(int code) {
    return numer_to_string(code);
};
char* dg_firstNameToString(char* firstName) {
    return firstName;
};
char* dg_lastNameToString(char* lastName) {
    return lastName;
};
char* dg_sexToString(int sex) {
    return numer_to_string(sex);
};
char* dg_statusToString(int status) {
    return numer_to_string(status);
};


int dg_stringToCode(char* code) {
    return stoi(code);
};
char* dg_stringToFirstName(char* firstName) {
    return firstName;
};
char* dg_stringToLastName(char* lastName) {
    return lastName;
};
int dg_stringToSex(char* sex) {
    return stoi(sex);
};
int dg_stringToStatus(char* status) {
    return stoi(status);
};

#endif /*_DOCGIA_H*/
