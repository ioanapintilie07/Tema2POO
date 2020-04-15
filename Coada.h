//
// Created by Expert on 4/14/2020.
//

#ifndef PROIECT2_COADA_H
#define PROIECT2_COADA_H

#include "Vector.h"

class Coada : public Vector {
public:
    Coada(int n, const Complex &number) : Vector(n, number) {};

    explicit Coada(const Vector &x) : Vector(x) {};

    explicit Coada(int dim = 0, Complex *vector = nullptr) : Vector(dim, vector) {};

    ~Coada() override = default;

    Coada &operator=(const Coada &x);

    bool purImaginar() override;

    void adaugare(Complex &valoare, int pozitie) override;

    Complex stergere(int pozitie) override;
};


#endif //PROIECT2_COADA_H
