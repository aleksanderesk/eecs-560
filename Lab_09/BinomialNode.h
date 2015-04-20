#ifndef _BINOMIAL_NODE
#define _BINOMIAL_NODE

template<typename ItemType>
class BinomialNode {
    private:
        ItemType item;
        int order;
        BinomialNode<ItemType>* leftSiblingPtr;
        BinomialNode<ItemType>* firstChildPtr;
        BinomialNode<ItemType>* rightSiblingPtr;

    public:
        BinomialNode();
        BinomialNode(const ItemType& anItem);

        void setItem(const ItemType& anItem);
        ItemType getItem() const;
        void setOrder(const int anOrder);
        int getOrder() const;
        void setLeftSiblingPtr(BinomialNode<ItemType>* leftPtr);
        void setFirstChildPtr(BinomialNode<ItemType>* childPtr);
        void setRightSiblingPtr(BinomialNode<ItemType>* rightPtr);
        BinomialNode<ItemType>* getLeftSiblingPtr() const;
        BinomialNode<ItemType>* getFirstChildPtr() const;
        BinomialNode<ItemType>* getRightSiblingPtr() const;
};

#include "BinomialNode.cpp"
#endif
