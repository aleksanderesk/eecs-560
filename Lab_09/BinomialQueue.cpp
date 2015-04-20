#include <iostream>

template<typename ItemType>
BinomialQueue<ItemType>::BinomialQueue(): rootPtr(NULL) {
    for (int i = 0; i < MAX_ORDER; i++) {
        QueueArr[i] = NULL;
    }
}

template<typename ItemType>
BinomialNode<ItemType>* BinomialQueue<ItemType>::merge(BinomialNode<ItemType>* q1, BinomialNode<ItemType>* q2) {
    if (q1 -> getItem() > q2 -> getItem()) {
        merge(q2, q1);
    } else {
        if (q1 -> getFirstChildPtr() == NULL) {
            q1 -> setFirstChildPtr(q2);
            q1 -> setOrder(q1 -> getOrder() + 1);
            return q1;
        } else {
            q2 -> setLeftSiblingPtr(q1 -> getFirstChildPtr() -> getLeftSiblingPtr());
            q1 -> getFirstChildPtr() -> getLeftSiblingPtr() -> setRightSiblingPtr(q2);
            q1 -> getFirstChildPtr() -> setLeftSiblingPtr(q2);
            q1 -> setOrder(q1 -> getOrder() + 1);

            return q1;
        }
    }
}

template<typename ItemType>
void BinomialQueue<ItemType>::insertHelper(BinomialNode<ItemType>* queueToInsertPtr) {
    int nodeOrder = queueToInsertPtr -> getOrder();
    if (QueueArr[nodeOrder] == NULL) {
        QueueArr[nodeOrder] = queueToInsertPtr;
    } else {
        insertHelper(merge(queueToInsertPtr, QueueArr[nodeOrder]));
        QueueArr[nodeOrder] = NULL;
    }
}

template<typename ItemType>
void BinomialQueue<ItemType>::insert(const ItemType anItem) {
    BinomialNode<ItemType>* nodeToInsertPtr = new BinomialNode<ItemType>(anItem);
    insertHelper(nodeToInsertPtr);
    
    for (int i = 0; i < MAX_ORDER; i++) {
        if (QueueArr[i] != NULL) {
            rootPtr = QueueArr[i];
            break;
        }
    }
}

template<typename ItemType>
void BinomialQueue<ItemType>::deleteMin() {
    BinomialNode<ItemType>* nodeToDeletePtr = rootPtr;
    for (int i = 0; i < MAX_ORDER; i++) {
        if (QueueArr[i] != NULL && QueueArr[i] -> getItem() < nodeToDeletePtr -> getItem()) {
            nodeToDeletePtr = QueueArr[i];
        }
    }

    BinomialNode<ItemType>** tempQueueArr = new BinomialNode<ItemType>*[nodeToDeletePtr -> getOrder()];
    BinomialNode<ItemType>* childPtr = nodeToDeletePtr -> getFirstChildPtr();
    for (int i = 0; childPtr != NULL; i++) {
        tempQueueArr[i] = childPtr;
        childPtr = childPtr -> getRightSiblingPtr();
    }

    QueueArr[nodeToDeletePtr -> getOrder()] = NULL;

    for (int i = 0; i < nodeToDeletePtr -> getOrder(); i++) {
        insertHelper(tempQueueArr[i]);
    }

    delete[] tempQueueArr;
}

template<typename ItemType>
void BinomialQueue<ItemType>::queueTraverse(BinomialNode<ItemType>* rootPtr) {
    levelorderQueue.enqueue(rootPtr);
    BinomialNode<ItemType>* nodeToVisitPtr;
    
    do {
        nodeToVisitPtr = levelorderQueue.peek();
        while (nodeToVisitPtr != NULL) {
            std::cout << nodeToVisitPtr -> getItem() << " ";
            if (nodeToVisitPtr -> getFirstChildPtr() != NULL) {
                levelorderQueue.enqueue(nodeToVisitPtr -> getFirstChildPtr());
            }
            nodeToVisitPtr = nodeToVisitPtr -> getRightSiblingPtr();
        }

        levelorderQueue.dequeue();
    } while (!(levelorderQueue.isEmpty()));

    std::cout << std::endl;
}

template<typename ItemType>
void BinomialQueue<ItemType>::levelorderTraverse() {
    std::cout << "Levelorder: " << std::endl;
    for (int i = 0; i < MAX_ORDER; i++) {
        if (QueueArr[i] != NULL) {
            std::cout << i << std::endl;
            queueTraverse(QueueArr[i]);
        }
    }
}
