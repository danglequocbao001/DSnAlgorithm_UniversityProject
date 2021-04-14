#ifndef _MODEL_H
#define _MODEL_H

#ifndef _LINKED_LIST_
#define _LINKED_LIST_


#include "stdio.h"
#include "stdlib.h"

template <class C>
struct node { 
    node* next;
    C value;
};


template <class C>
class LinkedList {

    private:
        node<C>* insertNode(node<C>*, C);

    public:
        node<C> *head;
        node<C> *tail;
        int size;


    public:

        LinkedList(C*, C*);
        ~LinkedList();

        #define $for_each(runner) for ( node<C>* runner = LinkedList<C>::head;\
                                        runner != NULL;\
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
    _node->next = NULL;
    _node->value = value;

    return _node;
}


template <class C>
C LinkedList<C>::FreeNode(node<C>* previousNode) {
    node<C>* unused = NULL;
    // delete head of this list
    if (previousNode == NULL) {
        unused = LinkedList<C>::head;
        LinkedList<C>::head = LinkedList<C>::head->next;
    // delete tail of this list
    } else if (previousNode->next == LinkedList<C>::tail) {
        unused = LinkedList<C>::tail;
        LinkedList<C>::tail = previousNode;
        LinkedList<C>::tail->next = NULL;
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
    LinkedList<C>::traverser(LinkedList<C>::head, NULL, bw);
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
    $for_each(runner) {
        if (index == _current_index + 1) {
            return LinkedList<C>::insertNode(runner, value);
        }
        _current_index++;
    }
    return LinkedList<C>::addTail(value);
}


template <class C>
node<C>* LinkedList<C>::get(int index) {
    int _current_index = 0;
    $for_each(runner) {
        if (index == _current_index) {
            return runner;
        }
        _current_index++;
    }
    return NULL;
}


template <class C>
C LinkedList<C>::delHead() {
    return LinkedList<C>::FreeNode(NULL);
}


template <class C>
C LinkedList<C>::delTail() {
    C result;
    $for_each(runner) {
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
