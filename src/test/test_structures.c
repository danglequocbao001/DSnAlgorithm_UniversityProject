#include "../models/structures.hpp"
#include <stdio.h>


int main() {
    int a[3] = {0, 1, 2};
    LinkedList<int> x = LinkedList<int>(a, a+3);
    x.addHead(-1);
    x.addTail(4);
    x.addAt(3, 3);
    x.addAt(3, 3);

    int id = 2;
    int value = 2;
    printf("find with value %d\n\n", x.search(value)->value);
    printf("find with id %d; value: %d\n", id, x.get(id)->value);

    auto fw = [](int crt_index, node<int> *c) { 
        printf("fw: index:%d %d\n", crt_index, c->value); 
    };
    auto bw = [](int crt_index, node<int> *c) { 
        printf("bw: index:%d %d\n", crt_index, c->value);
    };
    x.traverser(x.head, fw, NULL);
    printf("-> this is the length of list: %d\n", x.getSize());

    x.delHead();
    x.delTail();
    x.delAt(3);

    printf("-> this is the length of list: %d\n", x.getSize());

    x.traverser(x.head, fw, NULL);


    Array<int> b = Array<int>();
    printf("-> this is the first length of list: %d\n", b.getSize());
    b.addHead(3);
    b.addHead(3);
    b.addHead(2);
    b.addHead(1);
    b.addHead(2);
    b.addHead(1);
    // b.addTail(5);
    // b.addTail(6);
    // b.addTail(7);
    // printf("====================== mark here\n");
    // b.addAt(2, 3);
    // printf("====================== mark here\n");

    printf("-> search some things with value is 2: %d\n", *(b.search(2)));
    printf("-> get value using index id=1 value=%d\n", *(b.get(1)));

    // b.delHead();

    for(int* runner = b.head; runner < b.head + b.getSize(); runner++) {
        printf("index: %d; element: %d\n", runner - b.head, *runner);
    }
    printf("[log] this is the end\n");
}

