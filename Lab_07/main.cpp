#include <iostream>
#include <fstream>
#include <string>
#include "MinMaxHeap.h"

int main() {
    std::cout << "Provide the name of the integer list file" << std::endl;
    std::string fileName;
    std::cin >> fileName;

    std::ifstream input;
    input.open(fileName.c_str());

    int size = 0;
    int value;
    while (input >> value) {
        size++;
    }

    input.clear();
    input.seekg(0, input.beg);

    int vals[size];
    int i = 0;
    while (input >> value) {
        vals[i] = value;
        i++;
    }

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
