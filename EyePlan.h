//
// Created by ali salamatian on 2022-09-17.
//

#ifndef SASASURANCE2_EYEPLAN_H
#define SASASURANCE2_EYEPLAN_H

#include "Plan.h"

class EyePlan : public Plan {
public:
    const std::string type = "Eye";
    EyePlan(int coverage, double creditLimit, std::string insuranceName);

};

#endif //SASASURANCE2_EYEPLAN_H
