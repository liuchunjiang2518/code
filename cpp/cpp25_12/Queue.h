#pragma once
#include <iostream>
#include <vector>

class Queue {
private:
    std::vector<int> data;
    int front;
    int count;

public:
    explicit Queue(const int size = 100);
    ~Queue() = default;
    bool push(const int& item);
    bool pop(int& item);
    void traverse() const;
    int size() const;
};

Queue::Queue(const int size) : data(size), front(0), count(0) {}

bool Queue::push(const int& item) {
    if (count == data.size()) {
        return false;
    }
    int rear = (front + count) % data.size();
    data[rear] = item;
    count++;
    return true;
}

bool Queue::pop(int& item) {
    if (count == 0) {
        return false;
    }
    item = data[front];
    front = (front + 1) % data.size();
    count--;
    return true;
}

void Queue::traverse() const {
    for (int i = 0; i < count; i++) {
        int index = (front + i) % data.size();
        std::cout << data[index] << ' ';
    }
    std::cout << std::endl;
}

int Queue::size() const {
    return count;
}