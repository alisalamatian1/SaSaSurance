//
// Created by ali salamatian on 2022-09-30.
//

#include "gtest/gtest.h"
#include "../src/insurance/EyePlan.h"
#include "../src/insurance/Insurance.h"
#include <iterator>

TEST (Subcription, InsuranceValidSubcscription) {
    EyePlan* eyePlan = new EyePlan (12, 2.0);
    vector<Plan*> plans;
    plans.push_back(eyePlan);
    Insurance* insurance = new Insurance("sunLife", plans, 1000);
    Client *c = new Client("Ali", "123", 100);
    c->subscribeInsurance(insurance);
    std::set<Client *>::iterator it;
    it = insurance->getClients().find(c);
    EXPECT_TRUE(it != insurance->getClients().end());
}