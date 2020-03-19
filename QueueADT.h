//
//  QueueADT.h
//  QueueADT
//
//  Created by Edgar Olvera on 3/16/20.
//  Copyright © 2020 Edgar Olvera. All rights reserved.
//

#ifndef QueueADT_h
#define QueueADT_h

template <class Type>
class Queue{
public:
    virtual bool isEmpty() const = 0; //    Function to determine whether the queue is empty.
    virtual bool isFull() const = 0;    //  Function to determine whether the queue is full.
    virtual void initializeQueue() = 0;   //    Function to initialize the queue to an empty state.
    virtual Type front() const = 0;     //  Function to return the first element of the queue.
    virtual Type back() const = 0;      //  Function to return the last element of the queue.
    virtual void add(const Type &item) = 0;         // Function to add queueElement to the queue.
    virtual void remove() = 0;      //  Function to remove the first element of the queue.
};


#endif /* QueueADT_h */
