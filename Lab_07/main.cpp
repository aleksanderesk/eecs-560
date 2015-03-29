#include <iostream>
#include "MinMaxHeap.h"

int main() {
    int size = 10;
    int vals[10] = {6, 8, 5, 2, 7, 10, 3, 9, 12, 1};

    MinMaxHeap<int> intHeap(vals, size);
    intHeap.levelorderTraverse();

    return 0;
}
