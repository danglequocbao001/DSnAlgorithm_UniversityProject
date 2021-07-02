#ifndef Ghi_file
#define Ghi_file
#include "../schema/schema.h"
#include "../../library/standard/date_time.h"
#include <fstream>
void Luu_1_doc_gia(DS_DAU_SACH ds_dau_sach, TREE t, ofstream &Fileout)
{
	Fileout << t->data.Ma_the << endl;
	Fileout << t->data.Ho << endl;
	Fileout << t->data.Ten << endl;
	Fileout << t->data.Phai << endl;
	Fileout << t->data.Trang_thai_the << endl;
	Fileout << t->data.ds_muon_tra_cua_doc_gia.so_luong << endl;
	// Ghi danh sach sach dang muon
	Fileout << t->data.So_luong_sach_dang_muon << endl;
	for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
	{
		string tensachtam;
		Fileout << k->data.Ma_sach << endl;
		// Ngay muon
		Fileout << k->data.Ngay_muon.Ngay << endl;
		Fileout << k->data.Ngay_muon.Thang << endl;
		Fileout << k->data.Ngay_muon.Nam << endl;
		// Ngay tra
		Fileout << k->data.Ngay_tra.Ngay << endl;
		Fileout << k->data.Ngay_tra.Thang << endl;
		Fileout << k->data.Ngay_tra.Nam << endl;
		// Thong tin sach
		tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
		Fileout << tensachtam << endl;
		Fileout << k->data.Trang_thai << endl;
	}
}
void Luu_ds_doc_gia(DS_DAU_SACH ds_dau_sach, TREE t, ofstream &Fileout)
{
	if (t != NULL)
	{
		Luu_ds_doc_gia(ds_dau_sach, t->pLeft, Fileout);
		Luu_1_doc_gia(ds_dau_sach, t, Fileout);
		Luu_ds_doc_gia(ds_dau_sach, t->pRight, Fileout);
	}
}
void Ghi_file_ds_doc_gia(DS_DAU_SACH ds_dau_sach, TREE t, DS_DOC_GIA ds_doc_gia)
{
	ofstream Fileout;
	Fileout.open("DS_DOC_GIA.txt", ios_base::out);
	if (Fileout.fail() == true)
	{
		cout << "Luu file that bai.\n";
		return;
	}
	else
	{
		Fileout << ds_doc_gia.so_luong << endl;
		Luu_ds_doc_gia(ds_dau_sach, t, Fileout);
	}
	Fileout.close();
}
void Luu_ds_dau_sach(DS_DAU_SACH ds_dau_sach, ofstream &Fileout)
{
	Fileout << ds_dau_sach.so_luong << endl;
	for (int i = 0; i < ds_dau_sach.so_luong; i++)
	{
		// Thong tin dau sach
		Fileout << ds_dau_sach.list[i]->Ten_sach << endl;
		Fileout << ds_dau_sach.list[i]->ISBN << endl;
		Fileout << ds_dau_sach.list[i]->Tac_gia << endl;
		Fileout << ds_dau_sach.list[i]->The_loai << endl;
		Fileout << ds_dau_sach.list[i]->So_trang << endl;
		Fileout << ds_dau_sach.list[i]->Nam_xuat_ban << endl;
		Fileout << ds_dau_sach.list[i]->So_lan_muon << endl;
		// So luong sach trong dau sach
		Fileout << ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach.so_luong << endl;
		// Thong tin cac sach thuoc dau sach
		for (NODE_DANH_MUC_SACH *k = ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach.pHead; k != NULL; k = k->pNext)
		{
			Fileout << k->data.Ma_sach << endl;
			Fileout << k->data.Trang_thai << endl;
			Fileout << k->data.Vi_tri << endl;
		}
	}
}
void Ghi_file_ds_dau_sach(DS_DAU_SACH ds_dau_sach)
{
	ofstream Fileout;
	Fileout.open("DS_DAU_SACH.txt", ios_base::out);
	if (Fileout.fail() == true)
	{
		cout << "Luu file that bai.\n";
		return;
	}
	else
	{
		Luu_ds_dau_sach(ds_dau_sach, Fileout);
	}
	Fileout.close();
}
#endif
