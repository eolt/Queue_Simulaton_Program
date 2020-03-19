//
//  Customer.cpp
//  QueueSimulaton
//
//  Created by Edgar Olvera on 3/17/20.
//  Copyright © 2020 Edgar Olvera. All rights reserved.
//

#include "Customer.hpp"

Customer::Customer(int customerNum, int arrivTime, int waitTime, int tranTime) {
    setCustomerInfo(customerNum, arrivTime, waitTime, tranTime);
}


void Customer::setCustomerInfo(int customerNum, int arrivTime, int waitTime, int tranTime) {
    customerNumber = customerNum;
    arrivalTime = arrivTime;
    waitingTime = waitTime;
    transactionTime = tranTime;
}

int Customer::getWaitingTime() const {
    return waitingTime;
}

void Customer::setWaitingTime(int time) {
    waitingTime = time;
}

void Customer::incrementWaitingTime() {
    waitingTime++;
}

int Customer::getArrivalTime() const {
    return arrivalTime;
}

int Customer::getTransactionTime() const {
    return transactionTime;
}

int Customer::getCustomerNumber() const {
    return customerNumber;
}











