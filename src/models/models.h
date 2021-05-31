#include "__init__.h"

/*
 * TODO:
 *      Model<DanhMucSachSchema, LinkedList>* DanhMucSach = new Model<>();
 *       - actions:
 *           + load from db
 *           + write to db
 */

template <class T, template <class T> class C>
class Model {
    // private:
    public:
        int count_substring(char*, char*);
        struct string_2d split_string(char*, char*);

    public:
        C<T>* data;
        T str2attr(char* string);
        Model();
        ~Model();
};


/*____PRIVATE BLOCK____*/
template <class T, template <class T> class C>
int Model<T, C>::count_substring(char* string, char* chr) {
    int len_string = strlen(string),
        len_chr = strlen(chr),
        counted_chrs = 0;

    for (int index = 0; index < len_string; index++)
        for(int _index = index; _index < index + len_chr; _index++)
            if (string[_index] == chr[_index - index])
                counted_chrs++;

    return counted_chrs;
}


template <class T, template <class T> class C>
struct string_2d Model<T, C>::split_string(char* string, char* chr) {

    int len_string = strlen(string),
        len_chr = strlen(chr),
        counted_chrs = 0;

    char _string[len_string];
    strcpy(_string, string);

    counted_chrs = Model<T, C>::count_substring(string, char);
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
template <class T, template <class T> class C>
Model<T, C>::Model() {
    Model::data = new C<T>();
}


template <class T, template <class T> class C>
Model<T, C>::~Model() {
    Model::data = new C<T>();
}
