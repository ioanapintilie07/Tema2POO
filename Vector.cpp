//
// Created by Expert on 4/10/2020.
//

#include "Vector.h"
#include "Complex.h"
#include <iostream>

Vector::Vector(int n, const Complex &number) {
    int i;
    dim = n;
    v = new Complex[dim];
    for (i = 0; i < n; ++i)
        v[i] = number;
}

Vector::Vector(const Vector &x) {
    int i;
    dim = x.dim;
    v = new Complex[dim];
    for (i = 0; i < dim; ++i)
        v[i] = x.v[i];
}

Vector::Vector(int dim, Complex *vector) : dim{dim} {
    dim = dim;
    v = new Complex[dim];
    int i;
    for (i = 0; i < dim; ++i)
        v[i] = vector[i];
}

Vector::~Vector() {
    delete[] v;
    dim = 0;
}

std::istream &operator>>(std::istream &input, Vector &x) {
    int i;
    input >> x.dim;
    x.v = new Complex[x.dim];
    for (i = 0; i < x.dim; ++i)
        input >> x.v[i];
    return input;
}

std::ostream &operator<<(std::ostream &output, Vector &x) {
    int i;
    for (i = 0; i < x.dim - 1; ++i)
        output << x.v[i] << ", ";
    output << x.v[x.dim - 1];
    return output;
}

Vector &Vector::operator=(const Vector &x) {
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

void Vector::adaugare(Complex &valoare, const int pozitie) {
    int i, dimAux = 0;
    Complex *aux;
    aux = new Complex[dim + 1];
    for (i = 0; i < pozitie; ++i)
        aux[dimAux++] = v[i];
    aux[dimAux++] = valoare;
    for (i = pozitie; i < dim; ++i)
        aux[dimAux++] = v[i];
    Vector Aux(dimAux, aux);
    *this = Aux;
    delete[] aux;
}

Complex Vector::stergere(const int pozitie) {
    int i, dimAux = 0;
    Complex *aux, deleted = v[pozitie];
    aux = new Complex[dim + 1];
    for (i = 0; i < pozitie; ++i)
        aux[dimAux++] = v[i];
    for (i = pozitie + 1; i < dim; ++i)
        aux[dimAux++] = v[i];
    Vector Aux(dimAux, aux);
    *this = Aux;
    delete[] aux;
    return deleted;
}