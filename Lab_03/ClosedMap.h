/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Descr: Description of the closed hashmap
 */

#ifndef _CLOSED_MAP
#define _CLOSED_MAP

#include "Node.h"

template<class ItemType>
class ClosedMap {
    private:
        int tableSize;
        Node<ItemType>* table;

        int hash(const ItemType& value, const int iter) const;
        int contains(const ItemType& value) const;
        bool isFull() const;

    public:
        ClosedMap();
        ClosedMap(const int size);
        virtual ~ClosedMap();

        bool insert(const ItemType& newValue) const;
        bool remove(const ItemType& value) const;
        void print();
};

#include "ClosedMap.cpp"
#endif
