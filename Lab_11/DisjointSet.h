#ifndef _DIS_SET
#define _DIS_SET

template<typename ItemType>
class DisjointSet {
    private:
        int setSize;
        SetNode<ItemType>* auxArr;

        SetNode<ItemType>* findHelper(SetNode<ItemType>* setPtr);

    public:
        DisjointSet();
        DisjointSet(ItemType set[], int size);
        virtual ~DistjointSet();

        void union(const int seti, const int setj);
        ItemType find(ItemType value);
};

#include "DisjointSet.cpp"
#endif
