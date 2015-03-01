#ifndef _NODE
#define _NODE

template<class ItemType>
class Node {
    private:
        ItemType item;
        bool flag;

    public:
        Node();
        ItemType getItem() const;
        void setItem(const ItemType& value);
        bool getFlag() const;
        void setFlag(const bool value);
};

#include "Node.cpp"
#endif
