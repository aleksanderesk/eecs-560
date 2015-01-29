#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "Node.h"

template<class ItemType>
class LinkedList {
    private:
        Node<ItemType>* headPtr;
        int itemCount;

        Node<ItemType>* find(Node<ItemType>* currPtr, const ItemType& entry); // returns previous pointer to node containing value
        void insertHelper(Node<ItemType>* currPtr, Node<ItemType>* newNodePtr); // recursive helper method
    
    public:
        LinkedList();
        virtual ~LinkedList();

        bool isEmpty() const;
        void insert(const ItemType& newEntry);
        void erase(const ItemType& entry);
        void print();
        void clear();
};

#include "LinkedList.cpp"
#endif
