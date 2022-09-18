#include <iostream>
#include "Client.h"
#include "Business.h"
#include "EyePlan.h"

int main() {
    Client client("As");
    Business business("clinic", "Eye");
    EyePlan eyePlan(12, 2.0, "sunLife");
    client.addToPlan(eyePlan);
    Insurance* insurance = new Insurance();
    (*insurance).setName("sunLife2");
    client.setInsurance(insurance);
    std::cout << client.getInsurance()->getName() << std::endl;

    Insurance insurance1;
    insurance1.setName("sunLife");
    business.addInsurance(insurance1);
    bool res = business.raiseRequest(12, client);
    std::cout << eyePlan.getCoverage() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
