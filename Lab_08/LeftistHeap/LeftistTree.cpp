#include <iostream>

template<typename ItemType>
LeftistTree<ItemType>::LeftistTree(): rootPtr(NULL) {
}

template<typename ItemType>
LeftistTree<ItemType>::~LeftistTree() {
    if (rootPtr != NULL)
        deleteTree(rootPtr);
}

template<typename ItemType>
LeftistNode<ItemType>* LeftistTree<ItemType>::findHelper(LeftistNode<ItemType>* nodePtr, ItemType& value) {

}

template<typename ItemType>
bool LeftistTree<ItemType>::find(const ItemType& value) {
    
}

template<typename ItemType>
void LeftistTree<ItemType>::insert(const ItemType& newEntry) {
    if (!(find(newEntry))) {
        LeftistNode<ItemType>* newNodePtr = new LeftistNode<ItemType>(newEntry);
        rootPtr = merge(rootPtr, newNodePtr);
    }
}

template<typename ItemType>
void LeftistTree<ItemType>::deleteMin() {
    if (rootPtr != NULL) {
        LeftistNode<ItemType>* nodeToDeletePtr = rootPtr;
        LeftistNode<ItemType>* leftChild = rootPtr -> getLeftChildPtr();
        LeftistNode<ItemType>* rightChild = rootPtr -> getRightChildPtr();

        delete nodeToDeletePtr;
        nodeToDeletePtr = NULL;

        rootPtr = merge(leftChild, rightChild);
    }
}

template<typename ItemType>
LeftistNode<ItemType>* LeftistTree<ItemType>::merge(LeftistNode<ItemType>* leftTreePtr, LeftistNode<ItemType>* rightTreePtr) {
    if (leftTreePtr == NULL) {
        return rightTreePtr;
    } 
    else if (rightTreePtr == NULL) {
        return leftTreePtr;
    } 
    else {
        if (leftTreePtr -> getItem() > rightTreePtr -> getItem()) {
            LeftistNode<ItemType>* temp;
            
            temp = leftTreePtr;
            leftTreePtr = rightTreePtr;
            rightTreePtr = temp;

            temp = NULL;
        }

        leftTreePtr -> setRightChildPtr(merge(leftTreePtr -> getRightChildPtr(), rightTreePtr));

        if (leftTreePtr -> getLeftChildPtr() == NULL || 
                (leftTreePtr -> getLeftChildPtr() -> getRank() < 
                leftTreePtr -> getRightChildPtr() -> getRank())) {
            LeftistNode<ItemType>* temp;

            temp = leftTreePtr -> getLeftChildPtr();
            leftTreePtr -> setLeftChildPtr(leftTreePtr -> getRightChildPtr());
            leftTreePtr -> setRightChildPtr(temp);

            temp = NULL;
        }
        if (leftTreePtr -> getRightChildPtr() == NULL) {
            leftTreePtr -> setRank(1);
        }
        else {
            leftTreePtr -> setRank((leftTreePtr -> getRightChildPtr() -> getRank()) + 1);
        }

        return leftTreePtr;
    }
}

template<typename ItemType>
void LeftistTree<ItemType>::levelorderTraverse() {
    std::cout << "Levelorder: ";
    if (rootPtr != NULL) {
        LeftistNode<ItemType>* nodeToVisitPtr;
        levelorderQueue.enqueue(rootPtr);

        do {
            nodeToVisitPtr = levelorderQueue.peek();
            std::cout << nodeToVisitPtr -> getItem() << " ";

            if (nodeToVisitPtr -> getLeftChildPtr() != NULL) {
                levelorderQueue.enqueue(nodeToVisitPtr -> getLeftChildPtr());
            }
            if (nodeToVisitPtr -> getRightChildPtr() != NULL) {
                levelorderQueue.enqueue(nodeToVisitPtr -> getRightChildPtr());
            }

            levelorderQueue.dequeue();
        } while (!(levelorderQueue.isEmpty()));
    }
    
    std::cout << std::endl;
}

template<typename ItemType>
void LeftistTree<ItemType>::preorderTraverse() {
    std::cout << "Preorder: ";
    preorderHelper(rootPtr);
    std::cout << std::endl;
}

template<typename ItemType>
void LeftistTree<ItemType>::preorderHelper(LeftistNode<ItemType>* subTreePtr) {
    if (subTreePtr != NULL) {
        std::cout << subTreePtr -> getItem() << " ";
        preorderHelper(subTreePtr -> getLeftChildPtr());
        preorderHelper(subTreePtr -> getRightChildPtr());
    }
}

template<typename ItemType>
void LeftistTree<ItemType>::inorderTraverse() {
    std::cout << "Inorder: ";
    inorderHelper(rootPtr);
    std::cout << std::endl;
}

template<typename ItemType>
void LeftistTree<ItemType>::inorderHelper(LeftistNode<ItemType>* subTreePtr) {
    if (subTreePtr != NULL) {
        inorderHelper(subTreePtr -> getLeftChildPtr());
        std::cout << subTreePtr -> getItem() << " ";
        inorderHelper(subTreePtr -> getRightChildPtr());
    }
}

template<typename ItemType>
void LeftistTree<ItemType>::deleteTree(LeftistNode<ItemType>* subTreePtr) {
    if (subTreePtr -> getLeftChildPtr() != NULL) {
        deleteTree(subTreePtr -> getLeftChildPtr());
    }
    if (subTreePtr -> getRightChildPtr() != NULL) {
        deleteTree(subTreePtr -> getRightChildPtr());
    }

    delete subTreePtr;
}
