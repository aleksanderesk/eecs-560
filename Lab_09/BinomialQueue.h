#ifndef _BINOMIAL_QUEUE
#define _BINOMIAL_QUEUE

#include "BinomialNode.h"
#include "Queue.h"

#define MAX_ORDER 100

template<typename ItemType>
class BinomialQueue {
    private:
        BinomialNode<ItemType>* rootPtr;
        BinomialNode<ItemType>* QueueArr[MAX_ORDER];
        Queue<BinomialNode<ItemType>*> levelorderQueue;

        void queueTraverse(BinomialNode<ItemType>* rootPtr);
        void insertHelper(BinomialNode<ItemType>* queueToInertPtr);
        BinomialNode<ItemType>* merge(BinomialNode<ItemType>* q1, BinomialNode<ItemType>* q2);

    public:
        BinomialQueue();
        //virtual ~BinomialQueue();
        
        void insert(ItemType anItem);
        void deleteMin();
        void levelorderTraverse();
};

#include "BinomialQueue.cpp"
#endif
