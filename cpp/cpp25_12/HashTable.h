#pragma once
#include <iostream>
#include <vector>

class HashTable {
private:
    struct HashNode {
        int key;
        int val;
        HashNode();
    };
    std::vector<HashNode> table;
    int hash(int key) const;

public:
    explicit HashTable(const int size = 13);
    bool insert(int key, int val);
    bool search(int key, int& val) const;
    void traverse() const;
};

HashTable::HashNode::HashNode(): key(-1), val(0) {}

int HashTable::hash(int key) const {
    return key % table.size();
}

HashTable::HashTable(const int size): table(size) {}

bool HashTable::insert(int key, int val) {
    if (key == -1) {
        return false;
    }
    int index = HashTable::hash(key);
    int start = index;
    while (table[index].key != -1) {
        if (table[index].key == key) {
            table[index].val = val;
            return true;
        }
        index = (index + 1) % table.size();
        if (index == start) {
            return false;
        }
    }
    table[index].key = key;
    table[index].val = val;
    return true;
}

bool HashTable::search(int key, int& val) const {
    if (key == -1) {
        return false;
    }
    int index = HashTable::hash(key);
    int start = index;
    while (table[index].key != -1) {
        if (table[index].key == key) {
            val = table[index].val;
            return true;
        }
        index = (index + 1) % table.size();
        if (index == start) {
            return false;
        }
    }
}

void HashTable::traverse() const {
    for (int i = 0; i < table.size(); i++) {
        if (table[i].key == -1) {
            std::cout << "EMPTY" << std::endl;
        }
        else {
            std::cout << table[i].key << ':' << table[i].val << std::endl;
        }
    }
}