#ifndef _DANHMUCSACH_H
#define _DANHMUCSACH_H

#include "../../libraries/utils.h"
enum DanhMucSachStatus { BORROWABLE, BORROWED, LIQUIDATED };
struct DanhMucSachSchema {
    // struct DanhMucSachSchema *id;
    char* code;
    enum DanhMucSachStatus status;
    int position;
};


enum DanhMucSachAttirbutes {
    DM_code,
    DM_status,
    DM_position,
};

char* dm_codeToString(char* code) {
    return code;
};
char* dm_statusToString(int status) {
    return numer_to_string(status);
};
char* dm_positionToString(int position) {
    return numer_to_string(position);
};


char* dm_stringToCode(char* code) {
    return code;
};
int dm_stringToStatus(char* status) {
    return stoi(status);
};
int dm_stringToPosition(char* position) {
    return stoi(position);
};

#endif /*_DANHMUCSACH_H*/
