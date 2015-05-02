#ifndef _SET_NODE
#define _SET_NODE

template<typename ItemType>
class SetNode {
    private:
        ItemType item;
        int rank;
        SetNode<ItemType>* parentPtr;

    public:
        SetNode();
        SetNode(const ItemType& anItem);

        void setItem(const ItemType& anItem);
        ItemType getItem() const;
        void setRank(const int aRank);
        int getRank() const;
        void setParentPtr(SetNode<ItemType>* nodePtr);
        SetNode<ItemType>* getParentPtr() const;
};

#include "SetNode.cpp"
#endif
