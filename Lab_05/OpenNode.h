/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Desc: Definition of OpenNode class, an itemtype agnostic container
 * for data in the linked list
 */

#ifndef _OPEN_NODE
#define _OPEN_NODE

template<class ItemType>
class OpenNode {
    private:
        ItemType item;
        OpenNode<ItemType>* next;

    public:
        OpenNode();
        OpenNode(const ItemType& anItem);
        OpenNode(const ItemType& anItem, OpenNode<ItemType>* nextOpenNodePtr);
        void setNext(OpenNode<ItemType>* nextOpenNodePtr);
        ItemType getItem() const;
        OpenNode<ItemType>* getNext() const;
};

#include "OpenNode.cpp"
#endif
