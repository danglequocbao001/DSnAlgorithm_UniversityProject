#include "./danhmucsach.h"


struct DauSachSchema {
    // struct DauSachSchema *id;
    // int ISBN;
    char* ISBN;
    char* name;
    int numberOfPages;
    char* author;
    int publishingYear;
    struct DanhMucSachSchema *DanhMucSach;
};


enum DauSachAttirbutes {
    ISBN,
    name,
    numberOfPages,
    author,
    publishingYear,
    publishingYear,
    DanhMucSach,
};
