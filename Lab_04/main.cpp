/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Desc: Test program for an integer Binary Search Tree
 */
#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTree.h"

int main() {
    std::cout << "Provide the name of the integer list file" << std::endl;
    std::string fileName;
    std::cin >> fileName;

    std::ifstream input;
    input.open(fileName.c_str());

    int value;
    BinarySearchTree<int> intTree;
    while (input >> value) {
        intTree.add(value);
    }

    int selection;
    while (selection != 8) {
        std::cout << "Please choose one of the following commands:" << std::endl;
        std::cout << "1- insert\n2- delete\n3- deletemin\n4- deletemax\n5- preorder\n6- inorder\n7- levelorder\n8- exit" << std::endl;
        std::cin >> selection;
        
        switch (selection) {
            case 1:
                std::cout << "Choose a number to be inserted to the tree:" << std::endl;
                std::cin >> value;
                intTree.add(value);
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
                intTree.preorderTraverse();
                break;
            case 6:
                intTree.inorderTraverse();
                break;
            case 7:
                intTree.levelorderTraverse();
                break;
        }
    }
    
    return 0;
}
