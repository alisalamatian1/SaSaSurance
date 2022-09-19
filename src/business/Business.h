//
// Created by ali salamatian on 2022-09-17.
//
#pragma once
#include "../insurance/Insurance.h"
#include <vector>

class Business {
private:
    std::string name;
    std::string sector;
    vector<Client> clients;
public:
    Business(string name, string sector);
    Business(string name, string sector, vector<Client> clients);
    void setClients(vector<Client> clients);
    bool raiseRequest(double cost, Client client);
};
