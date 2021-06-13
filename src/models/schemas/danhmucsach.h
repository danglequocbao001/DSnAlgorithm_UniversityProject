#ifndef _DANHMUCSACH_H
#define _DANHMUCSACH_H

#include "../../vars.h"
#include "../../libraries/utils.h"

enum DanhMucSachStatus { BORROWABLE, BORROWED, LIQUIDATED };
struct DanhMucSachSchema { char* code;
                           int status;
                           int position; };

enum DanhMucSachAttirbutes { DM_code, DM_status, DM_position, };

struct DanhMucSachSchema DanhMucSachInit(struct string_2d);
struct string_2d DanhMucSachToArray(struct DanhMucSachSchema);

char* dm_codeToString(char*);
char* dm_statusToString(int);
char* dm_positionToString(int);

char* dm_stringToCode(char*);
int dm_stringToStatus(char*);
int dm_stringToPosition(char*);


struct DanhMucSachSchema DanhMucSachInit(struct string_2d values) {
    return (struct DanhMucSachSchema) {
        .code = dm_stringToCode(values.array[DM_code]),
        .status = dm_stringToStatus(values.array[DM_status]),
        .position = dm_stringToPosition(values.array[DM_position]),
    };
}

struct string_2d DanhMucSachToArray(struct DanhMucSachSchema value) {
    char **str_array = (char**)malloc(3*POINTER_SIZE);
    str_array[DM_code] = dm_codeToString(value.code);
    str_array[DM_status] = dm_statusToString(value.status);
    str_array[DM_position] = dm_positionToString(value.position);
    return (struct string_2d){ .array = str_array, .size = 3 };
}

char* dm_codeToString(char* code) { return code; };
char* dm_statusToString(int status) { return numer_to_string(status); };
char* dm_positionToString(int position) { return numer_to_string(position); };

char* dm_stringToCode(char* code) { return code; };
int dm_stringToStatus(char* status) { return stoi(status); };
int dm_stringToPosition(char* position) { return stoi(position); };

#endif /*_DANHMUCSACH_H*/
