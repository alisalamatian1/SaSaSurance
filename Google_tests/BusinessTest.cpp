#include "gtest/gtest.h"
#include "../src/business/Business.h"
#include "../src/insurance/EyePlan.h"
#include "../src/insurance/Insurance.h"
#include <iostream>

TEST (Constructor, ConstructorNameSectorMoney) {
    Business b("n", "m", 100);
    EXPECT_EQ("n", b.getName());
    EXPECT_EQ("m", b.getSector());
    EXPECT_EQ(100, b.getMoney());
}

TEST (RaiseRequest, ClaimInsurance) {
    EyePlan* eyePlan = new EyePlan (12, 2.0);
    vector<Plan*> plans;
    plans.push_back(eyePlan);
    Insurance* insurance = new Insurance("sunLife", plans, 1000);
    Client c("Ali", "123", 100);
    c.subscribeInsurance(insurance);
    Business b("EyeCare", "Eye", 1000);
    b.raiseRequest(9, c);
    EXPECT_EQ(1009, b.getMoney());
    EXPECT_EQ(3, insurance->getPlans()[0]->getCoverage());
    b.raiseRequest(3,c);
    EXPECT_EQ(1012, b.getMoney());
    EXPECT_EQ(0, insurance->getPlans()[0]->getCoverage());
}

TEST (RaiseRequest, ClaimInsuranceExceedLimit) {
    EyePlan* eyePlan = new EyePlan (12, 2.0);
    vector<Plan*> plans;
    plans.push_back(eyePlan);
    Insurance* insurance = new Insurance("sunLife", plans, 1000);
    Client c("Ali", "123", 100);
    c.subscribeInsurance(insurance);
    Business b("EyeCare", "Eye", 1000);
    b.raiseRequest(13, c);
    EXPECT_EQ(1012, b.getMoney());
    EXPECT_EQ(0, insurance->getPlans()[0]->getCoverage());
}

