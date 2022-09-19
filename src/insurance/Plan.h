//
// Created by ali salamatian on 2022-09-17.
//
#pragma once
#include <string>

class Plan {
protected:
    std::string sector;
    double coverage;
    double creditLimit;
public:
    Plan(double coverage, double creditLimit);
    bool decreaseCredit(double usedAmount);
    double getCoverage();
    std::string getSector();
    double getCreditLimit() const;
};
