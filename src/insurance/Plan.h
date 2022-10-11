//
// Created by ali salamatian on 2022-09-17.
//
#pragma once
#include <string>

class Plan {
protected:
    std::string sector;
    double coverage = 0;
    double creditLimit = 0;
public:
    Plan(double coverage, double creditLimit);
    bool decreaseCredit(double usedAmount);
    double getCoverage();
    std::string getSector();
    double getCreditLimit() const;
};
