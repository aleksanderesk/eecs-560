/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Descr: Implementation of the Binomial Node class
 */
template<typename ItemType>
BinomialNode<ItemType>::BinomialNode(): leftSiblingPtr(this), firstChildPtr(NULL), rightSiblingPtr(NULL) {
}

template<typename ItemType>
BinomialNode<ItemType>::BinomialNode(const ItemType& anItem): order(0), leftSiblingPtr(this), firstChildPtr(NULL), rightSiblingPtr(NULL) {
    setItem(anItem);
}

template<typename ItemType>
void BinomialNode<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

template<typename ItemType>
ItemType BinomialNode<ItemType>::getItem() const {
    return item;
}

template<typename ItemType>
void BinomialNode<ItemType>::setOrder(const int anOrder) {
    order = anOrder;
}

template<typename ItemType>
int BinomialNode<ItemType>::getOrder() const {
    return order;
}

template<typename ItemType>
void BinomialNode<ItemType>::setLeftSiblingPtr(BinomialNode<ItemType>* leftPtr) {
    leftSiblingPtr = leftPtr;
}

template<typename ItemType>
void BinomialNode<ItemType>::setFirstChildPtr(BinomialNode<ItemType>* childPtr) {
    firstChildPtr = childPtr;
}

template<typename ItemType>
void BinomialNode<ItemType>::setRightSiblingPtr(BinomialNode<ItemType>* rightPtr) {
    rightSiblingPtr = rightPtr;
}

template<typename ItemType>
BinomialNode<ItemType>* BinomialNode<ItemType>::getLeftSiblingPtr() const {
    return leftSiblingPtr;
}

template<typename ItemType>
BinomialNode<ItemType>* BinomialNode<ItemType>::getFirstChildPtr() const {
    return firstChildPtr;
}

template<typename ItemType>
BinomialNode<ItemType>* BinomialNode<ItemType>::getRightSiblingPtr() const {
    return rightSiblingPtr;
}
