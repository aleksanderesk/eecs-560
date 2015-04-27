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
    double binomialQueueInsertionTimes[20];
    double binomialQueueOperationTimes[20];
    double leftistTreeInsertionTimes[20];
    double leftistTreeOperationTimes[20];
    double skewTreeInsertionTimes[20];
    double skewTreeOperationTimes[20];
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
            binomialQueueInsertionTimes[j + i * 5] = timer.stop();
            std::cout << "Binomial Queue: seed " << j << ", data size " << nValues[i] << ", time " << binomialQueueInsertionTimes[j + i * 5] << std::endl;

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
            binomialQueueOperationTimes[j + i * 5] = timer.stop();
            std::cout << "Binomail Queue: seed " << j << ", operations " << nValues[i] * 0.1 << ", time " << binomialQueueOperationTimes[j + i * 5] << std::endl;
            delete binomialQueue;


            srand(j);
            timer.start();
            for (int k = 0; k < nValues[i]; k++) {
                int entry = rand() % (nValues[i] * 4);
                leftistTree -> insert(entry);
            }
            leftistTreeInsertionTimes[j + i * 5] = timer.stop();
            std::cout << "Leftist Tree: seed " << j << ", data size " << nValues[i] << ", time " << leftistTreeInsertionTimes[j + i * 5] << std::endl;

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
            leftistTreeOperationTimes[j + i * 5] = timer.stop();
            std::cout << "Leftist Tree: seed " << j << ", operations " << nValues[i] * 0.1 << ", time " << leftistTreeOperationTimes[j + i * 5] << std::endl;
            delete leftistTree;

            srand(j);
            timer.start();
            for (int k = 0; k < nValues[i]; k++) {
                int entry = rand() % (nValues[i] * 4);
                skewTree -> insert(entry);
            }
            skewTreeInsertionTimes[j + i * 5] = timer.stop();
            std::cout << "Skew Tree: seed " << j << ", data size " << nValues[i] << ", time " << skewTreeInsertionTimes[j + i * 5] << std::endl;

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
            skewTreeOperationTimes[j + i * 5] = timer.stop();
            std::cout << "Skew Tree: seed " << j << ", operations " << nValues[i] * 0.1 << ", time " << skewTreeOperationTimes[j + i * 5] << std::endl;
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
            binomialQueueInsertionSum += binomialQueueInsertionTimes[k + i * 5];
            binomialQueueOperationSum += binomialQueueOperationTimes[k + i * 5];
            leftistTreeInsertionSum += leftistTreeInsertionTimes[k + i * 5];
            leftistTreeOperationSum += leftistTreeOperationTimes[k + i * 5];
            skewTreeInsertionSum += skewTreeInsertionTimes[k + i * 5];
            skewTreeOperationSum += skewTreeOperationTimes[k + i * 5];
        }
        std::cout << "Binomial Queue average insertion time: " << binomialQueueInsertionSum / 5.0 << std::endl;
        std::cout << "Binomial Queue average operation time: " << binomialQueueOperationSum / 5.0 << std::endl;
        std::cout << "Leftist Tree average insertion time: " << leftistTreeInsertionSum / 5.0 << std::endl;
        std::cout << "Leftist Tree average operation time: " << leftistTreeOperationSum / 5.0 << std::endl;
        std::cout << "Skew Tree average insertion time: " << skewTreeInsertionSum / 5.0 << std::endl;
        std::cout << "Skew Tree average operation time: " << skewTreeOperationSum / 5.0 << std::endl;

        std::cout << std::endl;
    }

    for (int m = 0; m < 3; m++) {
        if (m == 0) {
            for (int k = 0; k < 20; k++) {
                in << "Binomial & " << nValues[k / 5] << " & " << binomialQueueInsertionTimes[k] << "\\\\" << std::endl;
            }
            for (int k = 0; k < 20; k++) {
                op << "Binomial & " << nValues[k / 5] << " & " << binomialQueueOperationTimes[k] << "\\\\" << std::endl;
            }
        }
        else if (m == 1) {
            for (int k = 0; k < 20; k++) {
                in << "Leftist & " << nValues[k / 5] << " & " << leftistTreeInsertionTimes[k] << "\\\\" << std::endl;
            }
            for (int k = 0; k < 20; k++) {
                op << "Leftist & " << nValues[k / 5] << " & " << leftistTreeOperationTimes[k] << "\\\\" << std::endl;
            }
        }
        else {
            for (int k = 0; k < 20; k++) {
                in << "Skew & " << nValues[k / 5] << " & " << skewTreeInsertionTimes[k] << "\\\\" << std::endl;
            }
            for (int k = 0; k < 20; k++) {
                op << "Skew & " << nValues[k / 5] << " & " << skewTreeOperationTimes[k] << "\\\\" << std::endl;
            }
        }
    }

    double binomialQueueInsertionSum = 0;
    double binomialQueueOperationSum = 0;
    double leftistTreeInsertionSum = 0;
    double leftistTreeOperationSum = 0;
    double skewTreeInsertionSum = 0;
    double skewTreeOperationSum = 0;
    for (int m = 0; m < 3; m++) {
        if (m == 0) {
            for (int n = 0; n < 4; n++) {
                for (int p = 0; p < 5; p++) {
                    binomialQueueInsertionSum += binomialQueueInsertionTimes[p + n * 5];
                    binomialQueueOperationSum += binomialQueueOperationTimes[p + n * 5];
                }
                in << "Binomial & " << nValues[n] << " & " << binomialQueueInsertionSum / 5.0 << "\\\\" << std::endl;
                op << "Binomial & " << nValues[n] << " & " << binomialQueueOperationSum / 5.0 << "\\\\" << std::endl;
                binomialQueueInsertionSum = 0;
                binomialQueueOperationSum = 0;
            }
        }
        else if (m == 1) {
            for (int n = 0; n < 4; n++) {
                for (int p = 0; p < 5; p++) {
                    leftistTreeInsertionSum += leftistTreeInsertionTimes[p + n * 5];
                    leftistTreeOperationSum += leftistTreeOperationTimes[p + n * 5];
                }
                in << "Leftist & " << nValues[n] << " & " << leftistTreeInsertionSum / 5.0 << "\\\\" << std::endl;
                op << "Leftist & " << nValues[n] << " & " << leftistTreeOperationSum / 5.0 << "\\\\" << std::endl;
                leftistTreeInsertionSum = 0;
                leftistTreeOperationSum = 0;
            }

        }
        else {
            for (int n = 0; n < 4; n++) {
                for (int p = 0; p < 5; p++) {
                    skewTreeInsertionSum += skewTreeInsertionTimes[p + n * 5];
                    skewTreeOperationSum += skewTreeOperationTimes[p + n * 5];
                }
                in << "Skew & " << nValues[n] << " & " << skewTreeInsertionSum / 5.0 << "\\\\" << std::endl;
                op << "Skew & " << nValues[n] << " & " << skewTreeOperationSum / 5.0 << "\\\\" << std::endl;
                skewTreeInsertionSum = 0;
                skewTreeOperationSum = 0;
            }
        }
    }

    in.close();
    op.close();
    return 0;
}
