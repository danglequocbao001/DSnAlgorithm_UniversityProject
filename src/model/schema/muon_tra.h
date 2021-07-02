#include "__init__.h"

#ifndef MUON_TRA_H
#define MUON_TRA_H

typedef struct muon_tra MUON_TRA;
struct muon_tra {
    string Ma_sach;
    NGAY_THANG Ngay_muon;
    NGAY_THANG Ngay_tra;
    int Trang_thai; // 0: Dang muon, 1: Da tra, 2: Lam mat sach
    // Phan nay them vao, khong co trong yeu cau
    // string Ten_sach;
};

typedef struct node_muon_tra NODE_MUON_TRA;
struct node_muon_tra {
    MUON_TRA data;
    struct node_muon_tra *pNext;
    struct node_muon_tra *pBack;
};

typedef struct ds_muon_tra DS_MUON_TRA;
struct ds_muon_tra {
    // Khoi tao danh sach
    NODE_MUON_TRA *pHead = NULL;
    NODE_MUON_TRA *pTail = NULL;
    // Khai bao so luong
    int so_luong = 0;	
};

#endif /*MUON_TRA_H*/
