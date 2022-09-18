//
// Created by ali salamatian on 2022-09-17.
//

#ifndef SASASURANCE2_BUSINESS_H
#define SASASURANCE2_BUSINESS_H
#include "client.h"
#include <vector>

class Business {
private:
    string name;
    string sector;
    vector<Client> clients;
public:
    Business(string name, string sector);
    Business(string name, string sector, vector<Client> clients);
    void setClients(vector<Client> clients);
    void raiseRequest(int cost, Client client);
};
#endif //SASASURANCE2_BUSINESS_H
