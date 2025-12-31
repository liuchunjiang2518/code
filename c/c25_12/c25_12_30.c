#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 13
#define EMPTY -1

typedef struct HashNode {
    int key;
    int val;
} HashNode;

typedef struct HashTable {
    HashNode table[TABLE_SIZE];
} HashTable;

void initHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i].key = EMPTY;
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

int insert(HashTable* ht, int key, int val) {
    if (key == -1) {
        return 1;
    }
    int idx = hash(key);
    int start = idx;
    while (ht->table[idx].key != EMPTY) {
        idx = (idx + 1) % TABLE_SIZE;
        if (idx == start) {
            return 2;
        }
    }
    ht->table[idx].key = key;
    ht->table[idx].val = val;
    return 0;
}

int search(HashTable* ht, int key, int* val) {
    if (key == EMPTY) {
        return 1;
    }
    int idx = hash(key);
    int start = idx;
    while (ht->table[idx].key != EMPTY) {
        if (ht->table[idx].key == key) {
            *val = ht->table[idx].val;
            return 0;
        }
        idx = (idx + 1) % TABLE_SIZE;
        if (idx == start) {
            return 2;
        }
    }
}

void printHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i].key == EMPTY) {
            printf("EMPTY\n");
        }
        else {
            printf("[%d]:(%d,%d)\n", i, ht->table[i].key, ht->table[i].val);
        }
    }
}

void test() {
    HashTable* ht = malloc(sizeof(HashTable));
    initHashTable(ht);
    insert(ht, 10, 100);
    insert(ht, 23, 200);
    insert(ht, 36, 300);
    insert(ht, 49, 400);
    printHashTable(ht);
    int val;
    search(ht, 23, &val);
    free(ht);
}

int main() {
    printf("Hello World\n");
    test();
    return 0;
}