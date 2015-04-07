template<typename ItemType>
LeftistNode<ItemType>::LeftistNode(): item(NULL), rank(-1), leftChildPtr(NULL), rightChildPtr(NULL) {
}

template<typename ItemType>
LeftistNode<ItemType>::LeftistNode(const ItemType& anItem): rank(1), leftChildPtr(NULL), rightChildPtr(NULL) {
    setItem(anItem);
}

template<typename ItemType>
LeftistNode<ItemType>::LeftistNode(const ItemType& anItem, LeftistNode<ItemType>* leftPtr, LeftistNode<ItemType>* rightPtr): rank(1) {
    setItem(anItem);
    setLeftChildPtr(leftPtr);
    setRightChildPtr(rightPtr);
}

template<typename ItemType>
LeftistNode<ItemType>::LeftistNode(const ItemType& anItem, const int aRank, LeftistNode<ItemType>* leftPtr, LeftistNode<ItemType>* rightPtr) {
    setItem(anItem);
    setRank(aRank);
    setLeftChildPtr(leftPtr);
    setRightChildPtr(rightPtr);
}

template<typename ItemType>
void LeftistNode<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

template<typename ItemType>
ItemType LeftistNode<ItemType>::getItem() const {
    return item;
}

template<typename ItemType>
void LeftistNode<ItemType>::setRank(const int aRank) {
    rank = aRank;
}

template<typename ItemType>
int LeftistNode<ItemType>::getRank() const {
    return rank;
}

template<typename ItemType>
void LeftistNode<ItemType>::setLeftChildPtr(LeftistNode<ItemType>* leftPtr) {
    leftChildPtr = leftPtr;
}

template<typename ItemType>
void LeftistNode<ItemType>::setRightChildPtr(LeftistNode<ItemType>* rightPtr) {
    rightChildPtr = rightPtr;
}

template<typename ItemType>
LeftistNode<ItemType>* LeftistNode<ItemType>::getLeftChildPtr() const {
    return leftChildPtr;
}

template<typename ItemType>
LeftistNode<ItemType>* LeftistNode<ItemType>::getRightChildPtr() const {
    return rightChildPtr;
}
