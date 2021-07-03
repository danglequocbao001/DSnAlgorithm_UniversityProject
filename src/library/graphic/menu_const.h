#ifndef MENU_CONST_H
#define MENU_CONST_H

#define so_item                 5
#define dong                    8
#define cot                     54 
#define so_item_dg              7
#define dong_menu_dg            8
#define cot_menu_dg             51 
#define so_item_ds              7
#define dong_menu_ds            8
#define cot_menu_ds             51
#define so_item_dms             3
#define dong_menu_dms           8
#define cot_menu_dms            51 
#define so_item_mt              3
#define dong_menu_mt            8
#define cot_menu_mt             51 
#define so_item_thoat           2
#define dong_menu_thoat         25
#define cot_menu_thoat          63 

#define TITLE                   "QUAN LY THU VIEN"
#define SPACE                   " "
#define SEPARATER               "_"
#define TUTORIAL_KEY_BINDING    "Mui ten len xuong: Dieu khien thanh sang | Enter: Chon | Esc: Thoat"
#define INPUT_ANOTATION         "Enter: Tien hanh nhap lieu | Esc: Thoat" 
#define ADJUST_ANOTIAION        "Enter: Tien hanh chinh sua | Esc: Thoat" 
#define INPUT_CODE_DELETION     "Enter: Tien hanh nhap ma the de xoa | Esc: Thoat"
#define DELETE_CONFIRMATION     "Enter: Xoa | Esc: Thoat"
#define INPUT_CODE_DOCGIA       "Enter: Tien hanh nhap ma the doc gia | Esc: Thoat"
#define INPUT_INFO_BOOK         "Enter: Tien hanh nhap thong tin sach | Esc: Thoat"
#define ADJUST_INFO_BOOK        "Enter: Tien hanh chinh sua thong tin sach | Esc: Thoat"
#define INPUT_MORE              "Enter: Tien hanh them | Esc: Thoat"
#define TUTORIAL_RENTING_BOOK   "Mui ten trai phai: Chuyen trang | Mui ten len xuong: Di chuyen thanh sang | Enter: Chon | Esc: Thoat"
#define TOP_10                  "Mui ten len xuong: Di chuyen thanh sang | Enter: Xem chi tiet | Esc: Thoat"
#define INPUT_CODE_BOOK         "Enter: Tien hanh nhap ma sach | Esc: Huy tac vu"
#define READ_BOOK               "Mui ten trai phai: Chuyen trang | Mui ten len xuong: Di chuyen thanh sang | Enter: Chon | Esc: Thoat"
#define SEARCH_BOOK             "Mui ten len xuong: Di chuyen thanh sang | Enter: Chon | Esc: Thoat"
#define READ_CATE               "Mui ten trai phai: Chuyen trang | Esc: Thoat"
#define ADJUSTING               "Enter: Chuyen den chinh sua phan tiep theo"
#define ADJUST_DATETIME         "Enter: Xac nhan | F10: Chinh sua ngay thang"
#define NOTIFICATION            "THONG BAO: "

/*_____COMPONENTS_____*/
#define MATHE           "Ma the"
#define HOTEN           "Ho ten"
#define GIOTINH         "Gio tinh"
#define TRANGTHAITHE    "Trang thai the"
#define DANGMUON        "Dang muon"
#define DAMUON          "Da muon"
#define PASTED_DATES    "So ngay qua han"

#define ISBN_           "ISBN"
#define TENSACH         "Ten sach"
#define SOTRANG         "So trang"
#define TACGIA          "Tac gia"
#define NAMXUATBAN      "Nam xuat ban"
#define THELOAI         "The loai"
#define LUOTMUON        "Luot muon"

#define MASACH          "Ma sach"
#define VITRI           "Vi tri"
#define TRANGTHAI       "Trang thai"

char menu_chinh[so_item][50] = {
    "           DOC GIA          ",
    "           DAU SACH         ",
    "        DANH MUC SACH       ",
    "        MUON TRA SACH       ",
    "            THOAT           "};

char menu_dg[so_item_dg][50] = {
    "           THEM DOC GIA           ",
    "         CHINH SUA DOC GIA        ",
    "            XOA DOC GIA           ",
    "   SACH DANG MUON CUA 1 DOC GIA   ",
    "     DANH SACH DOC GIA QUA HAN    ",
    "     XUAT DOC GIA THEO HO TEN     ",
    "     XUAT DOC GIA THEO MA THE     "};

char menu_ds[so_item_ds][50] = {
    "           THEM DAU SACH          ",
    "           XOA DAU SACH           ",
    "        CHINH SUA DAU SACH        ",
    "             TIM SACH             ",
    "      XUAT THONG TIN DAU SACH     ",
    "    XUAT DAU SACH THEO THE LOAI   ",
    " 10 DAU SACH DUOC MUON NHIEU NHAT "};

char menu_dms[so_item_dms][50] = {
    "     THEM SACH VAO 1 DAU SACH     ",
    "     XOA SACH THUOC 1 DAU SACH    ",
    "  CHINH SUA SACH THUOC 1 DAU SACH "};

char menu_mt[so_item_mt][50] = {
    "             MUON SACH            ",
    "             TRA SACH             ",
    "           LAM MAT SACH           ",
};

char menu_thoat[so_item_thoat][50] = {
    "   CO    ",
    "  KHONG  "};

#endif /*MENU_CONST_H*/
