#ifndef _SKEW_NODE
#define _SKEW_NODE

template<typename ItemType>
class SkewNode {
    private:
        ItemType item;
        SkewNode<ItemType>* leftChildPtr;
        SkewNode<ItemType>* rightChildPtr;

    public:
        SkewNode();
        SkewNode(const ItemType& anItem);
        SkewNode(const ItemType& anItem, SkewNode<ItemType>* leftPtr, SkewNode<ItemType>* rightPtr);

        void setItem(const ItemType& anItem);
        ItemType getItem() const;
        void setLeftChildPtr(SkewNode<ItemType>* leftPtr);
        void setRightChildPtr(SkewNode<ItemType>* rightPtr);
        SkewNode<ItemType>* getLeftChildPtr() const;
        SkewNode<ItemType>* getRightChildPtr() const;
};

#include "SkewNode.cpp"
#endif
