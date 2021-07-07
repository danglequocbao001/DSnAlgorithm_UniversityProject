#include "./__init__.h"
#include "./file_out.h"
#include "../model/muon_tra.h"

#ifndef FILE_IN_H
#define FILE_IN_H

NODE_DOC_GIA* Tim_kiem_doc_gia(TREE t, int mathe)
{
	while (t != NULL && t->data.Ma_the != mathe)
	{
		if (mathe < t->data.Ma_the)
		{
			t = t->pLeft;
		}
		else
			t = t->pRight;
	}
	return (t);
}
void Load_file_doc_gia(TREE &t, DS_DOC_GIA &ds_dg)
{
	ifstream Filein;
	Filein.open(DOCGIA_DB, ios_base::in);
	NODE_DOC_GIA *p = NULL;
	DOC_GIA dg;
	int soluongdocgia, sosachdangmuon;
	if (Filein.fail() == true)
	{
		cout << "Mo file that bai.\n";
		return;
	}
	else
	{
		string tam; // Dung de doc ki tu "\n"
		string tensachtam;
		Filein >> soluongdocgia; // Dong dau tien doc so luong doc gia
		for (int i = 0; i < soluongdocgia; i++)
		{
			// Doc cac thong tin co ban cua doc gia
			Filein >> dg.Ma_the;
			getline(Filein, tam); // Doc ki tu "\n"
			getline(Filein, dg.Ho);
			getline(Filein, dg.Ten);
			getline(Filein, dg.Phai);
			Filein >> dg.Trang_thai_the;
			Filein >> dg.ds_muon_tra_cua_doc_gia.so_luong;
			Them_doc_gia(t, dg, ds_dg);			// Them doc gia vao cay
			p = Tim_kiem_doc_gia(t, dg.Ma_the); // Lay thong tin doc gia do ra va doc thong tin tiep theo
			p->data.Trang_thai_the = dg.Trang_thai_the;
			// Doc danh sach muon tra cua doc gia
			Filein >> sosachdangmuon;
			getline(Filein, tam);
			for (int j = 0; j < sosachdangmuon; j++)
			{
				MUON_TRA mt;
				getline(Filein, mt.Ma_sach);
				Filein >> mt.Ngay_muon.Ngay;
				Filein >> mt.Ngay_muon.Thang;
				Filein >> mt.Ngay_muon.Nam;
				Filein >> mt.Ngay_tra.Ngay;
				Filein >> mt.Ngay_tra.Thang;
				Filein >> mt.Ngay_tra.Nam;
				getline(Filein, tam);
				getline(Filein, tensachtam);
				Filein >> mt.Trang_thai;
				getline(Filein, tam);
				NODE_MUON_TRA *muontra = Khoi_tao_node_mt(mt);
				Them_vao_cuoi_danh_sach_mt(p->data.ds_muon_tra_cua_doc_gia, muontra);
				p->data.So_luong_sach_dang_muon++;
				//p->data.ds_muon_tra_cua_doc_gia.so_luong++;
			}
		}
	}
	Filein.close();
}
void Load_file_dau_sach(DS_DAU_SACH &ds_dau_sach)
{
	ifstream Filein;
	Filein.open(DAUSACH_DB, ios_base::in);
	int soluongdausach, sosachthuocdausach;
	if (Filein.fail() == true)
	{
		cout << "Mo file that bai.\n";
		return;
	}
	else
	{
		string tam;
		Filein >> soluongdausach;
		getline(Filein, tam);
		for (int i = 0; i < soluongdausach; i++)
		{
			// Doc thong tin dau sach
			DAU_SACH *p = new DAU_SACH; // Dung 1 bien de doc cac thong tin
			getline(Filein, p->Ten_sach);
			getline(Filein, p->ISBN);
			getline(Filein, p->Tac_gia);
			getline(Filein, p->The_loai);
			Filein >> p->So_trang;
			Filein >> p->Nam_xuat_ban;
			Filein >> p->So_lan_muon;
			Filein >> sosachthuocdausach;
			getline(Filein, tam);
			ds_dau_sach.list[i] = p; // Dua bien do vao danh sach
			// Doc thong tin danh muc sach cua dau sach
			for (int j = 0; j < sosachthuocdausach; j++)
			{
				DANH_MUC_SACH dms;
				getline(Filein, dms.Ma_sach);
				Filein >> dms.Trang_thai;
				getline(Filein, tam);
				getline(Filein, dms.Vi_tri);
				NODE_DANH_MUC_SACH *k = Khoi_tao_node(dms);
				Them_vao_cuoi_danh_sach_dms(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach, k); // Them danh muc sach vao trong dau sach
				ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach.so_luong++;
			}
			if (sosachthuocdausach > 0)
			{
				ds_dau_sach.list[i]->Check = true;
			}
			ds_dau_sach.so_luong++;
		}
	}
	Filein.close();
}
#endif /*FILE_IN_H*/
