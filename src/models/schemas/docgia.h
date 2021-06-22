#include "__init__.h"

#ifndef _DOCGIA_H
#define _DOCGIA_H

enum SEX {MALE, FEMALE};
enum TheDocGiaStatus {DEACTIVE, ACTIVE};
struct TheDocGiaSchema {
    int code;
    char* firstName;
    char* lastName;
    int sex;
    int status;
    struct MuonTraSchema *MuonTraSchema; };


enum TheDocGiaAttirbutes { DG_code, DG_firstName, DG_lastName, DG_sex, DG_status, };

struct DanhMucSachSchema DanhMucSachInit(struct string_2d);
struct string_2d DanhMucSachToArray(struct DanhMucSachSchema);

char* dg_codeToString(int);
char* dg_firstNameToString(char*);
char* dg_lastNameToString(char*);
char* dg_sexToString(int);
char* dg_statusToString(int);

int dg_stringToCode(char*);
char* dg_stringToFirstName(char*);
char* dg_stringToLastName(char*);
int dg_stringToSex(char*);
int dg_stringToStatus(char*);


struct TheDocGiaSchema TheDocGiaInit(struct string_2d values) {
    return (struct TheDocGiaSchema) {
        .code = dg_stringToCode(values.array[DG_code]),
        .firstName = dg_stringToFirstName(values.array[DG_firstName]),
        .lastName = dg_stringToLastName(values.array[DG_lastName]),
        .sex = dg_stringToSex(values.array[DG_sex]),
        .status = dg_stringToStatus(values.array[DG_status]),
    };
}

struct string_2d TheDocGiaToArray(struct TheDocGiaSchema value) {
    char **str_array = (char**)malloc(5*POINTER_SIZE);
    str_array[DG_code] = dg_codeToString(value.code);
    str_array[DG_firstName] = dg_firstNameToString(value.firstName);
    str_array[DG_lastName] = dg_lastNameToString(value.lastName);
    str_array[DG_sex] = dg_sexToString(value.sex);
    str_array[DG_status] = dg_statusToString(value.status);
    return (struct string_2d){ .array = str_array, .size = 5 };
}

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
