//
// Created by Expert on 4/14/2020.
//

#include "Coada.h"

void Coada::move() {
    int i, nrAux = 0;
    Complex *aux;
    aux = new Complex[capacitate];
    if (first <= last) {
        for (i = first; i <= last; ++i)
            aux[nrAux++] = v[i];
    } else {
        for (i = first; i < dim; ++i)
            aux[nrAux++] = v[i];
        for (i = 0; i <= last; ++i)
            aux[nrAux++] = v[i];
    }
    delete[] v;
    v = new Complex[capacitate];
    for (i = 0; i < dim; ++i)
        v[i] = aux[i];
    delete[] aux;
}

Coada &Coada::operator=(const Coada &x) {
    if (this == &x)
        return *this;
    first = x.first;
    last = x.last;
    *this = x;
    return *this;
}

std::ostream &operator<<(std::ostream &output, Coada &x) {
    int first = x.getFirst(), last = x.getLast(), dim = x.getDim(), i;
    Complex *v;
    v = x.getVector();
    if (first == -1 && last == -1)
        output << "Empty";
    else {
        if (first <= last) {
            for (i = first; i <= last; ++i)
                output << v[i] << " ";
        } else {
            for (i = first; i < dim; ++i)
                output << v[i] << " ";

            for (i = 0; i <= last; ++i)
                output << v[i] << " ";
        }
    }
    return output;
}

void Coada::adauga(Complex &valoare, const int pozitie) {
    if (dim == capacitate)
        resize();
    if (first == -1 && last == -1) {
        first = last = 0;
        v[first] = valoare;
    } else if (last == dim - 1 && first > 0) {
        last = 0;
        v[last] = valoare;
    } else
        v[++last] = valoare;
    dim++;
}

Complex Coada::sterge(int pozitie) {
    Complex dequeue = v[first];
    if (first == last) {
        first = last = -1;
    } else if (first == dim - 1)
        first = 0;
    else
        first++;
    dim--;
    return dequeue;
}