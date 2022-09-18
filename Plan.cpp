//
// Created by ali salamatian on 2022-09-17.
//

#include "Plan.h"

Plan::Plan(double coverage, double creditLimit, std::string insuranceName) {
    this->coverage = coverage;
    this->creditLimit = creditLimit;
    this->insuranceName = insuranceName;
}

std::string Plan::getInsuranceName() {
    return insuranceName;
}

bool Plan::decreaseCredit(double usedAmount) {
    if (coverage - usedAmount < 0) {
        return false;
    }
    this->coverage -= usedAmount;
    return true;
}

double Plan::getCreditLimit() const {
    return creditLimit;
}

std::string Plan::getSector() {
    return this->sector;
}