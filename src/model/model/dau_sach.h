#ifndef Dausach
#define Dausach

#include "./__init__.h"
#include "./docgia_controller.h"
#include "../schema/schema.h"
#include "../../library/standard/date_time.h"
#include "../../library/standard/validated_inp_num.h"

// void Xuat_thong_tin_1_dau_sach(DAU_SACH *dau_sach);

void Xuat_dms_cua_1_dau_sach(DS_DANH_MUC_SACH ds_dms, int dong_bat_dau);
using namespace std;
// Dau sach
bool Kiem_tra_rong_ds_dau_sach(DS_DAU_SACH ds_dau_sach) // Danh sach dau sach hien tai dang rong (true) hay da co phan tu (false)?
{
    if (ds_dau_sach.so_luong == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Kiem_tra_day_ds_dau_sach(DS_DAU_SACH ds_dau_sach) // Danh sach dau sach day (true) thi khong cho them nua
{
    if (ds_dau_sach.so_luong == MAX_DAU_SACH)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Kiem_tra_ki_tu_ISBN(std::string isbn) // Chi cho nhap so hoac chu cai
{
    for (int i = 0; i < isbn.length(); i++)
    {
        if ((isbn[i] < 65 || isbn[i] > 90) && (isbn[i] < 48 || isbn[i] > 57) && (isbn[i] < 97 || isbn[i] > 122))
        {
            return false;
        }
    }
    return true;
}
bool Kiem_tra_trung_ISBN(DS_DAU_SACH ds_dau_sach, std::string isbn)
{
    for (int i = 0; i < ds_dau_sach.so_luong; i++)
    {
        if (ds_dau_sach.list[i]->ISBN == isbn)
        {
            return true;
        }
    }
    return false;
}
int Kiem_tra_dau_sach(DS_DAU_SACH ds_dau_sach, std::string a)
{
    for (int i = 0; i < ds_dau_sach.so_luong; i++)
    {
        // Kiem tra xem dau sach co ton tai khong
        if (ds_dau_sach.list[i]->ISBN == a)
        {
            // Kiem tra xem dau sach do da co sach chua
            if (ds_dau_sach.list[i]->Check == false)
            {
                return i;
            }
        }
    }
    return -1;
}
bool Kiem_tra_ten_sach(DS_DAU_SACH ds_dau_sach, std::string a)
{
    for (int i = 0; i < ds_dau_sach.so_luong; i++)
    {
        if (ds_dau_sach.list[i]->Ten_sach == a)
        {
            return true;
        }
    }
    return false;
}
void Xuat_thong_tin_1_dau_sach_theo_hang(DAU_SACH *dau_sach, int dong_bat_dau, int dem)
{
    gotoxy(8, dong_bat_dau + dem);
    cout << dau_sach->ISBN;
    gotoxy(16, dong_bat_dau + dem);
    cout << dau_sach->Ten_sach;
    gotoxy(51, dong_bat_dau + dem);
    cout << dau_sach->So_trang;
    gotoxy(62, dong_bat_dau + dem);
    cout << dau_sach->Tac_gia;
    gotoxy(93, dong_bat_dau + dem);
    cout << dau_sach->Nam_xuat_ban;
    gotoxy(104, dong_bat_dau + dem);
    cout << dau_sach->The_loai;
    gotoxy(121, dong_bat_dau + dem);
    cout << dau_sach->So_lan_muon;
}
void Xuat_dms_cua_1_dau_sach(DS_DANH_MUC_SACH ds_dms, int dong_bat_dau)
{
    int dem = 0;
    for (NODE_DANH_MUC_SACH *k = ds_dms.pHead; k != NULL; k = k->pNext)
    {
        gotoxy(30, dong_bat_dau + dem);
        cout << k->data.Ma_sach << endl;
        gotoxy(39, dong_bat_dau + dem);
        cout << k->data.Vi_tri << endl
             << endl;
        if (k->data.Trang_thai == 0)
        {
            gotoxy(82, dong_bat_dau + dem);
            cout << k->data.Trang_thai << " (Cho muon duoc)" << endl;
        }
        else if (k->data.Trang_thai == 1)
        {
            gotoxy(82, dong_bat_dau + dem);
            cout << k->data.Trang_thai << " (Da co nguoi muon)" << endl;
        }
        else
        {
            gotoxy(82, dong_bat_dau + dem);
            cout << k->data.Trang_thai << " (Sach da thanh ly)" << endl;
        }
        dem++;
    }
}
void Them_dau_sach(DS_DAU_SACH &ds_dau_sach)
{
    huong_dan_nhap_dau_sach();
    gotoxy(30, 9);
    cout << "Nhap ISBN: ";
    gotoxy(30, 11);
    cout << "Nhap ten sach: ";
    gotoxy(30, 13);
    cout << "Cho biet so trang: ";
    gotoxy(30, 15);
    cout << "Nhap ten tac gia: ";
    gotoxy(30, 17);
    cout << "Nhap nam xuat ban: ";
    gotoxy(30, 19);
    cout << "Nhap the loai: ";
    if (Kiem_tra_day_ds_dau_sach(ds_dau_sach) == true) // Neu danh sach day thi khong cho thep nua
    {
        thong_bao("Danh sach da day.");
        return;
    }
    while (true)
    {
        if (kbhit())
        {
            char key = getch();
            if (key == 13)
            {
                ShowCur(1);
                DAU_SACH *p = new DAU_SACH;
                do
                {
                    gotoxy(41, 9);
                    Nhap_va_kiem_tra_bo_trong_du_lieu(p->ISBN, 41, 9);
                    if (Kiem_tra_ki_tu_ISBN(p->ISBN) == false)
                    {
                        do
                        {
                            thong_bao("Ma ISBN khong hop le. Xin sua lai.");
                            xoa_man_hinh(41, 9, 80, 1);
                            gotoxy(41, 9);
                            getline(std::cin, p->ISBN);
                        } while (Kiem_tra_ki_tu_ISBN(p->ISBN) == false);
                    }
                    if (p->ISBN.length() != 4)
                    {
                        do
                        {
                            thong_bao("Ma ISBN phai co 4 ki tu. Xin nhap lai.");
                            xoa_man_hinh(41, 9, 80, 1);
                            gotoxy(41, 9);
                            getline(std::cin, p->ISBN);
                        } while (p->ISBN.length() != 4);
                    }
                    if (Kiem_tra_trung_ISBN(ds_dau_sach, p->ISBN) == true)
                    {
                        thong_bao("Ma ISBN da ton tai. Xin nhap lai ma khac.");
                        xoa_man_hinh(41, 9, 80, 1);
                        gotoxy(41, 9);
                    }
                } while (Kiem_tra_trung_ISBN(ds_dau_sach, p->ISBN) == true);
                gotoxy(45, 11);
                Nhap_va_kiem_tra_bo_trong_du_lieu(p->Ten_sach, 45, 11);
                gotoxy(49, 13);
                Nhap_so(p->So_trang, 49, 13);
                do
                {
                    gotoxy(48, 15);
                    Nhap_va_kiem_tra_bo_trong_du_lieu(p->Tac_gia, 48, 15);
                    if (Kiem_tra_nhap_ho_ten(p->Tac_gia) == false)
                    {
                        thong_bao("Ten khong hop le, xin nhap lai");
                        xoa_man_hinh(48, 15, 80, 1);
                        gotoxy(48, 15);
                    }
                } while (Kiem_tra_nhap_ho_ten(p->Tac_gia) == false);
                int namhientai = Lay_nam_he_thong();
                do
                {
                    gotoxy(49, 17);
                    Nhap_so(p->Nam_xuat_ban, 49, 17);
                    if (p->Nam_xuat_ban > namhientai)
                    {
                        thong_bao("Nam xuat ban khong the lon hon nam hien tai. Xin kiem tra lai.");
                        xoa_man_hinh(49, 17, 80, 1);
                        gotoxy(49, 17);
                    }
                } while (p->Nam_xuat_ban > namhientai);
                gotoxy(45, 19);
                Nhap_va_kiem_tra_bo_trong_du_lieu(p->The_loai, 45, 19);
                Chuan_hoa_chu(p->Tac_gia);
                Chuan_hoa_chu(p->Ten_sach);
                Chuan_hoa_chu(p->The_loai);
                ds_dau_sach.list[ds_dau_sach.so_luong] = p;
                ds_dau_sach.so_luong++;
                thong_bao("Them thanh cong.");
                return;
            }
            else if (key == 27)
            {
                return;
            }
        }
    }
}
void Xoa_dau_sach(DS_DAU_SACH &ds_dau_sach)
{
    int vitri = 0;
    int chon = 0;
    int c;
    int dem = 0;
    int page;
    int current_page = 1;
    if (ds_dau_sach.so_luong % 25 == 0)
    {
        page = ds_dau_sach.so_luong / 25;
    }
    else
    {
        page = ds_dau_sach.so_luong / 25 + 1;
    }
    gotoxy(114, 36);
    cout << "Trang " << current_page << " / " << page;
    huong_dan_xem_danh_sach();
    khung_xuat_thong_tin_ds(5, 7, 28);
    for (int i = 0; i < ds_dau_sach.so_luong; i++)
    {
        vitri = 0;
        if (dem == 0)
            SetColor(26);
        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[i], 10, dem);
        Normal();
        if (dem == 24 || i == ds_dau_sach.so_luong - 1)
        {
            do
            {
                c = getch();
                if (c == 0)
                    c = getch();
                switch (c)
                {
                case 80:
                    if (vitri + 1 < 25 && chon < ds_dau_sach.so_luong - 1)
                    {
                        Normal();
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        chon++;
                        vitri++;
                        SetColor(26);
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        gotoxy(10, 5);
                    }
                    break;
                case 72:
                    if (vitri + 1 > 1)
                    {
                        Normal();
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        chon--;
                        vitri--;
                        SetColor(26);
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        gotoxy(10, 5);
                    }
                    break;
                case 13:
                    Normal();
                    xoa_man_hinh(5, 7, 128, 30);
                    gotoxy(62, 12);
                    cout << "THONG TIN SACH";
                    khung_xuat_thong_tin_ds(5, 13, 4);
                    Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 16, 0);
                    gotoxy(60, 19);
                    cout << "DANH MUC SACH";
                    khung_xuat_dms(27, 20, 16);
                    Xuat_dms_cua_1_dau_sach(ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach, 23);
                    huong_dan_xoa_doc_gia_2();
                    gotoxy(62, 37);
                    textcolor(11);
                    ShowCur(1);
                    cout << "XAC NHAN XOA?";
                    Normal();
                    while (true)
                    {
                        if (kbhit())
                        {
                            char key2 = getch();
                            if (key2 == 13)
                            {
                                int vitri = Kiem_tra_dau_sach(ds_dau_sach, ds_dau_sach.list[chon]->ISBN);
                                if (vitri < 0)
                                {
                                    thong_bao("Dau sach van con sach. Khong the xoa.");
                                    ShowCur(0);
                                    break;
                                }
                                else
                                {
                                    // 	C1:
                                    // B1: Doi vi tri
                                    delete ds_dau_sach.list[i];
                                    ds_dau_sach.list[i] = NULL;
                                    for (int i = vitri; i < ds_dau_sach.so_luong - 1; i++)
                                    {
                                        ds_dau_sach.list[i] = ds_dau_sach.list[i + 1];
                                    }
                                    // B2: Giai phong
                                    // DAU_SACH *tam = ds_dau_sach.list[ds_dau_sach.so_luong-1];
                                    delete ds_dau_sach.list[ds_dau_sach.so_luong - 1];
                                    // Tranh truong hop con tro bi treo
                                    ds_dau_sach.list[ds_dau_sach.so_luong - 1] = NULL;
                                    // Giam so luong
                                    ds_dau_sach.so_luong--;
                                    thong_bao("Xoa thanh cong.");
                                    ShowCur(0);
                                    break;
                                }
                            }
                            else if (key2 == 27)
                            {
                                ShowCur(0);
                                xoa_man_hinh(5, 37, 100, 1);
                                break;
                            }
                        }
                    }
                    break;
                case 77:
                    if (i == ds_dau_sach.so_luong - 1)
                        c = 0;
                    break;
                case 75:
                    if (i == 24)
                        c = 0;
                    break;
                case 27:
                    Normal();
                    return;
                }
            } while (c != 77 && c != 75 && c != 13);
            if (c == 77 && i < ds_dau_sach.so_luong - 1)
            {
                Normal();
                chon = 25;
                dem = -1;
                gotoxy(120, 36);
                cout << ++current_page;
                xoa_man_hinh(5, 7, 128, 29);
            }
            else if (c == 75 && i > 24)
            {
                Normal();
                chon = 0;
                dem = -1;
                gotoxy(120, 36);
                cout << --current_page;
                if (i < 50 && dem <= 24)
                    i = -1;
                else if (i > 49)
                    i = i - ((i % 25) + 26);
                xoa_man_hinh(5, 7, 128, 29);
            }
            else if (c == 13)
            {
                Normal();
                chon = 0;
                dem = -1;
                current_page = 1;
                if (ds_dau_sach.so_luong % 25 == 0)
                {
                    page = ds_dau_sach.so_luong / 25;
                }
                else
                {
                    page = ds_dau_sach.so_luong / 25 + 1;
                }
                if (i < 50 && dem <= 24)
                    i = -1;
                else if (i > 49)
                    i = i - ((i % 25) + 26);
                xoa_man_hinh(5, 7, 128, 30);
                gotoxy(114, 36);
                cout << "Trang 1 / " << page;
            }
            khung_xuat_thong_tin_ds(5, 7, 28);
            huong_dan_xem_danh_sach();
        }
        dem++;
    }
}
void Hieu_chinh_dau_sach(DS_DAU_SACH &ds_dau_sach)
{
    int vitri = 0;
    int chon = 0;
    int c;
    int dem = 0;
    int page;
    int current_page = 1;
    if (ds_dau_sach.so_luong % 25 == 0)
    {
        page = ds_dau_sach.so_luong / 25;
    }
    else
    {
        page = ds_dau_sach.so_luong / 25 + 1;
    }
    gotoxy(114, 36);
    cout << "Trang " << current_page << " / " << page;
    huong_dan_xem_danh_sach();
    khung_xuat_thong_tin_ds(5, 7, 28);
    for (int i = 0; i < ds_dau_sach.so_luong; i++)
    {
        vitri = 0;
        if (dem == 0)
            SetColor(26);
        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[i], 10, dem);
        Normal();
        if (dem == 24 || i == ds_dau_sach.so_luong - 1)
        {
            do
            {
                c = getch();
                if (c == 0)
                    c = getch();
                switch (c)
                {
                case 80:
                    if (vitri + 1 < 25 && chon < ds_dau_sach.so_luong - 1)
                    {
                        Normal();
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        chon++;
                        vitri++;
                        SetColor(26);
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        gotoxy(10, 5);
                    }
                    break;
                case 72:
                    if (vitri + 1 > 1)
                    {
                        Normal();
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        chon--;
                        vitri--;
                        SetColor(26);
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        gotoxy(10, 5);
                    }
                    break;
                case 13:
                    Normal();
                    xoa_man_hinh(5, 7, 128, 30);
                    gotoxy(59, 11);
                    cout << "THONG TIN DAU SACH";
                    khung_xuat_thong_tin_ds(5, 12, 4);
                    Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 15, 0);
                    ShowCur(0);
                    huong_dan_chinh_sua_sach();
                    gotoxy(59, 18);
                    cout << "CHINH SUA THONG TIN";
                    gotoxy(30, 20);
                    cout << "Nhap ten sach moi: " << ds_dau_sach.list[chon]->Ten_sach;
                    gotoxy(30, 22);
                    cout << "Cho biet so trang moi: " << ds_dau_sach.list[chon]->So_trang;
                    gotoxy(30, 24);
                    cout << "Nhap ten tac gia moi: " << ds_dau_sach.list[chon]->Tac_gia;
                    gotoxy(30, 26);
                    cout << "Nhap nam xuat ban moi: " << ds_dau_sach.list[chon]->Nam_xuat_ban;
                    gotoxy(30, 28);
                    cout << "Nhap the loai moi: " << ds_dau_sach.list[chon]->The_loai;
                    gotoxy(45, 20);
                    while (true)
                    {
                        if (kbhit())
                        {
                            char key = getch();
                            {
                                if (key == 13)
                                {
                                    huong_dan_chinh_sua();
                                    ShowCur(1);
                                    std::string temp = ds_dau_sach.list[chon]->Ten_sach;
                                    xoa_man_hinh(49, 20, 60, 1);
                                    gotoxy(49, 20);
                                    Nhap_va_kiem_tra_bo_trong_du_lieu_chinh_sua(ds_dau_sach.list[chon]->Ten_sach, 49, 20);
                                    if (ds_dau_sach.list[chon]->Ten_sach == "")
                                    {
                                        ds_dau_sach.list[chon]->Ten_sach = temp;
                                    }
                                    gotoxy(49, 20);
                                    cout << ds_dau_sach.list[chon]->Ten_sach;
                                    int tam = ds_dau_sach.list[chon]->So_trang;
                                    xoa_man_hinh(53, 22, 60, 1);
                                    gotoxy(53, 22);
                                    Nhap_so_chinh_sua(ds_dau_sach.list[chon]->So_trang, 53, 22);
                                    if (ds_dau_sach.list[chon]->So_trang == '\0')
                                    {
                                        ds_dau_sach.list[chon]->So_trang = tam;
                                    }
                                    gotoxy(53, 22);
                                    cout << ds_dau_sach.list[chon]->So_trang;
                                    temp = ds_dau_sach.list[chon]->Tac_gia;
                                    xoa_man_hinh(52, 24, 60, 1);
                                    do
                                    {
                                        gotoxy(52, 24);
                                        Nhap_va_kiem_tra_bo_trong_du_lieu_chinh_sua(ds_dau_sach.list[chon]->Tac_gia, 52, 24);
                                        if (Kiem_tra_nhap_ho_ten(ds_dau_sach.list[chon]->Tac_gia) == false)
                                        {
                                            thong_bao("Ten khong hop le, xin nhap lai");
                                            xoa_man_hinh(52, 24, 80, 1);
                                            gotoxy(52, 24);
                                        }
                                    } while (Kiem_tra_nhap_ho_ten(ds_dau_sach.list[chon]->Tac_gia) == false);
                                    if (ds_dau_sach.list[chon]->Tac_gia == "")
                                    {
                                        ds_dau_sach.list[chon]->Tac_gia = temp;
                                    }
                                    gotoxy(52, 24);
                                    cout << ds_dau_sach.list[chon]->Tac_gia;
                                    int namhientai = Lay_nam_he_thong();
                                    tam = ds_dau_sach.list[chon]->Nam_xuat_ban;
                                    xoa_man_hinh(53, 26, 60, 1);
                                    do
                                    {
                                        gotoxy(53, 26);
                                        Nhap_so_chinh_sua(ds_dau_sach.list[chon]->Nam_xuat_ban, 53, 26);
                                        if (ds_dau_sach.list[chon]->Nam_xuat_ban > namhientai)
                                        {
                                            thong_bao("Nam xuat ban khong the lon hon nam hien tai. Xin kiem tra lai.");
                                            xoa_man_hinh(53, 26, 80, 1);
                                            gotoxy(53, 26);
                                        }
                                    } while (ds_dau_sach.list[chon]->Nam_xuat_ban > namhientai);
                                    if (ds_dau_sach.list[chon]->Nam_xuat_ban == '\0')
                                    {
                                        ds_dau_sach.list[chon]->Nam_xuat_ban = tam;
                                    }
                                    gotoxy(53, 26);
                                    cout << ds_dau_sach.list[chon]->Nam_xuat_ban;
                                    temp = ds_dau_sach.list[chon]->The_loai;
                                    xoa_man_hinh(49, 28, 60, 1);
                                    gotoxy(49, 28);
                                    Nhap_va_kiem_tra_bo_trong_du_lieu_chinh_sua(ds_dau_sach.list[chon]->The_loai, 49, 28);
                                    if (ds_dau_sach.list[chon]->The_loai == "")
                                    {
                                        ds_dau_sach.list[chon]->The_loai = temp;
                                    }
                                    gotoxy(49, 28);
                                    cout << ds_dau_sach.list[chon]->The_loai;
                                    Chuan_hoa_chu(ds_dau_sach.list[chon]->Tac_gia);
                                    Chuan_hoa_chu(ds_dau_sach.list[chon]->Ten_sach);
                                    Chuan_hoa_chu(ds_dau_sach.list[chon]->The_loai);
                                    ShowCur(0);
                                    thong_bao("Hieu chinh thanh cong.");
                                    break;
                                }
                                else if (key == 27)
                                {
                                    break;
                                }
                            }
                        }
                    }
                    break;
                case 77:
                    if (i == ds_dau_sach.so_luong - 1)
                        c = 0;
                    break;
                case 75:
                    if (i == 24)
                        c = 0;
                    break;
                case 27:
                    Normal();
                    return;
                }
            } while (c != 77 && c != 75 && c != 13);
            if (c == 77 && i < ds_dau_sach.so_luong - 1)
            {
                Normal();
                chon = 25;
                dem = -1;
                gotoxy(120, 36);
                cout << ++current_page;
                xoa_man_hinh(5, 7, 128, 29);
            }
            else if (c == 75 && i > 24)
            {
                Normal();
                chon = 0;
                dem = -1;
                gotoxy(120, 36);
                cout << --current_page;
                if (i < 50 && dem <= 24)
                    i = -1;
                else if (i > 49)
                    i = i - ((i % 25) + 26);
                xoa_man_hinh(5, 7, 128, 29);
            }
            else if (c == 13)
            {
                Normal();
                chon = 0;
                dem = -1;
                current_page = 1;
                if (i < 50 && dem <= 24)
                    i = -1;
                else if (i > 49)
                    i = i - ((i % 25) + 26);
                xoa_man_hinh(5, 7, 128, 29);
                gotoxy(114, 36);
                cout << "Trang 1 / " << page;
                huong_dan_xem_danh_sach();
            }
            khung_xuat_thong_tin_ds(5, 7, 28);
        }
        dem++;
    }
}
void Xuat_thong_tin_cac_dau_sach(DS_DAU_SACH ds_dau_sach)
{
    int vitri = 0;
    int chon = 0;
    int c;
    int dem = 0;
    int page;
    int current_page = 1;
    if (ds_dau_sach.so_luong % 25 == 0)
    {
        page = ds_dau_sach.so_luong / 25;
    }
    else
    {
        page = ds_dau_sach.so_luong / 25 + 1;
    }
    gotoxy(114, 36);
    cout << "Trang " << current_page << " / " << page;
    huong_dan_xem_danh_sach();
    khung_xuat_thong_tin_ds(5, 7, 28);
    for (int i = 0; i < ds_dau_sach.so_luong; i++)
    {
        //chon=0;
        vitri = 0;
        if (dem == 0)
            SetColor(26);
        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[i], 10, dem);
        Normal();
        if (dem == 24 || i == ds_dau_sach.so_luong - 1)
        {
            do
            {
                c = getch();
                if (c == 0)
                    c = getch();
                switch (c)
                {
                case 80:
                    if (vitri + 1 < 25 && chon < ds_dau_sach.so_luong - 1)
                    {
                        Normal();
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        chon++;
                        vitri++;
                        SetColor(26);
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        gotoxy(10, 5);
                    }
                    break;
                case 72:
                    if (vitri + 1 > 1)
                    {
                        Normal();
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        chon--;
                        vitri--;
                        SetColor(26);
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        gotoxy(10, 5);
                    }
                    break;
                case 13:
                    Normal();
                    xoa_man_hinh(5, 7, 128, 30);
                    gotoxy(30, 10);
                    cout << "Ten sach: " << ds_dau_sach.list[chon]->Ten_sach;
                    gotoxy(60, 12);
                    cout << "DANH MUC SACH";
                    khung_xuat_dms(27, 13, 20);
                    Xuat_dms_cua_1_dau_sach(ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach, 16);
                    thong_bao(" ");
                    break;
                case 77:
                    if (i == ds_dau_sach.so_luong - 1)
                        c = 0;
                    break;
                case 75:
                    if (i == 24)
                        c = 0;
                    break;
                case 27:
                    Normal();
                    return;
                }
            } while (c != 77 && c != 75 && c != 13);
            if (c == 77 && i < ds_dau_sach.so_luong - 1)
            {
                Normal();
                chon = 25;
                dem = -1;
                gotoxy(120, 36);
                cout << ++current_page;
                xoa_man_hinh(5, 7, 128, 29);
            }
            else if (c == 75 && i > 24)
            {
                Normal();
                chon = 0;
                dem = -1;
                gotoxy(120, 36);
                cout << --current_page;
                if (i < 50 && dem <= 24)
                    i = -1;
                else if (i > 49)
                    i = i - ((i % 25) + 26);
                xoa_man_hinh(5, 7, 128, 29);
            }
            else if (c == 13)
            {
                Normal();
                chon = 0;
                dem = -1;
                current_page = 1;
                if (i < 50 && dem <= 24)
                    i = -1;
                else if (i > 49)
                    i = i - ((i % 25) + 26);
                xoa_man_hinh(5, 7, 128, 29);
                gotoxy(114, 36);
                cout << "Trang 1 / " << page;
            }
            khung_xuat_thong_tin_ds(5, 7, 28);
        }
        dem++;
    }
}
// Danh muc sach
NODE_DANH_MUC_SACH *Khoi_tao_node(DANH_MUC_SACH dms)
{
    NODE_DANH_MUC_SACH *p = new NODE_DANH_MUC_SACH;
    if (p == NULL)
    {
        thong_bao("Khong du bo nho de cap phat.");
        return NULL;
    }
    else
    {
        p->pNext = NULL;
        p->data = dms;
        return p;
    }
}
void Them_vao_dau_danh_sach_dms(DS_DANH_MUC_SACH &ds_dms, NODE_DANH_MUC_SACH *p)
{
    if (ds_dms.pHead == NULL)
    {
        ds_dms.pHead = ds_dms.pTail = p;
    }
    else
    {
        p->pNext = ds_dms.pHead;
        ds_dms.pHead = p;
    }
}
void Them_vao_cuoi_danh_sach_dms(DS_DANH_MUC_SACH &ds_dms, NODE_DANH_MUC_SACH *p)
{
    if (ds_dms.pHead == NULL)
    {
        ds_dms.pHead = ds_dms.pTail = p;
    }
    else
    {
        ds_dms.pTail->pNext = p;
        ds_dms.pTail = p;
    }
}
void Xoa_dau_danh_sach_dms(DS_DANH_MUC_SACH &ds_dms)
{
    if (ds_dms.pHead == NULL)
    {
        return;
    }
    else
    {
        NODE_DANH_MUC_SACH *p = ds_dms.pHead;
        ds_dms.pHead = ds_dms.pHead->pNext;
        delete p;
    }
}
void Xoa_cuoi_danh_sach_dms(DS_DANH_MUC_SACH &ds_dms)
{
    if (ds_dms.pHead == NULL)
    {
        return;
    }
    else if (ds_dms.pHead == ds_dms.pTail)
    {
        Xoa_dau_danh_sach_dms(ds_dms);
    }
    else
    {
        for (NODE_DANH_MUC_SACH *k = ds_dms.pHead; k != NULL; k = k->pNext)
        {
            if (k->pNext == ds_dms.pTail)
            {
                delete ds_dms.pTail;
                k->pNext = NULL;
                ds_dms.pTail = k;
                return;
            }
        }
    }
}
void Xoa_1_sach_theo_ma_sach(DS_DANH_MUC_SACH &ds_dms, std::string a)
{
    if (ds_dms.pHead->data.Ma_sach == a)
    {
        Xoa_dau_danh_sach_dms(ds_dms);
    }
    if (ds_dms.pTail->data.Ma_sach == a)
    {
        Xoa_cuoi_danh_sach_dms(ds_dms);
    }
    NODE_DANH_MUC_SACH *g = new NODE_DANH_MUC_SACH;
    for (NODE_DANH_MUC_SACH *k = ds_dms.pHead; k != NULL; k = k->pNext)
    {
        if (k->data.Ma_sach == a)
        {
            g->pNext = k->pNext;
            delete k;
        }
        g = k;
    }
}
bool Kiem_tra_trung_ma_sach(DS_DANH_MUC_SACH ds_dms, std::string masach)
{
    for (NODE_DANH_MUC_SACH *k = ds_dms.pHead; k != NULL; k = k->pNext)
    {
        if (k->data.Ma_sach == masach)
        {
            return true;
        }
    }
    return false;
}
void Them_sach(DS_DANH_MUC_SACH &ds_dms, DS_DAU_SACH ds_dau_sach)
{
    int vitri = 0;
    int chon = 0;
    int c;
    int dem = 0;
    int page;
    int current_page = 1;
    if (ds_dau_sach.so_luong % 25 == 0)
    {
        page = ds_dau_sach.so_luong / 25;
    }
    else
    {
        page = ds_dau_sach.so_luong / 25 + 1;
    }
    gotoxy(114, 36);
    cout << "Trang " << current_page << " / " << page;
    huong_dan_xem_danh_sach();
    khung_xuat_thong_tin_ds(5, 7, 28);
    for (int i = 0; i < ds_dau_sach.so_luong; i++)
    {
        vitri = 0;
        if (dem == 0)
            SetColor(26);
        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[i], 10, dem);
        Normal();
        if (dem == 24 || i == ds_dau_sach.so_luong - 1)
        {
            do
            {
                c = getch();
                if (c == 0)
                    c = getch();
                switch (c)
                {
                case 80:
                    if (vitri + 1 < 25 && chon < ds_dau_sach.so_luong - 1)
                    {
                        Normal();
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        chon++;
                        vitri++;
                        SetColor(26);
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        gotoxy(10, 5);
                    }
                    break;
                case 72:
                    if (vitri + 1 > 1)
                    {
                        Normal();
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        chon--;
                        vitri--;
                        SetColor(26);
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                        gotoxy(10, 5);
                    }
                    break;
                case 13:
                    Normal();
                    xoa_man_hinh(5, 7, 128, 30);
                    gotoxy(59, 11);
                    cout << "THONG TIN SACH";
                    khung_xuat_thong_tin_ds(5, 13, 4);
                    Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 16, 0);
                    huong_dan_them_sach_vao_dau_sach();
                    ShowCur(0);
                    while (true)
                    {
                        if (kbhit())
                        {
                            char key2 = getch();
                            if (key2 == 13)
                            {
                                ShowCur(1);
                                gotoxy(30, 20);
                                textcolor(11);
                                int n;
                                cout << "Nhap so luong sach can them: ";
                                Normal();
                                Nhap_so(n, 59, 20);
                                if (n == 0)
                                    break;
                                for (int j = 0; j < n; j++)
                                {
                                    int stt = ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach.so_luong;
                                    DANH_MUC_SACH dms;
                                    // Danh ma tu dong
                                    // masach = ISBN + stt. VD: AAAA1, AAAA2, AAAA3,...
                                    std::string masach = ds_dau_sach.list[chon]->ISBN + to_string(stt); // to_string: Chuyen kieu int thanh string. Neu Dev-C++ khong dung duoc: Tools -> Compiler options...-> Settings -> Code Generation -> Language Standard -> Doi thanh ISO C++11 hoac GNU C++11
                                    // Neu ma trung thi tu dong tang len
                                    while (Kiem_tra_trung_ma_sach(ds_dms, masach) == true)
                                    {
                                        stt++;
                                        masach = ds_dau_sach.list[chon]->ISBN + to_string(stt);
                                    }
                                    dms.Ma_sach = masach;
                                    gotoxy(30, 24);
                                    cout << "Ma sach: " << dms.Ma_sach;
                                    dms.Trang_thai = 0;
                                    gotoxy(30, 26);
                                    cout << "Trang thai: " << dms.Trang_thai << " (Cho muon duoc)";
                                    gotoxy(30, 28);
                                    cout << "Nhap vi tri: ";
                                    Nhap_va_kiem_tra_bo_trong_du_lieu(dms.Vi_tri, 43, 28);
                                    NODE_DANH_MUC_SACH *p = Khoi_tao_node(dms);
                                    Them_vao_cuoi_danh_sach_dms(ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach, p);
                                    ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach.so_luong++;
                                    ds_dau_sach.list[chon]->Check = true; // <=> Dau sach nay hien tai da co sach => Khong duoc xoa
                                    gotoxy(30, 21);
                                    textcolor(11);
                                    cout << "So sach da them";
                                    gotoxy(57, 21);
                                    cout << ": ";
                                    Normal();
                                    cout << j + 1;
                                    thong_bao("Them thanh cong.");
                                    xoa_man_hinh(42, 28, 20, 1);
                                    if (j == n - 1)
                                    {
                                        break;
                                    }
                                }
                                if (key2 == 13)
                                    break;
                            }
                            else if (key2 == 27)
                            {
                                break;
                            }
                        }
                    }
                    break;
                case 77:
                    if (i == ds_dau_sach.so_luong - 1)
                        c = 0;
                    break;
                case 75:
                    if (i == 24)
                        c = 0;
                    break;
                case 27:
                    Normal();
                    return;
                }
            } while (c != 77 && c != 75 && c != 13);
            if (c == 77 && i < ds_dau_sach.so_luong - 1)
            {
                Normal();
                chon = 25;
                dem = -1;
                gotoxy(120, 36);
                cout << ++current_page;
                xoa_man_hinh(5, 7, 128, 29);
            }
            else if (c == 75 && i > 24)
            {
                Normal();
                chon = 0;
                dem = -1;
                gotoxy(120, 36);
                cout << --current_page;
                if (i < 50 && dem <= 24)
                    i = -1;
                else if (i > 49)
                    i = i - ((i % 25) + 26);
                xoa_man_hinh(5, 7, 128, 29);
            }
            else if (c == 13)
            {
                ShowCur(0);
                Normal();
                chon = 0;
                dem = -1;
                current_page = 1;
                if (ds_dau_sach.so_luong % 25 == 0)
                {
                    page = ds_dau_sach.so_luong / 25;
                }
                else
                {
                    page = ds_dau_sach.so_luong / 25 + 1;
                }
                if (i < 50 && dem <= 24)
                    i = -1;
                else if (i > 49)
                    i = i - ((i % 25) + 26);
                xoa_man_hinh(5, 7, 128, 30);
                gotoxy(114, 36);
                cout << "Trang 1 / " << page;
            }
            khung_xuat_thong_tin_ds(5, 7, 28);
        }
        dem++;
    }
}
void Xoa_sach(DS_DANH_MUC_SACH &ds_dms, DS_DAU_SACH ds_dau_sach)
{
    int vitri = 0;
    int chon = 0;
    int c;
    int dem = 0;
    int page;
    int current_page = 1;
    if (ds_dau_sach.so_luong % 25 == 0)
    {
        page = ds_dau_sach.so_luong / 25;
    }
    else
    {
        page = ds_dau_sach.so_luong / 25 + 1;
    }
    huong_dan_xem_danh_sach();
    if (ds_dau_sach.so_luong == 0)
    {
        thong_bao("Chua co dau sach nao.");
        return;
    }
    else
    {
        gotoxy(114, 36);
        cout << "Trang " << current_page << " / " << page;
        khung_xuat_thong_tin_ds(5, 7, 28);
        for (int i = 0; i < ds_dau_sach.so_luong; i++)
        {
            vitri = 0;
            if (dem == 0)
                SetColor(26);
            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[i], 10, dem);
            Normal();
            if (dem == 24 || i == ds_dau_sach.so_luong - 1)
            {
                do
                {
                    std::string a;
                    c = getch();
                    if (c == 0)
                        c = getch();
                    switch (c)
                    {
                    case 80:
                        if (vitri + 1 < 25 && chon < ds_dau_sach.so_luong - 1)
                        {
                            Normal();
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                            chon++;
                            vitri++;
                            SetColor(26);
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                            gotoxy(10, 5);
                        }
                        break;
                    case 72:
                        if (vitri + 1 > 1)
                        {
                            Normal();
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                            chon--;
                            vitri--;
                            SetColor(26);
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                            gotoxy(10, 5);
                        }
                        break;
                    case 13:
                        Normal();
                        xoa_man_hinh(5, 7, 128, 30);
                        gotoxy(30, 10);
                        cout << "Ten sach: " << ds_dau_sach.list[chon]->Ten_sach;
                        gotoxy(60, 12);
                        cout << "DANH MUC SACH";
                        khung_xuat_dms(27, 13, 20);
                        Xuat_dms_cua_1_dau_sach(ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach, 16);
                        huong_dan_chinh_sua_sach();
                        gotoxy(30, 35);
                        cout << "Nhap ma sach: ";
                        ShowCur(0);
                        while (true)
                        {
                            if (kbhit())
                            {
                                char key2 = getch();
                                if (key2 == 13)
                                {
                                    ShowCur(1);
                                    Nhap_va_kiem_tra_bo_trong_du_lieu(a, 44, 35);
                                    if (Kiem_tra_trung_ma_sach(ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach, a) == false)
                                    {
                                        thong_bao("Ma sach khong ton tai.");
                                        break;
                                    }
                                    else
                                    {
                                        for (NODE_DANH_MUC_SACH *k = ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach.pHead; k != NULL; k = k->pNext)
                                        {
                                            if (k->data.Ma_sach == a && k->data.Trang_thai == 1)
                                            {
                                                thong_bao("Sach hien da co nguoi muon. Khong the xoa.");
                                                dem = -1;
                                                break;
                                            }
                                        }
                                        if (dem == -1)
                                        {
                                            break;
                                        }
                                        textcolor(11);
                                        gotoxy(60, 36);
                                        cout << "XAC NHAN XOA";
                                        Normal();
                                        while (true)
                                        {
                                            if (kbhit())
                                            {
                                                int key3 = getch();
                                                if (key3 == 0)
                                                    key3 = getch();
                                                if (key3 == 13)
                                                {
                                                    Xoa_1_sach_theo_ma_sach(ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach, a);
                                                    ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach.so_luong--;
                                                    if (ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach.so_luong == 0)
                                                    {
                                                        ds_dau_sach.list[chon]->Check = false; // <=> Dau sach nay hien tai khong con sach. Co the xoa
                                                    }
                                                    thong_bao("Xoa thanh cong.");
                                                    dem = -1;
                                                    break;
                                                }
                                                else if (key3 == 27)
                                                {
                                                    dem = -1;
                                                    break;
                                                }
                                            }
                                        }
                                        if (dem == -1)
                                        {
                                            break;
                                        }
                                    }
                                }
                                else if (key2 == 27)
                                {
                                    break;
                                }
                            }
                        }
                        break;
                    case 77:
                        if (i == ds_dau_sach.so_luong - 1)
                            c = 0;
                        break;
                    case 75:
                        if (i == 24)
                            c = 0;
                        break;
                    case 27:
                        Normal();
                        return;
                    }
                } while (c != 77 && c != 75 && c != 13);
                if (c == 77 && i < ds_dau_sach.so_luong - 1)
                {
                    Normal();
                    chon = 25;
                    dem = -1;
                    gotoxy(120, 36);
                    cout << ++current_page;
                    xoa_man_hinh(5, 7, 128, 29);
                }
                else if (c == 75 && i > 24)
                {
                    Normal();
                    chon = 0;
                    dem = -1;
                    gotoxy(120, 36);
                    cout << --current_page;
                    if (i < 50 && dem <= 24)
                        i = -1;
                    else if (i > 49)
                        i = i - ((i % 25) + 26);
                    xoa_man_hinh(5, 7, 128, 29);
                }
                else if (c == 13)
                {
                    ShowCur(0);
                    Normal();
                    chon = 0;
                    dem = -1;
                    current_page = 1;
                    if (ds_dau_sach.so_luong % 25 == 0)
                    {
                        page = ds_dau_sach.so_luong / 25;
                    }
                    else
                    {
                        page = ds_dau_sach.so_luong / 25 + 1;
                    }
                    if (i < 50 && dem <= 24)
                        i = -1;
                    else if (i > 49)
                        i = i - ((i % 25) + 26);
                    xoa_man_hinh(5, 7, 128, 30);
                    gotoxy(114, 36);
                    cout << "Trang 1 / " << page;
                }
                khung_xuat_thong_tin_ds(5, 7, 28);
            }
            dem++;
        }
    }
}
void Hieu_chinh_sach(DS_DANH_MUC_SACH &ds_dms, DS_DAU_SACH ds_dau_sach)
{
    int vitri = 0;
    int chon = 0;
    int c;
    int dem = 0;
    int page;
    int current_page = 1;
    if (ds_dau_sach.so_luong % 25 == 0)
    {
        page = ds_dau_sach.so_luong / 25;
    }
    else
    {
        page = ds_dau_sach.so_luong / 25 + 1;
    }
    huong_dan_xem_danh_sach();
    if (ds_dau_sach.so_luong == 0)
    {
        thong_bao("Chua co dau sach nao.");
        return;
    }
    else
    {
        gotoxy(114, 36);
        cout << "Trang " << current_page << " / " << page;
        khung_xuat_thong_tin_ds(5, 7, 28);
        for (int i = 0; i < ds_dau_sach.so_luong; i++)
        {
            vitri = 0;
            if (dem == 0)
                SetColor(26);
            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[i], 10, dem);
            Normal();
            if (dem == 24 || i == ds_dau_sach.so_luong - 1)
            {
                do
                {
                    std::string a;
                    c = getch();
                    if (c == 0)
                        c = getch();
                    switch (c)
                    {
                    case 80:
                        if (vitri + 1 < 25 && chon < ds_dau_sach.so_luong - 1)
                        {
                            Normal();
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                            chon++;
                            vitri++;
                            SetColor(26);
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                            gotoxy(10, 5);
                        }
                        break;
                    case 72:
                        if (vitri + 1 > 1)
                        {
                            Normal();
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                            chon--;
                            vitri--;
                            SetColor(26);
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[chon], 10, vitri);
                            gotoxy(10, 5);
                        }
                        break;
                    case 13:
                        Normal();
                        xoa_man_hinh(5, 7, 128, 30);
                        gotoxy(30, 10);
                        cout << "Ten sach: " << ds_dau_sach.list[chon]->Ten_sach;
                        gotoxy(60, 12);
                        cout << "DANH MUC SACH";
                        khung_xuat_dms(27, 13, 20);
                        Xuat_dms_cua_1_dau_sach(ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach, 16);
                        huong_dan_chinh_sua_sach();
                        gotoxy(30, 35);
                        cout << "Nhap ma sach: ";
                        ShowCur(0);
                        while (true)
                        {
                            if (kbhit())
                            {
                                char key2 = getch();
                                if (key2 == 13)
                                {
                                    ShowCur(1);
                                    Nhap_va_kiem_tra_bo_trong_du_lieu(a, 44, 35);
                                    if (Kiem_tra_trung_ma_sach(ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach, a) == false)
                                    {
                                        thong_bao("Ma sach khong ton tai.");
                                        break;
                                    }
                                    for (NODE_DANH_MUC_SACH *k = ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach.pHead; k != NULL; k = k->pNext)
                                    {
                                        if (k->data.Ma_sach == a)
                                        {
                                            xoa_man_hinh(27, 12, 85, 25);
                                            gotoxy(30, 9);
                                            cout << "                                       ";
                                            gotoxy(30, 9);
                                            cout << "Ma sach: " << k->data.Ma_sach;
                                            gotoxy(30, 12);
                                            cout << "0: Cho muon duoc";
                                            gotoxy(30, 13);
                                            cout << "1: Da co nguoi muon";
                                            gotoxy(30, 14);
                                            cout << "2: Sach da thanh ly";
                                            gotoxy(30, 16);
                                            cout << "Nhap trang thai sach(0/1/2): " << k->data.Trang_thai;
                                            gotoxy(30, 18);
                                            cout << "Nhap vi tri moi: " << k->data.Vi_tri;
                                            ShowCur(0);
                                            while (true)
                                            {
                                                if (kbhit())
                                                {
                                                    char key3 = getch();
                                                    if (key3 == 13)
                                                    {
                                                        ShowCur(1);
                                                        do
                                                        {
                                                            xoa_man_hinh(59, 16, 70, 1);
                                                            gotoxy(59, 16);
                                                            Nhap_so(k->data.Trang_thai, 59, 16);
                                                            if (k->data.Trang_thai != 0 && k->data.Trang_thai != 1 && k->data.Trang_thai != 2)
                                                            {
                                                                thong_bao("Trang thai khong hop le, xin nhap lai.");
                                                                xoa_man_hinh(59, 16, 70, 1);
                                                                gotoxy(59, 16);
                                                            }
                                                        } while (k->data.Trang_thai != 0 && k->data.Trang_thai != 1 && k->data.Trang_thai != 2);
                                                        std::string tam = k->data.Vi_tri;
                                                        xoa_man_hinh(47, 18, 60, 1);
                                                        gotoxy(47, 18);
                                                        Nhap_va_kiem_tra_bo_trong_du_lieu_chinh_sua(k->data.Vi_tri, 47, 18);
                                                        if (k->data.Vi_tri == "")
                                                        {
                                                            k->data.Vi_tri = tam;
                                                        }
                                                        gotoxy(47, 18);
                                                        cout << k->data.Vi_tri;
                                                        thong_bao("Hieu chinh thanh cong.");
                                                        xoa_man_hinh(44, 35, 20, 1);
                                                        dem = -1;
                                                        break;
                                                    }
                                                    else if (key3 == 27)
                                                    {
                                                        dem = -1;
                                                        break;
                                                    }
                                                }
                                            }
                                            if (dem == -1)
                                            {
                                                Normal();
                                                xoa_man_hinh(5, 7, 128, 30);
                                                gotoxy(30, 10);
                                                cout << "Ten sach: " << ds_dau_sach.list[chon]->Ten_sach;
                                                gotoxy(60, 12);
                                                cout << "DANH MUC SACH";
                                                khung_xuat_dms(27, 13, 20);
                                                Xuat_dms_cua_1_dau_sach(ds_dau_sach.list[chon]->ds_danh_muc_sach_cua_dau_sach, 16);
                                                gotoxy(30, 35);
                                                cout << "Nhap ma sach: ";
                                                ShowCur(0);
                                            }
                                        }
                                    }
                                }
                                else if (key2 == 27)
                                {
                                    break;
                                }
                            }
                        }
                        break;
                    case 77:
                        if (i == ds_dau_sach.so_luong - 1)
                            c = 0;
                        break;
                    case 75:
                        if (i == 24)
                            c = 0;
                        break;
                    case 27:
                        Normal();
                        return;
                    }
                } while (c != 77 && c != 75 && c != 13);
                if (c == 77 && i < ds_dau_sach.so_luong - 1)
                {
                    Normal();
                    chon = 25;
                    dem = -1;
                    gotoxy(120, 36);
                    cout << ++current_page;
                    xoa_man_hinh(5, 7, 128, 29);
                }
                else if (c == 75 && i > 24)
                {
                    Normal();
                    chon = 0;
                    dem = -1;
                    gotoxy(120, 36);
                    cout << --current_page;
                    if (i < 50 && dem <= 24)
                        i = -1;
                    else if (i > 49)
                        i = i - ((i % 25) + 26);
                    xoa_man_hinh(5, 7, 128, 29);
                }
                else if (c == 13)
                {
                    ShowCur(0);
                    Normal();
                    chon = 0;
                    dem = -1;
                    current_page = 1;
                    if (ds_dau_sach.so_luong % 25 == 0)
                    {
                        page = ds_dau_sach.so_luong / 25;
                    }
                    else
                    {
                        page = ds_dau_sach.so_luong / 25 + 1;
                    }
                    if (i < 50 && dem <= 24)
                        i = -1;
                    else if (i > 49)
                        i = i - ((i % 25) + 26);
                    xoa_man_hinh(5, 7, 128, 30);
                    gotoxy(114, 36);
                    cout << "Trang 1 / " << page;
                }
                khung_xuat_thong_tin_ds(5, 7, 28);
            }
            dem++;
        }
    }
}

// Sap xep
void Sap_Xep_Dau_Sach_Theo_Ten(DS_DAU_SACH &dau_sach)
{
    DAU_SACH *tam = NULL;
    for (int i = 0; i < dau_sach.so_luong - 1; i++)
    {
        for (int j = i + 1; j <= dau_sach.so_luong - 1; j++)
        {
            if (dau_sach.list[i]->Ten_sach > dau_sach.list[j]->Ten_sach)
            {
                tam = dau_sach.list[i];
                dau_sach.list[i] = dau_sach.list[j];
                dau_sach.list[j] = tam;
            }
        }
    }
}
bool Kiem_Tra_Trung_The_Loai(DS_DAU_SACH ds, std::string theloai[], int soluong[], int h, int i) // h: So luong the loai hien co
{
    for (int j = 0; j < h; j++) // Duyet danh sach so luong the loai hien co
    {
        if (ds.list[i]->The_loai == theloai[j])
        {
            soluong[j]++; //tang so luong phan tu cua 1 the loai them 1
            return false;
        }
    }
    return true;
}
void Xuat_DS_Theo_Tung_The_Loai(DS_DAU_SACH ds)
{
    int c;
    if (ds.so_luong == 0)
    {
        thong_bao("Thu vien chua co sach nao.");
        return;
    }
    Sap_Xep_Dau_Sach_Theo_Ten(ds);
    std::string the_loai[100];          // Tao 1 mang chua toi da 100 the loai
    int soluong[100];                   // So luong sach cua tung the loai
    int h = 0;                          // So luong the loai hien co
    the_loai[0] = ds.list[0]->The_loai; // The loai dau tien = the loai cua dau sach dau tien trong danh sach dau sach
    h = 1;
    for (int i = 1; i < ds.so_luong; i++)
    {
        if (Kiem_Tra_Trung_The_Loai(ds, the_loai, soluong, h, i))
        {
            the_loai[h++] = ds.list[i]->The_loai;
        }
    }
    khung_xuat_thong_tin_ds(5, 7, 28);
    int dem_hang = 0;
    int dem_ds = 0;
    int page;
    int current_page = 1;
    if (ds.so_luong % 25 == 0)
    {
        page = ds.so_luong / 25;
    }
    else
    {
        page = ds.so_luong / 25 + 1;
    }
    gotoxy(114, 36);
    cout << "Trang " << current_page << " / " << page;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < ds.so_luong; j++)
        {
            if (ds.list[j]->The_loai == the_loai[i])
            {
                Xuat_thong_tin_1_dau_sach_theo_hang(ds.list[j], 10, dem_hang);
                dem_hang++;
                dem_ds++;
            }

            if (dem_hang == 25 || dem_ds == ds.so_luong)
            {
                do
                {
                    if (kbhit())
                    {
                        c = getch();
                        if (c == 0)
                            c = getch();
                        if (c == 77 && dem_ds < ds.so_luong)
                        {
                            dem_hang = 0;
                            gotoxy(120, 36);
                            cout << ++current_page;
                            xoa_man_hinh(5, 7, 128, 29);
                            break;
                        }
                        if (c == 75 && dem_ds > 25)
                        {
                            dem_hang = 0;
                            dem_ds = 0;
                            i = 0;
                            j = -1;
                            gotoxy(120, 36);
                            cout << --current_page;
                            xoa_man_hinh(5, 7, 128, 29);
                            break;
                        }
                        if (c == 27 || c == 13)
                        {
                            break;
                        }
                    }
                } while (1);
                if (c == 27 || c == 13)
                {
                    huong_dan();
                    return;
                }
                khung_xuat_thong_tin_ds(5, 7, 28);
            }
        }
    }
}
void Tim_thong_tin_sach_dua_vao_ten_sach(DS_DAU_SACH ds_dau_sach, DS_DANH_MUC_SACH ds_dms)
{
    huong_dan_nhap_dau_sach();
    ShowCur(0);
    std::string a;
    gotoxy(30, 8);
    cout << "Nhap ten sach can tim kiem: ";
    while (true)
    {
        if (kbhit())
        {
            char key = getch();
            if (key == 13)
            {
                ShowCur(1);
                Nhap_va_kiem_tra_bo_trong_du_lieu(a, 58, 8);
                Chuan_hoa_chu(a);
                gotoxy(60, 10);
                cout << "THONG TIN SACH";
                khung_xuat_thong_tin_ds(5, 11, 4);
                int i = 0;
                for (; i < ds_dau_sach.so_luong; i++)
                {
                    if (ds_dau_sach.list[i]->Ten_sach == a)
                    {
                        Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[i], 14, 0);
                        gotoxy(60, 17);
                        cout << "DANH MUC SACH";
                        khung_xuat_dms(27, 18, 16);
                        Xuat_dms_cua_1_dau_sach(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach, 21);
                        break;
                    }
                }
                if (i == ds_dau_sach.so_luong)
                {
                    thong_bao("Dau sach khong ton tai.");
                    return;
                }
                thong_bao(" ");
                return;
            }
            else if (key == 27)
            {
                return;
            }
        }
    }
}
void Sap_xep_dau_sach_tang_dan_theo_so_lan_muon(DS_DAU_SACH &ds_dau_sach)
{
    for (int i = 0; i < ds_dau_sach.so_luong - 1; i++)
    {
        for (int j = i + 1; j <= ds_dau_sach.so_luong - 1; j++)
        {
            if (ds_dau_sach.list[i]->So_lan_muon > ds_dau_sach.list[j]->So_lan_muon)
            {
                DAU_SACH *t = ds_dau_sach.list[i];
                ds_dau_sach.list[i] = ds_dau_sach.list[j];
                ds_dau_sach.list[j] = t;
            }
        }
    }
}
void Top_10_sach(DS_DAU_SACH ds_dau_sach)
{
    Sap_xep_dau_sach_tang_dan_theo_so_lan_muon(ds_dau_sach);
    int vitri = 0;
    int c;
    int dem = 0;
    huong_dan_top_10();
    khung_xuat_thong_tin_ds(5, 7, 13);
    if (ds_dau_sach.so_luong < 10)
    {
        for (int i = ds_dau_sach.so_luong - 1; i >= 0; i--)
        {
            if (dem == 0)
                SetColor(26);
            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[i], 10, dem);
            Normal();
            if (dem == ds_dau_sach.so_luong - 1)
            {
                do
                {
                    c = getch();
                    if (c == 0)
                        c = getch();
                    switch (c)
                    {
                    case 80:
                        if (vitri + 1 < ds_dau_sach.so_luong)
                        {
                            Normal();
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[ds_dau_sach.so_luong - 1 - vitri], 10, vitri);
                            vitri++;
                            SetColor(26);
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[ds_dau_sach.so_luong - 1 - vitri], 10, vitri);
                        }
                        break;
                    case 72:
                        if (vitri + 1 > 1)
                        {
                            Normal();
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[ds_dau_sach.so_luong - 1 - vitri], 10, vitri);
                            vitri--;
                            SetColor(26);
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[ds_dau_sach.so_luong - 1 - vitri], 10, vitri);
                        }
                        break;
                    case 13:
                        Normal();
                        xoa_man_hinh(5, 7, 128, 30);
                        gotoxy(30, 10);
                        cout << "Ten sach: " << ds_dau_sach.list[ds_dau_sach.so_luong - 1 - vitri]->Ten_sach;
                        gotoxy(60, 12);
                        cout << "DANH MUC SACH";
                        khung_xuat_dms(27, 13, 20);
                        Xuat_dms_cua_1_dau_sach(ds_dau_sach.list[ds_dau_sach.so_luong - 1 - vitri]->ds_danh_muc_sach_cua_dau_sach, 16);
                        thong_bao(" ");
                        break;
                    case 27:
                        Normal();
                        return;
                    }
                } while (c != 13);
                if (c == 13)
                {
                    Normal();
                    i = ds_dau_sach.so_luong;
                    vitri = 0;
                    dem = -1;
                    xoa_man_hinh(5, 7, 128, 29);
                }
                khung_xuat_thong_tin_ds(5, 7, 13);
            }
            dem++;
        }
    }
    else
    {
        for (int i = ds_dau_sach.so_luong - 1; i >= ds_dau_sach.so_luong - 10; i--)
        {
            if (dem == 0)
                SetColor(26);
            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[i], 10, dem);
            Normal();
            if (dem == 9)
            {
                do
                {
                    c = getch();
                    if (c == 0)
                        c = getch();
                    switch (c)
                    {
                    case 80:
                        if (vitri + 1 < 10)
                        {
                            Normal();
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[ds_dau_sach.so_luong - 1 - vitri], 10, vitri);
                            vitri++;
                            SetColor(26);
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[ds_dau_sach.so_luong - 1 - vitri], 10, vitri);
                        }
                        break;
                    case 72:
                        if (vitri + 1 > 1)
                        {
                            Normal();
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[ds_dau_sach.so_luong - 1 - vitri], 10, vitri);
                            vitri--;
                            SetColor(26);
                            Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[ds_dau_sach.so_luong - 1 - vitri], 10, vitri);
                        }
                        break;
                    case 13:
                        Normal();
                        xoa_man_hinh(5, 7, 128, 30);
                        gotoxy(30, 10);
                        cout << "Ten sach: " << ds_dau_sach.list[ds_dau_sach.so_luong - 1 - vitri]->Ten_sach;
                        gotoxy(60, 12);
                        cout << "DANH MUC SACH";
                        khung_xuat_dms(27, 13, 20);
                        Xuat_dms_cua_1_dau_sach(ds_dau_sach.list[ds_dau_sach.so_luong - 1 - vitri]->ds_danh_muc_sach_cua_dau_sach, 16);
                        thong_bao(" ");
                        break;
                    case 27:
                        Normal();
                        return;
                    }
                } while (c != 13);
                if (c == 13)
                {
                    Normal();
                    i = ds_dau_sach.so_luong;
                    vitri = 0;
                    dem = -1;
                    xoa_man_hinh(5, 7, 128, 29);
                }
                khung_xuat_thong_tin_ds(5, 7, 13);
            }
            dem++;
        }
    }
}
#endif
