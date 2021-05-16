
struct MuonTraSchema {
    // struct MuonTraSchema *id;
    char* code;
    uint16_t status;
    int borrowedDate; // unix time
    int returnedDate;
    enum MuonTraStatus { BORROWING, RETURNED, LOST } status;
};


enum MuonTraAttirbutes {
    code,
    status,
    borrowedDate,
    returnedDate,
    status
};

