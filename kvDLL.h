#ifndef KVDLL_H
#define KVDLL_H

#include <iostream>
using namespace std;

typedef struct key_value {
    int key;
    int value;
} KEY_VALUE;

class node {
public:
    KEY_VALUE kv;
    node *next;
    node *prev;
    
    node(KEY_VALUE kv, node *next = nullptr, node *prev = nullptr);
};

class kvDoublyLinkedList {
private:
    node *first;
    node *last;
    int nCount;

    int getIndex(int key, node *pn, int index) const;
    void printIt(node *pn, int index, int limit) const;
    void printItBackwards(node *pn, int index, int limit) const;
    void clear(node *pn);

public:
    kvDoublyLinkedList();
    ~kvDoublyLinkedList();

    bool insert(KEY_VALUE kv);
    bool add(KEY_VALUE kv);
    bool insertAt(int index, KEY_VALUE kv);
    bool deleteAt(int index, KEY_VALUE &kv);
    bool deleteFirst(KEY_VALUE &kv);
    bool deleteLast(KEY_VALUE &kv);
    void clear();
    bool readAt(int index, KEY_VALUE &kv) const;
    int getIndex(int key) const;
    void printIt(int limit) const;
    void printItBackwards(int limit) const;
    int getCount() const;
    int getCapacity() const;
};

#endif /* KVDLL_H */
