/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Desc: Test program for an integer Binary Search Tree
 */
#include <iostream>
#include <fstream>
#include <string>
#include "TwoThreeTree.h"

int main() {
    std::cout << "Provide the name of the integer list file" << std::endl;
    std::string fileName;
    std::cin >> fileName;

    std::ifstream input;
    input.open(fileName.c_str());

    int value;
    TwoThreeTree<int> intTree;
    while (input >> value) {
        intTree.insert(value);
    }

    int selection;
    while (selection != 6) {
        std::cout << "Please choose one of the following commands:" << std::endl;
        std::cout << "1- insert\n2- delete\n3- deletemin\n4- deletemax\n5- levelorder\n6- exit" << std::endl;
        std::cin >> selection;
        
        switch (selection) {
            case 1:
                std::cout << "Choose a number to be inserted to the tree:" << std::endl;
                std::cin >> value;
                intTree.insert(value);
                break;
            case 2:
                std::cout << "Choose a number to be deleted from the tree:" << std::endl;
                std::cin >> value;
                intTree.remove(value);
                break;
            case 3:
                intTree.deleteMin();
                break;
            case 4:
                intTree.deleteMax();
                break;
            case 5:
                intTree.levelorderTraverse();
                break;
        }
    }
    
    return 0;
}
