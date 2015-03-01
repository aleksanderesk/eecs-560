/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Descr: Implementation of BinaryNode class
 */
template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(): leftChildPtr(NULL), rightChildPtr(NULL) {
}

template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem): leftChildPtr(NULL), rightChildPtr(NULL) {
    setItem(anItem);
}

template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr) {
    setItem(anItem);
    setLeftChildPtr(leftPtr);
    setRightChildPtr(rightPtr);
}

template<typename ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

template<typename ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
    return item;
}

template<typename ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
    return (getLeftChildPtr() == NULL && getRightChildPtr() == NULL);
}

template<typename ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const {
    return leftChildPtr;
}

template<typename ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const {
    return rightChildPtr;
}

template<typename ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr) {
    leftChildPtr = leftPtr;
}

template<typename ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr) {
    rightChildPtr = rightPtr;
}
