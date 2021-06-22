#include "__init__.h"

#ifndef _MODEL_H
#define _MODEL_H

template <template <typename T> class C, typename T>
class Model {

    public: // private:
        int count_substring(char*, char*);
        struct string_2d split_string(char*, char*);
        char* merge_string(struct string_2d, char* joinner);

        T arrayToType(struct string_2d); // INHERITED BY CHILD CLASS
        struct string_2d typeToArray(T); // INHERITED BY CHILD CLASS

    public:
        Model(); // INHERITED BY CHILD CLASS
        ~Model(); // INHERITED BY CHILD CLASS

        char* separator = (char*)SEPARATOR;
        char* database_connection;

        C<T> *data;
        void append(T); // INHERITED BY CHILD CLASS

        void refresh();
        void write(); // INHERITED BY CHILD CLASS
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
    str_array[0] = (char*) malloc(strlen(token));
    strcpy(str_array[0], token);

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
char* Model<C, T>::merge_string(struct string_2d array, char* joinner) {
    char _result[MAX_LINE_LEN] = "";
    int index = 0;
    for(; index < array.size - 1; index++) {
        strcat(_result, array.array[index]);
        strcat(_result, joinner);
    }
    strcat(_result, array.array[index]);
    char* result = (char*) malloc(sizeof(char)*strlen(_result));
    strcpy(result, _result);
    return result;
}


/*____PUBLIC BLOCK____*/
template <template <typename T> class C, typename T>
Model<C, T>::Model() {}

template <template <typename T> class C, typename T>
Model<C, T>::~Model() {}


template <template <typename T> class C, typename T>
struct string_2d Model<C, T>::typeToArray(T value) { return {}; }

#endif /*_MODEL_H*/
