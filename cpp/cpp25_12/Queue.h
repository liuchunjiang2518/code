#pragma once
#include <iostream>
template <typename myType>

class Queue
{
    private:
        myType* data;
        int front;
        int rear;
        int capacity;
        int count;

    public:
        explicit Queue(int size) : capacity(size),front(0),rear(-1),count(0)
        {
            data = new myType[size];
        }

        ~Queue()
        {
            delete[] data;
        }

        bool enQueue(const myType& item)
        {
            if (isFull())
            {
                return false;
            }
            rear = (rear + 1) % capacity;
            data[rear] = item;
            count++;
            return true;
        }

        bool deQueue(myType& item)
        {
            if (isEmpty())
            {
                return false;
            }
            item = data[front];
            front = (front + 1) % capacity;
            count--;
            return true;
        }

        void traverse()
        {
            int curr = front;
            for (int i = 0;i < size();i++)
            {
                std::cout << data[curr] << ' ';
                curr = (curr + 1) % capacity;
            }
            std::cout << std::endl;
        }

        bool isFull() const
        {
            return count == capacity;
        }

        bool isEmpty() const
        {
            return count == 0;
        }

        int size() const
        {
            return count;
        }
};