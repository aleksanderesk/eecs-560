/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Descr: Definition of BinaryNode class
 */
#ifndef _BINARY_NODE
#define _BINARY_NODE

template<typename ItemType>
class BinaryNode {
    private:
        ItemType item;
        BinaryNode<ItemType>* leftChildPtr;
        BinaryNode<ItemType>* rightChildPtr;

    public:
        BinaryNode();
        BinaryNode(const ItemType& anItem);
        BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr);
        
        void setItem(const ItemType& anItem);
        ItemType getItem() const;
        bool isLeaf() const;
        BinaryNode<ItemType>* getLeftChildPtr() const;
        BinaryNode<ItemType>* getRightChildPtr() const;
        void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);
        void setRightChildPtr(BinaryNode<ItemType>* rightPrt);
};

#include "BinaryNode.cpp"
#endif
