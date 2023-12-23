/***
Lab 3: exercise 1            *
Polynomial class             *
Header file                  *
***/
#include <vector>
#include <iterator>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>


class Polynomial
{
public:
    Polynomial() = default; // default constructor
    Polynomial(int coefficient); // constructor with one argument
    Polynomial(int coefficient, int degree); // constructor with two arguments

    Polynomial(const std::vector<std::pair<int, int>>& coefficients); // constructor with vector of pairs. std::pair<int, int> is a pair of ints meaning coefficient and degree. first is coefficient, second is degree.

    // copy constructor
    Polynomial(const Polynomial& P) = default; // default copy constructor

    // assignment operator - returns reference to polynomial
    Polynomial& operator=(const Polynomial& P) = default; // default assignment operator

    // type conversion operator
    operator std::string() const; // returns a string representation of the polynomial. const

    Polynomial& operator+=(const Polynomial& P); // here we use reference to polynomial because we don't want to copy the polynomial. we want to change the polynomial itself.
    Polynomial& operator-=(const Polynomial& P);
    Polynomial& operator*=(const Polynomial& P);

    // friend functions. they reason we use friend here is because we want to access the private members of the class, here coefficients_table.
    friend Polynomial operator+(const Polynomial& P, const Polynomial& Q); // no ref because we don't want to change the object. we want to return a new object.
    friend Polynomial operator-(const Polynomial& P, const Polynomial& Q);
    friend Polynomial operator*(const Polynomial& P, const Polynomial& Q);
    friend std::ostream& operator<<(std::ostream& os, Polynomial& P);

    bool operator==(const Polynomial& P) const; // const because it doesn't change the object. it just compares the object.

    // Member functions

    // returns the degree of the polynomial
    int degree() const; // const because it doesn't change the object.

private:
    std::map<int, int> coefficients_table; // takes in a coefficient and a degree.
};