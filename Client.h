//
// Created by ali salamatian on 2022-09-17.
//

#ifndef SASASURANCE2_CLIENT_H
#define SASASURANCE2_CLIENT_H
#include <vector>
#include "Plan.h"
using namespace std;

class Client {
private:
    string name;
    string password;
    vector<Plan> plans;
public:
    Client(string name);
    string getName();
    vector<Plan> getPlans();
};
#endif //SASASURANCE2_CLIENT_H
