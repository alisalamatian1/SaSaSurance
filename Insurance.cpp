//
// Created by ali salamatian on 2022-09-17.
//

#include "Insurance.h"
#include "AmountExceedException.h"

bool Insurance::processRequest(double cost, Client client) {
    // 1. find the client
    for (auto c : clients) {
        // if id of the client is the same as the id of the current client then...
        if (c.getId() == client.getId()){
            // reduce the cost from the coverage
            for (auto p : c.getPlans()) {
                if (p.getInsuranceName() == this->name) {
                    // decrease the cost from the client plan coverage
                   if (!p.decreaseCredit(cost)) {
                       // throw an exception if the client does not have enough coverage
                       throw AmountExceedException();
                   } else {
                       return true;
                   }
                }
            }
        }
        return false;
    }

}

const vector<Client> &Insurance::getClients() const {
    return clients;
}

void Insurance::setClients(const vector<Client> &clients) {
    Insurance::clients = clients;
}

const string &Insurance::getName() const {
    return name;
}

void Insurance::setName(const string &name) {
    Insurance::name = name;
}

void Insurance::addClient(Client client) {
    clients.push_back(client);
}