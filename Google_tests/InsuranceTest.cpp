//
// Created by ali salamatian on 2022-10-10.
//

#include "gtest/gtest.h"
#include "../src/insurance/EyePlan.h"
#include "../src/insurance/Insurance.h"
#include "../src/business/Business.h"

TEST (ProcessRequest, ClientSide) {
    EyePlan* eyePlan = new EyePlan (12, 2.0);
    vector<Plan*> plans;
    plans.push_back(eyePlan);
    Insurance* insurance = new Insurance("sunLife", plans, 1000);
    Client* c = new Client ("Ali", "123", 100);
    c->subscribeInsurance(insurance);
    insurance->processRequest(9, c, "Eye");
    EXPECT_EQ(109, c->getMoney());
    EXPECT_EQ(3, eyePlan->getCoverage());
    insurance->processRequest(3, c, "Eye");
    EXPECT_EQ(112, c->getMoney());
    EXPECT_EQ(0, eyePlan->getCoverage());
}

TEST (ProcessRequest, ClientSideExceedThePlanCoverage) {
    EyePlan* eyePlan = new EyePlan (12, 2.0);
    vector<Plan*> plans;
    plans.push_back(eyePlan);
    Insurance* insurance = new Insurance("sunLife", plans, 1000);
    Client* c = new Client ("Ali", "123", 100);
    c->subscribeInsurance(insurance);
    insurance->processRequest(13, c, "Eye");
    EXPECT_EQ(112, c->getMoney());
    EXPECT_EQ(0, eyePlan->getCoverage());
}

TEST (ProcessRequest, BusinessSide) {
    EyePlan* eyePlan = new EyePlan (12, 2.0);
    vector<Plan*> plans;
    plans.push_back(eyePlan);
    Insurance* insurance = new Insurance("sunLife", plans, 1000);
    Client c("Ali", "123", 100);
    c.subscribeInsurance(insurance);
    Business* b = new Business("EyeCare", "Eye", 1000);
    insurance->processBusinessRequest(9, c, b);
    EXPECT_EQ(1009,b->getMoney());
    EXPECT_EQ(3, eyePlan->getCoverage());
    insurance->processBusinessRequest(3, c, b);
    EXPECT_EQ(1012,b->getMoney());
    EXPECT_EQ(0, eyePlan->getCoverage());
}

TEST (ProcessRequest, BusinessSideExceedLimit) {
    EyePlan* eyePlan = new EyePlan (12, 2.0);
    vector<Plan*> plans;
    plans.push_back(eyePlan);
    Insurance* insurance = new Insurance("sunLife", plans, 1000);
    Client c("Ali", "123", 100);
    c.subscribeInsurance(insurance);
    Business* b = new Business("EyeCare", "Eye", 1000);
    insurance->processBusinessRequest(13, c, b);
    EXPECT_EQ(1012,b->getMoney());
    EXPECT_EQ(0, eyePlan->getCoverage());
}