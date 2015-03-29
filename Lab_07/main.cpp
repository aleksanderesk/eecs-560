#include <iostream>
#include "MinMaxHeap.h"

int main() {
    int size = 10;
    int vals[10] = {6, 8, 5, 2, 7, 10, 3, 9, 12, 1};

    MinMaxHeap<int> intHeap(vals, size);

    int selection;
    while (selection != 5) {
        std::cout << "Please choose one of the following commands:" << std::endl;
        std::cout << "1- insert\n2- deletemin\n3- deletemax\n4- levelorder\n5- exit" << std::endl;
        std::cin >> selection;
       
        int value;
        switch (selection) {
            case 1:
                std::cout << "Choose a number to be inserted to the heap:" << std::endl;
                std::cin >> value;
                intHeap.insert(value);
                break;
            case 2:
                intHeap.deleteMin();
                break;
            case 3:
                intHeap.deleteMax();
                break;
            case 4:
                intHeap.levelorderTraverse();
                break;
        }
    }
    
    return 0;
}
