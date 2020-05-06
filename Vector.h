//
// Created by Expert on 4/10/2020.
//

#ifndef PROIECT2_VECTOR_H
#define PROIECT2_VECTOR_H

#include "Complex.h"
#include <iostream>

class Vector {
protected:
    int dim;
    int capacitate;

    void resize();

    virtual void move();

    Complex *v = nullptr;
public:

    Vector(const Vector &x);

    explicit Vector(int dim = 0, int capacitate = 1, Complex *vector = new Complex[1]);

    virtual ~Vector();

    friend std::istream &operator>>(std::istream &input, Vector &x);

    friend std::ostream &operator<<(std::ostream &output, Vector &x);

    Vector &operator=(const Vector &x);

    virtual void adauga(Complex &valoare, int pozitie);

    virtual Complex sterge(int pozitie);

    bool purImaginar(int start, int stop);

    int getDim() { return dim; };
};


#endif //PROIECT2_VECTOR_H
