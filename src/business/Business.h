//
// Created by ali salamatian on 2022-09-17.
//
#pragma once
#include <string>
#include "../client/Client.h"
#include <vector>

class Business {
private:
    std::string name;
    std::string sector;
    vector<Client> clients;
    double money;
public:
    Business(string name, string sector);
    Business(string name, string sector, vector<Client> clients);
    Business(const string &name, const string &sector, double money);

    void setClients(vector<Client> clients);
    void raiseRequest(double cost, Client client);
    void addMoney(double income);
    double getMoney() const;

    const string &getName() const;

    void setName(const string &name);

    const string &getSector() const;

    void setSector(const string &sector);
};
