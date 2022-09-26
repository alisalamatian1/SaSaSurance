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
        // todo: after adding the money transfer functionality, we should set the coverage to 0 and send the money
        // todo: the difference to 0 to the business and throw a warning that the coverage was not enough for the ask

        throw new AmountExceedException(coverage);
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