#include "Queue.h"

template <typename T>
Queue<T>::Queue(int capacity)
 {
    this->capacity = capacity;
    this->front = this->rear = 0;
    this->noOfElement = 0;
    this->data = new T[capacity];
}

template <typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template <typename T>
void Queue<T>::enqueue(T val) 
{
    if (isFull()) 
    {
        throw std::runtime_error("Cannot enqueue to a full queue.");
    }
    data[rear] = val;
    rear = (rear + 1) % capacity;
    noOfElement++;
    if (noOfElement > capacity / 2)
        reSize(capacity * 2);
}

template <typename T>
T Queue<T>::deQueue() 
{
    if (isEmpty()) 
      {
        throw std::runtime_error("Cannot dequeue from an empty queue.");
      }
    noOfElement--;
    T val = data[front];
    front = (front + 1) % capacity;
    if (noOfElement > 0 && noOfElement == capacity / 4)
        reSize((capacity / 2));
    return val;
}

template <typename T>
T Queue<T>::getElementAtFront() 
{
    if (isEmpty()) 
    {
        throw std::runtime_error("Cannot access the front element of an empty queue.");
    }
    return data[front];
}

template <typename T>
bool Queue<T>::isEmpty() 
{
    return noOfElement == 0;
}

template <typename T>
bool Queue<T>::isFull() 
{
    return noOfElement == capacity;
}

template <typename T>
void Queue<T>::reSize(int newCapacity) 
{
    T* newData = new T[newCapacity];
    for (int i = 0; i < noOfElement; i++) 
    {
        newData[i] = data[(front + i) % capacity];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
    front = 0;
    rear = noOfElement;
}
