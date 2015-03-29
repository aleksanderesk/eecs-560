#ifndef _MINMAXHEAP
#define _MINMAXHEAP

#include "Queue.h"

template<class ItemType>
class MinMaxHeap {
    private:
        ItemType* heapArr;
        int heapArrSize;
        int numValues;
        Queue<int> levelorderQueue;

        void build(const ItemType values[]);
        void trickleDown(int pos);
        void trickleDownMin(int pos);
        void trickleDownMax(int pos);
        void bubbleUp(int pos);
        void bubbleUpMin(int pos);
        void bubbleUpMax(int pos);

        bool bounded(const int index);
        bool valued(const int index);

    public:
        MinMaxHeap();
        MinMaxHeap(const ItemType values[], const int size);
        virtual ~MinMaxHeap();

        void insert(const ItemType& newEntry);
        void deleteMin();
        void deleteMax();
        void levelorderTraverse();
};

#include "MinMaxHeap.cpp"
#endif
