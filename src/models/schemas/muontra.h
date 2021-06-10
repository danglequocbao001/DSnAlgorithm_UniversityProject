#ifndef _MUONTRA_H
#define _MUONTRA_H


enum MuonTraStatus { BORROWING, RETURNED, LOST };
struct MuonTraSchema {
    // struct MuonTraSchema *id;
    char* code;
    int borrowedDate; // unix time
    int returnedDate;
    enum MuonTraStatus status;
};


enum MuonTraAttirbutes {
    MT_code,
    MT_status,
    MT_borrowedDate,
    MT_returnedDate,
};


char* mt_codeToString(char* code) {
    return code;
};
char* mt_borrowedDateToString(int borrowedDate) {
    return numer_to_string(borrowedDate);
};
char* mt_returnedDateToString(int returnedDate) {
    return numer_to_string(returnedDate);
};
char* mt_statusToString(int status) {
    return numer_to_string(status);
};


char* mt_stringToCode(char* code) {
    return code;
};
int mt_stringToBorrowedDate(char* borrowedDate) {
    return stoi(borrowedDate);
};
int mt_stringToReturnedDate(char* returnedDate) {
    return stoi(returnedDate);
};
int mt_stringToStatus(char* status) {
    return stoi(status);
};

#endif /*_MUONTRA_H*/
