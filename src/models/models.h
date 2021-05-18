#include "__init__.h"

/*
 * Model<DanhMucSachSchema, LinkedList>* DanhMucSach = new Model<>();
 */

template <typename T, class C>
class Model {
    private:
        struct string_2d split_string(char*, char);

    public:
        C<T>* data;
        T str2attr(char* string)
        Model();
        ~Model();
};


/*____PRIVATE BLOCK____*/
template <typename T, class C>
struct string_2d Model<T, C>::split_string(char* string, char* chr) {

    int len_string = strlen(string);
    int len_chr = strlen(chr);
    int counted_chrs = 0;

    char _string[len_string];
    strcpy(_string, string);

    /*__COUNT AMOUNT OF CHR IN STRING__*/
    for (int index = 0; index < len_string; index ++)
        for(int _index = index; _index < index + len_chr; _index ++ )
            if (string[_index] == chr[_index - index])
                counted_chrs++;

    char **str_array = (char**) malloc(++counted_chrs);

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
template <typename T, class C>
Model::Model() {
    Model::data = new C<T>();
}


template <typename T, class C>
Model::~Model() {
    Model::data = new C<T>();
}
