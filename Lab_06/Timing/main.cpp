#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "BinarySearchTree.h"
#include "TwoThreeTree.h"
#include "Timer.h"

int main() {
    int nValues[4] = {50000, 100000, 200000, 400000};
    double bTreeTimes[5];
    double ttTreeTimes[5];
    Timer timer;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            BinarySearchTree<int>* bTree = new BinarySearchTree<int>;
            TwoThreeTree<int>* ttTree = new TwoThreeTree<int>;

            srand(j);
            timer.start();
            for (int k = 0; k < nValues[i]; k++) {
                int entry = rand() % (nValues[i] * 4);
                bTree -> add(entry);
            }
            bTreeTimes[j] = timer.stop();
            std::cout << "Binary Tree: seed " << j << ", data size " << nValues[i] << ", time " << bTreeTimes[j] << std::endl;
            delete bTree;

            srand(j);
            timer.start();
            for (int k = 0; k < nValues[i]; k++) {
                int entry = rand() % (nValues[i] * 4);
                ttTree -> insert(entry);
            }
            ttTreeTimes[j] = timer.stop();
            std::cout << "Two Three Tree: seed " << j << ", data size " << nValues[i] << ", time " << ttTreeTimes[j] << std::endl;
            delete ttTree;
            
            std::cout << std::endl;
        }

        double bTreeSum = 0;
        double ttTreeSum = 0;
        for (int i = 0; i < 5; i++) {
            bTreeSum += bTreeTimes[i];
            ttTreeSum += ttTreeTimes[i];
        }

        std::cout << "Binary Tree average time: " << bTreeSum / 5.0 << std::endl;
        std::cout << "Two Three Tree average time: " << ttTreeSum / 5.0 << std::endl;

        std::cout << std::endl;
    }

    return 0;
}
