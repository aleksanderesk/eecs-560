#include <cstddef>

template<class ItemType>
TwoThreeNode<ItemType>::TwoThreeNode() {
    setTag(false);
    setMinSecond(-1);
    setMinThird(-1);
    setKey(-1);
    setParent(NULL);
    setFirstChild(NULL);
    setSecondChild(NULL);
    setThirdChild(NULL);
}

template<class ItemType>
TwoThreeNode<ItemType>::TwoThreeNode(const bool& tag, const ItemType& min_second, const ItemType& min_third, const ItemType& key, TwoThreeNode<ItemType>* parentPtr, TwoThreeNode<ItemType>* firstChildPtr, TwoThreeNode<ItemType>* secondChildPtr, TwoThreeNode<ItemType* thirdChildPtr) {
    setTag(tag);
    setMinSecond(min_second);
    setMinThird(min_third);
    setKey(key);
    setParent(parentPtr);
    setFirstChild(firstChildPtr);
    setSecondChild(secondChildPtr);
    setThirdChild(thirdChildPtr);
}

template<class ItemType>
bool TwoThreeNode<ItemType>::getTag() {
    return tag;
}

template<class ItemType>
ItemType TwoThreeNode<ItemType>::getMinSecond() {
    return min_second;
}

template<class ItemType>
ItemType TwoThreeNode<ItemType>::getMinThird() {
    return min_third;
}

template<class ItemType>
ItemType TwoThreeNode<ItemType>::getKey() {
    return key;
}

template<class ItemType>
TwoThreeNode<ItemType>* TwoThreeNode<ItemType>::getParent() {
    return parent;
}

template<class ItemType>
TwoThreeNode<ItemType>* TwoThreeNode<ItemType>::getFirstChild() {
    return first;
}

template<class ItemType>
TwoThreeNode<ItemType>* TwoThreeNode<ItemType>::getSecondChild() {
    return second;
}

template<class ItemType>
TwoThreeNode<ItemType>* TwoThreeNode<ItemType>::getThirdChild() {
    return third;
}

template<class ItemType>
void TwoThreeNode<ItemType>::setTag(const bool& newTag) {
    tag = newTag;
}

template<class ItemType>
void TwoThreeNode<ItemType>::setMinSecond(const ItemType& value) {
    min_second = value;
}

template<class ItemType>
void TwoThreeNode<ItemType>::setMinThird(const ItemType& value) {
    min_third = value;
}

template<class ItemType>
void TwoThreeNode<ItemType>::setKey(const ItemType& value) {
    key = value;
}

template<class ItemType>
void TwoThreeNode<ItemType>::setParent(TwoThreeNode<ItemType>* newParentPtr) {
    parent = newParentPtr;
}

template<class ItemType>
void TwoThreeNode<ItemType>::setFirstChild(TwoThreeNode<ItemType>* newFirstChildPtr) {
    firstChild = newFirstChildPtr;
}

template<class ItemType>
void TwoThreeNode<ItemType>::setSecondChild(TwoThreeNode<ItemType>* newSecondChildPtr) {
    secondChild = newSecondChildPtr;
}

template<class ItemType>
void TwoThreeNode<ItemType>::setThirdChild(TwoThreeNode<ItemType>* newThirdChildPtr) {
    thirdChild = newThirdChildPtr;
}
