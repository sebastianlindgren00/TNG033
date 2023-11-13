/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

constexpr double EPSILON = 1.0e-5;

class Expression {
public:
    // Destructor, compiler-generated
    virtual ~Expression() {
        --count_expressions;
    }
    static std::size_t get_count_expressions();

    // Test whether a given value 𝑥 is a root of the function f
    bool isRoot(double x) const ;
    // Return the value of Expression when x = d
    virtual double operator()(double d) const = 0;
    // Clone function
    virtual Expression* clone() const = 0;
    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Expression& E); // Same as in lab1

// We use protected instead of private to allow derived classes to access these members
protected:
    // Default constructor
    Expression() {
        ++count_expressions;
    };
    // Copy constructor
    Expression(const Expression&) {
        ++count_expressions;
    };

    // Total number of existing expressions -- to help to detect bugs in the code
    static std::size_t count_expressions;
    // Display function
    virtual void display(std::ostream& os = std::cout) const = 0;
};