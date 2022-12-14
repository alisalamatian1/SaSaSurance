//
// Created by ali salamatian on 2022-09-17.
//

#include "Insurance.h"
#include "../AmountExceedException.h"
#include "../business/Business.h"
#include <iostream>

Insurance::Insurance(string name) {
    this->name = name;
}

void Insurance::processRequest(double cost, Client* client, std::string planType) {
    // loop over the clients
    for (auto c : clients) {
        // if id of the client is the same as the id of the current client then...
        if (c->getId() == client->getId()){
            // reduce the cost from the coverage
            try {
                for (auto p : client->getInsurance()->getPlans()) {
                    if (p->getSector() == planType) {
                        p->decreaseCredit(cost);
                    }
                }
                payClient(cost, c);
            } catch (AmountExceedException* e) {
                cout << "you can't spend more than your coverage" << endl;
                payClient(e->getCoverage(), c);
            }
        }
    }
}

void Insurance::processBusinessRequest(double cost, Client client, Business* business) {
    // loop over the clients
    for (auto c : clients) {
        // if id of the client is the same as the id of the current client then...
        if (c->getId() == client.getId()){
            // reduce the cost from the coverage
            try {
                for (auto p : client.getInsurance()->getPlans()) {
                    if (p->getSector() == business->getSector()) {
                        p->decreaseCredit(cost);
                    }
                }
                payBusiness(cost, business);
            } catch (AmountExceedException* e) {
                payBusiness(e->getCoverage(), business);
                cout << "you can't spend more than your coverage" << endl;
            }
        }
    }
}

const set<Client*> &Insurance::getClients() const {
    return clients;
}

const string &Insurance::getName() const {
    return name;
}

void Insurance::setName(const string &name) {
    Insurance::name = name;
}

void Insurance::addClient(Client* client) {
    if (this->clients.find(client) != this->clients.end()) {
        // element is already present
    } else {
        clients.insert(client);
        client->subscribeInsurance(this);
    }
}

vector<Plan*> Insurance::getPlans() {
    return this->plans;
}

void Insurance::addToPlan(Plan* plan) {
    plans.push_back(plan);
}

void Insurance::removeClient(Client *client) {
    if (this->clients.find(client) != this->clients.end()) {
        // we haven't removed the element yet
        clients.erase(client);
        client->removeInsurance(this);
    } else {
        // the element has already removed
    }
}

bool Insurance::operator==(const Insurance &rhs) const {
    return name == rhs.name &&
           money == rhs.money;
}

bool Insurance::operator!=(const Insurance &rhs) const {
    return !(rhs == *this);
}

void Insurance::addMoney(double fee) {
    this->money += fee;
}

void Insurance::payClient(double payable, Client* client) {
    this->money -= payable;
    client->addMoney(payable);
}

void Insurance::payBusiness(double payable, Business *business) {
    this->money -= payable;
    business->addMoney(payable);
}

double Insurance::getMoney() const {
    return money;
}

Insurance::Insurance(const string &name, const vector<Plan *> &plans, double money) : name(name), plans(plans),
                                                                                      money(money) {}
