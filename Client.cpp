//
// Created by ali salamatian on 2022-09-17.
//

#include "Client.h"

Client::Client(string name) {
    this->name = name;
}

string Client::getName() {
    return this->name;
}

vector<Plan> Client::getPlans() {
    return this->plans;
}