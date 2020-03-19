//
//  Server.cpp
//  QueueSimulaton
//
//  Created by Edgar Olvera on 3/17/20.
//  Copyright © 2020 Edgar Olvera. All rights reserved.
//

#include "Server.hpp"


Server::Server() {
    status = "free";
    transactionTime = 0;
}

bool Server::isFree() const {
    return status == "free";
}

void Server::setBusy() {
    status = "busy";
}

void Server::setFree() {
    status = "free";
}

void Server::setTransactionTime(int t) {
    transactionTime = t;
}

void Server::setTransactionTime() {
    int time;
    time = currentCustomer.getTransactionTime();
    transactionTime = time;
}

int Server::getRemainingTransactionTime() const {
    return transactionTime;
}

void Server::decreaseTransactionTime() {
    transactionTime--;
}

void Server::setCurrentCustomer(Customer cCustomer) {
    int customerNumber = cCustomer.getCustomerNumber();
    int arrivalTime = cCustomer.getArrivalTime();
    int waitingTime = cCustomer.getWaitingTime();
    int transactionTime = cCustomer.getTransactionTime();
    
    currentCustomer.setCustomerInfo(customerNumber, arrivalTime, waitingTime, transactionTime);
}

int Server::getCurrentCustomerNumber() const {
    return currentCustomer.getCustomerNumber();
}

int Server::getCurrentCustomerArrivalTime() const {
    return currentCustomer.getArrivalTime();
}

int Server::getCurrentCustomerWaitingTime() const {
    return currentCustomer.getWaitingTime();
}

int Server::getCurrentCustomerTransactionTime() const {
    return currentCustomer.getTransactionTime();
}















