#include "./docgia.h"

struct TheDocGiaSchema {
    // struct TheDocGiaSchema *id
    int code;
    char* firstName;
    char* lastName;
    enum SEX {MALE, FEMALE} sex;
    enum TheDocGiaStatus {DEACTIVE, ACTIVE} status;
    struct DanhMucSachSchema *DanhMucSachSchema;
};


enum TheDocGiaAttirbutes {
    code,
    firstName,
    lastName,
    sex,
    status,
};

