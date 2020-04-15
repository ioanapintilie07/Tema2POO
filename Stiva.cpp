//
// Created by Expert on 4/13/2020.
//

#include "Stiva.h"

bool Stiva::purImaginar() {
    int i;
    for (i = 0; i < dim; ++i)
        if (v[i].re != 0)
            return false;
    return true;
}


Stiva &Stiva::operator=(const Stiva &x) {
    if (this == &x)
        return *this;
    dim = x.dim;
    delete[] v;
    v = new Complex[dim];
    int i;
    for (i = 0; i < dim; ++i)
        v[i] = x.v[i];
    return *this;
}

Complex Stiva::stergere(const int pozitie) {
    Complex *aux, pop = v[dim - 1];
    aux = new Complex[dim - 1];
    int i, dimAux = 0;
    for (i = 0; i < dim - 1; ++i)
        aux[dimAux++] = v[i];
    Stiva newStack(dimAux, aux);
    *this = newStack;
    delete[] aux;
    return pop;
}

void Stiva::adaugare(Complex &valoare, const int pozitie) {
    Complex *aux;
    aux = new Complex[dim + 1];
    int i, dimAux = 0;
    for (i = 0; i < dim; ++i)
        aux[dimAux++] = v[i];
    aux[dimAux++] = valoare;
    Stiva newStack(dimAux, aux);
    *this = newStack;
    delete[] aux;
}
