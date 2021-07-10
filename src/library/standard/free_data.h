#ifndef FREE_DATA_H
#define FREE_DATA_H

void Giai_phong_ds_mt(TREE &t, DS_MUON_TRA &ds_mt)
{
	NODE_MUON_TRA *k = NULL;
	while (ds_mt.pHead != NULL)
	{
		k = ds_mt.pHead;
		ds_mt.pHead = ds_mt.pHead->pNext;
		delete k;
		t->data.So_luong_sach_dang_muon--;
	}
}
void Giai_phong_ds_dg(TREE &t, DS_DOC_GIA &ds_dg)
{
	if (t != NULL)
	{
		Giai_phong_ds_dg(t->pLeft, ds_dg);
		Giai_phong_ds_dg(t->pRight, ds_dg);
		while (t->data.ds_muon_tra_cua_doc_gia.pHead != NULL)
		{
			Giai_phong_ds_mt(t, t->data.ds_muon_tra_cua_doc_gia);
		}
		delete t;
		t = NULL;
		ds_dg.so_luong--;
	}
}
void Giai_phong_ds_dau_sach(DS_DAU_SACH &ds_dau_sach)
{
	int n = ds_dau_sach.so_luong;
	for (int i = 0; i < n; i++)
	{
		while (ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach.pHead != NULL)
		{
			Xoa_dau_danh_sach_dms(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach);
		}
		delete ds_dau_sach.list[i];
		ds_dau_sach.so_luong--;
	}
}

#endif /*FREE_DATA_H*/
