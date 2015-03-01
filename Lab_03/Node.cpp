#include <cstddef>

template<class ItemType>
Node<ItemType>::Node() : item(-1), flag(false) {
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& value) {
    item = value;
}

template<class ItemType>
bool Node<ItemType>::getFlag() const {
    return flag;
}

template<class ItemType>
void Node<ItemType>::setFlag(const bool value) {
    flag = value;
}
