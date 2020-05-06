//
// Created by Expert on 4/10/2020.
//

#include "Vector.h"
#include "Complex.h"
#include <iostream>

void Vector::move() {
    Complex *aux;
    aux = new Complex[capacitate];
    for (int i = 0; i < dim; ++i)
        aux[i] = v[i];
    delete[] v;
    v = new Complex[capacitate];
    for (int i = 0; i < dim; ++i)
        v[i] = aux[i];
    delete[] aux;
}

void Vector::resize() {
    capacitate = capacitate * 2;
    if (dim != 0)
        move();
    else {
        delete[] v;
        v = new Complex[capacitate];
    }
}

Vector::Vector(const Vector &x) {
    int i;
    dim = x.dim;
    capacitate = x.capacitate;
    v = new Complex[capacitate];
    for (i = 0; i < dim; ++i)
        v[i] = x.v[i];
}

Vector::Vector(int dim, int capacitate, Complex *vector) : dim{dim}, capacitate{capacitate} {
    dim = dim;
    capacitate = capacitate;
    v = new Complex[capacitate];
    int i;
    for (i = 0; i < dim; ++i)
        v[i] = vector[i];
}

Vector::~Vector() {
    delete[] v;
    dim = 0;
    capacitate = 0;
}

std::istream &operator>>(std::istream &input, Vector &x) {
    int i;
    input >> x.dim;
    if (x.dim > x.capacitate) x.capacitate = x.dim;
    delete[] x.v;
    x.v = new Complex[x.capacitate];
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
    if (x.dim > dim) {
        if (x.dim > capacitate) {
            dim = x.dim;
            resize();
        }
    }
    int i;
    for (i = 0; i < dim; ++i)
        v[i] = x.v[i];
    return *this;
}

void Vector::adauga(Complex &valoare, const int pozitie) {
    int i;
    if (dim == capacitate)
        resize();
    dim++;
    for (i = dim + 1; i >= pozitie; --i)
        v[i] = v[i - 1];
    v[pozitie] = valoare;
}

Complex Vector::sterge(const int pozitie) {
    int i;
    Complex deleted = v[pozitie];
    for (i = pozitie + 1; i < dim; ++i)
        v[i - 1] = v[i];
    dim--;
    return deleted;
}

bool Vector::purImaginar(int start, int stop) {
    int i;
    if (start == -1 && stop == -1)
        return false;
    else {
        if (start <= stop) {
            for (i = start; i <= stop; ++i)
                if (v[i].re != 0)
                    return false;
        } else {
            for (i = start; i < dim; ++i)
                if (v[i].re != 0)
                    return false;

            for (i = 0; i <= stop; ++i)
                if (v[i].re != 0)
                    return false;
        }
    }
    return true;
}