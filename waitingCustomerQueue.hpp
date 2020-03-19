//
//  waitingCustomerQueue.hpp
//  QueueSimulaton
//
//  Created by Edgar Olvera on 3/17/20.
//  Copyright © 2020 Edgar Olvera. All rights reserved.
//

#ifndef waitingCustomerQueue_hpp
#define waitingCustomerQueue_hpp

#include "Customer.hpp"
#include "QueueArray.h"

class WaitingCustomerQueue : public QueueArray<Customer>{
public:
    WaitingCustomerQueue(int size = 100);       //  Constructor
    void updateWaitingQueue();      //  Function to increment the waiting time of each customer in the queue by one time unit

};

#endif /* waitingCustomerQueue_hpp */
