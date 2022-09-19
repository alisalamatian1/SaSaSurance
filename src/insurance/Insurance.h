//
// Created by ali salamatian on 2022-09-17.
//
#pragma once
#include "../client/Client.h"
#include "Plan.h"
#include <set>

class Insurance {
private:
    set <Client *> clients;
    std::string name;
    vector<Plan*> plans;
    // todo: write the functions for transferring money from insurance account to business and subscription
    double money;
public:
    Insurance(string name);
    bool processRequest(double cost, Client client);
    void addClient(Client* client);
    void removeClient(Client* client);
    const set<Client*> &getClients() const;
    vector<Plan*> getPlans();
    const string &getName() const;
    void addToPlan (Plan* plan);
    void setName(const string &name);

    bool checkForSubscription();
    void collectSubscriptionFee(double fee);

    bool operator==(const Insurance &rhs) const;

    bool operator!=(const Insurance &rhs) const;
};
