/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Descr: Implementation of Queue using a simple linked list
 */
#include <exception>
template<class ItemType>
Queue<ItemType>::Queue() : headPtr(NULL), tailPtr(NULL), itemCount(0) {
}

template<class ItemType>
Queue<ItemType>::~Queue() {
    while (!(isEmpty())) {
        dequeue();
    }
}

template<class ItemType>
bool Queue<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
void Queue<ItemType>::enqueue(const ItemType& newValue) {
    Node<ItemType>* newNodePtr = new Node<ItemType>(newValue);
    if (isEmpty()) {
        headPtr = newNodePtr;
        tailPtr = headPtr;
    }
    else {
        tailPtr -> setNext(newNodePtr);
        tailPtr = newNodePtr;
    }

    itemCount++;
}

template<class ItemType>
void Queue<ItemType>::dequeue() {
    if (!(isEmpty())) {
        Node<ItemType>* nodeToRemovePtr = headPtr;
        headPtr = nodeToRemovePtr -> getNext();

        delete nodeToRemovePtr;

        itemCount--;
    }
}

/** Only call after having checked that the queue is not empty */
template<class ItemType>
ItemType Queue<ItemType>::peek() const {
    return headPtr -> getItem();
}
