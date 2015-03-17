#include <cstddef>

template<typename ItemType>
TwoThreeTree<ItemType>::TwoThreeTree(): rootPtr(NULL) {
}

template<typename ItemType>
TwoThreeTree<ItemType>::~TwoThreeTree() {
    destroyTree(rootPtr);
}

template<typename ItemType>
TwoThreeNode<ItemType>* TwoThreeTree<ItemType>::locate(const ItemType& value) {
    if (rootPtr == NULL) {
        return NULL;
    }
    else {
        return locateHelper(value, rootPtr);
    }
}

template<typename ItemType>
TwoThreeNode<ItemType>* TwoThreeTree<ItemType>::locateHelper(ItemType& value, TwoThreeNode<ItemType>* subtreePtr) {
    if (isLeaf(subtreePtr)) {
        return subtreePtr;
    }
    else if (value > subtreePtr -> getMinThird() && subtreePtr -> getMinThird() != -1) {
        return locateHelper(value, subtreePtr -> getThirdChild());
    }
    else if (value > subtreePtr -> getMinSecond() && subtreePtr -> getMinSecond() != -1) {
        return locateHelper(value, subtreePtr -> getSecondChild());
    }
    else {
        return locateHelper(value, subtreePtr -> getFirstChild());
    }
}

template<typename ItemType>
void TwoThreeTree<ItemType>::insert(const ItemType& newEntry) {
    TwoThreeNode<ItemType>* newLeafPtr = createLeaf(newEntry);
    if (rootPtr == NULL) {
        rootPtr = newLeafPtr;
    }
    else {
        TwoThreeNode<ItemType>* siblingPtr = locate(newEntry);
        
        if (siblingPtr -> getKey() > newLeafPtr -> getKey()) {
            swap(siblingPtr, newLeafPtr);
        }

        attach(siblingPtr, newLeafPtr, newLeafPtr -> getKey());
    }
}

template<typename ItemType>
void TwoThreeTree<ItemType>::attach(TwoThreeNode<ItemType>* siblingPtr, TwoThreeNode<ItemType>* leafPtr, ItemType& leafLow) {
    if (siblingPtr == rootPtr) {
        rootPtr = new TwoThreeNode<ItemType>();
        connect(siblingPtr, rootPtr, 1);
        connect(leafPtr, rootPtr, 2);
        rootPtr -> setMinSecond(leafLow);
    }
    else {
        TwoThreeNode<ItemType>* parentPtr = siblingPtr -> getParent();
        if (isTwoNode(parentPtr)) {
            if (siblingPtr == parentPtr -> getSecondChild()) {
                connect(leafPtr, parentPtr, 3);
                parentPtr -> setMinThird(leafLow);
            }
            else {
                TwoThreeNode<ItemType>* newThirdChild = parentPtr -> getSecondChild();
                connect(newThirdChild, parentPtr, 3);
                parentPtr -> setMinThird(parentPtr -> getMinSecond());
                parentPtr -> setMinSecond(leafLow);
                connect(leafPtr, parentPtr, 2);
            }
        }
        else {
            TwoThreeNode<ItemType>* splitNode = new TwoThreeNode<ItemType>();
            ItemType newLow;
            if (siblingPtr == parentPtr -> getThirdChild()) {
                connect(leafPtr, splitNode, 2);
                splitNode -> setMinSecond(leafLow);
                newLow = parentPtr -> getMinThird();
            }
            else {
                TwoThreeNode<ItemType>* newSecondChild = parentPtr -> getThirdChild();
                connect(newSecondChild, splitNode, 2);
                splitNode -> setMinSecond() = parentPtr -> getMinThird();

                if (siblingPtr == parentPtr -> getSecondChild()) {
                    connect(leafPtr, splitNode, 1);
                    newLow = leafLow;
                }
                else {
                    TwoThreeNode<ItemType>* newFirstChild = parentPtr -> getSecondChild();
                    connect(newFirstChild, splitNode, 1);
                    newLow = parentPtr -> getMinSecond();
                    connect(leafPtr, parentPtr, 2);
                    parentPtr -> setMinSecond(leafLow);
                }
            }

            parentPtr -> setThirdChild(NULL);
            parentPTr -> setMinThird(-1);
            attach(parentPtr, splitNode, newLow);
        }
    }
}

tempate<typename ItemType>
void TwoThreeTree<ItemType>::connect(TwoThreeNode<ItemType>* childPtr, TwoThreeNode<ItemType>* parentPtr, int position) {
    switch (position) {
        case 1:
            parentPtr -> setFirstChild(childPtr);
            break;
        case 2:
            parentPtr -> setSecondChild(childPtr);
            break;
        case 3:
            parentPtr -> setThirdChild(childPtr);
            break;
    }
}

template<typename ItemType>
void TwoThreeTree<ItemType>::swap(TwoThreeNode<ItemType>* siblingPtr, TwoThreeNode<ItemType>* leafPtr) {
    TwoThreeNode<ItemType>* parentPtr = siblingPtr -> getParent();
    if (parentPtr != NULL) {
        parentPtr -> setFirstChild(leafPtr);
    }

    TwoThreeNode<ItemType>* tempPtr = siblingPtr;
    siblingPtr = leafPtr;
    leafPtr = tempPtr;

    tempPtr = NULL;
}

template<typename ItemType>
TwoThreeNode<ItemType>* TwoThreeTree<ItemType>::createLeaf(const ItemType& value) {
    TwoThreeNode<ItemType>* newLeafPtr = new TwoThreeNode<ItemType>(true, -1, -1, value, NULL, NULL, NULL, NULL);
    return newLeafPtr;
}

template<typename ItemType>
bool TwoThreeTree<ItemType>::isLeaf(TwoThreeNode<ItemType>* subtreePtr) {
    return subtreePtr -> getTag();
}

template<typename ItemType>
bool TwoThreeTree<ItemType>::isTwoNode(TwoThreeNode<ItemType>* nodePtr) {
    return (nodePtr -> getMinSecond() != -1 && nodePtr -> getMinThird() == -1);
}

template<typename ItemType>
bool TwoThreeTree<ItemType>::isThreeNode(TwoThreeNode<ItemType>* nodePTr) {
    return (nodePtr -> getMinSecond() != -1 && nodePtr -> getMinThird() != -1);
}
