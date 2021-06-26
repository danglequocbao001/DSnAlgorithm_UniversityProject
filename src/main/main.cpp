#include <iostream>
#include <time.h>
#include <algorithm>
#include "./mylib.h"
// #include "Data.h"
// #include "Themxoahieuchinhdocgia.h"
// #include "Xuatthongtindocgia.h"
// #include "Dausach.h"
// #include "Ngaythang.h"
// #include "Muontra.h"
// #include "Ghi_file.h"
// #include "Doc_file.h"
// #include "Giai_phong_du_lieu.h"
#include "./Dohoa.h"
#include "./Xu_li_nhap_so.h"
using namespace std;
// Doc gia
// void Nhap_doc_gia(TREE t, DOC_GIA &dg);
// void Them_doc_gia(TREE &t, DOC_GIA dg, DS_DOC_GIA &ds_dg);
// void Chinh_sua_thong_tin_doc_gia(TREE &t);
// void Xoa_node_bat_ki(TREE &t, int mathe, DS_DOC_GIA &ds_dg); // Node o day chinh la doc gia
// void Xuat_thong_tin_doc_gia_theo_ma_the(TREE t);
// void Xuat_thong_tin_doc_gia_theo_ho_ten(TREE t, DOC_GIA a[], DS_DOC_GIA ds_dg, int n);
// void Liet_ke_danh_sach_sach_dang_muon_cua_1_doc_gia(TREE t, int mathe);
// void Xuat_danh_sach_doc_gia_qua_han_theo_thoi_gian_giam_dan(TREE t, DOC_GIA a[], DS_DOC_GIA ds_dg, int n);
// Dau sach
// void Them_dau_sach(DS_DAU_SACH &ds_dau_sach);
// void Xoa_dau_sach(DS_DAU_SACH &ds_dau_sach);
// void Hieu_chinh_dau_sach(DS_DAU_SACH &ds_dau_sach);
// void Xuat_thong_tin_1_dau_sach(DAU_SACH *dau_sach);
// void Xuat_dms_cua_1_dau_sach(DS_DANH_MUC_SACH ds_dms);
// void Xuat_thong_tin_cac_dau_sach(DS_DAU_SACH ds_dau_sach);
// Danh muc sach
// void Them_sach(DS_DANH_MUC_SACH &ds_dms, DS_DAU_SACH ds_dau_sach);
// void Xoa_sach(DS_DANH_MUC_SACH &ds_dms, DS_DAU_SACH ds_dau_sach);
// void Hieu_chinh_sach(DS_DANH_MUC_SACH &ds_dms, DS_DAU_SACH ds_dau_sach);
// void Xuat_DS_Theo_Tung_The_Loai(DS_DAU_SACH ds);
// void Tim_thong_tin_sach_dua_vao_ten_sach(DS_DAU_SACH ds_dau_sach, DS_DANH_MUC_SACH ds_dms);
// Muon tra
// void Muon_sach(TREE &t, DS_DAU_SACH &ds_dau_sach, DS_DANH_MUC_SACH &ds_dms, int mathe);
// void Tra_sach(TREE &t, DS_DAU_SACH &ds_dau_sach, DS_DANH_MUC_SACH &ds_dms);

// void Khoi_tao_cay(TREE &t)
// {
// 	t = NULL; // Cay rong
// }

int main()
{
	resizeConsole(1000, 700);
	srand((int)time(0));
	// TREE t;
	// Khoi_tao_cay(t);
	// DS_DOC_GIA ds_dg;
	// DS_DAU_SACH ds_dau_sach;
	// DS_DANH_MUC_SACH ds_dms;

	// Load_file_doc_gia(t, ds_dg);
	// Load_file_dau_sach(ds_dau_sach);
	// Tinh_ngay_qua_han_cua_cac_doc_gia(t);
	system("cls");
	int thoat = 0;
	int chon;
	do
	{
		ShowCur(0);
		khung_vien();
		huong_dan();
		chon = MenuDong(menu_chinh);
		Normal();
		switch (chon)
		{
		case 1:
		{
			int chon_dg;
			do
			{
				ShowCur(0);
				xoa_man_hinh(3, 4, 128, 32);
				chon_dg = MenuDongDG(menu_dg);
				Normal();
				switch (chon_dg)
				{
				case 1:
				{
					ve_lai_man_hinh();
					DeMuc("           THEM DOC GIA");
					// DOC_GIA dg;
					// Nhap_doc_gia(t, dg);
					// Them_doc_gia(t, dg, ds_dg);
					break;
				}
				case 2:
				{
					ve_lai_man_hinh();

					DeMuc("   CHINH SUA THONG TIN DOC GIA");
					// DOC_GIA a[ds_dg.so_luong];
					int k = 0;
					// Xuat_thong_tin_doc_gia_theo_ho_ten(t, a, ds_dg, k);
					xoa_man_hinh(2, 7, 130, 30);
					huong_dan_xem_danh_sach_sach_dang_muon_doc_gia();
					gotoxy(30, 9);
					cout << "Nhap ma the doc gia: ";
					while (true)
					{
						if (kbhit())
						{
							char key = getch();
							if (key == 13)
							{
								int n;
								ShowCur(1);
								Nhap_so(n, 51, 9);
								// if (Kiem_tra_trung_ma_the(t, n) == false)
								{
									thong_bao("Doc gia khong co trong thu vien.");
									break;
								}
								// else
								// {
								// 	Chinh_sua_thong_tin_doc_gia(t, n);
								// 	break;
								// }
							}
							else if (key == 27)
							{
								break;
							}
						}
					}
					break;
				}
				case 3:
				{
					ve_lai_man_hinh();
					DeMuc("           XOA DOC GIA");
					huong_dan_xoa_doc_gia_1();
					gotoxy(30, 9);
					cout << "Nhap ma the doc gia: ";
					while (true)
					{
						if (kbhit())
						{
							char key = getch();
							if (key == 13)
							{
								int mathe;
								ShowCur(1);
								Nhap_so(mathe, 51, 9);
								// if (Kiem_tra_trung_ma_the(t, mathe) == false)
								// {
								// 	thong_bao("Doc gia khong co trong thu vien.");
								// 	break;
								// }
								// else
								// {
								// 	Xoa_node_bat_ki(t, mathe, ds_dg, ds_dau_sach);
								// 	break;
								// }
							}
							else if (key == 27)
							{
								break;
							}
						}
					}
					break;
				}
				case 4:
				{
					ShowCur(1);
					ve_lai_man_hinh();
					huong_dan_xem_danh_sach_sach_dang_muon_doc_gia();
					DeMuc("   SACH DANG MUON CUA 1 DOC GIA");
					gotoxy(30, 9);
					cout << "Nhap ma the doc gia: ";
					ShowCur(0);
					while (true)
					{
						if (kbhit())
						{
							char key = getch();
							if (key == 13)
							{
								int mathe;
								ShowCur(1);
								Nhap_so(mathe, 51, 9);
								// if (Kiem_tra_trung_ma_the(t, mathe) == false)
								// {
								// 	thong_bao("Doc gia khong co trong thu vien.");
								// 	break;
								// }
								// else
								// {
								// 	Liet_ke_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t, mathe);
								// 	break;
								// }
							}
							else if (key == 27)
							{
								break;
							}
						}
					}
					break;
				}
				case 5:
				{
					ve_lai_man_hinh();
					DeMuc("       DANH SACH DOC GIA QUA HAN");
					// Xuat_danh_sach_doc_gia_qua_han_theo_thoi_gian_giam_dan(t, ds_dg);
					break;
				}
				case 6:
				{
					ve_lai_man_hinh();
					// DOC_GIA a[ds_dg.so_luong];
					int n = 0;
					DeMuc("        THONG TIN DOC GIA");
					// Xuat_thong_tin_doc_gia_theo_ho_ten(t, a, ds_dg, n);
					break;
				}
				case 7:
				{
					ve_lai_man_hinh();
					DeMuc("        THONG TIN DOC GIA");
					// DOC_GIA a[ds_dg.so_luong];
					int n = 0;
					// Xuat_thong_tin_doc_gia_theo_ma_the(t, a, ds_dg, n);
					break;
				}
				case 0:
					thoat++;
					break;
				}
				system("cls");
				khung_vien();
				huong_dan();
				if (thoat != 0)
				{
					thoat = 0;
					break;
				}
			} while (1);
			break;
		}
		case 2:
		{
			int chon_ds;
			do
			{
				ShowCur(0);
				xoa_man_hinh(3, 4, 128, 32);
				chon_ds = MenuDongDS(menu_ds);
				Normal();
				switch (chon_ds)
				{
				case 1:
				{
					ve_lai_man_hinh();
					DeMuc("           THEM DAU SACH");
					// Them_dau_sach(ds_dau_sach);
					break;
				}
				case 2:
				{
					ve_lai_man_hinh();
					DeMuc("           XOA DAU SACH");
					// if (Kiem_tra_rong_ds_dau_sach(ds_dau_sach) == true)
					// {
					// 	thong_bao("Danh sach dau sach dang rong. Khong the xoa.");
					// }
					// else
					// {
					// 	Xoa_dau_sach(ds_dau_sach);
					// }
					break;
				}
				case 3:
				{
					ve_lai_man_hinh();
					DeMuc("        CHINH SUA DAU SACH");
					// Hieu_chinh_dau_sach(ds_dau_sach);
					break;
				}
				case 4:
				{
					ve_lai_man_hinh();
					DeMuc("             TIM SACH");
					// Tim_thong_tin_sach_dua_vao_ten_sach(ds_dau_sach, ds_dms);
					break;
				}
				case 5:
				{
					ve_lai_man_hinh();
					DeMuc("         THONG TIN DAU SACH");
					// if (Kiem_tra_rong_ds_dau_sach(ds_dau_sach) == true)
					// {
					// 	thong_bao("Thu vien chua co sach nao.");
					// }
					// else
					// {
					// 	Xuat_thong_tin_cac_dau_sach(ds_dau_sach);
					// }
					break;
				}
				case 6:
				{
					ve_lai_man_hinh();
					DeMuc("   XUAT DANH SACH THEO THE LOAI");
					huong_dan_xem_theo_the_loai();
					// Xuat_DS_Theo_Tung_The_Loai(ds_dau_sach);
					break;
				}
				case 7:
				{
					ve_lai_man_hinh();
					DeMuc("   10 SACH DUOC MUON NHIEU NHAT");
					// Top_10_sach(ds_dau_sach);
					break;
				}
				case 0:
					thoat++;
					break;
				}
				system("cls");
				khung_vien();
				huong_dan();
				if (thoat != 0)
				{
					thoat = 0;
					break;
				}
			} while (1);
			break;
		}
		case 3:
		{
			int chon_dms;
			do
			{
				ShowCur(0);
				xoa_man_hinh(3, 4, 128, 32);
				chon_dms = MenuDongDMS(menu_dms);
				Normal();
				switch (chon_dms)
				{
				case 1:
				{
					ve_lai_man_hinh();
					DeMuc("      THEM SACH VAO DAU SACH");
					// Them_sach(ds_dms, ds_dau_sach);
					break;
				}
				case 2:
				{
					ve_lai_man_hinh();
					DeMuc("     XOA SACH THUOC DAU SACH");
					// Xoa_sach(ds_dms, ds_dau_sach);
					break;
				}
				case 3:
				{
					ve_lai_man_hinh();
					DeMuc("   CHINH SUA SACH THUOC DAU SACH");
					// Hieu_chinh_sach(ds_dms, ds_dau_sach);
					break;
				}
				case 0:
					thoat++;
					break;
				}
				system("cls");
				khung_vien();
				huong_dan();
				if (thoat != 0)
				{
					thoat = 0;
					break;
				}
			} while (1);
			break;
		}
		case 4:
		{
			int chon_mt;
			do
			{
				ShowCur(0);
				xoa_man_hinh(3, 4, 128, 32);
				chon_mt = MenuDongMT(menu_mt);
				Normal();
				switch (chon_mt)
				{
				case 1:
				{
					ve_lai_man_hinh();
					huong_dan_xem_danh_sach_sach_dang_muon_doc_gia();
					DeMuc("            MUON SACH");
					gotoxy(30, 9);
					cout << "Nhap ma the doc gia: ";
					while (true)
					{
						if (kbhit())
						{
							char key = getch();
							if (key == 13)
							{
								int a;
								ShowCur(1);
								Nhap_so(a, 51, 9);
								// if (Kiem_tra_trung_ma_the(t, a) == false)
								// {
								// 	thong_bao("Doc gia khong ton tai.");
								// 	break;
								// }
								// else
								// {
								// 	Muon_sach(t, ds_dau_sach, ds_dms, a);
								// 	break;
								// }
							}
							else if (key == 27)
							{
								break;
							}
						}
					}
					break;
				}
				case 2:
				{
					ve_lai_man_hinh();
					DeMuc("              TRA SACH");
					huong_dan_xem_danh_sach_sach_dang_muon_doc_gia();
					gotoxy(30, 9);
					cout << "Nhap ma the doc gia: ";
					while (true)
					{
						if (kbhit())
						{
							char key = getch();
							{
								if (key == 13)
								{
									ShowCur(1);
									int mathe;
									Nhap_so(mathe, 51, 9);
									// if (Kiem_tra_trung_ma_the(t, mathe) == false)
									// {
									// 	thong_bao("Doc gia khong co trong thu vien.");
									// 	break;
									// }
									// else
									// {
									// 	Xu_li_tra_sach(t, ds_dau_sach, ds_dms, mathe);
									// 	break;
									// }
								}
								else if (key == 27)
								{
									Normal();
									break;
								}
							}
						}
					}
					break;
				}
				case 3:
				{
					ve_lai_man_hinh();
					DeMuc("           LAM MAT SACH");
					huong_dan_xem_danh_sach_sach_dang_muon_doc_gia();
					gotoxy(30, 9);
					cout << "Nhap ma the doc gia: ";
					while (true)
					{
						if (kbhit())
						{
							char key = getch();
							if (key == 13)
							{
								ShowCur(1);
								int mathe;
								Nhap_so(mathe, 51, 9);
								// if (Kiem_tra_trung_ma_the(t, mathe) == false)
								// {
								// 	thong_bao("Doc gia khong co trong thu vien.");
								// 	break;
								// }
								// else
								// {
								// 	Xu_li_lam_mat_sach(t, ds_dau_sach, ds_dms, mathe);
								// 	break;
								// }
							}
							else if (key == 27)
							{
								break;
							}
						}
					}
					break;
				}
				case 0:
					thoat++;
					break;
				}
				system("cls");
				khung_vien();
				huong_dan();
				if (thoat != 0)
				{
					thoat = 0;
					break;
				}
			} while (1);
			break;
		}
		case so_item:
		{
			int chon_thoat;
			do
			{
				ShowCur(0);
				chon_thoat = MenuDongTHOAT(menu_thoat);
				Normal();
				switch (chon_thoat)
				{
				case 1:
				{
					// Ghi_file_ds_doc_gia(ds_dau_sach, t, ds_dg);
					// Ghi_file_ds_dau_sach(ds_dau_sach);
					system("cls");
					exit(0);
				}
				case 2:
				{
					system("cls");
					exit(0);
				}
				case 0:
				{
					thoat++;
					break;
				}
				}
				system("cls");
				khung_vien();
				huong_dan();
				if (thoat != 0)
				{
					thoat = 0;
					break;
				}
			} while (1);
			break;
		}
		}
	} while (1);

	return 0;
}
