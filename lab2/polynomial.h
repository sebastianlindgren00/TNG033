/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>
#include "expression.h"

class Polynomial : public Expression {
public:
    // Constructor
    Polynomial(const std::vector<double>& v);
    // Conversion constructor, real constant into polynomial.
    Polynomial(double d);

    // Copy constructor - compiler generated
    Polynomial(const Polynomial& p) = default;

    // Assignment operator - compiler generated
    Polynomial& operator=(const Polynomial&) = default;

    // Destructor - compiler generated
    ~Polynomial() = default;

    // Add-and-Assign operator
    Polynomial& operator+=(const Polynomial&);

    //Subscript operator[] to access polynomials coefficients.
    // k = p[i]; and p[i] = k; should compile.
    double operator[](std::size_t) const;

    // Conversion operator to std::string, inherited from Expression (virtual)
    explicit operator std::string() const override;
    // Evaluate the polynomial at the given value of x, also virtual
    double operator()(double d) const override;
    // Clone function, also virtual
    Polynomial* clone() const override;

    //
    double& operator[](std::size_t index);
    // p + d and d+ p
    Polynomial operator+(double value) const;

    // We use friend here since we want operator+ to do 2 things from the same operator
    friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);

private:
    std::vector<double> coefficients;
};