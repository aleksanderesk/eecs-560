#ifndef _SKEW_TREE
#define _SKEW_TREE

#include "SkewNode.h"
#include "Queue.h"

template<typename ItemType>
class SkewTree {
    private:
        SkewNode<ItemType>* rootPtr;
        Queue<SkewNode<ItemType>*> levelorderQueue;

        SkewNode<ItemType>* merge(SkewNode<ItemType>* leftTreePtr, SkewNode<ItemType>* rightTreePtr);
        void preorderHelper(SkewNode<ItemType>* subTreePtr);
        void inorderHelper(SkewNode<ItemType>* subTreePtr);

        void deleteTree(SkewNode<ItemType>* subTreePtr);

    public:
        SkewTree();
        virtual ~SkewTree();

        bool isEmpty();
        void insert(const ItemType& newEntry);
        void deleteMin();
        void preorderTraverse();
        void inorderTraverse();
        void levelorderTraverse();
};

#include "SkewTree.cpp"
#endif
