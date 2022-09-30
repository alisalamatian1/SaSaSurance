//
// Created by ali salamatian on 2022-09-17.
//

#include "Plan.h"
#include "../AmountExceedException.h"

Plan::Plan(double coverage, double creditLimit) {
    this->coverage = coverage;
    this->creditLimit = creditLimit;
}

bool Plan::decreaseCredit(double usedAmount) {
    if (coverage - usedAmount < 0) {
        double temp = coverage;
        coverage = 0;
        throw new AmountExceedException(temp);
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