/**
 * Name: Aleksander Eskilson
 * Email: aeskilson@ku.edu
 * KUID: 2373732
 * Desc: Definition of the OpenMap class
 */
#ifndef _OPEN_MAP
#define _OPEN_MAP

#include "Node.h"

template<class ItemType>
class OpenMap {
    private:
        int tableSize;
        Node<ItemType>** table;

        int hash(const ItemType& value) const;
        bool find(const ItemType& value) const;

    public:
        OpenMap();
        OpenMap(int size);
        virtual ~OpenMap();
       
        bool insert(const ItemType& newValue) const;
        bool remove(const ItemType& value) const;
        void print();

};

#include "OpenMap.cpp"
#endif
