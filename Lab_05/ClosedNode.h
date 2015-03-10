#ifndef _CLOSED_NODE
#define _CLOSED_NODE

template<class ItemType>
class ClosedNode {
    private:
        ItemType item;
        bool flag;

    public:
        ClosedNode();
        ItemType getItem() const;
        void setItem(const ItemType& value);
        bool getFlag() const;
        void setFlag(const bool value);
};

#include "ClosedNode.cpp"
#endif
