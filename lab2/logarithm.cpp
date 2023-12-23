/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"
#include <cmath>
#include <iomanip>

//Default
Logarithm::Logarithm():b(2), c1(0.0), c2(1.0) {
    std::vector<double> dummy{0,1};
    E = new Polynomial{dummy};
}

//Logarithmic
Logarithm::Logarithm(const Expression& E1, double c1, double c2, int b):b(b),c1(c1),c2(c2){
    E = E1.clone();
}

//Copy
Logarithm::Logarithm(const Logarithm& L1) :b(L1.b),c1(L1.c1),c2(L1.c2){
    E = L1.E->clone();
}

//Destructor
Logarithm::~Logarithm(){
    b = 0, c1 = 0, c2 = 0;
    delete E;
}

//Clone
Logarithm* Logarithm::clone() const{
    return new Logarithm(*this);
}

Logarithm& Logarithm::set_base(int new_b) {
    b = new_b;
    return *this;
}

double Logarithm::operator()(double d) const {
    return 0;
}

Logarithm::operator std::string() const {
    return std::string();
}