//
//  ServerList.cpp
//  QueueSimulaton
//
//  Created by Edgar Olvera on 3/17/20.
//  Copyright © 2020 Edgar Olvera. All rights reserved.
//

#include "ServerList.hpp"


ServerList::ServerList(int num) {
    numOfServers = num;
    servers = new Server[numOfServers];
}

ServerList::~ServerList() {
    delete [] servers;
}

int ServerList::getFreeServerID() const {
    
    int serverId{};
    for (int i{}; i < numOfServers; i++) {
        if (servers[i].isFree()){
            serverId = i;
            return serverId;
        }
    }
    return -1;
}

int ServerList::getNumberOfBusyServers() const {
    
    int busyServers{};
    for (int i{}; i < numOfServers; i++) {
        if (!servers[i].isFree()) {
            busyServers++;
        }
    }
    return busyServers;
}

void ServerList::setServerBusy(int serverID, Customer cCustomer, int tTime) {
    servers[serverID].setBusy();
    servers[serverID].setTransactionTime(tTime);
    servers[serverID].setCurrentCustomer(cCustomer);
}

void ServerList::setServerBusy(int serverID, Customer cCustomer) {
    
    int time = cCustomer.getTransactionTime();
    
    servers[serverID].setBusy();
    servers[serverID].setTransactionTime(time);
    servers[serverID].setCurrentCustomer(cCustomer);
    
}

void ServerList::updateServers(std::ostream &outfile) {
    for (int i {}; i < numOfServers; i++) {
        if (!servers[i].isFree()) {
            
            servers[i].decreaseTransactionTime();
            
            if (servers[i].getRemainingTransactionTime() == 0) {
                
                outfile << "From server number " << (i + 1) << " customer number " << servers[i].getCurrentCustomerNumber() << std::endl;
                outfile << "    departed at clock unit ";
                outfile << servers[i].getCurrentCustomerArrivalTime()
                            + servers[i].getCurrentCustomerWaitingTime()
                            + servers[i].getCurrentCustomerTransactionTime()
                        << std::endl;
                servers[i].setFree();
            }
        }
    }
}










