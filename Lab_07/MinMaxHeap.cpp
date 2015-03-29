#include <iostream>
#include <cmath>

#define ARR_SIZE 100

template<typename ItemType>
MinMaxHeap<ItemType>::MinMaxHeap() {
    heapArr = new ItemType[0];
}

template<typename ItemType>
MinMaxHeap<ItemType>::MinMaxHeap(const ItemType values[], const int size) {
    heapArrSize = ARR_SIZE + 1;
    //heapArrSize = size + 1;
    numValues = size;

    //heapArr = new ItemType[size];
    heapArr = new ItemType[ARR_SIZE];
    for (int i = 0; i < heapArrSize; i++) {
        heapArr[i] = -1;
    }

    build(values);
}

template<typename ItemType>
MinMaxHeap<ItemType>::~MinMaxHeap() {
}

template<typename ItemType>
void MinMaxHeap<ItemType>::build(const ItemType values[]) {
    for (int i = 0; i < heapArrSize - 1; i++) {
        heapArr[i + 1] = values[i];
    }

    for (int i = numValues; i != 0; i--) {
        trickleDown(i);
    }
}

template<typename ItemType>
void MinMaxHeap<ItemType>::deleteMin() {
    if (numValues == 0) {
        std::cout << "Heap is empty" << std::endl;
    }
    else if (numValues == 1) {
        heapArr[1] = -1;
    }
    else {
        heapArr[1] = heapArr[numValues];
        heapArr[numValues] = -1;

        trickleDown(1);
        numValues--;
    }
}

template<typename ItemType>
void MinMaxHeap<ItemType>::deleteMax() {
    if (numValues == 0) {
        std::cout << "Heap is empty" << std::endl;
    }
    else if (numValues == 1) {
        heapArr[1] = -1;
    }
    else {
        if (heapArr[2] > heapArr[3]) {
            heapArr[2] = heapArr[numValues];
            heapArr[numValues] = -1;

            trickleDown(2);
        }
        else {
            heapArr[3] = heapArr[numValues];
            heapArr[numValues] = -1;
            
            trickleDown(3);
        }
    }

    numValues--;
}

template<typename ItemType>
void MinMaxHeap<ItemType>::trickleDown(int pos) {
    if ((int)floor(log2(pos)) % 2 == 0) {
        trickleDownMin(pos);
    }
    else {
        trickleDownMax(pos);
    }
}

template<typename ItemType>
void MinMaxHeap<ItemType>::trickleDownMin(int pos) {
    int lc = 2 * pos;
    int rc = 2 * pos + 1;
    int lclc = 2 * (2 * pos);
    int lcrc = 2 * (2 * pos) + 1;
    int rclc = 2 * (2 * pos + 1);
    int rcrc = 2 * (2 * pos + 1) + 1;
    int m = 0;

    if (bounded(lc) && valued(lc)) 
        m = lc;
    if (bounded(rc) && valued(rc) && heapArr[m] > heapArr[rc])
        m = rc;
    if (bounded(lclc) && valued(lclc) && heapArr[m] > heapArr[lclc])
        m = lclc;
    if (bounded(lcrc) && valued(lcrc) && heapArr[m] > heapArr[lcrc])
        m = lcrc;
    if (bounded(rclc) && valued(rclc) && heapArr[m] > heapArr[rclc])
        m = rclc;
    if (bounded(rcrc) && valued(rcrc) && heapArr[m] > heapArr[rcrc])
        m = rcrc;

    if (m != 0) {
        if (m == lclc || m == lcrc || m == rclc || m == rcrc) {

            if (heapArr[m] < heapArr[pos]) {
                ItemType temp = heapArr[m];
                heapArr[m] = heapArr[pos];
                heapArr[pos] = temp;

                int parent = m / 2;
                if (heapArr[m] > heapArr[parent]) {
                    temp = heapArr[m];
                    heapArr[m] = heapArr[parent];
                    heapArr[parent] = temp;
                }

                trickleDownMin(m);
            }
        }
        else {
            if (heapArr[m] < heapArr[pos]) {
                ItemType temp = heapArr[m];
                heapArr[m] = heapArr[pos];
                heapArr[pos] = temp;
            }
        }
    } 
}

template<typename ItemType>
void MinMaxHeap<ItemType>::trickleDownMax(int pos) {
    int lc = 2 * pos;
    int rc = 2 * pos + 1;
    int lclc = 2 * (2 * pos);
    int lcrc = 2 * (2 * pos) + 1;
    int rclc = 2 * (2 * pos + 1);
    int rcrc = 2 * (2 * pos + 1) + 1;
    int m = 0;

    if (bounded(lc) && valued(lc)) 
        m = lc;
    if (bounded(rc) && valued(rc) && heapArr[m] < heapArr[rc])
        m = rc;
    if (bounded(lclc) && valued(lclc) && heapArr[m] < heapArr[lclc])
        m = lclc;
    if (bounded(lcrc) && valued(lcrc) && heapArr[m] < heapArr[lcrc])
        m = lcrc;
    if (bounded(rclc) && valued(rclc) && heapArr[m] < heapArr[rclc])
        m = rclc;
    if (bounded(rcrc) && valued(rcrc) && heapArr[m] < heapArr[rcrc])
        m = rcrc;

    if (m != 0) {
        if (m == lclc || m == lcrc || m == rclc || m == rcrc) {
            if (heapArr[m] > heapArr[pos]) {
                ItemType temp = heapArr[m];
                heapArr[m] = heapArr[pos];
                heapArr[pos] = temp;

                int parent = m / 2;
                if (heapArr[m] < heapArr[parent]) {
                    temp = heapArr[m];
                    heapArr[m] = heapArr[parent];
                    heapArr[parent] = temp;
                }

                trickleDownMax(m);
            }
        }
        else {
            if (heapArr[m] > heapArr[pos]) {
                ItemType temp = heapArr[m];
                heapArr[m] = heapArr[pos];
                heapArr[pos] = temp;
            }
        }
    }
}

template<typename ItemType>
void MinMaxHeap<ItemType>::insert(const ItemType& newValue) {
    heapArr[numValues + 1] = newValue;
    bubbleUp(numValues + 1);
    numValues++;
}

template<typename ItemType>
void MinMaxHeap<ItemType>::bubbleUp(int pos) {
    if ((int)floor(log2(pos)) % 2 == 0) {
        int parent = pos / 2;
        if (parent != 0 && heapArr[pos] > heapArr[parent]) {
            ItemType temp = heapArr[pos];
            heapArr[pos] = heapArr[parent];
            heapArr[parent] = temp;
        }
        else {
            bubbleUpMin(pos);
        }
    }
    else {
        int parent = pos / 2;
        if (parent != 0 && heapArr[pos] < heapArr[parent]) {
            ItemType temp = heapArr[pos];
            heapArr[pos] = heapArr[parent];
            heapArr[parent] = temp;
        }
        else {
            bubbleUpMax(pos);
        }
    }
}

template<typename ItemType>
void MinMaxHeap<ItemType>::bubbleUpMin(int pos) {
    int grandparent = (pos / 2) / 2;
    if (grandparent != 0) {
        if (heapArr[pos] < heapArr[grandparent]) {
            ItemType temp = heapArr[pos];
            heapArr[pos] = heapArr[grandparent];
            heapArr[grandparent] = temp;
            
            bubbleUpMin(grandparent);
        }
    }
}

template<typename ItemType>
void MinMaxHeap<ItemType>::bubbleUpMax(int pos) {
    int grandparent = (pos / 2) / 2;
    if (grandparent != 0) {
        if (heapArr[pos] > heapArr[grandparent]) {
            ItemType temp = heapArr[pos];
            heapArr[pos] = heapArr[grandparent];
            heapArr[grandparent] = temp;
            
            bubbleUpMin(grandparent);
        }
    }
}


template<typename ItemType>
void MinMaxHeap<ItemType>::levelorderTraverse() {
    levelorderQueue.enqueue(1);
    int indexToVisit;

    do {
        indexToVisit = levelorderQueue.peek();
        std::cout << heapArr[indexToVisit] << " ";

        if (bounded(indexToVisit * 2) && valued(indexToVisit * 2)) {
            levelorderQueue.enqueue(indexToVisit * 2);
        }
        if (bounded(indexToVisit * 2 + 1) && valued(indexToVisit * 2 + 1)) {
            levelorderQueue.enqueue(indexToVisit * 2 + 1);
        }

        levelorderQueue.dequeue();
    } while (!(levelorderQueue.isEmpty()));

    std::cout << std::endl;
}

template<typename ItemType>
bool MinMaxHeap<ItemType>::bounded(const int index) {
    return index < heapArrSize;
}

template<typename ItemType>
bool MinMaxHeap<ItemType>::valued(const int index) {
    return heapArr[index] != -1;
}
