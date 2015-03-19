/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Descr: Definition of a Queue
 */
#ifndef _QUEUE
#define _QUEUE

#include "Node.h"

template<class ItemType>
class Queue {
    private:
        Node<ItemType>* headPtr;
        Node<ItemType>* tailPtr;
        int itemCount;

    public:
        Queue();
        virtual ~Queue();

        bool isEmpty() const;
        void enqueue(const ItemType& newValue);
        void dequeue(); // leaky, preferable to use exceptions and have only dequeue
        ItemType peek() const;
};

#include "Queue.cpp"
#endif
