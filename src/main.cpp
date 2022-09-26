#include <iostream>
#include "client/Client.h"
#include "business/Business.h"
#include "insurance/EyePlan.h"
#include "insurance/Plan.h"
#include "insurance/Insurance.h"

int main() {
    // todo: adding insurance payment
    // making a client
    Client client("As");
    // making a business
    Business* business = new Business("clinic", "Eye", 100);
    // setting up an insurance with EyePlan
//    Insurance* insurance = new Insurance("sunLife");
    EyePlan* eyePlan = new EyePlan (12, 2.0);
//    (*insurance).addToPlan(eyePlan);
    vector<Plan*> plans;
    plans.push_back(eyePlan);
    Insurance* insurance = new Insurance("sunLife", plans, 1000);
    // adding the insurance to the client and the client to the insurance
    client.subscribeInsurance(insurance);
    std::cout << client.getInsurance()->getName() << std::endl;

    // raising the request to reduce money from the client's account
    // expecting success
    std::cout << "The business money before the payment: " << business->getMoney() << std::endl;
    std::cout << "Insurance money before the payment: " << insurance->getMoney() << std::endl;
    business->raiseRequest(10, client);
    std::cout << "The business money after the payment: " << business->getMoney() << std::endl;
    std::cout << "Insurance money after the payment: " << insurance->getMoney() << std::endl;
    std::cout << client.getInsurance()->getPlans().at(0)->getCoverage() << std::endl;

    // expecting a warning that we cannot spend more than our coverage
    business->raiseRequest(3, client);
    std::cout << "The business money after the warning: " << business->getMoney() << std::endl;
    std::cout << "Insurance money after the warning: " << insurance->getMoney() << std::endl;

    std::cout << "changing insurance \n\n"<< std::endl;

    // making a new insurance to test the setClient and remove method
    Insurance* insurance2 = new Insurance("manuLife");
    EyePlan* eyePlan2 = new EyePlan (16, 2.0);
    (*insurance2).addToPlan(eyePlan2);
    // adding the insurance to the client and the client to the insurance
    client.subscribeInsurance(insurance2);
    std::cout << "Name of the new insurance: " << std::endl;
    std::cout << client.getInsurance()->getName() << std::endl;
    // expecting success
    business->raiseRequest(15, client);
    std::cout << client.getInsurance()->getPlans().at(0)->getCoverage() << std::endl;

    business->raiseRequest(1, client);
    std::cout << "success" << std::endl;
    std::cout << client.getInsurance()->getPlans().at(0)->getCoverage() << std::endl;

    // expecting a warning that we cannot spend more than our coverage
    business->raiseRequest(1, client);

    return 0;
}
