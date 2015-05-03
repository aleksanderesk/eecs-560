/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Desc: Driver for Minimum Spanning Tree finder
 */
#include <iostream>
#include <fstream>
#include <string>
#include "Spanner.h"

int main() {
    std::cout << "Provide the name of the adjacency matrix file" << std::endl;
    std::string fileName;
    std::cin >> fileName;

    std::ifstream input;
    input.open(fileName.c_str());

    int cases;
    input >> cases;
    
    int entry;
    int dim;
    Spanner* spanner;
    for (int n = 0; n < cases; n++) {
        input >> dim;
        int** matrix = new int*[dim];
        for (int i = 0; i < dim; i++) {
            matrix[i] = new int[dim];
            for (int j = 0; j < dim; j++) {
                input >> entry;
                matrix[i][j] = entry;
            }
        }
        spanner = new Spanner(matrix, dim);
        std::cout << "Graph " << n + 1 << ":\nKruskal: ";
        spanner -> kruskals();
        std::cout << "Prim: ";
        spanner -> prims();
        std::cout << std::endl;

        delete spanner;
        spanner = NULL;
    }

    return 0;
}
