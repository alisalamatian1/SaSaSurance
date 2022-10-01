#include "gtest/gtest.h"
#include "../src/business/Business.h"

TEST (Constructor, ConstructorNameSectorMoney) {
    Business b("n", "m", 100);
    EXPECT_EQ("n", b.getName());
    EXPECT_EQ("m", b.getSector());
    EXPECT_EQ(100, b.getMoney());
}