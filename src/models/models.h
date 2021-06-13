#include "__init__.h"

template <template <typename T> class C, typename T>
class Model {

    public: // private:
        int count_substring(char*, char*);
        struct string_2d split_string(char*, char*);
        char* merge_string(struct string_2d);

        T arrayToType(struct string_2d);
        struct string_2d typeToArray(T);

    public:
        Model();
        ~Model();

        char* separator = "|";
        char* database_connection;

        C<T> *data;
        void append(T);

        void refresh();
        void commit();
};


/*____PRIVATE BLOCK____*/
template <template <typename T> class C, typename T>
int Model<C, T>::count_substring(char* string, char* chr) {
    int len_string = strlen(string),
        len_chr = strlen(chr),
        counted_chrs = 0;

    for (int index = 0; index < len_string; index++)
        for(int _index = index; _index < index + len_chr; _index++)
            if (string[_index] == chr[_index - index])
                counted_chrs++;

    return counted_chrs;
}


template <template <typename T> class C, typename T>
struct string_2d Model<C, T>::split_string(char* string, char* chr) {

    int len_string = strlen(string),
        len_chr = strlen(chr),
        counted_chrs = 0;

    char _string[len_string];
    strcpy(_string, string);

    counted_chrs = Model<C, T>::count_substring(string, chr);
    char **str_array = (char**)malloc(++counted_chrs);

    /*__SPLIT STRING WITH CHR__*/
    char * token = strtok(_string, chr);

    for(int index = 0; index < counted_chrs; index++) {
        str_array[index] = (char*) malloc(strlen(token));
        strcpy(str_array[index], token);
        token = strtok(NULL, chr);
    }

    return (struct string_2d) {
        .array = str_array,
        .size = counted_chrs
    };
}


template <template <typename T> class C, typename T>
void Model<C, T>::refresh() {
    FILE *file = fopen(Model<C, T>::database_connection, "r");
    char line[1000]; int index = 0;
    while((line[index++] = (char)getc(file)) != EOF) {
        if (line[index - 1] == '\n') {
            line[index - 1] = 0;
            Model<C, T>::append(Model<C, T>::stringToType(line));
            memset(line, 0, index - 1);
            index = 0;
        }
    }
    fclose(file);
}
