//
// Created by ali salamatian on 2022-09-17.
//

#ifndef SASASURANCE2_PLAN_H
#define SASASURANCE2_PLAN_H
#include <string>

class Plan {
protected:
    int coverage;
    double creditLimit;
    void decreaseCredit(int usedAmount);

public:
    Plan(int coverage, double creditLimit) {
        this->coverage = coverage;
        this->creditLimit = creditLimit;
    }
    int getCoverage();
};

#endif //SASASURANCE2_PLAN_H
