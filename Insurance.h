//
// Created by ali salamatian on 2022-09-17.
//
#pragma once
#include "Client.h"

class Insurance {
private:
    vector <Client> clients;
    std::string name;
public:
    bool processRequest(double cost, Client client);
    void addClient(Client client);
    void removeClient(Client client);
    const vector<Client> &getClients() const;
    void setClients(const vector<Client> &clients);

    const string &getName() const;

    void setName(const string &name);
};
