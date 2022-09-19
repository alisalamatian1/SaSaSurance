#include <iostream>
#include "client/Client.h"
#include "business/Business.h"
#include "insurance/EyePlan.h"

int main() {
    // making a client
    Client client("As");
    // making a business
    Business business("clinic", "Eye");
    // setting up an insurance with EyePlan
    Insurance* insurance = new Insurance("sunLife");
    EyePlan* eyePlan = new EyePlan (12, 2.0);
    (*insurance).addToPlan(eyePlan);
    // adding the insurance to the client and the client to the insurance
    client.setInsurance(insurance);
    std::cout << client.getInsurance()->getName() << std::endl;

    // raising the request to reduce $12 from the client's account
    // expecting success
    if (business.raiseRequest(12, client)) {
        std::cout << "success" << std::endl;
        std::cout << client.getInsurance()->getPlans().at(0)->getCoverage() << std::endl;
    }
    // expecting a warning that we cannot spend more than our coverage
    business.raiseRequest(1, client);

    std::cout << "changing insurance \n\n"<< std::endl;

    // making a new insurance to test the setClient and remove method
    Insurance* insurance2 = new Insurance("manuLife");
    EyePlan* eyePlan2 = new EyePlan (16, 2.0);
    (*insurance2).addToPlan(eyePlan2);
    // adding the insurance to the client and the client to the insurance
    client.setInsurance(insurance2);
    std::cout << "Name of the new insurance: " << std::endl;
    std::cout << client.getInsurance()->getName() << std::endl;
    // expecting success
    if (business.raiseRequest(15, client)) {
        std::cout << "success" << std::endl;
        std::cout << client.getInsurance()->getPlans().at(0)->getCoverage() << std::endl;
    }
    if (business.raiseRequest(1, client)) {
        std::cout << "success" << std::endl;
        std::cout << client.getInsurance()->getPlans().at(0)->getCoverage() << std::endl;
    }
    // expecting a warning that we cannot spend more than our coverage
    business.raiseRequest(1, client);

    return 0;
}
