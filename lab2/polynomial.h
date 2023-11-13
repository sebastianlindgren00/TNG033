/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

#include "expression.h"

class Polynomial : public Expression {
public:
    //Clang-tidy: "Single-argument constructors must be marked explicit to avoid unintentional implicit conversions"
    // Constructor for creating Polynomial from a vector of doubles
    explicit Polynomial (const std::vector<double>& v);
    // Constructor for creating Polynomial from a single double
    explicit Polynomial (double d);
    // Copy constructor
    Polynomial (const Polynomial& p);

    // Operators

    // clone() function
    Polynomial* clone() const override;
    // Assignment operator
    Polynomial& operator=(const Polynomial& p);
    // += operator
    Polynomial& operator+=(const Polynomial& p);
    // Addition of two polynomials p+q, where p and q are polynomials.
    friend Polynomial operator+(Polynomial p1, const Polynomial& p2) {
        return p1 += p2;
    }
    };






};