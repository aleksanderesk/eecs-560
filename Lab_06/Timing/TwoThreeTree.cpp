#include <iostream>
#include <math.h>

template<typename ItemType>
TwoThreeTree<ItemType>::TwoThreeTree(): rootPtr(NULL) {
}

template<typename ItemType>
TwoThreeTree<ItemType>::~TwoThreeTree() {
    destroyTree(rootPtr);
}

template<typename ItemType>
void TwoThreeTree<ItemType>::destroyTree(TwoThreeNode<ItemType>* subtreePtr) {
    if (isLeaf(subtreePtr)) {
        delete subtreePtr;
    }
    else {
        if (subtreePtr -> getThirdChild() != NULL) {
            destroyTree(subtreePtr -> getThirdChild());
        }
        if (subtreePtr -> getSecondChild() != NULL) {
            destroyTree(subtreePtr -> getSecondChild());
        }
        if (subtreePtr -> getFirstChild() != NULL) {
            destroyTree(subtreePtr -> getFirstChild());
        }

        delete subtreePtr;
    }
}

template<typename ItemType>
void TwoThreeTree<ItemType>::levelorderTraverse() {
    if (rootPtr != NULL) {
        TwoThreeNode<ItemType>* nodeToVisitPtr;
        levelorderQueue.enqueue(rootPtr);
        int level = 0;
        int counter = 0;

        do {
            nodeToVisitPtr = levelorderQueue.peek();
            if (isLeaf(nodeToVisitPtr)) {
                std::cout << nodeToVisitPtr -> getKey() << " ";
            }
            else {
                std::cout << nodeToVisitPtr -> getMinSecond() << " " << nodeToVisitPtr -> getMinThird() << " ";
            }

            if (nodeToVisitPtr -> getFirstChild() != NULL) {
                levelorderQueue.enqueue(nodeToVisitPtr -> getFirstChild());
            }
            if (nodeToVisitPtr -> getSecondChild() != NULL) {
                levelorderQueue.enqueue(nodeToVisitPtr -> getSecondChild());
            }
            if (nodeToVisitPtr -> getThirdChild() != NULL) {
                levelorderQueue.enqueue(nodeToVisitPtr -> getThirdChild());
            }

            levelorderQueue.dequeue();
        } while (!(levelorderQueue.isEmpty()));

        std::cout << std::endl;
    }
}

template<typename ItemType>
ItemType TwoThreeTree<ItemType>::findMinVal(TwoThreeNode<ItemType>* nodePtr) {
    return findMinNode(nodePtr) -> getKey();
}

template<typename ItemType>
TwoThreeNode<ItemType>* TwoThreeTree<ItemType>::findMinNode(TwoThreeNode<ItemType>* nodePtr) {
    if (isLeaf(nodePtr)) {
        return nodePtr;
    }
    else {
        findMinNode(nodePtr -> getFirstChild());
    }
}

template<typename ItemType>
void TwoThreeTree<ItemType>::deleteMin() {
    if (rootPtr != NULL)
        removeHelper(findMinNode(rootPtr));
}

template<typename ItemType>
TwoThreeNode<ItemType>* TwoThreeTree<ItemType>::findMaxNode(TwoThreeNode<ItemType>* nodePtr) {
    if (isLeaf(nodePtr)) {
        return nodePtr;
    }
    else {
        if (nodePtr -> getThirdChild() != NULL) {
            findMaxNode(nodePtr -> getThirdChild());
        }
        else {
            findMaxNode(nodePtr -> getSecondChild());
        }
    }
}

template<typename ItemType>
void TwoThreeTree<ItemType>::deleteMax() {
    if (rootPtr != NULL)
        removeHelper(findMaxNode(rootPtr));
}

template<typename ItemType>
void TwoThreeTree<ItemType>::updateMins(TwoThreeNode<ItemType>* nodePtr) {
    if (nodePtr != NULL && !(isLeaf(nodePtr))) {
        updateMins(nodePtr -> getFirstChild());
        if (nodePtr -> getSecondChild() != NULL) {
            updateMins(nodePtr -> getSecondChild());
            nodePtr -> setMinSecond(findMinVal(nodePtr -> getSecondChild()));
        }
        else {
            nodePtr -> setMinSecond(-1);
        }

        if (nodePtr -> getThirdChild() != NULL) {
            updateMins(nodePtr -> getThirdChild());
            nodePtr -> setMinThird(findMinVal(nodePtr -> getThirdChild()));
        }
        else {
            nodePtr -> setMinThird(-1);
        }
    }
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
TwoThreeNode<ItemType>* TwoThreeTree<ItemType>::locateHelper(const ItemType& value, TwoThreeNode<ItemType>* subtreePtr) {
    if (isLeaf(subtreePtr)) {
        std::cout << "Returning " << subtreePtr -> getKey() << std::endl;
        return subtreePtr;
    }
    else if (value >= subtreePtr -> getMinThird() && subtreePtr -> getMinThird() != -1) {
        std::cout << "Search min third" << std::endl;
        return locateHelper(value, subtreePtr -> getThirdChild());
    }
    else if (value >= subtreePtr -> getMinSecond() && subtreePtr -> getMinSecond() != -1) {
        std::cout << "Search min second" << std::endl;
        return locateHelper(value, subtreePtr -> getSecondChild());
    }
    else {
        std::cout << "Search first child" << std::endl;
        return locateHelper(value, subtreePtr -> getFirstChild());
    }
}

template<typename ItemType>
TwoThreeNode<ItemType>* TwoThreeTree<ItemType>::find(const ItemType& value) {
    TwoThreeNode<ItemType>* nodePtr = locate(value);
    if (nodePtr != NULL && nodePtr -> getKey() == value) {
        return nodePtr;
    }
    else {
        return NULL;
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
            TwoThreeNode<ItemType>* parentPtr = siblingPtr -> getParent();
            if (parentPtr != NULL) {
                parentPtr -> setFirstChild(newLeafPtr);
                newLeafPtr -> setParent(parentPtr);
            }
            else {
                rootPtr = newLeafPtr;
            }

            TwoThreeNode<ItemType>* tempPtr = siblingPtr;
            siblingPtr = newLeafPtr;
            newLeafPtr = tempPtr;

        }
        
        attach(siblingPtr, newLeafPtr, newLeafPtr -> getKey());
    }
}

template<typename ItemType>
void TwoThreeTree<ItemType>::attach(TwoThreeNode<ItemType>* siblingPtr, TwoThreeNode<ItemType>* leafPtr, ItemType leafLow) {
    if (siblingPtr == rootPtr) {
        rootPtr = new TwoThreeNode<ItemType>();
        connect(siblingPtr, rootPtr, 1);
        connect(leafPtr, rootPtr, 2);
        rootPtr -> setMinSecond(leafLow);
    }
    else {
        TwoThreeNode<ItemType>* parentPtr = siblingPtr -> getParent();
        if (parentPtr == NULL) {
        }
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
                splitNode -> setMinSecond(parentPtr -> getMinThird());

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
            parentPtr -> setMinThird(-1);
            attach(parentPtr, splitNode, newLow);
        }
    }
}

template<typename ItemType>
void TwoThreeTree<ItemType>::remove(const ItemType& entry) {
    TwoThreeNode<ItemType>* nodeToDeletePtr = find(entry);
    if (nodeToDeletePtr == NULL) {
        std::cout << "Value did not exist in the tree" << std::endl;
    }
    else {
        removeHelper(nodeToDeletePtr);
    }
}

template<typename ItemType>
void TwoThreeTree<ItemType>::removeHelper(TwoThreeNode<ItemType>* nodeToDeletePtr) {
    if (nodeToDeletePtr == rootPtr) {
        delete nodeToDeletePtr;
        rootPtr = NULL;
    } 
    else {
        TwoThreeNode<ItemType>* parentPtr = nodeToDeletePtr -> getParent();
        if (isThreeNode(parentPtr)) {
            if (nodeToDeletePtr == parentPtr -> getFirstChild()) {
                delete nodeToDeletePtr;
                parentPtr -> setFirstChild(parentPtr -> getSecondChild());
                parentPtr -> setSecondChild(parentPtr -> getThirdChild());
                parentPtr -> setThirdChild(NULL);
                parentPtr -> setMinSecond(parentPtr -> getMinThird());
                parentPtr -> setMinThird(-1);
            }
            else if (nodeToDeletePtr == parentPtr -> getSecondChild()) {
                delete nodeToDeletePtr;
                parentPtr -> setSecondChild(parentPtr -> getThirdChild());
                parentPtr -> setThirdChild(NULL);
                parentPtr -> setMinSecond(parentPtr -> getMinThird());
                parentPtr -> setMinThird(-1);
            }
            else {
                delete nodeToDeletePtr;
                parentPtr -> setThirdChild(NULL);
                parentPtr -> setMinSecond(parentPtr -> getMinThird());
                parentPtr -> setMinThird(-1);
            }
        }
        else { // parent is Two node
            if (parentPtr == rootPtr) {
                TwoThreeNode<ItemType>* internalNodeToDeletePtr = parentPtr;
                if (nodeToDeletePtr == parentPtr -> getFirstChild()) {
                    rootPtr = parentPtr -> getSecondChild();

                    delete nodeToDeletePtr;
                    delete internalNodeToDeletePtr;
                }
                else {
                    rootPtr = parentPtr -> getFirstChild();

                    delete nodeToDeletePtr;
                    delete internalNodeToDeletePtr;
                }
            }
            else { // parent N of x has parent p(N)
                TwoThreeNode<ItemType>* grandparentPtr = parentPtr -> getParent();
                TwoThreeNode<ItemType>* unclePtr;
                if (isThreeNode(grandparentPtr -> getFirstChild()) && grandparentPtr -> getFirstChild() != parentPtr) {
                    unclePtr = grandparentPtr -> getFirstChild();
                    parentPtr -> setSecondChild(parentPtr -> getFirstChild());
                    parentPtr -> setFirstChild(unclePtr -> getThirdChild());
                    unclePtr -> setThirdChild(NULL);
                    unclePtr -> setMinThird(-1);
                } 
                else if (isThreeNode(grandparentPtr -> getSecondChild()) && grandparentPtr -> getSecondChild() != parentPtr) {
                    unclePtr = grandparentPtr -> getSecondChild();
                    if (parentPtr == grandparentPtr -> getFirstChild()) {
                        parentPtr -> setSecondChild(unclePtr -> getFirstChild());
                        unclePtr -> setFirstChild(unclePtr -> getSecondChild());
                        unclePtr -> setSecondChild(unclePtr -> getThirdChild());
                        unclePtr -> setThirdChild(NULL);
                        unclePtr -> setMinThird(-1);
                    }
                    else {
                        parentPtr -> setSecondChild(parentPtr -> getFirstChild());
                        parentPtr -> setFirstChild(unclePtr -> getThirdChild());
                        unclePtr -> setThirdChild(NULL);
                        unclePtr -> setMinThird(-1);
                    }
                }
                else if (isThreeNode(grandparentPtr -> getThirdChild()) && grandparentPtr -> getSecondChild() != parentPtr) {
                    unclePtr = grandparentPtr -> getThirdChild();
                    parentPtr -> setSecondChild(unclePtr -> getFirstChild());
                    unclePtr -> setFirstChild(unclePtr -> getSecondChild());
                    unclePtr -> setSecondChild(unclePtr -> getThirdChild());
                    unclePtr -> setThirdChild(NULL);
                    unclePtr -> setMinThird(-1);
                    // update
                }
                else { // uncle is Two node
                    TwoThreeNode<ItemType>* siblingPtr;
                    if (parentPtr -> getFirstChild() == nodeToDeletePtr) {
                        siblingPtr = parentPtr -> getSecondChild();
                    }
                    else {
                        siblingPtr = parentPtr -> getFirstChild();
                    }

                    if (parentPtr == grandparentPtr -> getFirstChild()) {
                        unclePtr = grandparentPtr -> getSecondChild();
                        unclePtr -> setThirdChild(unclePtr -> getSecondChild());
                        unclePtr -> setSecondChild(unclePtr -> getFirstChild());
                        unclePtr -> setFirstChild(siblingPtr);
                    }
                    else if (parentPtr == grandparentPtr -> getSecondChild()) {
                        unclePtr = grandparentPtr -> getFirstChild();
                        if (!(isThreeNode(unclePtr))) {
                            unclePtr -> setThirdChild(siblingPtr);
                        }
                        else {
                            unclePtr = grandparentPtr -> getThirdChild();
                            unclePtr -> setThirdChild(unclePtr -> getSecondChild());
                            unclePtr -> setSecondChild(unclePtr -> getFirstChild());
                            unclePtr -> setFirstChild(siblingPtr);
                        }
                    }
                    else {
                        unclePtr = grandparentPtr -> getSecondChild();
                        unclePtr -> setThirdChild(siblingPtr);
                    }

                    delete nodeToDeletePtr;
                    removeHelper(parentPtr);
                }
            }
        }

        updateMins(rootPtr);
    }
}

template<typename ItemType>
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

    childPtr -> setParent(parentPtr);
}

template<typename ItemType>
void TwoThreeTree<ItemType>::swap(TwoThreeNode<ItemType>* siblingPtr, TwoThreeNode<ItemType>* leafPtr) {
    std::cout << "In swap" << std::endl;

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
bool TwoThreeTree<ItemType>::isThreeNode(TwoThreeNode<ItemType>* nodePtr) {
    return (nodePtr != NULL && nodePtr -> getMinSecond() != -1 && nodePtr -> getMinThird() != -1);
}
