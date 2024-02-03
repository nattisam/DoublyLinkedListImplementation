#include "kvDLL.h"

// Node class implementation

node::node(KEY_VALUE kv, node *next, node *prev) : kv(kv), next(next), prev(prev) {}

// kvDoublyLinkedList class implementation

// Private helper functions

int kvDoublyLinkedList::getIndex(int key, node *pn, int index) const {
    int result = -1;
    if (pn != nullptr) {
        if (pn->kv.key == key)
            result = index;
        else
            result = getIndex(key, pn->next, index + 1);
    }
    return result;
}

void kvDoublyLinkedList::printIt(node *pn, int index, int limit) const {
    if (pn != nullptr && (limit < 0 || index < limit)) {
        cout << "Index: " << index << ", Key: " << pn->kv.key << endl;
        printIt(pn->next, index + 1, limit);
    }
}

void kvDoublyLinkedList::printItBackwards(node *pn, int index, int limit) const {
    if (pn != nullptr && (limit < 0 || index < limit)) {
        printItBackwards(pn->next, index + 1, limit);
        cout << "Index: " << index << ", Key: " << pn->kv.key << endl;
    }
}

void kvDoublyLinkedList::clear(node *pn) {
    if (pn != nullptr) {
        clear(pn->next);
        delete pn;
    }
}

// Public member functions

kvDoublyLinkedList::kvDoublyLinkedList() : first(nullptr), last(nullptr), nCount(0) {}

kvDoublyLinkedList::~kvDoublyLinkedList() {
    clear();
}

bool kvDoublyLinkedList::insert(KEY_VALUE kv) {
    bool inserted = false;
    node *newNode = new node(kv, first, nullptr);
    if (newNode != nullptr) {
        if (first != nullptr)
            first->prev = newNode;
        else
            last = newNode;
        first = newNode;
        nCount++;
        inserted = true;
    }
    return inserted;
}

bool kvDoublyLinkedList::add(KEY_VALUE kv) {
    bool added = false;
    node *newNode = new node(kv, nullptr, last);
    if (newNode != nullptr) {
        if (last != nullptr)
            last->next = newNode;
        else
            first = newNode;
        last = newNode;
        nCount++;
        added = true;
    }
    return added;
}

bool kvDoublyLinkedList::insertAt(int index, KEY_VALUE kv) {
    bool inserted = false;
    if (index >= 0 && index <= nCount) {
        if (index == 0)
            inserted = insert(kv);
        else if (index == nCount)
            inserted = add(kv);
        else {
            node *current = first;
            for (int i = 0; i < index; i++)
                current = current->next;

            node *newNode = new node(kv, current, current->prev);
            if (newNode != nullptr) {
                current->prev->next = newNode;
                current->prev = newNode;
                nCount++;
                inserted = true;
            }
        }
    }
    return inserted;
}

bool kvDoublyLinkedList::deleteAt(int index, KEY_VALUE &kv) {
    bool deleted = false;
    if (index >= 0 && index < nCount) {
        if (index == 0) {
            kv = first->kv;
            node *temp = first;
            first = first->next;
            if (first != nullptr)
                first->prev = nullptr;
            delete temp;
        } else if (index == nCount - 1) {
            kv = last->kv;
            node *temp = last;
            last = last->prev;
            if (last != nullptr)
                last->next = nullptr;
            delete temp;
        } else {
            node *current = first;
            for (int i = 0; i < index; i++)
                current = current->next;
            kv = current->kv;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
        nCount--;
        deleted = true;
    }
    return deleted;
}

bool kvDoublyLinkedList::deleteFirst(KEY_VALUE &kv) {
    bool deleted = false;
    if (nCount > 0)
        deleted = deleteAt(0, kv);
    return deleted;
}

bool kvDoublyLinkedList::deleteLast(KEY_VALUE &kv) {
    bool deleted = false;
    if (nCount > 0)
        deleted = deleteAt(nCount - 1, kv);
    return deleted;
}

void kvDoublyLinkedList::clear() {
    clear(first);
    first = nullptr;
    last = nullptr;
    nCount = 0;
}

bool kvDoublyLinkedList::readAt(int index, KEY_VALUE &kv) const {
    bool read = false;
    if (index >= 0 && index < nCount) {
        node *current = first;
        for (int i = 0; i < index; i++)
            current = current->next;
        kv = current->kv;
        read = true;
    }
    return read;
}

int kvDoublyLinkedList::getIndex(int key) const {
    return getIndex(key, first, 0);
}

void kvDoublyLinkedList::printIt(int limit) const {
    printIt(first, 0, limit);
}

void kvDoublyLinkedList::printItBackwards(int limit) const {
    printItBackwards(last, nCount - 1, limit);
}

int kvDoublyLinkedList::getCount() const {
    return nCount;
}

int kvDoublyLinkedList::getCapacity() const {
    return -1;
}
