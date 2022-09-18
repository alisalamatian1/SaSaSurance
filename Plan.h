//
// Created by ali salamatian on 2022-09-17.
//

#ifndef SASASURANCE2_PLAN_H
#define SASASURANCE2_PLAN_H
#include <string>

class Plan {
protected:
    std::string sector;
    std::string insuranceName;
    double coverage;
    double creditLimit;

public:
    Plan(double coverage, double creditLimit, std::string insuranceName);
    std::string getInsuranceName();
    bool decreaseCredit(double usedAmount);
    double getCoverage();
    std::string getSector();

    double getCreditLimit() const;
};

#endif //SASASURANCE2_PLAN_H
