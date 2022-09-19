//
// Created by ali salamatian on 2022-09-17.
//

#include "Client.h"
#include "Insurance.h"

Client::Client(string name) {
    this->name = name;
    this->insurance = nullptr;
}

string Client::getName() {
    return this->name;
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
    if (this->insurance == nullptr) {
        this->insurance = insurance;
        insurance->addClient(this);
    } else if (this->insurance != insurance) {
        removeInsurance(this->insurance);
        this->insurance = insurance;
        insurance->addClient(this);
    }
}

void Client::removeInsurance(Insurance *insurance) {
    if (insurance != nullptr) {
        insurance->removeClient(this);
        insurance = nullptr;
    }
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

