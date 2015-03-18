#ifndef _TTTREE
#define _TTTREE

#include "TwoThreeNode.h"
#include "Queue.h"

template<class ItemType>
class TwoThreeTree {
    private:
        TwoThreeNode<ItemType>* rootPtr;
        Queue<TwoThreeNode<ItemType>*> levelorderQueue;
        
        TwoThreeNode<ItemType>* locate(const ItemType& value);
        TwoThreeNode<ItemType>* locateHelper(const ItemType& value, TwoThreeNode<ItemType>* subtreePtr);
        ItemType findMinVal(TwoThreeNode<ItemType>* nodePtr);
        TwoThreeNode<ItemType>* findMinNode(TwoThreeNode<ItemType>* nodePtr);
        TwoThreeNode<ItemType>* findMaxNode(TwoThreeNode<ItemType>* nodePtr);
        void updateMins(TwoThreeNode<ItemType>* nodePtr);
        void removeHelper(TwoThreeNode<ItemType>* nodeToDeletePtr);
        TwoThreeNode<ItemType>* find(const ItemType& value);
        void attach(TwoThreeNode<ItemType>* siblingPtr, TwoThreeNode<ItemType>* leafPtr, ItemType qlow);
        void connect(TwoThreeNode<ItemType>* childPtr, TwoThreeNode<ItemType>* parentPtr, int position);
        void swap(TwoThreeNode<ItemType>* leftPtr, TwoThreeNode<ItemType>* rightPtr);
        bool isLeaf(TwoThreeNode<ItemType>* nodePtr);
        TwoThreeNode<ItemType>* createLeaf(const ItemType& value);
        bool isTwoNode(TwoThreeNode<ItemType>* nodePtr);
        bool isThreeNode(TwoThreeNode<ItemType>* nodePtr);

    public:
        TwoThreeTree();
        virtual ~TwoThreeTree();

        void insert(const ItemType& newEntry);
        void remove(const ItemType& entry);
        void deleteMin();
        void deleteMax();
        void levelorderTraverse();
};

#include "TwoThreeTree.cpp"
#endif
