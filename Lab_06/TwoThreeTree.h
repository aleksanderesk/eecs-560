#ifndef _TTTREE
#define _TTTREE

#include "TwoThreeNode.h"

template<class ItemType>
class TwoThreeTree {
    private:
        TwoThreeNode<ItemType>* rootPtr;
        
        TwoThreeNode<ItemType>* locate(const ItemType& value);
       
        void attach(TwoThreeNode<ItemType>* siblingPtr, TwoThreeNode<ItemType>* leafPtr, ItemType& qlow);
        void connect(TwoThreeNode<ItemType>* childPtr, TwoThreeNode<ItemType>* parentPtr, int position);
        void swap(TwoThreeNode<ItemType>* leftPtr, TwoThreeNode<ItemType>* rightPtr);
        bool isLeaf(TwoThreeNode<ItemType>* nodePtr);
        TwoThreeNode<ItemType>* createLeaf(const ItemType& value);
        bool isTwoNode(TwoThreeNode<ItemType>* nodePtr);
        bool isThreeNode(TwoThreeNode<ItemType>* nodePtr);

    public:
        TwoThreeTree();
        virtual ~TwoThreeTree();

        bool find(const ItemType& entry);
        void insert(const ItemType& newEntry);
        void delete(const ItemType& entry);
        ItemType findMin();
        ItemType findMax();
        void deleteMin();
        void deleteMax();

        void levelorderTraverse();
};

#include "TwoThreeTree.cpp"
#endif
