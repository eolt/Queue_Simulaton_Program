//
//  ServerList.hpp
//  QueueSimulaton
//
//  Created by Edgar Olvera on 3/17/20.
//  Copyright © 2020 Edgar Olvera. All rights reserved.
//

#ifndef ServerList_hpp
#define ServerList_hpp

#include <iostream>
#include "Server.hpp"
#include "Customer.hpp"

class ServerList {
    int numOfServers;
    Server *servers;
public:
    ServerList(int num = 1);        //  Constructor to initialize a list of servers
    ~ServerList();      //  Destructor
    
    int getFreeServerID() const;        //  Function to search the list of servers
    int getNumberOfBusyServers() const;     //  Function to return the number of busy servers
    void setServerBusy(int serverID, Customer cCustomer, int tTime);        //  Function to set a server busy
    void setServerBusy(int serverID, Customer cCustomer);       //  Function to set a server busy
    void updateServers(std::ostream &outfile);      //  Function to update the status of a server
};

#endif /* ServerList_hpp */
