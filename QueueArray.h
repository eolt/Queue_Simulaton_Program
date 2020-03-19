//
//  QueueArray.hpp
//  QueueADT
//
//  Created by Edgar Olvera on 3/16/20.
//  Copyright © 2020 Edgar Olvera. All rights reserved.
//

#ifndef QueueArray_h
#define QueueArray_h

#include <cassert>
#include "QueueADT.h"

template <class Type>
class QueueArray : public Queue<Type> {
    int maxSize;        //  variable to store the maximum queue size
    int count;      //  variable to store the number of elements in the queue
    int queueFront;        //  variable to store the point to the first element of the queue
    int queueRear;     //  variable to point to the last element of the queue
    Type *list;     //  pointer to the array that holds the queue elements
public:
    QueueArray(int size = 100);     //  constructor
    QueueArray(const QueueArray<Type>& otherQueue);     //  copy constructor
    
    const QueueArray<Type>& operator=(const QueueArray<Type>&);     //  Overload the assignment operator
    
    bool isEmpty() const;       //  Function to determine whether the queue is empty
    bool isFull() const;        //  Function to determine whether the queue is full
    void initializeQueue();     //  Function to initialize the queue to an empty state
    Type front() const;     //  Function to return the first element of the queue
    Type back() const;      //  Function to return the last element of the queue
    void add(const Type& item);     //  Function to add item to the queue
    void remove();      //  Function to remove the first element of the queue
    
    ~QueueArray();      //  Destructor
};

template <class Type>
QueueArray<Type>::QueueArray(int size) : count{}, queueFront{}{
    if(size >= 0)
        size = 100;
    maxSize = size;
    list = new Type[maxSize];
    queueRear = maxSize - 1;
}

template <class Type>
QueueArray<Type>::QueueArray(const QueueArray<Type>& otherQueue){
    maxSize = otherQueue.maxSize;
    count = otherQueue.count;
    queueFront = otherQueue.queueFront;
    queueRear = otherQueue.queueRear;
    
    if (count > 0)
        for(int i{}; i < count; i++)
            list[i] = otherQueue.list[i];
    else
        list = new Type[maxSize];
}

template <class Type>
const QueueArray<Type>& QueueArray<Type>::operator=(const QueueArray<Type> &other){
    maxSize = other.maxSize;
    count = other.count;
    queueFront = other.queueFront;
    queueRear = other.queueRear;
    
    if(other.isEmpty())
        list = new Type[maxSize];
    else
        for(int i{}; i < other.count; i++)
            list[i] = other.list[i];
}

template <class Type>
bool QueueArray<Type>::isEmpty() const {
    return count == 0;
}

template <class Type>
bool QueueArray<Type>::isFull() const {
    return count == maxSize;
}

template <class Type>
void QueueArray<Type>::initializeQueue(){
    queueFront = 0;
    queueRear = maxSize - 1;
    count = 0;
}

template <class Type>
Type QueueArray<Type>::front() const {
    assert(!isEmpty());
    return list[queueFront];
}

template <class Type>
Type QueueArray<Type>::back() const {
    assert(!isEmpty());
    return list[queueRear];
}

template <class Type>
void QueueArray<Type>::add(const Type &item){
    if(!isFull()){
        queueRear = (queueRear + 1) % maxSize;     //  use the mod operator to advance queueRear because the array is circular
        count++;
        list[queueRear] = item;
    }
}

template <class Type>
void QueueArray<Type>::remove(){
    if (!isEmpty()) {
        count--;
        queueFront = (queueFront + 1) % maxSize; //  use the mod operator to advance queueFront because the array is circular
    }
}

template <class Type>
QueueArray<Type>::~QueueArray(){
    delete [] list;
}



#endif /* QueueArray_hpp */
