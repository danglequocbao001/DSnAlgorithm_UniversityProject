#include "__init__.h"
#include "danh_muc_sach.h"

#ifndef DAU_SACH_H
#define DAU_SACH_H

typedef struct dau_sach DAU_SACH;
struct dau_sach
{
    string ISBN;
    string Ten_sach;
    int So_trang;
    string Tac_gia;
    int Nam_xuat_ban;
    string The_loai;
    int So_lan_muon = 0;
    // *dms
    DS_DANH_MUC_SACH ds_danh_muc_sach_cua_dau_sach;
    bool Check; // True: dau sach hien tai van con sach, khong the xoa. False: dau sach hien tai dang rong, co the xoa
};

typedef struct ds_dau_sach DS_DAU_SACH;
struct ds_dau_sach
{
    DAU_SACH *list[MAX_DAU_SACH];
    int so_luong = 0;
};

#endif /*DAU_SACH_H*/
