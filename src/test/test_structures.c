#include "./test_frame.h"
#include "../models/structures/normalarray.h"
#include "../models/structures/linkedlist.h"
#include <stdio.h>

int main() {
    // ============= LinkedList =============
    int a[3] = {0, 1, 2};
    LinkedList<int> x = LinkedList<int>(1);
    assert(x.getSize() == 1);
    x.head->value = 1;
    x.addHead(-1);
    assert(x.head->value == -1);
    x.addTail(4);
    assert(x.tail->value == 4);
    x.addAt(3, 3);
    assert(x.get(3)->value == 3);
    x.addAt(3, 3);
    assert(x.get(3)->value == 3);

    int id = 2;
    int value = 2;
    assert(x.search(value)->value == value);

    auto fw = [](int crt_index, node<int> *c) { 
        // printf("fw: index:%d %d\n", crt_index, c->value); 
        assert(c->value);
    };
    auto bw = [](int crt_index, node<int> *c) { 
        // printf("bw: index:%d %d\n", crt_index, c->value);
        assert(c->value);
    };
    // x.traverser(x.head, fw, NULL);

    x.delHead();
    assert(x.head->value != -1);
    x.delTail();
    assert(x.tail->value != 3);
    int _z = x.getSize();
    x.delAt(2);
    assert(_z > x.getSize());
    x.traverser(x.head, fw, NULL);

    for (
        node<int>* runner = x.head;
        runner != nullptr;
        runner = runner->next
    )
        // printf("%d\n", runner->value);
        assert(runner->value);
    

    LinkedList<int> y = LinkedList<int>();
    y.addHead(1);
    y.traverser(y.head, fw, NULL);
    assert(y.head->value == 1);
    y.addHead(99);
    assert(y.head->value == 99);

    y.addTail(88);
    assert(y.tail->value == 88);
    y.addTail(77);
    assert(y.tail->value == 77);
    // ============= Array =============

    Array<int> b = Array<int>();
    assert(b.getSize() == 0);
    b.addHead(3);
    assert(*(b.head) == 3);
    b.addHead(3);
    assert(*(b.head) == 3);
    b.addHead(2);
    assert(*(b.head) == 2);
    b.addHead(1);
    assert(*(b.head) == 1);
    b.addHead(2);
    assert(*(b.head) == 2);
    b.addHead(1);
    assert(*(b.head) == 1);
    b.addTail(5);
    assert(*(b.get(b.getSize() - 1)) == 5);
    b.addTail(6);
    assert(*(b.head + b.getSize() - 1) == 6);
    b.addTail(7);
    assert(*(b.head + b.getSize() - 1) == 7);
    b.addAt(2, 3);
    assert(*(b.search(2)) == 2);
    b.delHead();
    assert(*(b.head) != 1);

    for(int* runner = b.head; runner < b.head + b.getSize(); runner++) {
        // printf("index: %d; element: %d\n", runner - b.head, *runner);
    }
}

