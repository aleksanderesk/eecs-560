#include <iostream>
#include <fstream>
#include <string>
#include "LeftistTree.h"

int main() {
    std::cout << "Provide the name of the integer list file" << std::endl;
    std::string fileName;
    std::cin >> fileName;

    std::ifstream input;
    input.open(fileName.c_str());

    int value;
    LeftistTree<int> intTree;
    while (input >> value) {
        intTree.insert(value);
    }

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
                intTree.insert(value);
                break;
            case 2:
                intTree.deleteMin();
                break;
            case 4:
                intTree.levelorderTraverse();
                break;
        }
    }
    
    return 0;
}
