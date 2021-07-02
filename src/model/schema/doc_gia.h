#include "__init__.h"
#include "muon_tra.h"

#ifndef DOC_GIA_H
#define DOC_GIA_H

typedef struct doc_gia DOC_GIA;
struct doc_gia {
    int Ma_the;
    string Ho;
    string Ten;
    string Phai;
    int Trang_thai_the; // 1: Dang hoat dong, 0: Bi khoa	
    int So_luong_sach_dang_muon;
    int So_ngay_qua_han;
    // Con tro
    DS_MUON_TRA ds_muon_tra_cua_doc_gia;
};

typedef struct node_doc_gia NODE_DOC_GIA;
typedef NODE_DOC_GIA *TREE;
struct node_doc_gia {
    DOC_GIA data;
    struct node_doc_gia *pLeft;
    struct node_doc_gia *pRight;	
};

typedef struct ds_doc_gia DS_DOC_GIA;
struct ds_doc_gia {
    int so_luong = 0;	
};

#endif /*DOC_GIA_H*/

