//
// Created by ali salamatian on 2022-09-17.
//

#ifndef SASASURANCE2_CLIENT_H
#define SASASURANCE2_CLIENT_H

#include <vector>
#include "Plan.h"
// #include "Insurance.h"
using namespace std;

class Client {
private:
    string id;
    string name;
    string password;
    vector<Plan> plans;
    // Insurance insurance;
public:
    Client(string name);
    string getName();
    vector<Plan> getPlans();
    string getId();
    string getPassword();
    // Insurance getInsurance();
    // void setInsurance(Insurance insurance);

    void addToPlan (Plan plan);
//
//    void setId(const string &id);
//
//    void setName(const string &name);
//
//    void setPassword(const string &password);
//
//    void setPlans(const vector<Plan> &plans);
//
//    void setInsurance(const Insurance &insurance);
};
#endif //SASASURANCE2_CLIENT_H
