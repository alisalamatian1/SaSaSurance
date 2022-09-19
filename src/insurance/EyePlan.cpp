//
// Created by ali salamatian on 2022-09-17.
//

#include "EyePlan.h"

double Plan::getCoverage() {
    return this->coverage;
}

EyePlan::EyePlan(int coverage, double creditLimit) : Plan(coverage, creditLimit){
    this->sector = type;
}