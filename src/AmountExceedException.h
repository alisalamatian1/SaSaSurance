//
// Created by ali salamatian on 2022-09-17.
//
#pragma once

#include <exception>

class AmountExceedException : public std::exception {
private:
    double covered;
public:
    AmountExceedException();
    AmountExceedException(double covered);
    double getCoverage();
};

