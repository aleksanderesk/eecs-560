#ifndef _DIS_SET
#define _DIS_SET

#include "SetNode.h"

template<typename ItemType>
class DisjointSet {
    private:
        int setSize;
        SetNode<ItemType>** auxArr;

        SetNode<ItemType>* findHelper(SetNode<ItemType>* setPtr);

    public:
        DisjointSet();
        DisjointSet(ItemType* set, int size);
        virtual ~DisjointSet();

        void setUnion(const ItemType seti, const ItemType setj);
        ItemType find(ItemType value);
};

#include "DisjointSet.cpp"
#endif
