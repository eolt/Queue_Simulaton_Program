//
//  Customer.hpp
//  QueueSimulaton
//
//  Created by Edgar Olvera on 3/17/20.
//  Copyright © 2020 Edgar Olvera. All rights reserved.
//

#ifndef Customer_hpp
#define Customer_hpp

class Customer {
    int customerNumber;
    int arrivalTime;
    int waitingTime;
    int transactionTime;
public:
    Customer(int customerNum = 0, int arrivTime = 0, int waitTime = 0, int tranTime = 0);   // Constructor to initialize instance variables
    
    void setCustomerInfo(int customerNum = 0, int arrivTime = 0, int waitTime = 0, int tranTime = 0);       //  Function to initialize the instance variables
    int getWaitingTime() const;     //  Function to return the waiting time of a customer
    void setWaitingTime(int time);      //  Function to set the waiting time of a customer
    void incrementWaitingTime();        //  Function to increment the waiting time by one time unit
    int getArrivalTime() const;     //  Function to return the arrival time of a customer
    int getTransactionTime() const;     //  Function to return the transaction time of a customer
    int getCustomerNumber() const;      //  Function to return the customer number
};


#endif /* Customer_hpp */
