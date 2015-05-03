#include <iostream>

template<typename ItemType>
SkewTree<ItemType>::SkewTree(): rootPtr(NULL) {
}

template<typename ItemType>
SkewTree<ItemType>::~SkewTree() {
    if (!(isEmpty())) 
        deleteTree(rootPtr);
}

template<typename ItemType>
bool SkewTree<ItemType>::isEmpty() {
    return rootPtr == NULL;
}

template<typename ItemType>
void SkewTree<ItemType>::insert(const ItemType& newEntry) {
    SkewNode<ItemType>* newNodePtr = new SkewNode<ItemType>(newEntry);
    rootPtr = merge(rootPtr, newNodePtr);
}

template<typename ItemType>
void SkewTree<ItemType>::deleteMin() {
    if (!(isEmpty())) {
        SkewNode<ItemType>* nodeToDeletePtr = rootPtr;
        SkewNode<ItemType>* leftChild = rootPtr -> getLeftChildPtr();
        SkewNode<ItemType>* rightChild = rootPtr -> getRightChildPtr();

        delete nodeToDeletePtr;
        nodeToDeletePtr = NULL;

        rootPtr = merge(leftChild, rightChild);
    }
}

template<typename ItemType>
SkewNode<ItemType>* SkewTree<ItemType>::merge(SkewNode<ItemType>* leftTreePtr, SkewNode<ItemType>* rightTreePtr) {
    if (leftTreePtr == NULL) {
        return rightTreePtr;
    } 
    else if (rightTreePtr == NULL) {
        return leftTreePtr;
    } 
    else {
        if (leftTreePtr -> getItem() > rightTreePtr -> getItem()) {
            SkewNode<ItemType>* temp;
            
            temp = leftTreePtr;
            leftTreePtr = rightTreePtr;
            rightTreePtr = temp;

            temp = NULL;
        }
        
        SkewNode<ItemType>* temp;
        
        temp = leftTreePtr -> getRightChildPtr();
        leftTreePtr -> setRightChildPtr(leftTreePtr -> getLeftChildPtr());
        leftTreePtr -> setLeftChildPtr(merge(temp, rightTreePtr));

        return leftTreePtr;
    }
}

template<typename ItemType>
void SkewTree<ItemType>::levelorderTraverse() {
    std::cout << "Levelorder: ";
    if (!(isEmpty())) {
        SkewNode<ItemType>* nodeToVisitPtr;
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
void SkewTree<ItemType>::preorderTraverse() {
    std::cout << "Preorder: ";
    preorderHelper(rootPtr);
    std::cout << std::endl;
}

template<typename ItemType>
void SkewTree<ItemType>::preorderHelper(SkewNode<ItemType>* subTreePtr) {
    if (subTreePtr != NULL) {
        std::cout << subTreePtr -> getItem() << " ";
        preorderHelper(subTreePtr -> getLeftChildPtr());
        preorderHelper(subTreePtr -> getRightChildPtr());
    }
}

template<typename ItemType>
void SkewTree<ItemType>::inorderTraverse() {
    std::cout << "Inorder: ";
    inorderHelper(rootPtr);
    std::cout << std::endl;
}

template<typename ItemType>
void SkewTree<ItemType>::inorderHelper(SkewNode<ItemType>* subTreePtr) {
    if (subTreePtr != NULL) {
        inorderHelper(subTreePtr -> getLeftChildPtr());
        std::cout << subTreePtr -> getItem() << " ";
        inorderHelper(subTreePtr -> getRightChildPtr());
    }
}

template<typename ItemType>
void SkewTree<ItemType>::deleteTree(SkewNode<ItemType>* subTreePtr) {
    if (subTreePtr -> getLeftChildPtr() != NULL) {
        deleteTree(subTreePtr -> getLeftChildPtr());
    }
    if (subTreePtr -> getRightChildPtr() != NULL) {
        deleteTree(subTreePtr -> getRightChildPtr());
    }

    delete subTreePtr;
}
