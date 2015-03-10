/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Descr: Driver program for Open and Closed hashmaps
 */
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "ClosedMap.h"
#include "OpenMap.h"
#include "Timer.h"

int main() {
    int TABLE_SIZE = 600011;
    float lambdas[5] = {0.2, 0.3, 0.4, 0.5, 0.6};
    double openTimes[5];
    double closedTimes[5];
    Timer timer;

    for (int i = 0; i < 5; i++) {
        int dataSize = floor(TABLE_SIZE * lambdas[i]);
        OpenMap<long>* openMap = new OpenMap<long>(dataSize);
        ClosedMap<long>* closedMap = new ClosedMap<long>(dataSize);

        srand(i);
        timer.start();
        for (int j = 0; j < dataSize; j++) {
            long entry = rand() % 2147483647L;
            openMap->insert(entry);
        }
        openTimes[i] = timer.stop();
        std::cout << "Open Map: seed " << i << ", load " << lambdas[i] << ", data size " << dataSize << ", time " << openTimes[i] << std::endl;
        delete openMap;

        srand(i);
        timer.start();
        for (int j = 0; j < dataSize; j++) {
            long entry = rand() % 2147483647L;
            closedMap->insert(entry);
        }
        closedTimes[i] = timer.stop();
        std::cout << "Closed Map: seed " << i << ", load " << lambdas[i] << ", data size " << dataSize << ", time " << closedTimes[i] << std::endl;
        delete closedMap;

        std::cout << std::endl;
    }

    double openSum = 0;
    double closedSum = 0;
    for (int i = 0; i < 5; i++) {
        openSum += openTimes[i];
        closedSum += closedTimes[i];
    }

    std::cout << "Open Map average time: " << openSum / 5.0 << std::endl;
    std::cout << "Closed Map average time " << closedSum / 5.0 << std::endl;

    return 0;
}
