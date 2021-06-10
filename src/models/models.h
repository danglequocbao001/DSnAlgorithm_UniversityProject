#include "__init__.h"

/*
 * TODO:
 *      Model<LinkedList, DanhMucSachSchema>* DanhMucSach = new Model<>();
 *       - actions:
 *           + load from db
 *           + write to db
 */

template <template <typename T> class C, typename T>
class Model {
    // private:
    public:
        int count_substring(char*, char*);
        struct string_2d split_string(char*, char*);

    public:
        C<T> *data;
        T str2attr(char* string);
        Model();
        ~Model();
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


/*____PUBLIC BLOCK____*/
template <template <typename T> class C, typename T>
Model<C, T>::Model() {
    int a[3] = {0, 1, 2};
    Model::data = new C<T>(a, a+3);
}


template <template <typename T> class C, typename T>
Model<C, T>::~Model() {
}
