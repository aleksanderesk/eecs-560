#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "BinarySearchTree.h"
#include "TwoThreeTree.h"
#include "Timer.h"

int main() {
    int nValues[4] = {50000, 100000, 200000, 400000};
    double bTreeInsertionTimes[5];
    double bTreeOperationTimes[5];
    double ttTreeInsertionTimes[5];
    double ttTreeOperationTimes[5];
    int removal;
    int insertion;
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
            bTreeInsertionTimes[j] = timer.stop();
            std::cout << "Binary Tree: seed " << j << ", data size " << nValues[i] << ", time " << bTreeInsertionTimes[j] << std::endl;

            timer.start();
            for (int k = 0; k < (int) nValues[i] * 0.1; k++) {
                int choice = rand() % 4;
                switch (choice) {
                    case 0:
                        bTree -> deleteMin();
                        break;
                    case 1:
                        bTree -> deleteMax();
                        break;
                    case 2:
                        removal = rand() % (nValues[i] * 4);
                        bTree -> remove(removal);
                        break;
                    case 3:
                        insertion = rand() % (nValues[i] * 4);
                        bTree -> add(insertion);
                        break;
                }
            }
            bTreeOperationTimes[j] = timer.stop();
            std::cout << "Binary Tree: seed " << j << ", operations " << nValues[i] * 0.1 << ", time " << bTreeOperationTimes[j] << std::endl;
            delete bTree;

            srand(j);
            timer.start();
            for (int k = 0; k < nValues[i]; k++) {
                int entry = rand() % (nValues[i] * 4);
                ttTree -> insert(entry);
            }
            ttTreeInsertionTimes[j] = timer.stop();
            std::cout << "Two Three Tree: seed " << j << ", data size " << nValues[i] << ", time " << ttTreeInsertionTimes[j] << std::endl;

            timer.start();
            for (int k = 0; k < (int) nValues[i] * 0.1; k++) {
                int choice = rand() % 4;
                switch (choice) {
                    case 0:
                        ttTree -> deleteMin();
                        break;
                    case 1:
                        ttTree -> deleteMax();
                        break;
                    case 2:
                        removal = rand() % (nValues[i] * 4);
                        ttTree -> remove(removal);
                        break;
                    case 3:
                        insertion = rand() % (nValues[i] * 4);
                        ttTree -> insert(insertion);
                        break;
                }
            }
            ttTreeOperationTimes[j] = timer.stop();
            std::cout << "Two Three Tree: seed " << j << ", operations " << nValues[i] * 0.1 << ", time " << ttTreeOperationTimes[j] << std::endl;
            delete ttTree;
            
            std::cout << std::endl;
        }

        double bTreeInsertionSum = 0;
        double bTreeOperationSum = 0;
        double ttTreeInsertionSum = 0;
        double ttTreeOperationSum = 0;
        for (int i = 0; i < 5; i++) {
            bTreeInsertionSum += bTreeInsertionTimes[i];
            bTreeOperationSum += bTreeOperationTimes[i];
            ttTreeInsertionSum += ttTreeInsertionTimes[i];
            ttTreeOperationSum += ttTreeOperationTimes[i];
        }

        std::cout << "Binary Tree average insertion time: " << bTreeInsertionSum / 5.0 << std::endl;
        std::cout << "Binary Tree average operation time: " << bTreeOperationSum / 5.0 << std::endl;
        std::cout << "Two Three Tree average insertion time: " << ttTreeInsertionSum / 5.0 << std::endl;
        std::cout << "Two Three Tree average operation time: " << ttTreeOperationSum / 5.0 << std::endl;

        std::cout << std::endl;
    }

    return 0;
}
