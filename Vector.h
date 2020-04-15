//
// Created by Expert on 4/10/2020.
//

#ifndef PROIECT2_VECTOR_H
#define PROIECT2_VECTOR_H

#include "Complex.h"
#include <iostream>

class Vector {
protected:
    Complex *v = nullptr;
    int dim;
public:

    Vector(int n, const Complex &number);

    Vector(const Vector &x);

    explicit Vector(int dim = 0, Complex *vector = nullptr);

    virtual ~Vector();

    friend std::istream &operator>>(std::istream &input, Vector &x);

    friend std::ostream &operator<<(std::ostream &output, Vector &x);

    Vector &operator=(const Vector &x);

    virtual void adaugare(Complex &valoare, const int pozitie);

    virtual Complex stergere(const int pozitie);

    virtual bool purImaginar() { return true; };
};


#endif //PROIECT2_VECTOR_H
