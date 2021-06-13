#include "./__init__.h"

#ifndef _POINTER_ARRAY_
#define _POINTER_ARRAY_


template <class C>
class Array {
    
    // private:
    public:
        void shiftLeft(int);
        void shiftRight(int);
        void increaseOne();
        void decreaseOne();

        size_t size;

    public:
        C* head;

    public:

        Array();
        ~Array();
        size_t getSize();

        #define $a_for_each(runner) for (\
                C* runner = Array<C>::head;\
                runner < Array<C>::head + Array<C>::size - 1;\
                runner++\
        )

        C* addHead    (C);
        C* addTail    (C);
        C* addAt      (int, C);
        C* search     (C);
        C* get        (int);
        C  delHead    ();
        C  delTail    ();
        C  delAt      (int);
};


template <class C>
void Array<C>::shiftRight(int index) {
    if (Array<C>::head == nullptr) return;
    for (C* runner = Array<C>::head + Array<C>::size - 1;
            runner > Array<C>::head + index;
            runner-- )
        *runner = *(runner - 1);
}


template <class C>
void Array<C>::shiftLeft(int index) {
    if (Array<C>::head == nullptr) return;
    for (C* runner = Array<C>::head + index;
            runner < Array<C>::head + Array<C>::size - 1;
            runner++ )
        *runner = *(runner + 1);
}


template <class C>
void Array<C>::increaseOne() {
    Array<C>::size++;
    // Array<C>::head = (C*) realloc(Array<C>::head, Array<C>::size);
}

template <class C>
void Array<C>::decreaseOne() {
    Array<C>::size--;
}


template <class C>
Array<C>::Array() {
    Array<C>::head = InitBuffer(C);
    Array<C>::size = 0;
};


template <class C>
Array<C>::~Array() {
    free(Array<C>::head);
    // printf("[log] goes here too\n");
};


template <class C>
size_t Array<C>::getSize() {
    return Array<C>::size;
};


template <class C>
C* Array<C>::addHead(C value) {
    // printf("[log] ------\n");
    Array<C>::increaseOne();
    Array<C>::shiftRight(0);
    *(Array<C>::head) = value;
    return Array<C>::head;
}


template <class C>
C* Array<C>::addTail(C value) {
    Array<C>::increaseOne();
    *(Array<C>::head + size - 1) = value;
    return Array<C>::head + size - 1;
}


template <class C>
C* Array<C>::addAt(int index, C value) {
    // for (C* runner = head; runner < head + size ;runner ++)
        // printf("[log] index: %d %d\n", runner - head, *runner);

    Array<C>::increaseOne();
    // printf("[log] ---\n");
    Array<C>::shiftRight(index);
    *(Array<C>::head + index) = value;

    // for (C* runner = head; runner < head + size ;runner ++)
        // printf("[log] index: %d %d\n", runner - head, *runner);

    return Array<C>::head + index;
}


template <class C>
C* Array<C>::search(C value) {
    C* result = nullptr;
    $a_for_each(runner)
        if(*(runner) == value) {
            result = runner;
            break;
        }
    return result;
}


template <class C>
C* Array<C>::get(int index) {
    if (0 < index && index < Array<C>::size )
        return Array<C>::head + index;

    return nullptr;
}


template <class C>
C Array<C>::delHead() {
    C result = *(Array<C>::head);
    Array<C>::shiftLeft(0);
    Array<C>::decreaseOne();
    return result;
}


template <class C>
C Array<C>::delTail() {
    C result = *(Array<C>::head + Array<C>::size);
    Array<C>::shiftRight(0);
    Array<C>::decreaseOne();
    return result;
}


template <class C>
C Array<C>::delAt(int index) {
    C result = *(Array<C>::head + index);
    Array<C>::shiftLeft(index);
    Array<C>::decreaseOne();
    return result;
}


#endif /*_POINTER_ARRAY_*/

