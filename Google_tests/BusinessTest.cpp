#include "gtest/gtest.h"
#include "../src/business/Business.h"
#include "../src/insurance/EyePlan.h"
#include "../src/insurance/Insurance.h"

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
    Business b("dental", "Eye", 1000);
    b.raiseRequest(12, c);
    EXPECT_EQ(1012, b.getMoney());
    EXPECT_EQ(0, insurance->getPlans()[0]->getCoverage());
}

