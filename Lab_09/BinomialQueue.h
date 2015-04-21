/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Descr: Class description for a Binomial Queue
 */
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
        Queue<BinomialNode<ItemType>*> levelorderQueue1;
        Queue<BinomialNode<ItemType>*> levelorderQueue2;

        void insertHelper(BinomialNode<ItemType>* queueToInertPtr);
        void deleteQueue(BinomialNode<ItemType>* rootPtr);
        void resetRootPtr();
        BinomialNode<ItemType>* merge(BinomialNode<ItemType>* q1, BinomialNode<ItemType>* q2);

        void traverseQueue(BinomialNode<ItemType>* rootPtr, void op(BinomialNode<ItemType>*));
        static void deleteNode(BinomialNode<ItemType>* nodePtr);
        static void printNode(BinomialNode<ItemType>* nodePtr);

    public:
        BinomialQueue();
        virtual ~BinomialQueue();
        
        void insert(ItemType anItem);
        void deleteMin();
        void levelorderTraverse();
};

#include "BinomialQueue.cpp"
#endif
