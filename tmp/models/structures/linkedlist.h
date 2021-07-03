#include "./__init__.h"

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H


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
        node<C>* initFirstNode(C);

    public:
        node<C> *head;
        node<C> *tail;


    public:
        LinkedList();
        LinkedList(C);
        LinkedList(C*, C*);
        ~LinkedList();
        size_t getSize();

        #define $ll_for_each(runner) for (\
                node<C>* runner = LinkedList<C>::head;\
                runner != nullptr;\
                runner = runner->next\
        )
        #define CHECK_INIT_NODE(V) if (\
                LinkedList<C>::initFirstNode(V) != nullptr\
        )\
                return LinkedList<C>::head;

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
node<C>* LinkedList<C>::initFirstNode(C value) {
    if (LinkedList<C>::size != 0) return nullptr;
    LinkedList<C>::head = LinkedList<C>::InitNode(value);
    LinkedList<C>::tail = LinkedList<C>::head;
    return LinkedList<C>::head;
};

template <class C>
LinkedList<C>::LinkedList() {
    LinkedList<C>::size = 0;
    LinkedList<C>::head = nullptr;
    LinkedList<C>::tail = LinkedList<C>::head;
};

template <class C>
LinkedList<C>::LinkedList(C value) {
    LinkedList<C>::size = 0;
    LinkedList<C>::initFirstNode(value);
};

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
    CHECK_INIT_NODE(value);
    node<C> *_node = LinkedList<C>::InitNode(value);
    _node->next = LinkedList<C>::head;
    LinkedList<C>::head = _node;
    return LinkedList<C>::head;
}


template <class C>
node<C>* LinkedList<C>::addTail(C value) {
    CHECK_INIT_NODE(value);
    LinkedList<C>::tail->next = LinkedList<C>::InitNode(value);
    LinkedList<C>::tail = LinkedList<C>::tail->next;
    return LinkedList<C>::tail;
}


template <class C>
node<C>* LinkedList<C>::addAt(int index, C value) {
    int _current_index = 0;
    // for (node<C>* runner = LinkedList<C>::head; runner != NULL; runner = runner->next)
    $ll_for_each(runner) {
        if (index == _current_index + 1)
            return LinkedList<C>::insertNode(runner, value);

        _current_index++;
    }
    return LinkedList<C>::addTail(value);
}


template <class C>
node<C>* LinkedList<C>::search(C value) {
    $ll_for_each(runner)
        if (runner->value = value) return runner;

    return nullptr;
}


template <class C>
node<C>* LinkedList<C>::get(int index) {
    int _current_index = 0;
    $ll_for_each(runner) {
        if (index == _current_index)
            return runner;
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


#endif /*_LINKEDLIST_H*/