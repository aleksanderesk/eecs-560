/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Desc: Test program for an integer open hashmap
 */
#include <iostream>
#include <fstream>
#include <string>
#include "OpenMap.h"

int main() {
    std::cout << "Provide the name of the integer list file" << std::endl;
    std::string fileName;
    std::cin >> fileName;

    std::ifstream input;
    input.open(fileName.c_str());

    int value;
    input >> value;
    OpenMap<int> intMap(value);
    while (input >> value) {
        intMap.insert(value);
    }

    int selection;
    while (selection != 4) {
        std::cout << "Please choose one of the following commands:" << std::endl;
        std::cout << "1- insert\n2- delete\n3- print\n4- exit" << std::endl;
        std::cin >> selection;
        
        switch (selection) {
            case 1:
                std::cout << "Choose a number to be inserted to the map:" << std::endl;
                std::cin >> value;
                intMap.insert(value);
                break;
            case 2:
                std::cout << "Choose a number to be deleted from the map:" << std::endl;
                std::cin >> value;
                intMap.remove(value);
                break;
            case 3:
                intMap.print();
                break;
        }
    }
    
    return 0;
}
