/**
 * Name: Aleksander Eskilson
 * Email: aeskilson@ku.edu
 * KUID: 2373732
 * Desc: Main method providing access to the LinkedList.
 */
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"

/** Helper method that builds the list from an integer file */
void buildList(LinkedList<int>& intList) {
    std::cout << "Provide the name of the integer list file" << std::endl;
    std::string fileName;
    std::cin >> fileName;

    std::ifstream input;
    input.open(fileName.c_str());

    int value;
    while (input >> value) {
        intList.insert(value);
    }
}

int main() {
    LinkedList<int> intList;
    buildList(intList);
    
    int selection;
    int value;
    while (selection != 4) {
        std::cout << "Please choose one of the following commands:" << std::endl;
        std::cout << "1- insert\n2- delete\n3- print\n4- exit" << std::endl;
        std::cin >> selection;

        switch (selection) {
            case 1:
                std::cout << "Choose a number to be inserted to the list:" << std::endl;
                std::cin >> value;
                intList.insert(value);
                break;
            case 2:
                std::cout << "Choose a number to be deleted form the list:" << std::endl;
                std::cin >> value;
                intList.erase(value);
                break;
            case 3:
                intList.print();
                break;
        }
                
    }

    return 0;
}
