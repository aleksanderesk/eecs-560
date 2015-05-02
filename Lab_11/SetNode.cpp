template<typename ItemType>
SetNode<ItemType>::SetNode(): parentPtr(NULL), rank(0) {
}

template<typename ItemType>
SetNode<ItemType>::SetNode(const ItemType& anItem): parentPtr(NULL), rank(0) {
    setItem(anItem);
}

template<typename Itemtype>
void SetNode<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

template<typename ItemType>
ItemType SetNode<ItemType>::getItem() const {
    return item;
}

template<typename ItemType>
void SetNode<ItemType>::setRank(const int aRank) {
    rank = aRank;
}

template<typename ItemType>
int SetNode<ItemType>::getRank() const {
    return rank;
}

template<typename ItemType>
void SetNode<ItemType>::setParentPtr(SetNode<ItemType>* nodePtr) {
    parentPtr = nodePtr;
}

template<typename ItemType>
SetNode<ItemType>* SetNode<ItemType>::getParentPtr() const {
    return parentPtr;
}
