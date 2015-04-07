#ifndef _LEFTIST_NODE
#define _LEFTIST_NODE

template<typename ItemType>
class LeftistNode {
    private:
        ItemType item;
        int rank;
        LeftistNode<ItemType>* leftChildPtr;
        LeftistNode<ItemType>* rightChildPtr;

    public:
        LeftistNode();
        LeftistNode(const ItemType& anItem);
        LeftistNode(const ItemType& anItem, LeftistNode<ItemType>* leftPtr, LeftistNode<ItemType>* rightPtr);
        LeftistNode(const ItemType& anItem, const int aRank, LeftistNode<ItemType>* leftPtr, LeftistNode<ItemType>* rightPtr);

        void setItem(const ItemType& anItem);
        ItemType getItem() const;
        void setRank(const int aRank);
        int getRank() const;
        void setLeftChildPtr(LeftistNode<ItemType>* leftPtr);
        void setRightChildPtr(LeftistNode<ItemType>* rightPtr);
        LeftistNode<ItemType>* getLeftChildPtr() const;
        LeftistNode<ItemType>* getRightChildPtr() const;
};

#include "LeftistNode.cpp"
#endif
