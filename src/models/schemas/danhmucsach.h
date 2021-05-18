#ifndef _DANHMUCSACH_H
#define _DANHMUCSACH_H

struct DanhMucSachSchema {
    // struct DanhMucSachSchema *id;
    char* code;
    enum DanhMucSachStatus { BORROWABLE, BORROWED, LIQUIDATED } status;
    int position;
};


enum DanhMucSachAttirbutes {
    code,
    status,
    position,
};

#endif /*_DANHMUCSACH_H*/
