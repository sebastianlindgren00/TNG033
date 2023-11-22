/*********************************************************
 * Class Expression member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "expression.h"

// Initialize the counter of the total number of existing Expressions
std::size_t Expression::count_expressions = 0;

// Used only for debug purposes
// Return number of existing Expressions
std::size_t Expression::get_count_expressions() {
    return Expression::count_expressions;
}


bool Expression::isRoot(double x) const {

    if (abs(operator()(x)) <= Epsilon) { // <= since if lower or equal to Epsilon (almost zero) - interpret as 0.
        return true;
    }
    return false;
}

/* ************************* */
