//
// Created by ali salamatian on 2022-09-17.
//
#pragma once

#include <vector>
#include <string>
class Insurance;
class Business;

using namespace std;

class Client {
private:
    string id;
    string name;
    string password;
    Insurance* insurance = nullptr;
    double money = 0;
    void copyClient(const Client &passedClient);
    void deleteClient();
public:
    Client(string name);
    Client(const string &id, const string &name, const string &password, Insurance *insurance, double money);
    Client(const string &name, const string &password, Insurance *insurance, double money);
    Client(const string &name, const string &password, double money);
    Client & operator=(const Client & assignment);
    Client(const Client & passedClient);
    ~Client();

    void subscribeInsurance(Insurance* insurance);
    bool raiseRequest(double cost, std::string planType);
    void removeInsurance(Insurance* insurance);
    void payInsuranceFees(double fee);
    void payBusinessFees(double fee, Business* business);
    void addMoney(double claimedMoney);

    string getName();
    string getId();
    string getPassword();
    Insurance* getInsurance();
    double getMoney() const;
};
