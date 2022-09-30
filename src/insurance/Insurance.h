//
// Created by ali salamatian on 2022-09-17.
//
#pragma once
#include "../client/Client.h"
#include "Plan.h"
#include <set>
class Business;

class Insurance {
private:
    set <Client *> clients;
    std::string name;
    vector<Plan*> plans;
    double money;
public:
    Insurance(string name);
    Insurance(const string &name, const vector<Plan *> &plans, double money);

    void processRequest(double cost, Client* client, std::string planType);
    void processBusinessRequest(double cost, Client client, Business* business);
    void addClient(Client* client);
    void removeClient(Client* client);
    const set<Client*> &getClients() const;
    vector<Plan*> getPlans();
    const string &getName() const;
    void addToPlan (Plan* plan);
    void setName(const string &name);

    bool checkForSubscription();
    void collectSubscriptionFee(double fee);
    void addMoney(double fee);
    void payClient(double payable, Client* client);
    void payBusiness(double payable, Business* business);

    double getMoney() const;

    bool operator==(const Insurance &rhs) const;

    bool operator!=(const Insurance &rhs) const;
};
