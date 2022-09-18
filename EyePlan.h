//
// Created by ali salamatian on 2022-09-17.
//
#pragma once
#include "Plan.h"

class EyePlan : public Plan {
public:
    const std::string type = "Eye";
    EyePlan(int coverage, double creditLimit, std::string insuranceName);

};

