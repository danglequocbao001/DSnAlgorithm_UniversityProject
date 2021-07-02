#ifndef TEST_MODEL_H
#define TEST_MODEL_H

#include "test_frame.h"
#include "../models/models.h"
#include "../models/dausach.h"
#include "../models/danhmucsach.h"
#include "../models/muontra.h"
#include "../models/structures/linkedlist.h"

void test_basemodel() {
    Model<LinkedList, int> *c = new Model<LinkedList, int>();
}


void test_dausach() {
    DauSach *muonTra = new DauSach((char*)"./a");
    muonTra->append( (DauSachSchema){
            .ISBN = (char*)"etwrt",
            .name = (char*)"rwt",
            .numberOfPages = 1411,
            .author = (char*)"ergwer",
            .publishingYear = 24133,
            .type = (char*)"ewete",
    });
    muonTra->append( (DauSachSchema){
            .ISBN = (char*)"etwrt",
            .name = (char*)"rwt",
            .numberOfPages = 1411,
            .author = (char*)"ergwer",
            .publishingYear = 24133,
            .type = (char*)"ewete",
    });
    assert(strcmp(muonTra->database_connection, "./a") == 0);
    assert(muonTra->data->getSize() == 2);
    muonTra->write(); 

    DauSach *d = new DauSach((char*)"./a");
    d->refresh();

    assert(strcmp(d->data->get(0)->ISBN, (char*)"etwrt") == 0);
    assert(strcmp(d->data->get(0)->name, (char*)"rwt") == 0);
    assert(d->data->get(0)->numberOfPages == 1411);
    assert(strcmp(d->data->get(0)->author, (char*)"ergwer") == 0);
    assert(d->data->get(0)->publishingYear == 24133);
    assert(strcmp(d->data->get(0)->type, (char*)"ewete") == 0);

    assert(strcmp(d->data->get(1)->ISBN, (char*)"etwrt") == 0);
    assert(strcmp(d->data->get(1)->name, (char*)"rwt") == 0);
    assert(d->data->get(1)->numberOfPages == 1411);
    assert(strcmp(d->data->get(1)->author, (char*)"ergwer") == 0);
    assert(d->data->get(1)->publishingYear == 24133);
    assert(strcmp(d->data->get(1)->type, (char*)"ewete") == 0);

}

void test_danhmucsach() {
    DanhMucSach *danhMucSach = new DanhMucSach((char*)"./b");
    danhMucSach->append( (DanhMucSachSchema){
            .code = (char*)"123",
            .status = 0,
            .position = 3264,
    });
    danhMucSach->append( (DanhMucSachSchema){
            .code = (char*)"this is the text",
            .status = 0,
            .position = 3264,
    });
    assert(strcmp(danhMucSach->database_connection, "./b") == 0);
    assert(danhMucSach->data->getSize());
    danhMucSach->write(); 

    DanhMucSach *d = new DanhMucSach((char*)"./b");
    d->refresh();
    assert(strcmp(d->data->get(0)->value.code, (char*)"123") == 0);
    assert(d->data->get(0)->value.status == 0);
    assert(d->data->get(0)->value.position == 3264);

    assert(strcmp(d->data->get(1)->value.code, (char*)"this is the text") == 0);
    assert(d->data->get(1)->value.status == 0);
    assert(d->data->get(1)->value.position == 3264);
} 

void test_muontra() {
    MuonTra *muonTra = new MuonTra((char*)"./a");
    muonTra->append( (MuonTraSchema){
            .code = (char*)"etwrt",
            .borrowedDate = 1411,
            .returnedDate = 1411,
            .status = 1,
    });
    muonTra->append( (MuonTraSchema){
            .code = (char*)"rtsdfsd",
            .borrowedDate = 2345,
            .returnedDate = 324532,
            .status = 234,
    });
    assert(strcmp(muonTra->database_connection, "./a") == 0);
    assert(muonTra->data->getSize() == 2);
    muonTra->write(); 

    MuonTra *d = new MuonTra((char*)"./a");
    d->refresh();

    assert(strcmp(d->data->get(0)->value.code, (char*)"etwrt") == 0);
    assert(d->data->get(0)->value.borrowedDate == 1411);
    assert(d->data->get(0)->value.returnedDate == 1411);
    assert(d->data->get(0)->value.status == 1);

    assert(strcmp(d->data->get(1)->value.code, (char*)"rtsdfsd") == 0);
    assert(d->data->get(1)->value.borrowedDate == 2345);
    assert(d->data->get(1)->value.returnedDate == 324532);
    assert(d->data->get(1)->value.status == 234);
}


void test_model() {
    test_basemodel();
    test_dausach();
    test_danhmucsach();
    test_muontra();
}

#endif /*TEST_MODEL_H*/
