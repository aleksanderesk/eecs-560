/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Descr: Implementation of BinarySearchTree class
 */
#include <iostream>

template<typename ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(): rootPtr(NULL) {
}

template<typename ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
    destroyTree(rootPtr);
}

template<typename ItemType>
void BinarySearchTree<ItemType>::add(const ItemType& newEntry) {
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
    rootPtr = inorderInsertion(rootPtr, newNodePtr);
}

template<typename ItemType>
void BinarySearchTree<ItemType>::remove(const ItemType& entry) {
    bool success = false;
    rootPtr = removeValue(rootPtr, entry, success);

    if (success == false) {
        std::cout << "The item does not exist in the tree" << std::endl;
    }
}

template<typename ItemType>
void BinarySearchTree<ItemType>::deleteMin() {
    bool success = false;
    if (rootPtr != NULL) {
        ItemType valueToDelete = findMin(rootPtr);
        rootPtr = removeValue(rootPtr, valueToDelete, success);
    }
}

template<typename ItemType>
void BinarySearchTree<ItemType>::deleteMax() {
    bool success = false;
    if (rootPtr != NULL) {
        ItemType valueToDelete = findMax(rootPtr);
        rootPtr = removeValue(rootPtr, valueToDelete, success);
    }
}

template<typename ItemType>
ItemType BinarySearchTree<ItemType>::findMin(BinaryNode<ItemType>* subTreePtr) {
    if (subTreePtr -> getLeftChildPtr() == NULL) {
        return subTreePtr -> getItem();
    }
    else {
        findMin(subTreePtr -> getLeftChildPtr());
    }
}

template<typename ItemType>
ItemType BinarySearchTree<ItemType>::findMax(BinaryNode<ItemType>* subTreePtr) {
    if (subTreePtr -> getRightChildPtr() == NULL) {
        return subTreePtr -> getItem();
    }
    else {
        findMax(subTreePtr -> getRightChildPtr());
    }
}

template<typename ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const {
    std::cout << "Preorder: ";
    preorderHelper(rootPtr);
    std::cout << std::endl;
}

template<typename ItemType>
void BinarySearchTree<ItemType>::inorderTraverse() const {
    std::cout << "Inorder: ";
    inorderHelper(rootPtr);
    std::cout << std::endl;
}

template<typename ItemType>
void BinarySearchTree<ItemType>::levelorderTraverse() {
    std::cout << "Levelorder: ";
    if (rootPtr != NULL) {
        BinaryNode<ItemType>* nodeToVisitPtr;
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
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success) {
    // tree empty, return false
    if (subTreePtr == NULL) {
        success = false;
        return NULL;
    }
    // current node contains target
    else if (subTreePtr -> getItem() == target) {
        // remove node, return subtree without node
        subTreePtr = removeNode(subTreePtr);
        success = true;
        return subTreePtr;
    }
    // current node greater than target, recurse left
    else if (subTreePtr -> getItem() > target) {
        BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr -> getLeftChildPtr(), target, success);
        subTreePtr -> setLeftChildPtr(tempPtr);
        return subTreePtr;
    }
    // current node less than target, recurse right
    else {
        BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr -> getRightChildPtr(), target, success);
        subTreePtr -> setRightChildPtr(tempPtr);
        return subTreePtr;
    }
}

template<typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodeToDeletePtr) {
    // node is leaf - delete it, return null as subTree
    if (nodeToDeletePtr -> isLeaf() == true) {
        delete nodeToDeletePtr;
        nodeToDeletePtr = NULL;
        return nodeToDeletePtr;
    }
    // node has only one child
    else if ((nodeToDeletePtr -> getLeftChildPtr() == NULL && nodeToDeletePtr -> getRightChildPtr() != NULL) || (nodeToDeletePtr -> getLeftChildPtr() != NULL && nodeToDeletePtr -> getRightChildPtr() == NULL)) {
        BinaryNode<ItemType>* nodeToConnectPtr;
        // get node's child
        if (nodeToDeletePtr -> getLeftChildPtr() != NULL) {
            nodeToConnectPtr = nodeToDeletePtr -> getLeftChildPtr();
        }
        else {
            nodeToConnectPtr = nodeToDeletePtr -> getRightChildPtr();
        }
        
        // delete node
        delete nodeToDeletePtr;
        nodeToDeletePtr = NULL;
        // return node's child to parent
        return nodeToConnectPtr;
    }
    // node has two children
    else {
        ItemType inorderSuccessor;
        BinaryNode<ItemType>* tempPtr = removeLeftmostNode(nodeToDeletePtr -> getRightChildPtr(), inorderSuccessor);
        nodeToDeletePtr -> setRightChildPtr(tempPtr);
        // change node's Item to the inorder successor's item
        nodeToDeletePtr -> setItem(inorderSuccessor);
    }
}

template<typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodeToDeletePtr, ItemType& inorderSuccessor) {
    // successor found
    if (nodeToDeletePtr -> getLeftChildPtr() == NULL) {
        inorderSuccessor = nodeToDeletePtr -> getItem();
        return removeNode(nodeToDeletePtr);
    }
    // not found, recurse
    else {
        nodeToDeletePtr -> setLeftChildPtr(removeLeftmostNode(nodeToDeletePtr -> getLeftChildPtr(), inorderSuccessor));
        return nodeToDeletePtr;
    }
}

/* Traversal helpers */
template<typename ItemType>
void BinarySearchTree<ItemType>::inorderHelper(BinaryNode<ItemType>* subTreePtr) const {
    if (subTreePtr != NULL) {
        inorderHelper(subTreePtr -> getLeftChildPtr());
        std::cout << subTreePtr -> getItem() << " ";
        inorderHelper(subTreePtr -> getRightChildPtr());
    }
}

template<typename ItemType>
void BinarySearchTree<ItemType>::preorderHelper(BinaryNode<ItemType>* subTreePtr) const {
    if (subTreePtr != NULL) {
        std::cout << subTreePtr -> getItem() << " ";
        preorderHelper(subTreePtr -> getLeftChildPtr());
        preorderHelper(subTreePtr -> getRightChildPtr());
    }
}

template<typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::inorderInsertion(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr) {
    // tree empty, or no child for previously compared node
    if (subTreePtr == NULL) {
        return newNodePtr;
    }
    // new node's item greater than current node, recurse right
    else if (newNodePtr -> getItem() > subTreePtr -> getItem()) {
        BinaryNode<ItemType>* tempPtr = inorderInsertion(subTreePtr -> getRightChildPtr(), newNodePtr);
        subTreePtr -> setRightChildPtr(tempPtr);
    }
    // new node's item less than current node, recurse left
    else {
        BinaryNode<ItemType>* tempPtr = inorderInsertion(subTreePtr -> getLeftChildPtr(), newNodePtr);
        subTreePtr -> setLeftChildPtr(tempPtr);
    }

    return subTreePtr;
}

template<typename ItemType>
void BinarySearchTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr) {
    if (subTreePtr != NULL) {
        destroyTree(subTreePtr -> getLeftChildPtr());
        destroyTree(subTreePtr -> getRightChildPtr());
        delete subTreePtr;
    }
}
