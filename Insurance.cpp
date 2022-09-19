//
// Created by ali salamatian on 2022-09-17.
//

#include "Insurance.h"
#include "AmountExceedException.h"

Insurance::Insurance(string name) {
    this->name = name;
}

bool Insurance::processRequest(double cost, Client client) {
    // loop over the clients
    for (auto c : clients) {
        // if id of the client is the same as the id of the current client then...
        if (c->getId() == client.getId()){
            // reduce the cost from the coverage
            bool res = client.getInsurance()->getPlans().at(0)->decreaseCredit(cost);
            if (!res) {
                throw AmountExceedException();
            } else {
                return true;
            }
//            for (auto p : c.getPlans()) {
//                if (p.getInsuranceName() == this->name) {
//                    // decrease the cost from the client plan coverage
//                   if (!p.decreaseCredit(cost)) {
//                       // throw an exception if the client does not have enough coverage
//                       throw AmountExceedException();
//                   } else {
//                       return true;
//                   }
//                }
//            }
        }
        return false;
    }
    return false;
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
        client->setInsurance(this);
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
