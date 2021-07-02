#include "__init__.h"

#ifndef DANH_MUC_SACH_H
#define DANH_MUC_SACH_H

typedef struct danh_muc_sach DANH_MUC_SACH;
struct danh_muc_sach
{
    string Ma_sach;
    int Trang_thai; // 0: Cho muon duoc, 1: Da co nguoi muon, 2: Sach da thanh ly
    string Vi_tri;
};

typedef struct node_danh_muc_sach NODE_DANH_MUC_SACH;
struct node_danh_muc_sach
{
    DANH_MUC_SACH data;
    struct node_danh_muc_sach *pNext;
};

typedef struct ds_danh_muc_sach DS_DANH_MUC_SACH;
struct ds_danh_muc_sach
{
    // Khoi tao danh sach
    NODE_DANH_MUC_SACH *pHead = NULL;
    NODE_DANH_MUC_SACH *pTail = NULL;
    // Khai bao so luong
    int so_luong = 0;
};

#endif /*DANH_MUC_SACH_H*/
