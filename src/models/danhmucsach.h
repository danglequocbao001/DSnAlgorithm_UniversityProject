#include "./models.h"
#include "./schemas/danhmucsach.h"
#include "./structures/linkedlist.h"

#ifndef _DANH_MUC_SACH_H
#define _DANH_MUC_SACH_H

class DanhMucSach: public Model<LinkedList, DanhMucSachSchema> {
    public: // private:
        DanhMucSachSchema arrayToType(struct string_2d);
        struct string_2d typeToArray(DanhMucSachSchema);

    public:
        char* database_connection;

        DanhMucSach(char* filedata);
        ~DanhMucSach();

        void append(DanhMucSachSchema);
        void commit(FILE*, DanhMucSachSchema);
        void write();
        void refresh();
};


DanhMucSach::DanhMucSach(char* filedata): database_connection(filedata) {
    DanhMucSach::data = new LinkedList<DanhMucSachSchema>();
}


DanhMucSach::~DanhMucSach() {}


DanhMucSachSchema DanhMucSach::arrayToType(struct string_2d value) {
    return DanhMucSachInit(value);
}


struct string_2d DanhMucSach::typeToArray(DanhMucSachSchema item) {
    return DanhMucSachToArray(item);
}


void DanhMucSach::append(DanhMucSachSchema item) {
    DanhMucSach::data->addTail(item);
}


void DanhMucSach::refresh() {
    F_STDIN file = F_STDIN(DanhMucSach::database_connection, READ_MODE);
    char line[MAX_LINE_LEN]; int index = 0;
    while(file >> std::noskipws >> line[index++])
        if (line[index - 1] == '\n') {
            line[index - 1] = 0;
            struct string_2d _x =DanhMucSach::split_string(
                    strdup(line),
                    DanhMucSach::separator
                );
            DanhMucSachSchema _data = DanhMucSach::arrayToType(
                DanhMucSach::split_string(
                    strdup(line),
                    DanhMucSach::separator
                )
            );
            DanhMucSach::append(_data);
            memset(line, 0, index - 1);
            index = 0;
        }
    file.close();
}


void DanhMucSach::commit(FILE *file, DanhMucSachSchema item) {
    char* a = DanhMucSach::merge_string(
        DanhMucSach::typeToArray(item),
        DanhMucSach::separator
    );
    fprintf( file, "%s\n", a);
}


void DanhMucSach::write() {
    FILE *file = fopen(DanhMucSach::database_connection, WRITE_MODE);
    for (
        node<DanhMucSachSchema> *runner = DanhMucSach::data->head;
        runner != nullptr;
        runner = runner->next
    )
        DanhMucSach::commit(file, runner->value);
    fclose(file);
}

#endif /*_DANH_MUC_SACH_H*/
