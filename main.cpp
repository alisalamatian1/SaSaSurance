#include <iostream>
#include "src/client/Client.h"
#include "src/business/Business.h"
#include "src/insurance/EyePlan.h"
#include "src/insurance/Plan.h"
#include "src/insurance/Insurance.h"
#include "src/AmountExceedException.h"

int main() {
    // making a client
    Client client("As");
    // making a business
    Business* business = new Business("clinic", "Eye", 100);
    // setting up an insurance with EyePlan
    EyePlan* eyePlan = new EyePlan (12, 2.0);
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

    client.addMoney(10);
    // making a new insurance to test the setClient and remove method
    Insurance* insurance2 = new Insurance("manuLife");
    EyePlan* eyePlan2 = new EyePlan (16, 2.0);
    (*insurance2).addToPlan(eyePlan2);
    // adding the insurance to the client and the client to the insurance
    client.subscribeInsurance(insurance2);
    std::cout << "Name of the new insurance: " << std::endl;
    std::cout << client.getInsurance()->getName() << std::endl;
    // paying the first month fee
    try {
        std::cout <<"client money before payment" << client.getMoney() << std::endl;
        std::cout <<"insurance money before payment" << client.getInsurance()->getMoney() << std::endl;
        client.payInsuranceFees(10);
        std::cout <<"money after payment" << client.getMoney() << std::endl;
        std::cout <<"insurance money after payment" << client.getInsurance()->getMoney() << std::endl;
    } catch (AmountExceedException* e) {
        std::cout << "client doesn't have enough money to pay" << std::endl;
    }

    // client raising a request
    std::cout <<"client money before payment2: " << client.getMoney() << std::endl;
    std::cout <<"insurance money before payment2: " << client.getInsurance()->getMoney() << std::endl;
    client.raiseRequest(5, "Eye");
    std::cout <<"money after payment2: " << client.getMoney() << std::endl;
    std::cout <<"insurance money after payment2: " << client.getInsurance()->getMoney() << std::endl;

    // client paying fees to the business
    try {
        std::cout <<"client money before payment to business: " << client.getMoney() << std::endl;
        std::cout <<"Business money before payment" << business->getMoney() << std::endl;
        client.payBusinessFees(6, business);
        std::cout <<"Client money after payment to business: " << client.getMoney() << std::endl;
        std::cout <<"Business money after payment: " << business->getMoney() << std::endl;
    } catch (AmountExceedException* e) {
        std::cout << "client doesn't have enough money to pay" << std::endl;
    }

    // expecting success
    business->raiseRequest(15, client);
    std::cout << client.getInsurance()->getPlans().at(0)->getCoverage() << std::endl;

    business->raiseRequest(1, client);
    std::cout << "success" << std::endl;
    std::cout << client.getInsurance()->getPlans().at(0)->getCoverage() << std::endl;

    // expecting a warning that we cannot spend more than our coverage
    business->raiseRequest(1, client);

    // deleting the pointers
    delete business;
    delete eyePlan;
    delete eyePlan2;
    delete insurance;
    delete insurance2;
    business = nullptr;
    eyePlan = nullptr;
    eyePlan2 = nullptr;
    insurance = nullptr;
    insurance2 = nullptr;
    return 0;
}
