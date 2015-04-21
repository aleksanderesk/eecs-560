/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Descr: Implementation of the Binomial Queue class
 */
#include <iostream>

template<typename ItemType>
BinomialQueue<ItemType>::BinomialQueue(): rootPtr(NULL) {
    for (int i = 0; i < MAX_ORDER; i++) {
        QueueArr[i] = NULL;
    }
}

template<typename ItemType>
BinomialQueue<ItemType>::~BinomialQueue() {
    for (int i = 0; i < MAX_ORDER; i++) {
        if (QueueArr[i] != NULL) {
            traverseQueue(QueueArr[i], deleteNode);
        }
    }
}

template<typename ItemType>
void BinomialQueue<ItemType>::levelorderTraverse() {
    std::cout << "Levelorder: " << std::endl;
    for (int i = 0; i < MAX_ORDER; i++) {
        if (QueueArr[i] != NULL) {
            traverseQueue(QueueArr[i], printNode);
            std::cout << "---" << std::endl;
        }
    }
}

template<typename ItemType>
void BinomialQueue<ItemType>::resetRootPtr() {
    for (int i = 0; i < MAX_ORDER; i++) {
        if (QueueArr[i] != NULL) {
            rootPtr = QueueArr[i];
            return;
        }
    }

    rootPtr = NULL;
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
    resetRootPtr();
}

template<typename ItemType>
void BinomialQueue<ItemType>::deleteMin() {
    if (rootPtr == NULL) {
        std::cout << "Queue contains no values" << std::endl;
    } else {
        BinomialNode<ItemType>* nodeToDeletePtr = rootPtr;
        for (int i = 0; i < MAX_ORDER; i++) {
            if (QueueArr[i] != NULL && QueueArr[i] -> getItem() < nodeToDeletePtr -> getItem()) {
                nodeToDeletePtr = QueueArr[i];
            }
        }

        // Gather resultant sub-queues into temp array
        int order = nodeToDeletePtr -> getOrder();
        BinomialNode<ItemType>** tempQueueArr = new BinomialNode<ItemType>*[order];
        BinomialNode<ItemType>* childPtr = nodeToDeletePtr -> getFirstChildPtr();
        for (int i = 0; childPtr != NULL; i++) {
            tempQueueArr[i] = childPtr;
            childPtr = childPtr -> getRightSiblingPtr();
        }

        delete nodeToDeletePtr;
        QueueArr[order] = NULL;

        // Merge resultant sub-queues
        for (int i = 0; i < order; i++) {
            BinomialNode<ItemType>* queueToInsertPtr = tempQueueArr[i];
            queueToInsertPtr -> setLeftSiblingPtr(queueToInsertPtr);
            queueToInsertPtr -> setRightSiblingPtr(NULL);
            insertHelper(queueToInsertPtr);
        }

        delete[] tempQueueArr;
        resetRootPtr();
    }
}

template<typename ItemType>
void BinomialQueue<ItemType>::traverseQueue(BinomialNode<ItemType>* rootPtr, void op(BinomialNode<ItemType>*)) {
    levelorderQueue1.enqueue(rootPtr);

    while (!(levelorderQueue1.isEmpty())) {
        BinomialNode<ItemType>* nodeToVisitPtr = levelorderQueue1.peek();
        levelorderQueue1.dequeue();

        if (nodeToVisitPtr != NULL) {
            if (nodeToVisitPtr -> getFirstChildPtr() != NULL) {
                BinomialNode<ItemType>* childPtr = nodeToVisitPtr -> getFirstChildPtr();
                do {
                    levelorderQueue2.enqueue(childPtr);
                    childPtr = childPtr -> getRightSiblingPtr();
                } while (childPtr != NULL);
            }
            op(nodeToVisitPtr);
        }
        if (levelorderQueue1.isEmpty()) {
            while(!(levelorderQueue2.isEmpty())) {
                levelorderQueue1.enqueue(levelorderQueue2.peek());
                levelorderQueue2.dequeue();
            }
        }
    }
}

template<typename ItemType>
void BinomialQueue<ItemType>::deleteNode(BinomialNode<ItemType>* nodePtr) {
    delete nodePtr;
}

template<typename ItemType>
void BinomialQueue<ItemType>::printNode(BinomialNode<ItemType>* nodePtr) {
    std::cout << nodePtr -> getItem() << " ";
}
