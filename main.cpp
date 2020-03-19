//
//  main.cpp
//  QueueSimulaton
//
//  Created by Edgar Olvera on 3/17/20.
//  Copyright © 2020 Edgar Olvera. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <fstream>
#include "Customer.hpp"
#include "Server.hpp"
#include "waitingCustomerQueue.hpp"
#include "ServerList.hpp"


using namespace std;

void setSimulationParameters(int &sTime, int &numOfServers, int &transTime, int &tBetweenCArrival);
void runSimulation(ofstream &outfile, int &sTime, int &numOfServers, int &transTime, int &tBetweenArrival);
void printSummary(ofstream &outfile, int &sTime, int &numOfServers, int &transTime, int &tBetweenArrival, int &customersServed, int &customersLeft, int &customersWaiting);

int main(int argc, const char * argv[]) {
    // insert code here...
    srand(time(nullptr));
    int simulationTime{}, numOfServers{}, transactionTime{}, timeBetweenArrival{};
    ofstream outfile;
    
    outfile.open("Simulation.txt");             //  We will output all of the results into a separate file
    
    setSimulationParameters(simulationTime, numOfServers, transactionTime, timeBetweenArrival);     //  Function will ask the user to enter the information for the program
    
    runSimulation(outfile, simulationTime, numOfServers, transactionTime, timeBetweenArrival);      //  Function will run the simulation program
    
    outfile.close();
    
    return 0;
}

void setSimulationParameters(int &sTime, int &numOfServers, int &transTime, int &tBetweenCArrival){
    
    cout << "Enter the simulation time: ";
    cin >> sTime;
    cout << endl;
    
    cout << "Enter the number of servers: ";
    cin >> numOfServers;
    cout << endl;
    
    cout << "Enter the transaction time: ";
    cin >> transTime;
    cout << endl;
    
    cout << "Enter the time between customers arrival: ";
    cin >> tBetweenCArrival;
    cout << endl;
}

void printSummary(ofstream &outfile, int &simulationTime, int &numOfServers, int &transTime, int &tBetweenCArrival, int &totalWait, int &customersServed, int &customersLeftServing, int &customersLeftWaiting){
    //  Results will be written into an output file.
    //  I have spread the code out for readability
    
    
    outfile << endl;
    outfile << "The simulation ran for " << simulationTime << " time units" << endl;
    outfile << "Numbers of servers: " << numOfServers << endl;
    outfile << "Average transaction time: " << transTime << endl;
    outfile << "Total waiting time: " << totalWait << endl;
    outfile << "Number of customers that completed a transaction: " << customersServed << endl;
    outfile << "Number of customers left in the servers: " <<  customersLeftServing << endl;
    outfile << "The number of customers left in queue: " << customersLeftWaiting << endl;
    outfile << "Average waiting time: " << fixed << setprecision(2) << float(totalWait) / customersServed;
    
}

void runSimulation(ofstream &outfile, int &sTime, int &numOfServers, int &transTime, int &tBetweenCArrival){
    
    //  Intialize instance variables and customer queue, server list ADT
    int customersServed{}, customersLeftServing{}, customersLeftQueue{};
    int totalWait{};
    int customerNumber{}, timeArrived{};
    WaitingCustomerQueue customerQueue;
    ServerList serverList(numOfServers);
    
    
    for (int clock = 1; clock < sTime; clock++) {           //  The loop runs as a representation of time passing in simulation
        
        if (clock >= timeArrived + tBetweenCArrival) {      //  If statement is used to enforce seperation of customer arrival times.
                                                            //  For instance if average arrival time is "4" we check in increments of 4
            
            int hasArrived = rand() % 2;            //  get a random number 0 or 1; if 0 no customer has arrived, if 1 a customer has arrived
            
            if (hasArrived == 1 and clock <= sTime - transTime) {       //  The other statment checks if a customer has arrived at a time where                                                                  //  a server can still serve them, while under the time interval of simulation
                
                customerNumber++;       //  increment number of customers arrived
                timeArrived = clock;        //  Save the time customer arrived
                
                Customer customer(customerNumber, timeArrived, 0, transTime);       //  inititalize customer class
                outfile << "Customer number " << customer.getCustomerNumber() << " arrived at time unit " << customer.getArrivalTime() << endl;     //  save information to output file
                customerQueue.add(customer);        //  Add customer to queue
            }
        }
        
        while(serverList.getFreeServerID() != -1 && !customerQueue.isEmpty()) {        //  While someone on server list is not busy and customer queue is nonempty
            
            customersServed++;      //  increment number of customers served
            totalWait += customerQueue.front().getWaitingTime();        //  adding the customers waiting time to total waiting time
            
            serverList.setServerBusy(serverList.getFreeServerID(), customerQueue.front());      //  assign customer to "free" server then set to "busy"
            customerQueue.remove();     //  remove customer from the queue
        }
        
        if (!customerQueue.isEmpty())
            customerQueue.updateWaitingQueue();     //  increments the waiting time of each customer in queue by 1
        
        serverList.updateServers(outfile);          //  decrements the transaction time of servere with customer
    }
    
    customersLeftServing = serverList.getNumberOfBusyServers();     //  Assigns the number of customers still being served after simulation loop
    customersLeftQueue = customerNumber  - customersServed;     //  Assigns the number of customers in queue by subtracting number of customers whoe
                                                                //  arrived to customers who were served
    
    //  Fuction will print the results
    printSummary(outfile, sTime, numOfServers, transTime, tBetweenCArrival, totalWait, customersServed, customersLeftServing, customersLeftQueue);
    
}
