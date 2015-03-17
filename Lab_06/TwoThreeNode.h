#ifndef _TTNODE
#define _TTNODE

template<class ItemType>
class TwoThreeNode {
    private:
        bool tag; // true if leaf node
        ItemType min_second;
        ItemType min_third;
        ItemType key;
        TwoThreeNode<ItemType>* parent;
        TwoThreeNode<ItemType>* first;
        TwoThreeNode<ItemType>* second;
        TwoThreeNode<ItemType>* third;

    public:
        TwoThreeNode();
        TwoThreeNode(const bool& tag, const ItemType& min_second, const ItemType& min_third, const ItemType& key, TwoThreeNode<ItemType>* parentPtr, TwoThreeNode<ItemType>* firstChildPtr, TwoThreeNode<ItemType>* secondChildPtr, TwoThreeNode<ItemType>* thirdChildPtr);
        
        bool getTag() const;
        ItemType getMinSecond() const;
        ItemType getMinThird() const;
        ItemType getKey() const;
        TwoThreeNode<ItemType>* getParent() const;
        TwoThreeNode<ItemType>* getFirstChild() const;
        TwoThreeNode<ItemType>* getSecondChild() const;
        TwoThreeNode<ItemTYpe>* getThirdChild() const;

        void setTag(const bool& newTag);
        void setMinSecond(const ItemType& value);
        void setMinThird(const ItemType& value);
        void setKey(const ItemType& value);
        void setParent(TwoThreeNode<ItemType>* newParentPtr);
        void setFirstChild(TwoThreeNode<ItemType>* newFirstChildPtr);
        void setSecondChild(TwoThreeNode<ItemType>* newSecondChildPtr);
        void setThirdChild(TwoThreeNode<ItemType>* newThirdChildPtr);
};

#include "TwoThreeNode.cpp"
#endif
