//
//  waitingCustomerQueue.cpp
//  QueueSimulaton
//
//  Created by Edgar Olvera on 3/17/20.
//  Copyright © 2020 Edgar Olvera. All rights reserved.
//

#include "waitingCustomerQueue.hpp"


WaitingCustomerQueue::WaitingCustomerQueue(int size):QueueArray<Customer>(size){
}

void WaitingCustomerQueue::updateWaitingQueue() {
    Customer cust;
    cust.setWaitingTime(-1);
    int wTime{};
    
    add(cust);
    
    while (wTime != -1) {
        
        cust = front();
        remove();
        
        wTime = cust.getWaitingTime();
        
        if (wTime == -1)
            break;
        
        cust.incrementWaitingTime();
        add(cust);
    }
}

