//
//  Server.hpp
//  QueueSimulaton
//
//  Created by Edgar Olvera on 3/17/20.
//  Copyright © 2020 Edgar Olvera. All rights reserved.
//

#ifndef Server_hpp
#define Server_hpp

#include <string>
#include "Customer.hpp"

class Server{
    Customer currentCustomer;
    std::string status;
    int transactionTime;
public:
    Server();       //  Default Constructor
    
    bool isFree() const;        //  Function to determine if the server is free
    void setBusy();     //  Function to set the status of the server to "busy"
    void setFree();     //  Function to set the status of the server to "free"
    void setTransactionTime(int t);     //  Function to set the transaction time
    void setTransactionTime();      //  Function to set the transaction time according to the transaction time of the current customer
    int getRemainingTransactionTime() const;        //  Function to return the remaining transaction time
    void decreaseTransactionTime();     //  Function to decrease the transactionTime by 1 unit
    void setCurrentCustomer(Customer cCustomer);        //  Function to set the info of the current customer
    int getCurrentCustomerNumber() const;       //  Function to return the customer number of the current customer
    int getCurrentCustomerArrivalTime() const;      //  Function to return the arrival time of the current customer
    int getCurrentCustomerWaitingTime() const;      //  Function to return the current waiting time of the current customer
    int getCurrentCustomerTransactionTime() const;      //  Function to return the transaction time of the current customer
};

#endif /* Server_hpp */
