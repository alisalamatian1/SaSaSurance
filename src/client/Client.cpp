//
// Created by ali salamatian on 2022-09-17.
//

#include "Client.h"
#include "../insurance/Insurance.h"
#include "../business/Business.h"
#include "../AmountExceedException.h"

Client::Client(string name) {
    this->name = name;
    this->insurance = nullptr;
}

Client::Client(const Client & passedClient) {
    id = passedClient.id;
    name = passedClient.name;
    password = passedClient.password;
    money = passedClient.money;
    if (passedClient.insurance->getPlans().empty()) {
        insurance = new Insurance(passedClient.insurance->getName());
    } else {
        insurance = new Insurance(passedClient.insurance->getName(), passedClient.insurance->getPlans(), passedClient.money);
    }
}

Client::~Client() {
    if (insurance != nullptr) {
        if (insurance->getName() != "") {
            delete insurance;
        }
    }
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

bool Client::raiseRequest(double cost, std::string planType) {
    this->getInsurance()->processRequest(cost, this, planType);
}

void Client::removeInsurance(Insurance *insurance) {
    if (insurance != nullptr) {
        insurance->removeClient(this);
        insurance = nullptr;
    }
}

void Client::payInsuranceFees(double fee) {
    if (money < fee) {
        throw new AmountExceedException();
    }
    this->money -= fee;
    this->insurance->addMoney(fee);
}

void Client::payBusinessFees(double fee, Business* business) {
    if (money < fee) {
        throw new AmountExceedException();
    }
    this->money -= fee;
    business->addMoney(fee);
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

double Client::getMoney() const {
    return money;
}

Client::Client(const string &name, const string &password, double money) : name(name), password(password),
                                                                           money(money) {}

