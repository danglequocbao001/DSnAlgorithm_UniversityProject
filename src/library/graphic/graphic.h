#include "__init__.h"

#ifndef GRAPHIC_H
#define GRAPHIC_H

void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {
        x,
        y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void textcolor(int x)
{
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}
void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {
        1,
        CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}
void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
int whereX()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.X;
    return -1;
}
int whereY()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.Y;
    return -1;
}
void xoa_man_hinh(int x, int y, int rong, int cao)
{
    for (int i = 0; i < rong; i++)
    {
        for (int j = 0; j < cao; j++)
        {
            gotoxy(x + i, y + j);
            std::cout << SPACE;
        }
    }
}
void khung_vien()
{
    for (int i = 0; i <= 133; i++)
    {
        gotoxy(0 + i, 0);
        std::cout << char(219);
        gotoxy(0 + i, 40);
        std::cout << char(219);
    }
    for (int i = 1; i <= 40; i++)
    {
        gotoxy(0, 0 + i);
        std::cout << char(219);
        gotoxy(133, 0 + i);
        std::cout << char(219);
    }
    gotoxy(60, 2);
    std::cout << TITLE;
}
void khung_menu()
{
    for (int i = 0; i <= 37; i++)
    {
        gotoxy(49 + i, 4);
        std::cout << char(219);
        gotoxy(49 + i, 19);
        std::cout << char(219);
    }
    for (int i = 1; i <= 15; i++)
    {
        gotoxy(49, 4 + i);
        std::cout << char(219);
        gotoxy(86, 4 + i);
        std::cout << char(219);
    }
}
void huong_dan()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << TUTORIAL_KEY_BINDING;
}
void huong_dan_nhap_doc_gia()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << INPUT_ANOTATION;
}
void huong_dan_chinh_sua_doc_gia()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << ADJUST_ANOTIAION;
}
void huong_dan_xoa_doc_gia_1()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << INPUT_CODE_DELETION;
}
void huong_dan_xoa_doc_gia_2()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << DELETE_CONFIRMATION;
}
void huong_dan_xem_danh_sach_sach_dang_muon_doc_gia()
{
    xoa_man_hinh(2, 39, 110, 1);
    gotoxy(2, 39);
    std::cout << INPUT_CODE_DOCGIA;
}
void huong_dan_nhap_dau_sach()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << INPUT_INFO_BOOK;
}
void huong_dan_chinh_sua_sach()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << ADJUST_INFO_BOOK;
}
void huong_dan_them_sach_vao_dau_sach()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << INPUT_MORE;
}
void huong_dan_muon_sach()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << TUTORIAL_RENTING_BOOK;
}
void huong_dan_top_10()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << TOP_10;
}
void huong_dan_muon_sach_2()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << INPUT_CODE_BOOK;
}
void huong_dan_xem_danh_sach()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << READ_BOOK;
}

void huong_dan_tra_sach()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << SEARCH_BOOK;
}
void huong_dan_xem_theo_the_loai()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << READ_CATE;
}
void huong_dan_chinh_sua()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << ADJUSTING;
}
void huong_dan_nhap_ngay_thang()
{
    xoa_man_hinh(2, 39, 100, 1);
    gotoxy(2, 39);
    std::cout << ADJUST_DATETIME;
}
void Normal()
{
    SetColor(15);
    SetBGColor(0);
}
void HighLight()
{
    SetColor(15);
    SetBGColor(3);
}
void DeMuc(std::string s)
{
    gotoxy(51, 6);
    textcolor(14);
    std::cout << s;
    textcolor(15);
}
void ve_lai_man_hinh()
{
    system("cls");
    khung_vien();
    huong_dan();
}

void xoa_thong_bao()
{
    for (int i = 2; i < 120; i++)
    {
        gotoxy(i, 37);
        std::cout << SPACE;
    }
}
void thong_bao(std::string s)
{
    //ShowCur(0);
    xoa_thong_bao();
    gotoxy(3, 37);
    textcolor(10);
    std::cout << NOTIFICATION << s << SPACE;
    system("pause");
    textcolor(15);
    xoa_thong_bao();
}
void khung_xuat_thong_tin_dg(int x, int y, int chieu_cao)
{
    gotoxy(x + 2, y + 1);
    std::cout << MATHE;
    gotoxy(x + 14, y + 1);
    std::cout << HOTEN;
    gotoxy(x + 40, y + 1);
    std::cout << GIOTINH;
    gotoxy(x + 54, y + 1);
    std::cout << TRANGTHAITHE;
    gotoxy(x + 73, y + 1);
    std::cout << DANGMUON;
    gotoxy(x + 85, y + 1);
    std::cout << DAMUON;
    gotoxy(x + 95, y + 1);
    std::cout << PASTED_DATES;
    for (int i = 0; i < 110; i++)
    {
        gotoxy(x + 1 + i, y);
        std::cout << SEPARATER;
        gotoxy(x + 1 + i, y + 2);
        std::cout << SEPARATER;
        gotoxy(x + 1 + i, y + chieu_cao);
        std::cout << SEPARATER;
    }
    for (int i = 0; i < chieu_cao; i++)
    {
        gotoxy(x, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 9, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 38, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 50, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 71, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 83, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 93, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 111, y + 1 + i);
        std::cout << char(179);
    }
}
void khung_sach_dang_muon()
{
    gotoxy(20, 13);
    std::cout << "Ma sach \tNgay muon \tTen sach \t\t\t\t\tTrang thai sach";
    for (int i = 0; i < 93; i++)
    {
        gotoxy(19 + i, 12);
        std::cout << SEPARATER;
        gotoxy(19 + i, 14);
        std::cout << SEPARATER;
        gotoxy(19 + i, 18);
        std::cout << SEPARATER;
    }
    for (int i = 0; i < 6; i++)
    {
        gotoxy(18, 13 + i);
        std::cout << char(179);
        gotoxy(28, 13 + i);
        std::cout << char(179);
        gotoxy(43, 13 + i);
        std::cout << char(179);
        gotoxy(94, 13 + i);
        std::cout << char(179);
        gotoxy(112, 13 + i);
        std::cout << char(179);
    }
}
void khung_xuat_thong_tin_ds(int x, int y, int chieu_cao)
{
    gotoxy(x + 3, y + 1);
    std::cout << ISBN_;
    gotoxy(x + 23, y + 1);
    std::cout << TENSACH;
    gotoxy(x + 46, y + 1);
    std::cout << SOTRANG;
    gotoxy(x + 65, y + 1); //61
    std::cout << TACGIA;
    gotoxy(x + 84, y + 1);
    std::cout << NAMXUATBAN;
    gotoxy(x + 100, y + 1);
    std::cout << THELOAI;
    gotoxy(x + 113, y + 1);
    std::cout << LUOTMUON;
    for (int i = 0; i < 122; i++)
    {
        gotoxy(x + 1 + i, y);
        std::cout << SEPARATER;
        gotoxy(x + 1 + i, y + 2);
        std::cout << SEPARATER;
        gotoxy(x + 1 + i, y + chieu_cao);
        std::cout << SEPARATER;
    }
    for (int i = 0; i < chieu_cao; i++)
    {
        gotoxy(x, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 9, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 44, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 55, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 82, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 97, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 111, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 123, y + 1 + i);
        std::cout << char(179);
    }
}
void khung_xuat_dms(int x, int y, int chieu_cao)
{
    gotoxy(x + 2, y + 1);
    std::cout << MASACH;
    gotoxy(x + 27, y + 1);
    std::cout << VITRI;
    gotoxy(x + 60, y + 1);
    std::cout << TRANGTHAI;
    for (int i = 0; i < 79; i++)
    {
        gotoxy(x + 1 + i, y);
        std::cout << SEPARATER;
        gotoxy(x + 1 + i, y + 2);
        std::cout << SEPARATER;
        gotoxy(x + 1 + i, y + chieu_cao);
        std::cout << SEPARATER;
    }
    for (int i = 0; i < chieu_cao; i++)
    {
        gotoxy(x, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 10, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 50, y + 1 + i);
        std::cout << char(179);
        gotoxy(x + 80, y + 1 + i);
        std::cout << char(179);
    }
}

//menu chinh
extern char menu_chinh[so_item][50];
int MenuDong(char td[so_item][50])
{
    DeMuc("               MENU               ");
    khung_menu();
    Normal();
    int chon = 0;
    int i;
    for (i = 0; i < so_item; i++)
    {
        gotoxy(cot, dong + i);
        std::cout << td[i];
    }
    HighLight();
    gotoxy(cot, dong + chon);
    std::cout << td[chon];
    char kytu;
    do
    {
        kytu = getch();
        if (kytu == 0)
            kytu = getch();
        switch (kytu)
        {
        case 72:
            if (chon + 1 > 1)
            {
                Normal();
                gotoxy(cot, dong + chon);
                std::cout << td[chon];
                chon--;
                HighLight();
                gotoxy(cot, dong + chon);
                std::cout << td[chon];
            }
            break;
        case 80:
            if (chon + 1 < so_item)
            {
                Normal();
                gotoxy(cot, dong + chon);
                std::cout << td[chon];
                chon++;
                HighLight();
                gotoxy(cot, dong + chon);
                std::cout << td[chon];
            }
            break;
        case 13:
            return chon + 1;
        } // end switch
    } while (1);
}
//menu doc gia
extern char menu_dg[so_item_dg][50];
int MenuDongDG(char td[so_item_dg][50])
{
    DeMuc("             DOC GIA              ");
    khung_menu();

    Normal();
    int chon = 0;
    int i;
    for (i = 0; i < so_item_dg; i++)
    {
        gotoxy(cot_menu_dg, dong_menu_dg + i);
        std::cout << td[i];
    }
    HighLight();
    gotoxy(cot_menu_dg, dong_menu_dg + chon);
    std::cout << td[chon];
    char kytu;
    do
    {
        kytu = getch();
        if (kytu == 0)
            kytu = getch();
        switch (kytu)
        {
        case 72:
            if (chon + 1 > 1)
            {
                Normal();
                gotoxy(cot_menu_dg, dong_menu_dg + chon);
                std::cout << td[chon];
                chon--;
                HighLight();
                gotoxy(cot_menu_dg, dong_menu_dg + chon);
                std::cout << td[chon];
            }
            break;
        case 80:
            if (chon + 1 < so_item_dg)
            {
                Normal();
                gotoxy(cot_menu_dg, dong_menu_dg + chon);
                std::cout << td[chon];
                chon++;
                HighLight();
                gotoxy(cot_menu_dg, dong_menu_dg + chon);
                std::cout << td[chon];
            }
            break;
        case 13:
            return chon + 1;
        case 27:
            return 0;

        } // end switch
    } while (1);
}
//menu dau sach
extern char menu_ds[so_item_ds][50];
int MenuDongDS(char td[so_item_ds][50])
{
    DeMuc("             DAU SACH             ");
    khung_menu();

    Normal();
    int chon = 0;
    int i;
    for (i = 0; i < so_item_ds; i++)
    {
        gotoxy(cot_menu_ds, dong_menu_ds + i);
        std::cout << td[i];
    }
    HighLight();
    gotoxy(cot_menu_ds, dong_menu_ds + chon);
    std::cout << td[chon];
    char kytu;
    do
    {
        kytu = getch();
        if (kytu == 0)
            kytu = getch();
        switch (kytu)
        {
        case 72:
            if (chon + 1 > 1)
            {
                Normal();
                gotoxy(cot_menu_ds, dong_menu_ds + chon);
                std::cout << td[chon];
                chon--;
                HighLight();
                gotoxy(cot_menu_ds, dong_menu_ds + chon);
                std::cout << td[chon];
            }
            break;
        case 80:
            if (chon + 1 < so_item_ds)
            {
                Normal();
                gotoxy(cot_menu_ds, dong_menu_ds + chon);
                std::cout << td[chon];
                chon++;
                HighLight();
                gotoxy(cot_menu_ds, dong_menu_ds + chon);
                std::cout << td[chon];
            }
            break;
        case 13:
            return chon + 1;
        case 27:
            return 0;

        } // end switch
    } while (1);
}
//menu danh muc sach;
extern char menu_dms[so_item_dms][50];
int MenuDongDMS(char td[so_item_dms][50])
{
    DeMuc("          DANH MUC SACH           ");
    khung_menu();

    Normal();
    int chon = 0;
    int i;
    for (i = 0; i < so_item_dms; i++)
    {
        gotoxy(cot_menu_dms, dong_menu_dms + i);
        std::cout << td[i];
    }
    HighLight();
    gotoxy(cot_menu_dms, dong_menu_dms + chon);
    std::cout << td[chon];
    char kytu;
    do
    {
        kytu = getch();
        if (kytu == 0)
            kytu = getch();
        switch (kytu)
        {
        case 72:
            if (chon + 1 > 1)
            {
                Normal();
                gotoxy(cot_menu_dms, dong_menu_dms + chon);
                std::cout << td[chon];
                chon--;
                HighLight();
                gotoxy(cot_menu_dms, dong_menu_dms + chon);
                std::cout << td[chon];
            }
            break;
        case 80:
            if (chon + 1 < so_item_dms)
            {
                Normal();
                gotoxy(cot_menu_dms, dong_menu_dms + chon);
                std::cout << td[chon];
                chon++;
                HighLight();
                gotoxy(cot_menu_dms, dong_menu_dms + chon);
                std::cout << td[chon];
            }
            break;
        case 13:
            return chon + 1;
        case 27:
            return 0;

        } // end switch
    } while (1);
}
//menu muon tra
extern char menu_mt[so_item_mt][50];
int MenuDongMT(char td[so_item_mt][50])
{
    DeMuc("          MUON TRA SACH          ");
    khung_menu();

    Normal();
    int chon = 0;
    int i;
    for (i = 0; i < so_item_mt; i++)
    {
        gotoxy(cot_menu_mt, dong_menu_mt + i);
        std::cout << td[i];
    }
    HighLight();
    gotoxy(cot_menu_mt, dong_menu_mt + chon);
    std::cout << td[chon];
    char kytu;
    do
    {
        kytu = getch();
        if (kytu == 0)
            kytu = getch();
        switch (kytu)
        {
        case 72:
            if (chon + 1 > 1)
            {
                Normal();
                gotoxy(cot_menu_mt, dong_menu_mt + chon);
                std::cout << td[chon];
                chon--;
                HighLight();
                gotoxy(cot_menu_mt, dong_menu_mt + chon);
                std::cout << td[chon];
            }
            break;
        case 80:
            if (chon + 1 < so_item_mt)
            {
                Normal();
                gotoxy(cot_menu_mt, dong_menu_mt + chon);
                std::cout << td[chon];
                chon++;
                HighLight();
                gotoxy(cot_menu_mt, dong_menu_mt + chon);
                std::cout << td[chon];
            }
            break;
        case 13:
            return chon + 1;
        case 27:
            return 0;

        } // end switch
    } while (1);
}

//menu thoat
extern char menu_thoat[so_item_thoat][50];
int MenuDongTHOAT(char td[so_item_thoat][50])
{
    gotoxy(54, 23);
    std::cout << "LUU DU LIEU TRUOC KHI THOAT?";
    Normal();
    int chon = 0;
    int i;
    for (i = 0; i < so_item_thoat; i++)
    {
        gotoxy(cot_menu_thoat, dong_menu_thoat + i);
        std::cout << td[i];
    }
    HighLight();
    gotoxy(cot_menu_thoat, dong_menu_thoat + chon);
    std::cout << td[chon];
    char kytu;
    do
    {
        kytu = getch();
        if (kytu == 0)
            kytu = getch();
        switch (kytu)
        {
        case 72:
            if (chon + 1 > 1)
            {
                Normal();
                gotoxy(cot_menu_thoat, dong_menu_thoat + chon);
                std::cout << td[chon];
                chon--;
                HighLight();
                gotoxy(cot_menu_thoat, dong_menu_thoat + chon);
                std::cout << td[chon];
            }
            break;
        case 80:
            if (chon + 1 < so_item_thoat)
            {
                Normal();
                gotoxy(cot_menu_thoat, dong_menu_thoat + chon);
                std::cout << td[chon];
                chon++;
                HighLight();
                gotoxy(cot_menu_thoat, dong_menu_thoat + chon);
                std::cout << td[chon];
            }
            break;
        case 13:
            return chon + 1;
        case 27:
            return 0;

        } // end switch
    } while (1);
}

#endif /*GRAPHIC_H*/
