#ifndef _MODEL_H
#define _MODEL_H

#include "stdio.h"
#include "stddef.h"
#include "stdlib.h"

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

        #define $a_for_each(runner) for ( C* runner = Array<C>::head;\
                                        runner < Array<C>::head + Array<C>::size - 1;\
                                        runner++)

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
    for (C* runner = Array<C>::head + Array<C>::size - 1; runner > Array<C>::head + index; runner-- ) {
        *runner = *(runner - 1);
    }
}


template <class C>
void Array<C>::shiftLeft(int index) {
    if (Array<C>::head == nullptr) return;
    for (C* runner = Array<C>::head + index; runner < Array<C>::head + Array<C>::size - 1; runner++ ) {
        *runner = *(runner + 1);
    }
}


template <class C>
void Array<C>::increaseOne() {
    Array<C>::size++;
    Array<C>::head = (C*) realloc(Array<C>::head, Array<C>::size);
}

template <class C>
void Array<C>::decreaseOne() {
    Array<C>::size--;
}


template <class C>
Array<C>::Array() {
    Array<C>::head = nullptr;
    Array<C>::size = 0;
};


template <class C>
Array<C>::~Array() {
    free(Array<C>::head);
    printf("[log] goes here too\n");
};


template <class C>
size_t Array<C>::getSize() {
    return Array<C>::size;
};


template <class C>
C* Array<C>::addHead(C value) {
    printf("[log] ------\n");
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
    for (C* runner = head; runner < head + size ;runner ++) {
        printf("[log] index: %d %d\n", runner - head, *runner);
    }
    Array<C>::increaseOne();
    printf("[log] ---\n");
    Array<C>::shiftRight(index);
    *(Array<C>::head + index) = value;
    for (C* runner = head; runner < head + size ;runner ++) {
        printf("[log] index: %d %d\n", runner - head, *runner);
    }
    return Array<C>::head + index;
}


template <class C>
C* Array<C>::search(C value) {
    C* result = nullptr;
    $a_for_each(runner) {
        if(*(runner) == value) {
            result = runner;
            break;
        }
    }
    return result;
}


template <class C>
C* Array<C>::get(int index) {
    if (0 < index && index < Array<C>::size ) {
        return Array<C>::head + index;
    }
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

#ifndef _LINKED_LIST_
#define _LINKED_LIST_


template <class C>
struct node { 
    node* next;
    C value;
};


template <class C>
class LinkedList {

    private:
        size_t size;
        node<C>* insertNode(node<C>*, C);

    public:
        node<C> *head;
        node<C> *tail;


    public:

        LinkedList(C*, C*);
        ~LinkedList();
        size_t getSize();

        #define $ll_for_each(runner) for ( node<C>* runner = LinkedList<C>::head;\
                                        runner != nullptr;\
                                        runner = runner->next)

        void traverser( node<C>*,
                        void (*travelForward) (int, node<C>*),
                        void (*travelBackward) (int, node<C>*),
                        int = 0);
        node<C>* InitNode(C);
        C FreeNode(node<C>*);
        node<C>* addHead    (C);
        node<C>* addTail    (C);
        node<C>* addAt      (int, C);
        node<C>* search     (C);
        node<C>* get        (int);
               C delHead    ();
               C delTail    ();
               C delAt      (int);

};


/* === PRIVATE METHOD ATTRIBUTES === */
template <class C>
node<C>* LinkedList<C>::insertNode(node<C> *previousNode, C value) {
    node<C> *_node = LinkedList<C>::InitNode(value);
    _node->next = previousNode->next;
    previousNode->next = _node;
    return _node;
}


/* === PUBLIC METHOD ATTRIBUTES === */
template <class C>
LinkedList<C>::LinkedList(C *start_array, C *end_array) {
    LinkedList<C>::size = 0;
    node<C> *tmp = LinkedList<C>::InitNode(*start_array);
    LinkedList<C>::head = tmp;

    for (C *runner = start_array+1; runner < end_array; runner++ ) {
        tmp->next = LinkedList<C>::InitNode(*runner);
        tmp = tmp->next;
    }

    LinkedList<C>::tail = tmp;
};


template <class C>
node<C>* LinkedList<C>::InitNode(C value) {
    LinkedList<C>::size++;
    node<C> *_node = (node<C>*) malloc(sizeof(node<C>));
    _node->next = nullptr;
    _node->value = value;

    return _node;
}


template <class C>
C LinkedList<C>::FreeNode(node<C>* previousNode) {
    node<C>* unused = nullptr;
    // delete head of this list
    if (previousNode == nullptr) {
        unused = LinkedList<C>::head;
        LinkedList<C>::head = LinkedList<C>::head->next;
    // delete tail of this list
    } else if (previousNode->next == LinkedList<C>::tail) {
        unused = LinkedList<C>::tail;
        LinkedList<C>::tail = previousNode;
        LinkedList<C>::tail->next = nullptr;
    // normal deleting
    } else {
        unused = previousNode->next;
        previousNode->next = unused->next;
    }

    LinkedList<C>::size--;
    C return_value = unused->value;
    free(unused);
    return return_value;
}


template <class C>
LinkedList<C>::~LinkedList() {
    auto bw = [](int _, node<C>* _node) { free(_node); };
    LinkedList<C>::traverser(LinkedList<C>::head, nullptr, bw);
};


template <class C>
size_t LinkedList<C>::getSize() {
    return LinkedList<C>::size;
};


template<class C>
void LinkedList<C>::traverser(
        node<C>* _node,
        void (*travelForward) (int, node<C>*),
        void (*travelBackward) (int, node<C>*),
        int current_index) {

    if (_node) {

        if (travelForward) {
            travelForward(current_index,_node);
            current_index++ ;
        }

        if (_node->next)
            LinkedList<C>::traverser(
                    _node->next,
                    travelForward,
                    travelBackward,
                    current_index
                    );
    }

    if (travelBackward) {
        travelBackward(current_index, _node);
        current_index--;
    }
}


template <class C>
node<C>* LinkedList<C>::addHead(C value) {
    node<C> *_node = LinkedList<C>::InitNode(value);
    _node->next = LinkedList<C>::head;
    LinkedList<C>::head = _node;
    return LinkedList<C>::head;
}


template <class C>
node<C>* LinkedList<C>::addTail(C value) {
    LinkedList<C>::tail->next = LinkedList<C>::InitNode(value);
    LinkedList<C>::tail = LinkedList<C>::tail->next;
    return LinkedList<C>::tail;
}


template <class C>
node<C>* LinkedList<C>::addAt(int index, C value) {
    int _current_index = 0;
    // for (node<C>* runner = LinkedList<C>::head; runner != NULL; runner = runner->next)
    $ll_for_each(runner) {
        if (index == _current_index + 1) {
            return LinkedList<C>::insertNode(runner, value);
        }
        _current_index++;
    }
    return LinkedList<C>::addTail(value);
}


template <class C>
node<C>* LinkedList<C>::search(C value) {
    $ll_for_each(runner) {
        if (runner->value = value) return runner;
    }
    return nullptr;
}


template <class C>
node<C>* LinkedList<C>::get(int index) {
    int _current_index = 0;
    $ll_for_each(runner) {
        if (index == _current_index) {
            return runner;
        }
        _current_index++;
    }
    return nullptr;
}


template <class C>
C LinkedList<C>::delHead() {
    return LinkedList<C>::FreeNode(nullptr);
}


template <class C>
C LinkedList<C>::delTail() {
    C result;
    $ll_for_each(runner) {
        if (runner->next == LinkedList<C>::tail) {
            result = LinkedList<C>::FreeNode(runner);
            break;
        }
    }
    return result;
}


template <class C>
C LinkedList<C>::delAt(int index) {
    int previousIndex = index - 1;
    if (previousIndex == -1) {
        return LinkedList<C>::delHead();
    } else if (previousIndex == LinkedList<C>::size - 1) {
        return LinkedList<C>::delTail();
    } else {
        node<C>* previousNode = LinkedList<C>::get(previousIndex);
        return LinkedList<C>::FreeNode(previousNode);
    }
}


#endif /*_LINKED_LIST_*/


#endif /*_MODEL_H*/
