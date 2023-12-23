/*******************************
 * Lab 3: exercise 1            *
 * Polynomial class             *
 *******************************/

#include "polynomial.h"

/*******************************
 *  Create constructor - empty, coefficient, both. done         *
 *******************************/
Polynomial::Polynomial(int coefficient) {
    if (coefficient != 0) {
        coefficients_table[0] = coefficient; // polynomial p1{2} gives p1 = 2
    }
}

Polynomial::Polynomial(int degree, int coefficient) {
    if (coefficient != 0) {
        coefficients_table[degree] = coefficient; // polynomial p1{3, 2} gives p1 = 2X^3
    }
}

/*******************************
 *  Create constructor - vector of terms. done         *
 *******************************/
Polynomial::Polynomial(const std::vector<std::pair<int, int>>& coefficients) { // polynomial p{{{1, 2}, {2, -5}, {6, 1}}}; gives p = 2X^1 - 5X^2 + X^6
    std::copy(coefficients.begin(), coefficients.end(), std::inserter(coefficients_table, coefficients_table.begin())); // this is how copy works: https://www.cplusplus.com/reference/algorithm/copy/, this is how inserter works: https://www.cplusplus.com/reference/iterator/inserter/
}

/*******************************
 *  Member function degree. done        *
 *******************************/
int Polynomial::degree() const {
    if (coefficients_table.empty()) {
        return 0; // needed since the degree of the zero polynomial is not defined
    }
    int max_degree = 0;
    for (const auto& term : coefficients_table) {
        int degree = term.first;
        if (degree > max_degree) {
            max_degree = degree;
        }
    }
    return max_degree;
}

/*******************************
 *  Type conversion operator. done         *
 *******************************/
Polynomial::operator std::string() const {
    std::string s;
    bool isFirstTerm = true;
    char sign = '+'; // sign of the coefficient

    if (coefficients_table.empty()) { // if the polynomial is empty, return 0
        return std::string("0");
    }

    for (const auto& term : coefficients_table) { // const reference to the term since we don't want to change the term
        int degree = term.first;
        int coefficient = term.second;

        if (isFirstTerm) {
            s += (coefficient > 0) ? std::format("{}X^{}", coefficient, degree) : std::format("{}{}X^{}", sign = '-', std::abs(coefficient), degree);
            isFirstTerm = false;
            continue;
        }

        sign = (coefficient < 0) ? '-' : '+';

        s += std::format(" {} {}X^{}", sign, std::abs(coefficient), degree);
    }
    return s;
}

/*******************************
 *  Overloaded operators. done         *
 *******************************/

Polynomial& Polynomial::operator+=(const Polynomial& P) {
    for (const auto& i : P.coefficients_table) {
        int degree = i.first;
        int coefficient = i.second;

        // add coeff to existing coeff with same degree
        coefficients_table[degree] += coefficient;

        // remove if zero
        if (coefficients_table[degree] == 0) {
            coefficients_table.erase(degree); // this is how erase works: https://www.cplusplus.com/reference/map/map/erase/
        }
    }
    return *this;
}


Polynomial& Polynomial::operator-=(const Polynomial& P) {
    for (const auto& i : P.coefficients_table) {
        int degree = i.first;
        int coefficient = i.second;

        coefficients_table[degree] -= coefficient;

        if (coefficients_table[degree] == 0) {
            coefficients_table.erase(degree);
        }
    }
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& P) {
    std::map<int, int> result;

    for (const auto& term1 : coefficients_table) { // current term of the first polynomial
        for (const auto& term2 : P.coefficients_table) { // current term of the second polynomial
            int degree_sum = term1.first + term2.first;
            int coefficient_product = term1.second * term2.second;

            // add the product to the existing term with the same degree
            result[degree_sum] += coefficient_product;

            // remove if zero
            if (result[degree_sum] == 0) {
                result.erase(degree_sum);
            }
        }
    }

    coefficients_table = result;
    return *this;
}


Polynomial operator+(const Polynomial& P, const Polynomial& Q) {
    Polynomial p = P;
    return p += Q;
}

Polynomial operator-(const Polynomial& P, const Polynomial& Q) {
    Polynomial p = P;
    return p -= Q;
}

Polynomial operator*(const Polynomial& P, const Polynomial& Q) {
    Polynomial p = P;
    return p *= Q;
}

bool Polynomial::operator==(const Polynomial& P) const {
    return coefficients_table == P.coefficients_table; // the compiler is smart, so if the statement in the bool function is true it will return true, if it's false it will return false.
}

std::ostream& operator<<(std::ostream& os, Polynomial& P) {
    os << std::string(P); // calls the type conversion operator making the polynomial into a string
    return os; // return the output stream
}