/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Desc: Definition of Node class, an itemtype agnostic container
 * for data in the linked list
 */

#ifndef _NODE
#define _NODE

template<class ItemType>
class Node {
    private:
        ItemType item;
        Node<ItemType>* next;

    public:
        Node();
        Node(const ItemType& anItem);
        Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
        void setNext(Node<ItemType>* nextNodePtr);
        ItemType getItem() const;
        Node<ItemType>* getNext() const;
};

#include "Node.cpp"
#endif
