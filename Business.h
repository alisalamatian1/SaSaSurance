//
// Created by ali salamatian on 2022-09-17.
//

#ifndef SASASURANCE2_BUSINESS_H
#define SASASURANCE2_BUSINESS_H
#include "Insurance.h"
#include <vector>

class Business {
private:
    std::string name;
    std::string sector;
    vector<Client> clients;
    vector<Insurance> insurances;
public:
    Business(string name, string sector);
    Business(string name, string sector, vector<Client> clients);
    void setClients(vector<Client> clients);
    bool raiseRequest(double cost, Client client);
    void addInsurance(Insurance insurance);
};
#endif //SASASURANCE2_BUSINESS_H
