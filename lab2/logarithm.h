/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include "expression.h"

class Logarithm : public Expression {

public:
    Logarithm(); //Default: creates log2(x)
    Logarithm(const Expression& E1, double c1, double c2, int b); //Logarithmic
    Logarithm(const Logarithm& L1);//Copy

    ~Logarithm() override; //Destructor

    Logarithm* clone() const override; //Clone
    Logarithm& set_base(int new_b);

    double operator()(double d) const override; //Evaluate
    explicit operator std::string() const override; //Conversion



private:
    Expression* E;
    int b;
    double c1,c2;
};