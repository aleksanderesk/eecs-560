#include <cstddef>

template<class ItemType>
ClosedNode<ItemType>::ClosedNode() : item(-1), flag(false) {
}

template<class ItemType>
ItemType ClosedNode<ItemType>::getItem() const {
    return item;
}

template<class ItemType>
void ClosedNode<ItemType>::setItem(const ItemType& value) {
    item = value;
}

template<class ItemType>
bool ClosedNode<ItemType>::getFlag() const {
    return flag;
}

template<class ItemType>
void ClosedNode<ItemType>::setFlag(const bool value) {
    flag = value;
}
