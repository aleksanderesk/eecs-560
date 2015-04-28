#include<iostream>
#include<fstream>
#include<string>
//#include "Spanner.h"

void print(int** matrix, int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

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
        print(matrix, dim);

        for (int i = 0; i < dim; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    return 0;
}
