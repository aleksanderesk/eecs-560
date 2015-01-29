/**
 * Name: Aleksander Eskilson
 * Email: aeskilson@ku.edu
 * KUID: 2373732
 * Desc: Implementation of the LinkedList class
 */
#include <iostream>

/** Empty constructor */
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(NULL), itemCount(0) {
}

/** Destructor */
template<class ItemType>
LinkedList<ItemType>::~LinkedList() {
    clear();
}

/** Determines if list contains no values */
template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    return itemCount == 0;
}

/** Inserts a new value at the tail of the list */
template<class ItemType>
void LinkedList<ItemType>::insert(const ItemType& newEntry) {
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
    if (isEmpty()) {
        headPtr = newNodePtr;
    } else {
        insertHelper(headPtr, newNodePtr);
    }

    itemCount++;
}

/** Recursive helper implementation of insert */
template<class ItemType>
void LinkedList<ItemType>::insertHelper(Node<ItemType>* currPtr, Node<ItemType>* newNodePtr) {
    if (currPtr->getNext() == NULL) {
        currPtr->setNext(newNodePtr);
    } else {
        insertHelper(currPtr->getNext(), newNodePtr);
    }
}

/** 
 * Recursive helper method that returns the pointer to a node preceding a node 
 * containing a value to find
 */
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::find(Node<ItemType>* currPtr, const ItemType& entry) {
    if (currPtr->getNext() == NULL) {
        return NULL;
    } else {
        Node<ItemType>* nextNode = currPtr->getNext();
        if (nextNode->getItem() == entry) {
            return currPtr;
        } else {
            find(nextNode, entry);
        }
    }
}

/** Removes a value from the list, returns a message if the value does not exist */
template<class ItemType>
void LinkedList<ItemType>::erase(const ItemType& entry) {
    Node<ItemType>* nodeToDeletePtr;
    // if the list is empty
    if (isEmpty()) {
        std::cout << "The value does not exist in the list" << std::endl;
    // if the head contains the item
    } else if ((headPtr->getItem()) == entry) {
        nodeToDeletePtr = headPtr;
        headPtr = (headPtr->getNext());

        delete nodeToDeletePtr;
        itemCount--;
    } else {
        Node<ItemType>* prevPtr = find(headPtr, entry);
        // if the element does not exist
        if (prevPtr == NULL) {
            std::cout << "The value does not exist in the list" << std::endl;
        // if the element is in the list
        } else {
            Node<ItemType>* nodeToDeletePtr = prevPtr->getNext();
            prevPtr->setNext(nodeToDeletePtr->getNext());

            delete nodeToDeletePtr;
            itemCount--;
        }
    }
}
/** Prints all elements of the list in order */
template<class ItemType>
void LinkedList<ItemType>::print() {
    Node<ItemType>* currPtr = headPtr;
    std::cout << "List: ";
    while (currPtr != NULL) {
        ItemType entry = currPtr->getItem();
        std::cout << entry << " ";

        currPtr = currPtr->getNext();
    }

    std::cout << std::endl;
}

/** Removes all elements from the list */
template<class ItemType>
void LinkedList<ItemType>::clear() {
    while(headPtr != NULL) {
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = nodeToDeletePtr->getNext();

        delete nodeToDeletePtr;
    }
}
