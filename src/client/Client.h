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
    double money;
public:
    Client(string name);
    Client(const string &id, const string &name, const string &password, Insurance *insurance, double money);

    Client(const string &name, const string &password, Insurance *insurance, double money);

    string getName();
    string getId();
    string getPassword();
    Insurance* getInsurance();
    void subscribeInsurance(Insurance* insurance);
    bool raiseRequest(double cost, Client client);
    void removeInsurance(Insurance* insurance);
    void payFees(double fee);
    void addMoney(double claimedMoney);
//
//    void setId(const string &id);
//
//    void setName(const string &name);
//
//    void setPassword(const string &password);
//
//    void setPlans(const vector<Plan> &plans);
//
//    void subscribeInsurance(const Insurance &insurance);
};
