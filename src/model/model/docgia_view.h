#ifndef Xuatthongtin
#define Xuatthongtin

#include "./__init__.h"
#include "../../library/standard/date_time.h"
#include "../../library/graphic/graphic.h"

string Tra_ve_ten_sach(DS_DAU_SACH ds_dau_sach, string masach);

void Tinh_ngay_qua_han_cua_cac_doc_gia(TREE &t)
{
	if (t != NULL)
	{
		t->data.So_ngay_qua_han = Ngay_qua_han(t->data.ds_muon_tra_cua_doc_gia);
		Tinh_ngay_qua_han_cua_cac_doc_gia(t->pLeft);
		Tinh_ngay_qua_han_cua_cac_doc_gia(t->pRight);
	}
}
void Xuat_thong_tin_1_doc_gia_theo_hang(DOC_GIA dg, int dong_bat_dau, int dem)
{
	gotoxy(15, dong_bat_dau + dem);
	cout << dg.Ma_the;
	gotoxy(24, dong_bat_dau + dem);
	cout << dg.Ho << " " << dg.Ten;
	gotoxy(56, dong_bat_dau + dem);
	cout << dg.Phai;
	if (dg.Trang_thai_the == 0)
	{
		gotoxy(65, dong_bat_dau + dem);
		cout <<" Da bi khoa ";
	}
	else
	{
		gotoxy(65, dong_bat_dau + dem);
		cout <<" Dang hoat dong ";
	}
	gotoxy(90, dong_bat_dau + dem);
	cout << dg.So_luong_sach_dang_muon;
	gotoxy(101, dong_bat_dau + dem);
	cout << dg.ds_muon_tra_cua_doc_gia.so_luong;
	if (dg.So_ngay_qua_han < 0)
	{
		dg.So_ngay_qua_han = 0;
	}
	gotoxy(115, dong_bat_dau + dem);
	cout << dg.So_ngay_qua_han;
}
void Chuyen_doc_gia_sang_mang(TREE t, DOC_GIA a[], int &n)
{
	if (t == NULL) return;
	else
	{
		Chuyen_doc_gia_sang_mang(t->pLeft, a, n);
		a[n++] = t->data;
		Chuyen_doc_gia_sang_mang(t->pRight, a, n);
	}
}
void Sap_xep_doc_gia_theo_ma_the(TREE t, DOC_GIA a[], int &n) // Xuat theo the ma the tang dan
{
	Chuyen_doc_gia_sang_mang(t, a, n);
	struct Element_Stack // Khai bao cau truc stack
	{
		int left, right;
	};
	Element_Stack Stack[MA_THE_MAX]; // So luong phan tu toi da cua stack
	int sp = 0;						 // Con tro cua stack
	int i, j, left, right;
	DOC_GIA pivot;
	Stack[0].left = 0;		// Chi so phan tu dau tien cua stack
	Stack[0].right = n - 1; // Chi so phan tu cuoi cung cua stack
	do
	{ // Lay left, right tu stack ra
		left = Stack[sp].left;
		right = Stack[sp].right;
		sp--; // Xoa 1 day phan tu khoi stack
		do
		{								   // Phan doan day con a[left],..., a[right] thanh 2 day a[left],...,(pivot),...,a[right]
			pivot = a[(left + right) / 2]; // Chon phan tu chinh giua cua day can sap xep lam pivot
			i = left;
			j = right;
			do
			{
				while (a[i].Ma_the < pivot.Ma_the)
				{
					i++; // Tim phan tu left dau tien >= pivot
				}
				while (a[j].Ma_the > pivot.Ma_the)
				{
					j--; // Tim phan tu right dau tien <= pivot
				}
				if (i <= j) // Doi cho 2 phan tu left right
				{
					DOC_GIA t = a[i];
					a[i] = a[j];
					a[j] = t;
					// Tang giam left, right de thuc hien tiep viec doi cho
					i++;
					j--;
				}
			} while (i <= j);
			if (i < right) // Phan thu 3 co tu 2 phan tu tro len
			{
				// Dua vao stack chi so dau va chi so cuoi cua phan thu 3
				sp++;
				Stack[sp].left = i;
				Stack[sp].right = right;
			}
			right = j; // Chuan bi vi tri de thiet lap phan co gia tri nho hon pivot
		} while (left < right);
	} while (sp != -1); // Ket thuc khi Stack rong
}
void Xuat_thong_tin_doc_gia_theo_ma_the(TREE t, DOC_GIA a[], DS_DOC_GIA ds_dg, int n)
{
	huong_dan_xem_theo_the_loai();
	Sap_xep_doc_gia_theo_ma_the(t, a, n);
	khung_xuat_thong_tin_dg(13, 7, 28);
	int dem = 0; //dem so hang danh sach xuat ra
	int c;
	int page;
	int current_page = 1;
	if (ds_dg.so_luong % 25 == 0)
	{
		page = ds_dg.so_luong / 25;
	}
	else
	{
		page = ds_dg.so_luong / 25 + 1;
	}
	gotoxy(114, 36);
	cout << "Trang " << current_page << " / " << page;
	for (int i = 0; i < ds_dg.so_luong; i++)
	{
		Xuat_thong_tin_1_doc_gia_theo_hang(a[i], 10, dem);
		if (dem == 24 || i == ds_dg.so_luong - 1)
		{
			do
			{
				if (kbhit())
				{
					c = getch();
					if (c == 0)
						c = getch();
					if (c == 77 && i < ds_dg.so_luong - 1) // neu chua xuat danh sach ra het thi cho phep bam mui ten qua phai
					{
						dem = -1;
						gotoxy(120, 36);
						cout << ++current_page;
						xoa_man_hinh(13, 7, 120, 29);
						break;
					}
					if (c == 75 && i > 24) // quay ve trang truoc do
					{
						dem = -1;
						gotoxy(120, 36);
						cout << --current_page;
						if (i < 50 && dem <= 24)
							i = -1;
						else if (i > 49)
							i = i - ((i % 25) + 26);
						xoa_man_hinh(13, 7, 120, 29);
						break;
					}
					if (c == 27)
					{
						break;
					}
				}
			} while (1);
			khung_xuat_thong_tin_dg(13, 7, 28);
			if (c == 27)
			{
				huong_dan();
				return;
			}
		}
		dem++;
	}
}
string Noi_ho_ten(string ten, string ho)
{
	string tam;
	tam = ten;
	for (int i = 0; i < ho.length(); i++)
	{
		tam.push_back(ho[i]); // Them ho vao sau ten. VD: Ten la "Phuc", Ho (+ chu lot) la "Pham Hoang" thi khi them vao se la Phuc Pham Hoang
	}
	return tam;
}
void Sap_xep_doc_gia_theo_ho_ten(TREE t, DOC_GIA a[], int &n)
{
	Chuyen_doc_gia_sang_mang(t, a, n);
	struct Element_Stack // Khai bao cau truc stack
	{
		int left, right;
	};
	Element_Stack Stack[MA_THE_MAX]; // So luong phan tu toi da cua stack
	int sp = 0;						 // Con tro cua stack
	int i, j, left, right;
	DOC_GIA pivot;
	Stack[0].left = 0;		// Chi so phan tu dau tien cua stack
	Stack[0].right = n - 1; // Chi so phan tu cuoi cung cua stack
	do
	{ // Lay left, right tu stack ra
		left = Stack[sp].left;
		right = Stack[sp].right;
		sp--; // Xoa 1 day phan tu khoi stack
		do
		{								   // Phan doan day con a[left],..., a[right] thanh 2 day a[left],...,(pivot),...,a[right]
			pivot = a[(left + right) / 2]; // Chon phan tu chinh giua cua day can sap xep lam pivot
			i = left;
			j = right;
			do
			{
				while (Noi_ho_ten(a[i].Ten, a[i].Ho) < Noi_ho_ten(pivot.Ten, pivot.Ho))
				{
					i++; // Tim phan tu left dau tien >= pivot
				}
				while (Noi_ho_ten(a[j].Ten, a[j].Ho) > Noi_ho_ten(pivot.Ten, pivot.Ho))
				{
					j--; // Tim phan tu right dau tien <= pivot
				}
				if (i <= j) // Doi cho 2 phan tu left right
				{
					DOC_GIA t = a[i];
					a[i] = a[j];
					a[j] = t;
					// Tang giam left, right de thuc hien tiep viec doi cho
					i++;
					j--;
				}
			} while (i <= j);
			if (i < right) // Phan thu 3 co tu 2 phan tu tro len
			{
				// Dua vao stack chi so dau va chi so cuoi cua phan thu 3
				sp++;
				Stack[sp].left = i;
				Stack[sp].right = right;
			}
			right = j; // Chuan bi vi tri de thiet lap phan co gia tri nho hon pivot
		} while (left < right);
	} while (sp != -1); // Ket thuc khi Stack rong
}
void Xuat_thong_tin_doc_gia_theo_ho_ten(TREE t, DOC_GIA a[], DS_DOC_GIA ds_dg, int n)
{
	int c;
	int dem = 0;
	huong_dan_xem_theo_the_loai();
	khung_xuat_thong_tin_dg(13, 7, 28);
	Sap_xep_doc_gia_theo_ho_ten(t, a, n);
	int page;
	int current_page = 1;
	if (ds_dg.so_luong % 25 == 0)
	{
		page = ds_dg.so_luong / 25;
	}
	else
	{
		page = ds_dg.so_luong / 25 + 1;
	}
	gotoxy(114, 36);
	cout << "Trang " << current_page << " / " << page;
	for (int i = 0; i < ds_dg.so_luong; i++)
	{
		Xuat_thong_tin_1_doc_gia_theo_hang(a[i], 10, dem);
		if (dem == 24 || i == ds_dg.so_luong - 1)
		{
			do
			{
				if (kbhit())
				{
					c = getch();
					if (c == 0)
						c = getch();
					if (c == 77 && i < ds_dg.so_luong - 1)
					{
						dem = -1;
						gotoxy(120, 36);
						cout << ++current_page;
						xoa_man_hinh(13, 7, 120, 29);
						break;
					}
					if (c == 75 && i > 24)
					{
						dem = -1;
						gotoxy(120, 36);
						cout << --current_page;
						if (i < 50 && dem <= 24)
							i = -1;
						else if (i > 49)
							i = i - ((i % 25) + 26);
						xoa_man_hinh(13, 7, 120, 29);
						break;
					}
					if (c == 27 || c == 13)
					{
						break;
					}
				}
			} while (1);
			khung_xuat_thong_tin_dg(13, 7, 28);
			if (c == 27 || c == 13)
			{
				huong_dan();
				return;
			}
		}
		dem++;
	}
}
void Xuat_danh_sach_sach_dang_muon_cua_1_doc_gia(DS_DAU_SACH ds_dau_sach, DS_MUON_TRA ds_mt, TREE t)
{
	gotoxy(20, 11);
	cout << "DANH SACH SACH DANG MUON CUA DOC GIA: " << t->data.Ho << " " << t->data.Ten << endl;
	khung_sach_dang_muon();
	int dem = 0;
	for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2)
		{
			string tensachtam;
			tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
			dem++;
			gotoxy(20, 14 + dem);
			cout << k->data.Ma_sach << "\t" << k->data.Ngay_muon.Ngay << "/" << k->data.Ngay_muon.Thang << "/" << k->data.Ngay_muon.Nam << "\t" << tensachtam;
			if (k->data.Trang_thai == 0)
			{
				gotoxy(96, 14 + dem);
				cout << k->data.Trang_thai << " (Dang muon)";
			}
			else if (k->data.Trang_thai == 2)
			{
				gotoxy(96, 14 + dem);
				cout << k->data.Trang_thai << " (Da lam mat)";
			}
		}
	}
}
void Liet_ke_danh_sach_sach_dang_muon_cua_1_doc_gia(DS_DAU_SACH ds_dau_sach, TREE t, int mathe)
{
	if (t != NULL)
	{
		if (mathe < t->data.Ma_the)
		{
			Liet_ke_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->pLeft, mathe);
		}
		else if (mathe > t->data.Ma_the)
		{
			Liet_ke_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->pRight, mathe);
		}
		else
		{
			if (t->data.ds_muon_tra_cua_doc_gia.so_luong == 0)
			{
				thong_bao("Doc gia van chua muon sach nao.");
				return;
			}
			Xuat_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->data.ds_muon_tra_cua_doc_gia, t);
			thong_bao(" ");
		}
	}
}
void Chuyen_doc_gia_qua_han_sang_mang(TREE t, DOC_GIA a[], int &n)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		Chuyen_doc_gia_qua_han_sang_mang(t->pLeft, a, n);
		if (t->data.So_ngay_qua_han > 0)
		{
			a[n++] = t->data;
		}
		Chuyen_doc_gia_qua_han_sang_mang(t->pRight, a, n);
	}
}
void Sap_xep_doc_gia_qua_han_theo_thoi_gian_giam_dan(TREE t, DOC_GIA a[], int &n)
{
	Chuyen_doc_gia_qua_han_sang_mang(t, a, n);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (a[i].So_ngay_qua_han < a[j].So_ngay_qua_han)
			{
				DOC_GIA t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}
void Xuat_danh_sach_doc_gia_qua_han_theo_thoi_gian_giam_dan(TREE t, DS_DOC_GIA ds_dg)
{
	int c;
	int dem = 0;
	huong_dan_xem_theo_the_loai();
	khung_xuat_thong_tin_dg(13, 7, 28);
	int n = 0;
	DOC_GIA *a = new DOC_GIA[ds_dg.so_luong];
	Sap_xep_doc_gia_qua_han_theo_thoi_gian_giam_dan(t, a, n);
	int page;
	int current_page = 1;
	if (n % 25 == 0)
	{
		page = n / 25;
	}
	else
	{
		page = n / 25 + 1;
	}
	gotoxy(114, 36);
	cout << "Trang " << current_page << " / " << page;
	for (int i = 0; i < n; i++)
	{
		Xuat_thong_tin_1_doc_gia_theo_hang(a[i], 10, dem);
		if (dem == 24 || i == n - 1)
		{
			do
			{
				if (kbhit())
				{
					c = getch();
					if (c == 0)
						c = getch();
					if (c == 77 && i < n - 1)
					{
						dem = -1;
						gotoxy(120, 36);
						cout << ++current_page;
						xoa_man_hinh(13, 7, 120, 29);
						break;
					}
					if (c == 75 && i > 24)
					{
						dem = -1;
						gotoxy(120, 36);
						cout << --current_page;
						if (i < 50 && dem <= 24)
							i = -1;
						else if (i > 49)
							i = i - ((i % 25) + 26);
						xoa_man_hinh(13, 7, 120, 29);
						break;
					}
					if (c == 27)
					{
						break;
					}
				}

			} while (1);
			khung_xuat_thong_tin_dg(13, 7, 28);
			if (c == 27)
			{
				huong_dan_xem_danh_sach();
				return;
			}
		}
		dem++;
	}
	delete[] a;
}
#endif
