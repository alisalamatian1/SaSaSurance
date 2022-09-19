//
// Created by ali salamatian on 2022-09-17.
//
#pragma once

#include <vector>
#include <string>
class Insurance;

using namespace std;

class Client {
private:
    string id;
    string name;
    string password;
    Insurance* insurance;
public:
    Client(string name);
    string getName();
    string getId();
    string getPassword();
    Insurance* getInsurance() const;
    void setInsurance(Insurance* insurance);
    bool raiseRequest(double cost, Client client);
    void removeInsurance(Insurance* insurance);
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
