#include "./models.h"
#include "./schemas/muontra.h"
#include "./structures/linkedlist.h"

#ifndef _MUON_TRA_H
#define _MUON_TRA_H

class MuonTra: public Model<LinkedList, MuonTraSchema> {
    public: // private:
        MuonTraSchema arrayToType(struct string_2d);
        struct string_2d typeToArray(MuonTraSchema);

    public:
        char* database_connection;

        MuonTra(char* filedata);
        ~MuonTra();

        void append(MuonTraSchema);
        void commit(FILE*, MuonTraSchema);
        void write();
        void refresh();
};


MuonTra::MuonTra(char* filedata): database_connection(filedata) {
    MuonTra::data = new LinkedList<MuonTraSchema>();
}


MuonTra::~MuonTra() {}


MuonTraSchema MuonTra::arrayToType(struct string_2d value) {
    return MuonTraInit(value);
}


struct string_2d MuonTra::typeToArray(MuonTraSchema item) {
    return MuonTraToArray(item);
}


void MuonTra::append(MuonTraSchema item) {
    MuonTra::data->addTail(item);
}


void MuonTra::refresh() {
    F_STDIN file = F_STDIN(MuonTra::database_connection, READ_MODE);
    char line[MAX_LINE_LEN]; int index = 0;
    while(file >> std::noskipws >> line[index++])
        if (line[index - 1] == '\n') {
            line[index - 1] = 0;
            struct string_2d _x =MuonTra::split_string(
                    strdup(line),
                    MuonTra::separator
                );
            MuonTraSchema _data = MuonTra::arrayToType(
                MuonTra::split_string(
                    strdup(line),
                    MuonTra::separator
                )
            );
            MuonTra::append(_data);
            memset(line, 0, index - 1);
            index = 0;
        }
    file.close();
}


void MuonTra::commit(FILE *file, MuonTraSchema item) {
    char* a = MuonTra::merge_string(
        MuonTra::typeToArray(item),
        MuonTra::separator
    );
    fprintf( file, "%s\n", a);
}


void MuonTra::write() {
    FILE *file = fopen(MuonTra::database_connection, WRITE_MODE);
    for (
        node<MuonTraSchema> *runner = MuonTra::data->head;
        runner != nullptr;
        runner = runner->next
    )
        MuonTra::commit(file, runner->value);
    fclose(file);
}

#endif /*_MUON_TRA_H*/

