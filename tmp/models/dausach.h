#include "./models.h"
#include "./schemas/dausach.h"
#include "./structures/normalarray.h"

#ifndef _DAU_SACH_H
#define _DAU_SACH_H

class DauSach: public Model<Array, DauSachSchema> {
    public: // private:
        DauSachSchema arrayToType(struct string_2d);
        struct string_2d typeToArray(DauSachSchema);

    public:
        char* database_connection;

        DauSach(char* filedata);
        ~DauSach();

        void append(DauSachSchema);
        void commit(FILE*, DauSachSchema);
        void write();
        void refresh();
};


DauSach::DauSach(char* filedata): database_connection(filedata) {
    DauSach::data = new Array<DauSachSchema>();
}


DauSach::~DauSach() {}


DauSachSchema DauSach::arrayToType(struct string_2d value) {
    return DauSachInit(value);
}


struct string_2d DauSach::typeToArray(DauSachSchema item) {
    return DauSachToArray(item);
}


void DauSach::append(DauSachSchema item) {
    DauSach::data->addTail(item);
}


void DauSach::refresh() {
    F_STDIN file = F_STDIN(DauSach::database_connection, READ_MODE);
    char line[MAX_LINE_LEN]; int index = 0;
    while(file >> std::noskipws >> line[index++])
        if (line[index - 1] == '\n') {
            line[index - 1] = 0;
            struct string_2d _x =DauSach::split_string(
                    strdup(line),
                    DauSach::separator
                );
            DauSachSchema _data = DauSach::arrayToType(
                DauSach::split_string(
                    strdup(line),
                    DauSach::separator
                )
            );
            DauSach::append(_data);
            memset(line, 0, index - 1);
            index = 0;
        }
    file.close();
}


void DauSach::commit(FILE *file, DauSachSchema item) {
    char* a = DauSach::merge_string(
        DauSach::typeToArray(item),
        DauSach::separator
    );
    fprintf( file, "%s\n", a);
    free(a);
}


void DauSach::write() {
    FILE *file = fopen(DauSach::database_connection, WRITE_MODE);
    for (
        DauSachSchema* runner = DauSach::data->head;
        runner < DauSach::data->head + DauSach::data->size;
        runner++
    )
        DauSach::commit(file, *runner);
    fclose(file);
}

#endif /*_DAU_SACH_H*/
