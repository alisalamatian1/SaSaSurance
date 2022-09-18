//
// Created by ali salamatian on 2022-09-17.
//

#include "Business.h"
#include <iostream>
Business::Business(string name, string sector) {
    this->name = name;
    this->sector = sector;
}

void Business::setClients(vector <Client> clients) {
    this->clients = clients;
}

void Business::raiseRequest(int cost, Client client) {
    cout << "we are raising the request in the business" << endl;
}