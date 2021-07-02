#include "./__init__.h"

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H


template <class C>
struct node { 
    C data;
    node* left;
    node* right;
};

template <class C>
uint8_t greater_like(C value_a, C value_b) {
    return value_a > value_b;
}

template <class C>
class BinaryTree {

    private:
        size_t size;

    public:
        node<C> *root;


    public:
        BinaryTree();
        ~BinaryTree();
        size_t getSize();
        node<C>* insertNode(
            C,
            uint8_t (*f)(node, node)
        );
};


/* === PRIVATE METHOD ATTRIBUTES === */
template <class C>
node<C>* BinaryTree<C>::insertNode(C value, uint8_t (*f)(node, node)) {
    if node.value > value {
    if () {
        if node.left != nil {
            node.left.insert(value)
        } else {
            node.left = InitNode(value)
        }
    } else if node.value < value {
        if node.right != nil {
            node.right.insert(value)
        } else {
            node.right = InitNode(value)
        }
    }
    return _node;
}


/* === PUBLIC METHOD ATTRIBUTES === */
template <class C>
BinaryTree<C>::BinaryTree() {
    BinaryTree<C>::size = 0;
    BinaryTree<C>::head = nullptr;
    BinaryTree<C>::tail = BinaryTree<C>::head;
};

template <class C>
node<C>* BinaryTree<C>::InitNode(C value) {
    BinaryTree<C>::size++;
    node<C> *_node = (node<C>*) malloc(sizeof(node<C>));
    _node->next = nullptr;
    _node->value = value;

    return _node;
}

template <class C>
BinaryTree<C>::~BinaryTree() {
    auto bw = [](int _, node<C>* _node) { free(_node); };
    BinaryTree<C>::traverser(BinaryTree<C>::head, nullptr, bw);
};


template <class C>
size_t BinaryTree<C>::getSize() {
    return BinaryTree<C>::size;
};


template <class C>
node<C>* BinaryTree<C>::search(C value) {
    $ll_for_each(runner)
        if (runner->value = value) return runner;

    return nullptr;
}


#endif /*_BINARYTREE_H*/

