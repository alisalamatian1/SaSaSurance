//
// Created by ali salamatian on 2022-10-10.
//

#include "gtest/gtest.h"
#include "../src/insurance/Plan.h"
#include "../src/AmountExceedException.h"

TEST (DecreaseCredit, Pass) {
    Plan p(500, 1000);
    try {
        bool res = p.decreaseCredit(499);
        EXPECT_TRUE(res);
        EXPECT_EQ(1, p.getCoverage());
        bool res2 = p.decreaseCredit(1);
        EXPECT_TRUE(res2);
        EXPECT_EQ(0, p.getCoverage());
    } catch (AmountExceedException e) {

    }
}

TEST (DecreaseCredit, Fail) {
    Plan p(500, 1000);
    try {
        p.decreaseCredit(501);
        FAIL();
    } catch (AmountExceedException* e) {
        EXPECT_EQ(500, e->getCoverage());
    }
}