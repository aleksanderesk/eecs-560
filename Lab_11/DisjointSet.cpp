#include <iostream>

template<typename ItemType>
DisjointSet<ItemType>::DisjointSet() {
}

template<typename ItemType>
DisjointSet<ItemType>::DisjointSet(ItemType set[], int size) {
    auxArr = new SetNode<ItemType>[size];
    for (int i = 0; i < size; i++) {
        auxArr[i] = new SetNode<ItemType>(set[i]);
    }
}

template<typename ItemType>
DisjointSet<ItemType>::~DisjointSet() {
    delete[] auxArr;
}

template<typename ItemType>
void DisjointSet<ItemType>::union(const ItemType seti, const ItemType setj) {
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
            setjPtr = AuxArr[i];
            break;
        }
    }

    if (setiPtr != NULL && setjPtr != NULL) {
        if (seti -> getRank() <= setj -> getRank()) {
            seti -> setParentPtr(setj);

            if (seti -> getRank() == setj -> getRank()) {
                setj -> setRank(setj -> getRank() + 1);
            }
        }
        else {
            setj -> setParentPtr(seti);
        }
    }
}

template<typename ItemType>
SetNode<ItemType>* DisjointSet<ItemType>::findHelper(SetNode<ItemType>* setPtr) {
    if (setPtr -> getParent() == NULL) {
        return setPtr;
    }
    else {
        return findHelper(setPtr -> getParent());
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
