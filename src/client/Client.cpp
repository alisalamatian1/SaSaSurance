//
// Created by ali salamatian on 2022-09-17.
//

#include "Client.h"
#include "../insurance/Insurance.h"

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

Insurance* Client::getInsurance() {
    return insurance;
}

void Client::subscribeInsurance(Insurance* insurance) {
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

void Client::payFees(double fee) {
    this->money -= fee;
    this->insurance->addMoney(fee);
}

void Client::addMoney(double claimedMoney) {
    this->money += claimedMoney;
}

Client::Client(const string &id, const string &name, const string &password, Insurance *insurance, double money) : id(
        id), name(name), password(password), insurance(insurance), money(money) {}

Client::Client(const string &name, const string &password, Insurance *insurance, double money) : name(name),
                                                                                                 password(password),
                                                                                                 insurance(insurance),
                                                                                                 money(money) {}

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
//void Client::subscribeInsurance(const Insurance &insurance) {
//    Client::insurance = insurance;
//}

