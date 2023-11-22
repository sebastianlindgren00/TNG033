/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Polynomial : public Expression {
public:
    // Constructor
    Polynomial(std::vector<double> v) {
        
    }
    // Conversion constructor, real constant into polynomial.
    Polynomial(double d);

    // Copy constructor
    Polynomial(const Polynomial&);

    // Assignment operator
    Polynomial& operator=(const Polynomial&);

    // Add-and-Assign operator
    Polynomial& operator+=(const Polynomial&);

    // Add two polynomials together
    friend Polynomial operator+(const Polynomial&, const Polynomial&);

    // Addition of polynomial with real double value d. p+d and d+p. p+=d should work.
    friend Polynomial operator+(const Polynomial&, double);
    friend Polynomial operator+(double, const Polynomial&);
    friend Polynomial& operator+=(Polynomial&, double);

    //Subscript operator[] to access polynomials coefficients.
    // k = p[i]; and p[i] = k; should compile.
    double operator[](std::size_t) const;

    //When converting Polynomial to std::string, coefficients should be represented
    //with two digits after the decimal point and zero coefficients should also be represented
    //in the string.
    explicit operator std::string() const override;

};

/*
 * std::vector should be used to store polinomial's coefficients
 */