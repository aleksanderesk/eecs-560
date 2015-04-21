#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "BinomialQueue.h"
#include "LeftistTree.h"
#include "SkewTree.h"
#include "Timer.h"

int main() {
    int nValues[4] = {50000, 100000, 200000, 400000};
    double binomialQueueInsertionTimes[5];
    double binomialQueueOperationTimes[5];
    double leftistTreeInsertionTimes[5];
    double leftistTreeOperationTimes[5];
    double skewTreeInsertionTimes[5];
    double skewTreeOperationTimes[5];
    int insertion;
    Timer timer;

    ofstream in;
    ofstream op;
    in.open("insertion.txt", ios::out | ios::app);
    op.open("operation.txt", ios::out | ios::app);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            BinomialQueue<int>* binomialQueue = new BinomialQueue<int>;
            LeftistTree<int>* leftistTree = new LeftistTree<int>;
            SkewTree<int>* skewTree = new SkewTree<int>;

            srand(j);
            timer.start();
            for (int k = 0; k < nValues[i]; k++) {
                int entry = rand() % (nValues[i] * 4);
                binomialQueue -> insert(entry);
            }
            binomialQueueInsertionTimes[j] = timer.stop();
            std::cout << "Binomial Queue: seed " << j << ", data size " << nValues[i] << ", time " << binomialQueueInsertionTimes[j] << std::endl;
            in << "Binomial & " << nValues[i] << " & " << binomialQueueInsertionTimes[j] << " \\\\" << std::endl;

            timer.start();
            for (int k = 0; k < (int) nValues[i] * 0.1; k++) {
                int choice = rand() % 2;
                switch (choice) {
                    case 0:
                        binomialQueue -> deleteMin();
                        break;
                    case 1:
                        insertion = rand() % (nValues[i] * 4);
                        binomialQueue -> insert(insertion);
                        break;
                }
            }
            binomialQueueOperationTimes[j] = timer.stop();
            std::cout << "Binomail Queue: seed " << j << ", operations " << nValues[i] * 0.1 << ", time " << binomialQueueOperationTimes[j] << std::endl;
            op << "Binomial & " << nValues[i] << " & " << binomialQueueOperationTimes[j] << " \\\\" << std::endl;
            delete binomialQueue;


            srand(j);
            timer.start();
            for (int k = 0; k < nValues[i]; k++) {
                int entry = rand() % (nValues[i] * 4);
                leftistTree -> insert(entry);
            }
            leftistTreeInsertionTimes[j] = timer.stop();
            std::cout << "Leftist Tree: seed " << j << ", data size " << nValues[i] << ", time " << leftistTreeInsertionTimes[j] << std::endl;
            in << "Leftist & " << nValues[i] << " & " << leftistTreeInsertionTimes[j] << " \\\\" << std::endl;

            timer.start();
            for (int k = 0; k < (int) nValues[i] * 0.1; k++) {
                int choice = rand() % 2;
                switch (choice) {
                    case 0:
                        leftistTree -> deleteMin();
                        break;
                    case 1:
                        insertion = rand() % (nValues[i] * 4);
                        leftistTree -> insert(insertion);
                        break;
                }
            }
            leftistTreeOperationTimes[j] = timer.stop();
            std::cout << "Leftist Tree: seed " << j << ", operations " << nValues[i] * 0.1 << ", time " << leftistTreeOperationTimes[j] << std::endl;
            op << "Leftist & " << nValues[i] << " & " << leftistTreeOperationTimes[j] << " \\\\" << std::endl;
            delete leftistTree;

            srand(j);
            timer.start();
            for (int k = 0; k < nValues[i]; k++) {
                int entry = rand() % (nValues[i] * 4);
                skewTree -> insert(entry);
            }
            skewTreeInsertionTimes[j] = timer.stop();
            std::cout << "Skew Tree: seed " << j << ", data size " << nValues[i] << ", time " << skewTreeInsertionTimes[j] << std::endl;
            in << "Skew & " << nValues[i] << " & " << skewTreeInsertionTimes[j] << " \\\\" << std::endl;

            timer.start();
            for (int k = 0; k < (int) nValues[i] * 0.1; k++) {
                int choice = rand() % 4;
                switch (choice) {
                    case 0:
                        skewTree -> deleteMin();
                        break;
                    case 1:
                        insertion = rand() % (nValues[i] * 4);
                        skewTree -> insert(insertion);
                        break;
                }
            }
            skewTreeOperationTimes[j] = timer.stop();
            std::cout << "Skew Tree: seed " << j << ", operations " << nValues[i] * 0.1 << ", time " << skewTreeOperationTimes[j] << std::endl;
            op << "Skew & " << nValues[i] << " & " << skewTreeOperationTimes[j] << " \\\\" << std::endl;
            delete skewTree;
            
            std::cout << std::endl;

        }

        double binomialQueueInsertionSum = 0;
        double binomialQueueOperationSum = 0;
        double leftistTreeInsertionSum = 0;
        double leftistTreeOperationSum = 0;
        double skewTreeInsertionSum = 0;
        double skewTreeOperationSum = 0;
        for (int k = 0; k < 5; k++) {
            binomialQueueInsertionSum += binomialQueueInsertionTimes[k];
            binomialQueueOperationSum += binomialQueueOperationTimes[k];
            leftistTreeInsertionSum += leftistTreeInsertionTimes[k];
            leftistTreeOperationSum += leftistTreeOperationTimes[k];
            skewTreeInsertionSum += skewTreeInsertionTimes[k];
            skewTreeOperationSum += skewTreeOperationTimes[k];
        }
        std::cout << "Binomial Queue average insertion time: " << binomialQueueInsertionSum / 5.0 << std::endl;
        std::cout << "Binomial Queue average operation time: " << binomialQueueOperationSum / 5.0 << std::endl;
        std::cout << "Leftist Tree average insertion time: " << leftistTreeInsertionSum / 5.0 << std::endl;
        std::cout << "Leftist Tree average operation time: " << leftistTreeOperationSum / 5.0 << std::endl;
        std::cout << "Skew Tree average insertion time: " << skewTreeInsertionSum / 5.0 << std::endl;
        std::cout << "Skew Tree average operation time: " << skewTreeOperationSum / 5.0 << std::endl;
        in << "Binomial & " << nValues[i] << " & " << binomialQueueInsertionSum / 5.0 << " \\\\" << std::endl;
        in << "Leftist & " << nValues[i] << " & " << leftistTreeInsertionSum / 5.0 << " \\\\" << std::endl;
        in << "Skew & " << nValues[i] << " & " << skewTreeInsertionSum / 5.0 << " \\\\" << std::endl;
        op << "Binomial & " << nValues[i] << " & " << binomialQueueOperationSum / 5.0 << " \\\\" << std::endl;
        op << "Leftist & " << nValues[i] << " & " << leftistTreeOperationSum / 5.0 << " \\\\" << std::endl;
        op << "Skew & " << nValues[i] << " & " << skewTreeOperationSum / 5.0 << " \\\\" << std::endl;

        std::cout << std::endl;

    }

    in.close();
    op.close();
    return 0;
}
