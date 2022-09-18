#include <iostream>
#include "Client.h"
#include "Business.h"
#include "EyePlan.h"

int main() {
    Client client("As");
    Business business("clinic", "Eye");
    EyePlan eyePlan(12, 2.0, "sunLife");
    client.addToPlan(eyePlan);
    Insurance insurance;
    insurance.setName("sunLife");
    insurance.addClient(client);
    business.addInsurance(insurance);
    bool res = business.raiseRequest(12, client);
    std::cout << eyePlan.getCoverage() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
