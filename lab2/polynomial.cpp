/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"

// ADD implementation of the member functions for class Polynomial

// Constructor for creating a vector of doubles into a polynomial
Polynomial::Polynomial(const std::vector<double>& v) { // copied for each invocation - const reference therefore used.
    for (double d : v) {
        coefficients.push_back(d); // add elements of v into coefficients.
    }
}

// Constructor for creating a polynomial from a double
Polynomial::Polynomial(double d) {
    coefficients.push_back(d);
}

// Add-and-Assign operator for adding two polynomials.
Polynomial &Polynomial::operator+=(const Polynomial& p) {
    for (std::size_t i = 0; i < p.coefficients.size(); ++i) { // can't use int i = 0 because size_t is unsigned.
        coefficients[i] += p.coefficients[i];
    }

    return *this;
}

// Addition of polynomial with real double value d. p+d and d+p. p+=d should work.
double Polynomial::operator[](std::size_t) const {
    return coefficients[std::size_t()];
}

// Evaluate the polynomial at the given value of x
double Polynomial::operator()(double x) const {
    double result = 0.0;
    double power_of_x = 1.0;

    for (double coefficient : coefficients) {
        result += coefficient * power_of_x;
        power_of_x *= x;
    }

    return result;
}

// Clone function
Polynomial* Polynomial::clone() const {
    return new Polynomial(*this);  // Assuming your copy constructor is implemented
}

// Implementation of the subscript operator
double& Polynomial::operator[](std::size_t index) {
    if (index < coefficients.size()) {
        return coefficients[index];
    } else {
        // Handle out-of-bounds access, throw an exception, or resize the coefficients vector, as needed.
        // For simplicity, I'll resize the vector here assuming you want to allow dynamic resizing.
        coefficients.resize(index + 1, 0.0);
        return coefficients[index];
    }
}

//When converting Polynomial to std::string, coefficients should be represented
Polynomial::operator std::string() const {
    std::string s;
    for (double d : coefficients) {
        // Format each coefficient with two digits after the decimal point
        s += std::to_string(d);
        s += " ";  // Add a space between coefficients (adjust as needed)
    }
    return s;
}

Polynomial Polynomial::operator+(double value) const {
    Polynomial p(*this);
    p.coefficients[0] += value;
    return p;
}

// Friend function for adding two polynomials
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
    Polynomial p(lhs);
    p += rhs;
    return p;
}

