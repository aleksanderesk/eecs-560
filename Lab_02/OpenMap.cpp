/**
 * Name: Aleksander Eskilson
 * Email: aeskilson@ku.edu
 * KUID: 2373732
 * Desc: Implementation of the OpenMap class
 */
#include <iostream>

/** Default constructor */
template<class ItemType>
OpenMap<ItemType>::OpenMap() {
    tableSize = 0;
    table = new Node<ItemType>*[0];
}

/** 
 * @param size
 * Size of the pointer array for the hashmap
 */
template<class ItemType>
OpenMap<ItemType>::OpenMap(int size) {
    tableSize = size;
    table = new Node<ItemType>*[tableSize];

    for (int i = 0; i < tableSize; i++) {
        table[i] = NULL;
    }
}

/** Default destructor */
template<class ItemType>
OpenMap<ItemType>::~OpenMap() {
    for (int i = 0; i < tableSize; i++) {
        Node<ItemType>* currPtr = table[i];
        while (currPtr != NULL) {
            Node<ItemType>* nodeToDeletePtr = currPtr;
            currPtr = currPtr->getNext();

            delete nodeToDeletePtr;
        }
    }
}

/**
 * @param value
 * Item to generate hash from
 * @return
 * Integer representing cell of array to insert item
 */
template<class ItemType>
int OpenMap<ItemType>::hash(const ItemType& value) const {
    return (value % tableSize);
}

/**
 * @param value
 * value to find in the hashmap
 * @return
 * Boolean indicating whether the item was found in the hashmap
 */
template<class ItemType>
bool OpenMap<ItemType>::find(const ItemType& value) const {
    int key = hash(value);
    Node<ItemType>* currPtr = table[key];
    while (currPtr != NULL) {
        if (currPtr->getItem() == value) {
            return true;
        }
        else {
            currPtr = currPtr->getNext();
        }
    }
    
    return false;
}

/**
 * @param newValue
 * Value to insert into the hashmap
 * @return
 * Boolean indicating if insertion was successful
 */
template<class ItemType>
bool OpenMap<ItemType>::insert(const ItemType& newValue) const {
    if (find(newValue)) {
        return false;
    }
    else {
        int key = hash(newValue);
        Node<ItemType>* nodeToInsertPtr = new Node<ItemType>(newValue);

        // hash key has no mapped values
        if (table[key] == NULL) {
            table[key] = nodeToInsertPtr;
        }
        // hash key has at least one other mapped value
        else {
            Node<ItemType>* currPtr = table[key];
            
            while (currPtr->getNext() != NULL) {
                currPtr = currPtr->getNext();
            }
            
            currPtr->setNext(nodeToInsertPtr);
        }
        
        return true;
    }
}

/**
 * @param value
 * Item to remove from the hashmap
 * @return
 * Boolean indicating if removal was successful
 */
template<class ItemType>
bool OpenMap<ItemType>::remove(const ItemType& value) const {
    if (find(value)) {
        int key = hash(value);
        Node<ItemType>* currPtr = table[key];

        // value is in list head
        if (currPtr->getItem() == value) {
            table[key] = currPtr->getNext();
            delete currPtr;

            return true;
        }
        else {
            // value is in list tail
            Node<ItemType>* prevPtr = currPtr;
            currPtr = currPtr->getNext();
            while (currPtr != NULL) {
                if (currPtr->getItem() == value) {
                    prevPtr->setNext(currPtr->getNext());
                    delete currPtr;

                    return true;
                }
                else {
                    prevPtr = currPtr;
                    currPtr = currPtr->getNext();
                }
            }
        }
        return false;
    }
}

/** Prints a listing of the hash cells and their contents */
template<class ItemType>
void OpenMap<ItemType>::print() {
    for (int i = 0; i < tableSize; i++) {
        std::cout << i << ": ";
        Node<ItemType>* currPtr = table[i];
        while (currPtr != NULL) {
            std::cout << currPtr->getItem() << " ";
            currPtr = currPtr->getNext();
        }
        std::cout << std::endl;
    }
}
