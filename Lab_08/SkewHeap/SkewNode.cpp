template<typename ItemType>
SkewNode<ItemType>::SkewNode(): item(NULL), leftChildPtr(NULL), rightChildPtr(NULL) {
}

template<typename ItemType>
SkewNode<ItemType>::SkewNode(const ItemType& anItem): leftChildPtr(NULL), rightChildPtr(NULL) {
    setItem(anItem);
}

template<typename ItemType>
SkewNode<ItemType>::SkewNode(const ItemType& anItem, SkewNode<ItemType>* leftPtr, SkewNode<ItemType>* rightPtr) {
    setItem(anItem);
    setLeftChildPtr(leftPtr);
    setRightChildPtr(rightPtr);
}

template<typename ItemType>
void SkewNode<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

template<typename ItemType>
ItemType SkewNode<ItemType>::getItem() const {
    return item;
}

template<typename ItemType>
void SkewNode<ItemType>::setLeftChildPtr(SkewNode<ItemType>* leftPtr) {
    leftChildPtr = leftPtr;
}

template<typename ItemType>
void SkewNode<ItemType>::setRightChildPtr(SkewNode<ItemType>* rightPtr) {
    rightChildPtr = rightPtr;
}

template<typename ItemType>
SkewNode<ItemType>* SkewNode<ItemType>::getLeftChildPtr() const {
    return leftChildPtr;
}

template<typename ItemType>
SkewNode<ItemType>* SkewNode<ItemType>::getRightChildPtr() const {
    return rightChildPtr;
}
