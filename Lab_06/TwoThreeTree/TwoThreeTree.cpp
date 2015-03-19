#include <iostream>
#include <math.h>

template<typename ItemType>
TwoThreeTree<ItemType>::TwoThreeTree(): rootPtr(NULL) {
}

template<typename ItemType>
TwoThreeTree<ItemType>::~TwoThreeTree() {
    if (rootPtr != NULL)
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
    if (nodePtr == NULL) {
        return -1;
    }
    else {
        return findMinNode(nodePtr) -> getKey();
    }
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
        return subtreePtr;
    }
    else if (value >= subtreePtr -> getMinThird() && subtreePtr -> getMinThird() != -1) {
        return locateHelper(value, subtreePtr -> getThirdChild());
    }
    else if (value >= subtreePtr -> getMinSecond() && subtreePtr -> getMinSecond() != -1) {
        return locateHelper(value, subtreePtr -> getSecondChild());
    }
    else {
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
void TwoThreeTree<ItemType>::insert(const ItemType& entry) {
    if (find(entry) == NULL) {
        TwoThreeNode<ItemType>* newLeafPtr = createLeaf(entry);
        if (rootPtr == NULL) {
            rootPtr = newLeafPtr;
        }
        else if (isLeaf(rootPtr)) {
            TwoThreeNode<ItemType>* newInteriorNode = new TwoThreeNode<ItemType>;
            if (rootPtr -> getKey() > newLeafPtr -> getKey()) {
                newInteriorNode -> setFirstChild(newLeafPtr);
                newInteriorNode -> setSecondChild(rootPtr);
                newInteriorNode -> setMinSecond(rootPtr -> getKey());
            }
            else {
                newInteriorNode -> setFirstChild(rootPtr);
                newInteriorNode -> setSecondChild(newLeafPtr);
                newInteriorNode -> setMinSecond(newLeafPtr -> getKey());
            }

            newLeafPtr -> setParent(newInteriorNode);
            rootPtr -> setParent(newInteriorNode);
            rootPtr = newInteriorNode;
        }
        else {
            TwoThreeNode<ItemType>* parentPtr = locate(entry) -> getParent();
            insertHelper(newLeafPtr, parentPtr);
        }
    }
}

template<typename ItemType>
void TwoThreeTree<ItemType>::insertHelper(TwoThreeNode<ItemType>* nodePtr, TwoThreeNode<ItemType>* parentPtr) {
    std::cout << "Insertion helper" << std::endl;
    if (isTwoNode(parentPtr)) {
        std::cout << "Parent is 2-node" << std::endl;
        if (nodePtr -> getKey() < parentPtr -> getFirstChild() -> getKey()) {
            connect(parentPtr -> getSecondChild(), parentPtr, 3);
            connect(parentPtr -> getFirstChild(), parentPtr, 2);
            connect(nodePtr, parentPtr, 1);
        }
        else if (nodePtr -> getKey() > parentPtr -> getFirstChild() -> getKey() &&
                nodePtr -> getKey() < parentPtr -> getSecondChild() -> getKey()) {
            connect(parentPtr -> getSecondChild(), parentPtr, 3);
            connect(nodePtr, parentPtr, 2);
        }
        else {
            connect(nodePtr, parentPtr, 3);
        }

        parentPtr -> setMinSecond(findMinVal(parentPtr -> getSecondChild()));
        parentPtr -> setMinThird(findMinVal(parentPtr -> getThirdChild()));
    }
    else { // parent has 3 children
        std::cout << "Parent is 3-node" << std::endl;
        TwoThreeNode<ItemType>* newInteriorNode = new TwoThreeNode<ItemType>;
        if (nodePtr -> getKey() < parentPtr -> getFirstChild() -> getKey()) {
            connect(parentPtr -> getThirdChild(), newInteriorNode, 2);
            parentPtr -> setThirdChild(NULL);
            connect(parentPtr -> getSecondChild(), newInteriorNode, 1);
            connect(parentPtr -> getFirstChild(), parentPtr, 2);
            connect(nodePtr, parentPtr, 1);
        }
        else if (nodePtr -> getKey() > parentPtr -> getFirstChild() -> getKey() &&
                nodePtr -> getKey() < parentPtr -> getSecondChild() -> getKey()) {
            connect(parentPtr -> getThirdChild(), newInteriorNode, 2);
            parentPtr -> setThirdChild(NULL);
            connect(parentPtr -> getSecondChild(), newInteriorNode, 1);
            connect(nodePtr, parentPtr, 2);
        }
        else if (nodePtr -> getKey() > parentPtr -> getSecondChild() -> getKey() &&
                nodePtr -> getKey() < parentPtr -> getThirdChild() -> getKey()) {
            connect(parentPtr -> getThirdChild(), newInteriorNode, 2);
            parentPtr -> setThirdChild(NULL);
            connect(nodePtr, newInteriorNode, 1);
        }
        else {
            connect(nodePtr, newInteriorNode, 2);
            connect(parentPtr -> getThirdChild(), newInteriorNode, 1);
            parentPtr -> setThirdChild(NULL);
        }

        parentPtr -> setMinSecond(findMinVal(parentPtr -> getSecondChild()));
        parentPtr -> setMinThird(-1);

        newInteriorNode -> setMinSecond(findMinVal(newInteriorNode -> getSecondChild()));
        newInteriorNode -> setMinThird(-1);

        attach(parentPtr, newInteriorNode);
    }
}

template<typename ItemType>
void TwoThreeTree<ItemType>::attach(TwoThreeNode<ItemType>* siblingPtr, TwoThreeNode<ItemType>* nodePtr) {
    if (siblingPtr == rootPtr) {
        TwoThreeNode<ItemType>* newRootPtr = new TwoThreeNode<ItemType>;
        connect(siblingPtr, newRootPtr, 1);
        connect(nodePtr, newRootPtr, 2);

        newRootPtr -> setMinSecond(findMinVal(nodePtr));
        rootPtr = newRootPtr;
    }
    else {
        TwoThreeNode<ItemType>* parentPtr = siblingPtr -> getParent();
        if (isTwoNode(parentPtr)) {
            if (siblingPtr == parentPtr -> getFirstChild()) {
                connect(parentPtr -> getSecondChild(), parentPtr, 3);
                connect(nodePtr, parentPtr, 2);
            }
            else {
                connect(nodePtr, parentPtr, 3);
            }

            parentPtr -> setMinSecond(findMinVal(parentPtr -> getSecondChild()));
            parentPtr -> setMinThird(findMinVal(parentPtr -> getThirdChild()));
        }
        else {
            TwoThreeNode<ItemType>* newInteriorNode = new TwoThreeNode<ItemType>;
            if (siblingPtr == parentPtr -> getFirstChild()) {
                connect(parentPtr -> getThirdChild(), newInteriorNode, 2);
                connect(parentPtr -> getSecondChild(), newInteriorNode, 1);
                connect(nodePtr, parentPtr, 2);
                parentPtr -> setThirdChild(NULL);
            }
            else if (siblingPtr == parentPtr -> getSecondChild()) {
                connect(parentPtr -> getThirdChild(), newInteriorNode, 2);
                connect(nodePtr, newInteriorNode, 1);
                parentPtr -> setThirdChild(NULL);
            }
            else {
                connect(nodePtr, newInteriorNode, 2);
                connect(parentPtr -> getThirdChild(), newInteriorNode, 1);
                parentPtr -> setThirdChild(NULL);
            }

            parentPtr -> setMinSecond(findMinVal(parentPtr -> getSecondChild()));
            parentPtr -> setMinThird(-1);

            newInteriorNode -> setMinSecond(findMinVal(newInteriorNode -> getSecondChild()));
            newInteriorNode -> setMinThird(-1);

            attach(parentPtr, newInteriorNode);
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
        std::cout << "getting to del helper" << std::endl;
        std::cout << "deleting " << nodeToDeletePtr -> getKey() << std::endl;
        if (nodeToDeletePtr == NULL) 
            std::cout << "NULL nodeToDeletePtr";
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
        std::cout << "past parent assignment" << std::endl;
        if (nodeToDeletePtr == NULL) 
            std::cout << "NULL parent" << std::endl;

        if (isThreeNode(parentPtr)) {
            std::cout << "parent is three node" << std::endl;
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
            std::cout << "parent is two node" << std::endl;
            if (parentPtr == rootPtr) {
                std::cout << "Found parent ptr" << std::endl;
                TwoThreeNode<ItemType>* internalNodeToDeletePtr = parentPtr;
                if (nodeToDeletePtr == parentPtr -> getFirstChild()) {
                    std::cout << "node is parent's first child" << std::endl;
                    rootPtr = parentPtr -> getSecondChild();

                    delete nodeToDeletePtr;
                    delete internalNodeToDeletePtr;
                }
                else {
                    std::cout << "node is parent's second child" << std::endl;
                    rootPtr = parentPtr -> getFirstChild();

                    delete nodeToDeletePtr;
                    delete internalNodeToDeletePtr;
                }
            }
            else { // parent N of x has parent p(N)
                std::cout << "parent N of x has parent p(N)" << std::endl;
                TwoThreeNode<ItemType>* grandparentPtr = parentPtr -> getParent();
                TwoThreeNode<ItemType>* unclePtr;
                if (isThreeNode(grandparentPtr -> getFirstChild()) && 
                        grandparentPtr -> getSecondChild() == parentPtr) {
                    std::cout << "1" << std::endl;
                    unclePtr = grandparentPtr -> getFirstChild();
                    if (nodeToDeletePtr == parentPtr -> getSecondChild()) {
                        connect(parentPtr -> getFirstChild(), parentPtr, 2);
                    }
                    connect(unclePtr -> getThirdChild(), parentPtr, 1);

                    unclePtr -> setThirdChild(NULL);
                    unclePtr -> setMinThird(-1);
                } 
                else if (isThreeNode(grandparentPtr -> getSecondChild()) && 
                        (grandparentPtr -> getFirstChild() == parentPtr ||
                         grandparentPtr -> getThirdChild() == parentPtr)) {
                    unclePtr = grandparentPtr -> getSecondChild();
                    if (parentPtr == grandparentPtr -> getFirstChild()) {
                        std::cout << "2.0" << std::endl;
                        if (nodeToDeletePtr == parentPtr -> getFirstChild()) {
                            connect(parentPtr -> getSecondChild(), parentPtr, 1);
                        }
                        connect(unclePtr -> getFirstChild(), parentPtr, 2);
                        connect(unclePtr -> getSecondChild(), unclePtr, 1);
                        connect(unclePtr -> getThirdChild(), unclePtr, 2);

                        unclePtr -> setThirdChild(NULL);
                        unclePtr -> setMinThird(-1);
                    }
                    else {
                        std::cout << "2.5" << std::endl;
                        if (nodeToDeletePtr == parentPtr -> getSecondChild()) {
                            connect(parentPtr -> getFirstChild(), parentPtr, 2);
                        }
                        connect(unclePtr -> getThirdChild(), parentPtr, 1);

                        unclePtr -> setThirdChild(NULL);
                        unclePtr -> setMinThird(-1);
                    }
                }
                else if (isThreeNode(grandparentPtr -> getThirdChild()) && 
                        grandparentPtr -> getSecondChild() == parentPtr) {
                    std::cout << "3" << std::endl;
                    unclePtr = grandparentPtr -> getThirdChild();
                    if (nodeToDeletePtr == parentPtr -> getFirstChild()) {
                        connect(parentPtr -> getSecondChild(), parentPtr, 1);
                    }
                    connect(unclePtr -> getFirstChild(), parentPtr, 2);
                    connect(unclePtr -> getSecondChild(), unclePtr, 1);
                    connect(unclePtr -> getThirdChild(), unclePtr, 2);

                    unclePtr -> setThirdChild(NULL);
                    unclePtr -> setMinThird(-1);
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
                        std::cout << "4.0" << std::endl;
                        unclePtr = grandparentPtr -> getSecondChild();
                        connect(unclePtr -> getSecondChild(), unclePtr, 3);
                        connect(unclePtr -> getFirstChild(), unclePtr, 2);
                        connect(siblingPtr, unclePtr, 1);
                    }
                    else if (parentPtr == grandparentPtr -> getSecondChild()) {
                        std::cout << "4.3" << std::endl;
                        unclePtr = grandparentPtr -> getFirstChild();
                        if (!(isThreeNode(unclePtr))) {
                            connect(siblingPtr, unclePtr, 3);
                        }
                        else {
                            unclePtr = grandparentPtr -> getThirdChild();
                            connect(unclePtr -> getSecondChild(), unclePtr, 3);
                            connect(unclePtr -> getFirstChild(), unclePtr, 2);
                            connect(siblingPtr, unclePtr, 1);
                        }
                    }
                    else {
                        std::cout << "4.6" << std::endl;
                        unclePtr = grandparentPtr -> getSecondChild();
                        connect(siblingPtr, unclePtr, 3);
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
TwoThreeNode<ItemType>* TwoThreeTree<ItemType>::createLeaf(const ItemType& value) {
    TwoThreeNode<ItemType>* leafPtr = new TwoThreeNode<ItemType>(true, -1, -1, value, NULL, NULL, NULL, NULL);
    return leafPtr;
}

template<typename ItemType>
bool TwoThreeTree<ItemType>::isLeaf(TwoThreeNode<ItemType>* subtreePtr) {
    return subtreePtr -> getTag();
}

template<typename ItemType>
bool TwoThreeTree<ItemType>::isTwoNode(TwoThreeNode<ItemType>* nodePtr) {
    std::cout << "checking isTwoNode" << std::endl;
    return (nodePtr != NULL && nodePtr -> getMinSecond() != -1 && nodePtr -> getMinThird() == -1);
}

template<typename ItemType>
bool TwoThreeTree<ItemType>::isThreeNode(TwoThreeNode<ItemType>* nodePtr) {
    return (nodePtr != NULL && nodePtr -> getMinSecond() != -1 && nodePtr -> getMinThird() != -1);
}
