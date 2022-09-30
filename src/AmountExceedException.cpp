//
// Created by ali salamatian on 2022-09-25.
//

#include "AmountExceedException.h"

AmountExceedException::AmountExceedException() {}

AmountExceedException::AmountExceedException(double covered) {
    this->covered = covered;
}

double AmountExceedException::getCoverage() {
    return this->covered;
}