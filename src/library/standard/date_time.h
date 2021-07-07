#include "./validated_inp_num.h"
#include "./__init__.h"

#ifndef DATE_TIME_H
#define DATE_TIME_H

int Lay_nam_he_thong();
void Xuat_ngay_thang(NGAY_THANG date);
void Lay_ngay_gio_he_thong(NGAY_THANG &date);
int Khoang_cach_giua_2_ngay(NGAY_THANG date1);
const int NAM_MAX = Lay_nam_he_thong();

bool Nam_nhuan(int nam)
{
	if (nam % 400 == 0)
	{
		return true;
	}
	if (nam % 4 == 0 && nam % 100 != 0)
	{
		return true;
	}
	return false;
}
int Ngay_hop_le(NGAY_THANG date) // 0: ngay sai, 1: thang sai, 2: nam sai, 3: hop le
{
	if (date.Thang == 2)
	{
		if (Nam_nhuan(date.Nam) == true)
		{
			if (date.Ngay > 29)
			{
				return 0;
			}
		}
		else
		{
			if (date.Ngay > 28)
			{
				return 0;
			}
		}
	}
	if ((date.Thang == 4 || date.Thang == 6 || date.Thang == 9 || date.Thang == 11) && date.Ngay > 30)
	{
		return 0;
	}
	return 3;
}
void Nhap_ngay_thang(NGAY_THANG &date, int x, int y)
{

	Lay_ngay_gio_he_thong(date);
	huong_dan_nhap_ngay_thang();
	gotoxy(x, y);
	Xuat_ngay_thang(date);
	while (true)
	{
		if (kbhit())
		{
			char key = getch();
			if (key == 13)
			{
				return;
			}
			else if (key == 0)
			{
				key = getch();
				if (key == 59)
				{
					NGAY_THANG ngaytam;
					do
					{
						gotoxy(x - 11, y + 1);
						cout << "Ngay: ";
						gotoxy(x - 11, y + 2);
						cout << "Thang: ";
						gotoxy(x - 11, y + 3);
						cout << "Nam: ";
						ShowCur(1);
						do
						{
							gotoxy(x - 5, y + 1);
							Nhap_ngay(ngaytam.Ngay, x - 5, y + 1);
							if (ngaytam.Ngay < 1 || ngaytam.Ngay > 31)
							{
								thong_bao("Ngay khong hop le. Xin nhap lai.");
								xoa_man_hinh(x - 5, y + 1, 20, 1);
							}
						} while (ngaytam.Ngay < 1 || ngaytam.Ngay > 31);
						do
						{
							gotoxy(x - 4, y + 2);
							Nhap_thang(ngaytam.Thang, x - 4, y + 2);
							if (ngaytam.Thang < 1 || ngaytam.Thang > 12)
							{
								thong_bao("Thang khong hop le. Xin nhap lai.");
								xoa_man_hinh(x - 4, y + 2, 20, 1);
							}
						} while (ngaytam.Thang < 1 || ngaytam.Thang > 12);
						do
						{
							gotoxy(x - 6, y + 3);
							Nhap_nam(ngaytam.Nam, x - 6, y + 3);
							if (ngaytam.Nam > NAM_MAX || ngaytam.Nam < NAM_MIN)
							{
								thong_bao("Nam khong hop le. Xin nhap lai.");
								xoa_man_hinh(x - 6, y + 3, 20, 1);
							}
						} while (ngaytam.Nam > NAM_MAX || ngaytam.Nam < NAM_MIN);
						if (Ngay_hop_le(ngaytam) == 0)
						{
							thong_bao("Ngay thang khong chinh xac. Xin nhap lai.");
							xoa_man_hinh(x - 5, y + 1, 20, 1);
							xoa_man_hinh(x - 4, y + 2, 20, 1);
							xoa_man_hinh(x - 6, y + 3, 20, 1);
						}
						if (Khoang_cach_giua_2_ngay(ngaytam) < 0)
						{
							thong_bao("Ngay thang khong the lon ngay hien tai. Xin kiem tra lai.");
							xoa_man_hinh(x - 5, y + 1, 20, 1);
							xoa_man_hinh(x - 4, y + 2, 20, 1);
							xoa_man_hinh(x - 6, y + 3, 20, 1);
						}
					} while (Ngay_hop_le(ngaytam) == 0 || Khoang_cach_giua_2_ngay(ngaytam) < 0);
					xoa_man_hinh(x, y, 20, 1);
					gotoxy(x, y);
					Xuat_ngay_thang(ngaytam);
					date.Ngay = ngaytam.Ngay;
					date.Thang = ngaytam.Thang;
					date.Nam = ngaytam.Nam;
					return;
				}
			}
		}
	}
}
void Xuat_ngay_thang(NGAY_THANG date)
{
	cout << date.Ngay << "/" << date.Thang << "/" << date.Nam;
}
void Lay_ngay_gio_he_thong(NGAY_THANG &date) // Muon biet ro hon len google search "Date va time C++"
{
	tm *Today;				   // Tao 1 struct thoi gian
	time_t ltime;			   // Tao 1 bien thuoc kieu du lieu time
	time(&ltime);			   // Tra ve so giay tinh tu epoch (00:00:00 1/1/1970 theo UTC)
	Today = localtime(&ltime); // Dua so giay o tren vao 1 cau truc thoi gian tm
	date.Ngay = Today->tm_mday;
	date.Thang = Today->tm_mon + 1;
	date.Nam = Today->tm_year + 1900;
}
int Lay_nam_he_thong() // Bat dieu kien khong cho nhap nam xuat ban lon hon nam hien tai
{
	tm *Today;
	time_t ltime;
	time(&ltime);
	Today = localtime(&ltime);
	return (Today->tm_year + 1900);
}
int Tinh_ngay(NGAY_THANG date) // http://mathforum.org/library/drmath/view/66535.html
{
	if (date.Thang < 3)
	{
		date.Nam--;
		date.Thang = date.Thang + 12;
	}
	return 365 * date.Nam + date.Nam / 4 - date.Nam / 100 + date.Nam / 400 + date.Ngay + (153 * date.Thang + 8) / 5;
}
int Khoang_cach_giua_2_ngay(NGAY_THANG date1)
{
	NGAY_THANG date2;
	Lay_ngay_gio_he_thong(date2);
	return (Tinh_ngay(date2) - Tinh_ngay(date1));
}
int So_ngay_muon(DS_MUON_TRA ds_mt)
{
	int max = 0;
	int ngay;
	for (NODE_MUON_TRA *k = ds_mt.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2) // Dang muon hoac lam mat sach ma chua den <=> Chua tra sach
		{
			ngay = Khoang_cach_giua_2_ngay(k->data.Ngay_muon);
			if (max < ngay)
			{
				max = ngay;
			}
		}
	}
	return max;
}
int Ngay_qua_han(DS_MUON_TRA ds_mt)
{
	int songaymuon = So_ngay_muon(ds_mt);
	return songaymuon - 7;
}

#endif /*DATE_TIME_H*/
