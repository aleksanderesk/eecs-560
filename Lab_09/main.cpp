#include <iostream>
#include <fstream>
#include <string>
#include "BinomialQueue.h"

int main() {
    std::cout << "Provide the name of the integer list file" << std::endl;
    std::string fileName;
    std::cin >> fileName;

    std::ifstream input;
    input.open(fileName.c_str());

    int value;
    BinomialQueue<int> intQueue;
    while (input >> value) {
        intQueue.insert(value);
    }

    int selection;
    while (selection != 4) {
        std::cout << "Please choose one of the following commands:" << std::endl;
        std::cout << "1- insert\n2- deletemin\n3- levelorder\n4- exit" << std::endl;
        std::cin >> selection;
        
        switch (selection) {
            case 1:
                std::cout << "Choose a number to be inserted to the queue:" << std::endl;
                std::cin >> value;
                intQueue.insert(value);
                break;
            case 2:
                intQueue.deleteMin();
                break;
            case 3:
                intQueue.levelorderTraverse();
                break;
        }
    }
    
    return 0;
}
