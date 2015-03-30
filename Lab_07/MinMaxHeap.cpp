/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Descr: MinMax Heap class implementation
 */
#include <iostream>
#include <cmath>

#define ARR_SIZE 1000 // A reasonable max heap size

/* empty constructor */
template<typename ItemType>
MinMaxHeap<ItemType>::MinMaxHeap() {
    heapArr = new ItemType[0];
}

/**
 * Parametrized constructor
 * Pre: An initial array of starting values, and the size of the array
 * Post: A min-max heap built from the starting values
 */
template<typename ItemType>
MinMaxHeap<ItemType>::MinMaxHeap(const ItemType values[], const int size) {
    heapArrSize = ARR_SIZE + 1;
    numValues = size;

    heapArr = new ItemType[heapArrSize];
    for (int i = 0; i < heapArrSize; i++) {
        heapArr[i] = -1;
    }

    build(values);
}

/* generic destructor */
template<typename ItemType>
MinMaxHeap<ItemType>::~MinMaxHeap() {
    delete[] heapArr;
}

/* Heapifies a min-max heap of starting values in linear time */
template<typename ItemType>
void MinMaxHeap<ItemType>::build(const ItemType values[]) {
    for (int i = 0; i < numValues; i++) {
        heapArr[i + 1] = values[i];
    }

    for (int i = numValues; i != 0; i--) {
        trickleDown(i);
    }
}

/* Deletes the minimum element */
template<typename ItemType>
void MinMaxHeap<ItemType>::deleteMin() {
    if (numValues == 0) {
        std::cout << "Heap is empty" << std::endl;
    }
    else if (numValues == 1) {
        heapArr[1] = -1;
        numValues--;
    }
    else {
        heapArr[1] = heapArr[numValues];
        heapArr[numValues] = -1;

        trickleDown(1);
        numValues--;
    }
}

/* deletes the maximum element */
template<typename ItemType>
void MinMaxHeap<ItemType>::deleteMax() {
    if (numValues == 0) { // empty 
        std::cout << "Heap is empty" << std::endl;
    }
    else if (numValues == 1) { // remove head
        heapArr[1] = -1;
        numValues--;
    }
    else { // remove the largest of the first max row, replace and trickle down
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

        numValues--;
    }
}

/* moves an element down to its appropriate level */
template<typename ItemType>
void MinMaxHeap<ItemType>::trickleDown(int pos) {
    if ((int)floor(log2(pos)) % 2 == 0) {
        trickleDownMin(pos);
    }
    else {
        trickleDownMax(pos);
    }
}

/* swap a min element with its appropriate child or grandchild */
template<typename ItemType>
void MinMaxHeap<ItemType>::trickleDownMin(int pos) {
    // find minimum among children and grandchildren
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

    // swap appropriately
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

/* swap a max element with its appropriate child or grandchild */
template<typename ItemType>
void MinMaxHeap<ItemType>::trickleDownMax(int pos) {
    // find maximum among children and grandchildren
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

    // swap appropriately
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

/* inserts an element at the end, move it to appropriate location */
template<typename ItemType>
void MinMaxHeap<ItemType>::insert(const ItemType& newValue) {
    if (numValues < heapArrSize) {
        heapArr[numValues + 1] = newValue;
        bubbleUp(numValues + 1);
        numValues++;
    }
    else {
        std::cout << "Inadequate space" << std::endl;
    }
}

/* bubble up an element to its appropriate location */
template<typename ItemType>
void MinMaxHeap<ItemType>::bubbleUp(int pos) {
    if ((int)floor(log2(pos)) % 2 == 0) {
        int parent = pos / 2;
        if (parent != 0 && heapArr[pos] > heapArr[parent]) {
            ItemType temp = heapArr[pos];
            heapArr[pos] = heapArr[parent];
            heapArr[parent] = temp;

            bubbleUpMax(parent);
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

            bubbleUpMin(parent);
        }
        else {
            bubbleUpMax(pos);
        }
    }
}

/* bubble up a min element to its appropriate row, swapping along the way */
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

/* bubble up a max element to its appropriate row, swapping along the way */
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

/* prints levelorder traversal with a newline for each level */
template<typename ItemType>
void MinMaxHeap<ItemType>::levelorderTraverse() {
    levelorderQueue.enqueue(1);
    int indexToVisit;
    bool toggle = true;
    bool prevToggle = true;

    do {
        indexToVisit = levelorderQueue.peek();
        if ((int)(floor(log2(indexToVisit))) % 2 == 0) 
            toggle = true;
        else
            toggle = false;

        if (toggle != prevToggle)
            std::cout << std::endl;

        std::cout << heapArr[indexToVisit] << " ";

        if (bounded(indexToVisit * 2) && valued(indexToVisit * 2)) {
            levelorderQueue.enqueue(indexToVisit * 2);
        }
        if (bounded(indexToVisit * 2 + 1) && valued(indexToVisit * 2 + 1)) {
            levelorderQueue.enqueue(indexToVisit * 2 + 1);
        }

        prevToggle = toggle;        

        levelorderQueue.dequeue();
    } while (!(levelorderQueue.isEmpty()));

    std::cout << std::endl;
}

/* is the index given inside the bounds of the array? */
template<typename ItemType>
bool MinMaxHeap<ItemType>::bounded(const int index) {
    return index < heapArrSize;
}

/* does the index given have a non-holder, i.e. -1, value? */
template<typename ItemType>
bool MinMaxHeap<ItemType>::valued(const int index) {
    return heapArr[index] != -1;
}
