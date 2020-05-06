//
// Created by Expert on 4/13/2020.
//

#include "Stiva.h"

Stiva &Stiva::operator=(const Stiva &x) {
    if (this == &x)
        return *this;
    *this = x;
    return *this;
}

Complex Stiva::sterge(const int pozitie) {
    Complex pop = v[dim - 1];
    dim--;
    return pop;
}

void Stiva::adauga(Complex &valoare, const int pozitie) {
    if (dim == capacitate)
        resize();
    v[dim] = valoare;
    dim++;
}