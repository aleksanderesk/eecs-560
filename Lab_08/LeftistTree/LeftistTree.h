#ifndef _LEFTIST_TREE
#define _LEFTIST_TREE

#include "LeftistNode.h"
#include "Queue.h"

template<typename ItemType>
class LeftistTree {
    private:
        LeftistNode<ItemType>* rootPtr;
        Queue<LeftistNode<ItemType>*> levelorderQueue;

        LeftistNode<ItemType>* merge(LeftistNode<ItemType>* leftTreePtr, LeftistNode<ItemType>* rightTreePtr);
        //void preorderHelper(LeftistNode<ItemType>* subTreePtr);
        //void inorderHelper(LeftistNode<ItemType>* subTreePtr);

        void deleteTree(LeftistNode<ItemType>* subTreePtr);

    public:
        LeftistTree();
        virtual ~LeftistTree();

        void insert(const ItemType& newEntry);
        void deleteMin();
        //void preorderTraverse();
        //void inorderTraverse();
        void levelorderTraverse();
};

#include "LeftistTree.cpp"
#endif
