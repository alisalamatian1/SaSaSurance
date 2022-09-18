#include <iostream>
#include "Client.h"
#include "Business.h"
#include "EyePlan.h"

int main() {
    Client client("As");
    Business business("focal", "dental");
    business.raiseRequest(12, client);
    EyePlan eyePlan(1, 2.0);
    std::cout << eyePlan.getCoverage() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
