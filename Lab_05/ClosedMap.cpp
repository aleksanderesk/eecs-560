/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Descr: Implementation of the closed hashmap
 */
#include <iostream>

/* Empty constructor */
template<class ItemType>
ClosedMap<ItemType>::ClosedMap() : tableSize(0) {
}

/* Default constructor */
template<class ItemType>
ClosedMap<ItemType>::ClosedMap(const int size) : tableSize(size) {
    table = new ClosedNode<ItemType>[size];
    for (int i = 0; i < size; i++) {
        table[i] = ClosedNode<ItemType>();
    }
}

/* Default desctructor */
template<class ItemType>
ClosedMap<ItemType>::~ClosedMap() {
    delete[] table;
}

/**
 * @param value
 * a value to be hashed
 * @param iter
 * quadratic probe addend
 */
template<class ItemType>
int ClosedMap<ItemType>::hash(const ItemType& value, const long iter) const {
    return ((value % tableSize) + iter * iter) % tableSize;
}

/**
 * @param value
 * the item to be searched for
 * @return
 * the array index of the item or -1 if the item is not in the table
 */
template<class ItemType>
int ClosedMap<ItemType>::contains(const ItemType& value) const {
    long iter = 0;
    int loc;

    do {
        loc = hash(value, iter);
        if (table[loc].getItem() == value) {
            return loc;
        }

        iter++;
    } while ((table[loc].getItem() != -1 || table[loc].getFlag() == true) && iter < tableSize);

    return -1;
}

/**
 * @param newValue
 * a value to be inserted
 * @return
 * true if the insertion was successful, false if insertion failed or the item
 * already existed in the table
 */
template<class ItemType>
bool ClosedMap<ItemType>::insert(const ItemType& newValue) const {
    if (contains(newValue) != -1) {
        return false;
    }
    else {
        int iter = 0;
        do {
            int loc = hash(newValue, iter);
            if (table[loc].getItem() == -1) {
                table[loc].setItem(newValue);
                
                return true;
            }

            iter++;
        } while (iter < tableSize);

        return false;
    }
}

/**
 * @param value
 * the item to remove
 * @return
 * true if the removal was successful, false if the item did not exist in the
 * table
 */
template<class ItemType>
bool ClosedMap<ItemType>::remove(const ItemType& value) const {
    int loc = contains(value);
    if (loc == -1) {
        std::cout << "Item does not exist in map" << std::endl;
        return false;
    } else {
        table[loc].setItem(-1);
        table[loc].setFlag(true);

        return true;
    }
}

/**
 * @return
 * true if any cell in the table can accept a value
 * false otherwise
 */
template<class ItemType>
bool ClosedMap<ItemType>::isFull() const {
    for (int i = 0; i < tableSize; i++) {
        if (table[i].getItem() == -1) {
            return true;
        }
    }

    return false;
}

/* Prints table */
template<class ItemType>
void ClosedMap<ItemType>::print() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i].getFlag()) {
            std::cout << i << ": " << table[i].getItem() << ", true" << std::endl;
        } else {
            std::cout << i << ": " << table[i].getItem() << ", false" << std::endl;
        }
    }
}
