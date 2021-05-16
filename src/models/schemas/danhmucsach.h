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
