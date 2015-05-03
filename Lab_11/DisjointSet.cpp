/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Desc: Class implementation for Disjoint Set
 */
#include <iostream>

template<typename ItemType>
DisjointSet<ItemType>::DisjointSet() {
}

template<typename ItemType>
DisjointSet<ItemType>::DisjointSet(ItemType* set, int size) {
    setSize = size;
    auxArr = new SetNode<ItemType>*[size];
    for (int i = 0; i < size; i++) {
        auxArr[i] = new SetNode<ItemType>(set[i]);
    }
}

template<typename ItemType>
DisjointSet<ItemType>::~DisjointSet() {
    delete[] auxArr;
}

template<typename ItemType>
void DisjointSet<ItemType>::setUnion(const ItemType seti, const ItemType setj) {
    SetNode<ItemType>* setiPtr = NULL;
    SetNode<ItemType>* setjPtr = NULL;

    for (int i = 0; i < setSize; i++) {
        if (auxArr[i] -> getItem() == seti) {
            setiPtr = auxArr[i];
            break;
        }
    }
    for (int i = 0; i < setSize; i++) {
        if (auxArr[i] -> getItem() == setj) {
            setjPtr = auxArr[i];
            break;
        }
    }
    setiPtr = findHelper(setiPtr);
    setjPtr = findHelper(setjPtr);

    if (setiPtr != NULL && setjPtr != NULL) {
        if (setiPtr -> getRank() <= setjPtr -> getRank()) {
            setiPtr -> setParentPtr(setjPtr);

            if (setiPtr -> getRank() == setjPtr -> getRank()) {
                setjPtr -> setRank(setjPtr -> getRank() + 1);
            }
        }
        else {
            setjPtr -> setParentPtr(setiPtr);
        }
    }
}

template<typename ItemType>
SetNode<ItemType>* DisjointSet<ItemType>::findHelper(SetNode<ItemType>* setPtr) {
    if (setPtr -> getParentPtr() == NULL) {
        return setPtr;
    }
    else {
        return findHelper(setPtr -> getParentPtr());
    }
}

template<typename ItemType>
ItemType DisjointSet<ItemType>::find(ItemType value) {
    SetNode<ItemType>* elemPtr = NULL;
    for (int i = 0; i < setSize; i++) {
        if (auxArr[i] -> getItem() == value) {
            elemPtr = auxArr[i];
            break;
        }
    }

    if (elemPtr == NULL) {
        return -1;
    }
    else {
        return findHelper(elemPtr) -> getItem();
    }
}
