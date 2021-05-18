#ifndef _MUONTRA_H
#define _MUONTRA_H


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


#endif /*_MUONTRA_H*/
