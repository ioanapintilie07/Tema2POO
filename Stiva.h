//
// Created by Expert on 4/13/2020.
//

#ifndef PROIECT2_STIVA_H
#define PROIECT2_STIVA_H

#include "Vector.h"

class Stiva : public Vector {
public:

    Stiva(const Stiva &x) : Vector(x) {};

    explicit Stiva(int dim = 0, int capacitate = 1, Complex *vector = new Complex[1]) : Vector(dim, capacitate,
                                                                                               vector) {};

    ~Stiva() override = default;

    Stiva &operator=(const Stiva &x);

    void adauga(Complex &valoare, int pozitie) override;

    Complex sterge(int pozitie) override;
};


#endif //PROIECT2_STIVA_H
