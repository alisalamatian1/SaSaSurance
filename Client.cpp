//
// Created by ali salamatian on 2022-09-17.
//

#include "Client.h"
#include "Insurance.h"

Client::Client(string name) {
    this->name = name;
}

string Client::getName() {
    return this->name;
}

vector<Plan> Client::getPlans() {
    return this->plans;
}

string Client::getId() {
    return this->id;
}

string Client::getPassword() {
    return password;
}

Insurance* Client::getInsurance() const {
    return insurance;
}

void Client::setInsurance(Insurance* insurance) {
    this->insurance = insurance;
}

void Client::addToPlan(Plan plan) {
    plans.push_back(plan);
}
//void Client::setId(const string &id) {
//    Client::id = id;
//}
//
//void Client::setName(const string &name) {
//    Client::name = name;
//}
//
//void Client::setPassword(const string &password) {
//    Client::password = password;
//}
//
//void Client::setPlans(const vector<Plan> &plans) {
//    Client::plans = plans;
//}
//
//void Client::setInsurance(const Insurance &insurance) {
//    Client::insurance = insurance;
//}

