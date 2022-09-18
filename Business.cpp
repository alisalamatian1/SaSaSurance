//
// Created by ali salamatian on 2022-09-17.
//

#include "Business.h"
#include <iostream>
#include "AmountExceedException.h"

Business::Business(string name, string sector) {
    this->name = name;
    this->sector = sector;
}

void Business::setClients(vector <Client> clients) {
    this->clients = clients;
}

bool Business::raiseRequest(double cost, Client client) {
    cout << "we are raising the request in the business" << endl;
    for (auto p : client.getPlans()) {
        if (p.getSector() == this->sector) {
            for (auto insurance: insurances) {
                if (insurance.getName() == p.getInsuranceName()) {
                    try {
                        bool result = insurance.processRequest(cost, client);
                        return result;
                    } catch (AmountExceedException) {
                        cout << "you can't spend more than your coverage" << endl;
                        return false;
                    }
                }
            }

        }
    }
    return false;
}

void Business::addInsurance(Insurance insurance) {
    insurances.push_back(insurance);
}