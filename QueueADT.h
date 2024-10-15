#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template <typename T>
class Queue
{
    T* data;
    int front, rear, capacity, noOfElement;

public:
    Queue(int capacity);
    ~Queue();
    void enqueue(T val);
    T deQueue();
    T getElementAtFront();
    bool isEmpty();
    bool isFull();
    void reSize(int newCapacity);
};

#endif  // QUEUE_H
