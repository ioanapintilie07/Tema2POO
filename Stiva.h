//
// Created by Expert on 4/13/2020.
//

#ifndef PROIECT2_STIVA_H
#define PROIECT2_STIVA_H

#include "Vector.h"

class Stiva : public Vector {
public:
    Stiva(int n, const Complex &number) : Vector(n, number) {};

    explicit Stiva(const Vector &x) : Vector(x) {};

    explicit Stiva(int dim = 0, Complex *vector = nullptr) : Vector(dim, vector) {};

    ~Stiva() override = default;

    Stiva &operator=(const Stiva &x);

    bool purImaginar() override;

    void adaugare(Complex &valoare, int pozitie) override;

    Complex stergere(int pozitie) override;
};


#endif //PROIECT2_STIVA_H
