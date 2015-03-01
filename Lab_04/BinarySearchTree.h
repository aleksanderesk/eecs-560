/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Descr: Definition of BinarySearchTree class
 */
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryNode.h"
#include "Queue.h"

template<typename ItemType>
class BinarySearchTree {
    private:
        BinaryNode<ItemType>* rootPtr;
        Queue<BinaryNode<ItemType>*> levelorderQueue;

        BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success);
        BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodeToDeletePtr);
        BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* nodeToDeletePtr, ItemType& inorderSuccessor);
        bool isLeaf(BinaryNode<ItemType>* subTreePtr);
        void destroyTree(BinaryNode<ItemType>* subTreePtr);
        void inorderHelper(BinaryNode<ItemType>* subTreePtr) const;
        void preorderHelper(BinaryNode<ItemType>* subTreePtr) const;
        void postorderHelper(BinaryNode<ItemType>* subTreePtr) const;
        BinaryNode<ItemType>* inorderInsertion(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
        ItemType findMin(BinaryNode<ItemType>* subTreePtr);
        ItemType findMax(BinaryNode<ItemType>* subTreePtr);

    public:
        BinarySearchTree();
        virtual ~BinarySearchTree();

        void add(const ItemType& newEntry);
        void remove (const ItemType& entry);
        void deleteMin();
        void deleteMax();
        ItemType getEntry(const ItemType& entry);
        void preorderTraverse() const;
        void inorderTraverse() const;
        void postorderTraverse() const;
        void levelorderTraverse();
};

#include "BinarySearchTree.cpp"
#endif
