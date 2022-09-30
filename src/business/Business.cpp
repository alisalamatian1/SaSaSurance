//
// Created by ali salamatian on 2022-09-17.
//

#include "Business.h"
#include <iostream>
#include "../insurance/Insurance.h"

Business::Business(string name, string sector) {
    this->name = name;
    this->sector = sector;
}

void Business::setClients(vector <Client> clients) {
    this->clients = clients;
}

void Business::raiseRequest(double cost, Client client) {
    cout << "we are raising the request in the business" << endl;
    client.getInsurance()->processBusinessRequest(cost, client, this);
}

void Business::addMoney(double income) {
    this->money += income;
}

double Business::getMoney() const {
    return money;
}

Business::Business(const string &name, const string &sector, double money) : name(name), sector(sector), money(money) {}

const string &Business::getName() const {
    return name;
}

void Business::setName(const string &name) {
    Business::name = name;
}

const string &Business::getSector() const {
    return sector;
}

void Business::setSector(const string &sector) {
    Business::sector = sector;
}
