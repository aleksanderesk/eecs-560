/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Desc: Implementation of the OpenNode class
 */
#include <cstddef>

template<class ItemType>
OpenNode<ItemType>::OpenNode() : next(NULL) {
}

template<class ItemType>
OpenNode<ItemType>::OpenNode(const ItemType& anItem) : item(anItem), next(NULL) {
}

template<class ItemType>
OpenNode<ItemType>::OpenNode(const ItemType& anItem, OpenNode<ItemType>* nextOpenNodePtr) :
                item(anItem), next(nextOpenNodePtr) {
}

template<class ItemType>
void OpenNode<ItemType>::setNext(OpenNode<ItemType>* nextOpenNodePtr) {
    next = nextOpenNodePtr;
}

template<class ItemType>
ItemType OpenNode<ItemType>::getItem() const {
    return item;
}

template<class ItemType>
OpenNode<ItemType>* OpenNode<ItemType>::getNext() const {
    return next;
}
