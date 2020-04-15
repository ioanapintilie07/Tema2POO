//
// Created by Expert on 4/14/2020.
//

#include "Coada.h"

bool Coada::purImaginar() {
    int i;
    for (i = 0; i < dim; ++i)
        if (v[i].re != 0)
            return false;
    return true;
}

Coada &Coada::operator=(const Coada &x) {
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

void Coada::adaugare(Complex &valoare, int pozitie) {
    Complex *aux;
    aux = new Complex[dim + 1];
    int i, dimAux = 0;
    aux[dimAux++] = valoare;
    for (i = 0; i < dim; ++i)
        aux[dimAux++] = v[i];
    Coada newQueue(dimAux, aux);
    *this = newQueue;
    delete[] aux;
}

Complex Coada::stergere(int pozitie) {
    Complex *aux, dequeue = v[dim - 1];
    aux = new Complex[dim - 1];
    int i, dimAux = 0;
    for (i = 0; i < dim - 1; ++i)
        aux[dimAux++] = v[i];
    Coada newQueue(dimAux, aux);
    *this = newQueue;
    delete[] aux;
    return dequeue;
}