//
// Created by Expert on 4/14/2020.
//

#ifndef PROIECT2_COADA_H
#define PROIECT2_COADA_H

#include "Vector.h"

class Coada : public Vector {
    int first, last;

    void move() override;

public:
    Coada(const Coada &x) : Vector(x) {
        first = x.first;
        last = x.last;
    }

    explicit Coada(int dim = 0, int capacitate = 1, Complex *vector = new Complex[1]) : Vector(dim, capacitate,
                                                                                               vector) {
        if (dim == 0)
            first = last = -1;
        else {
            first = 0;
            last = dim - 1;
        }
    };

    ~Coada() override = default;

    Coada &operator=(const Coada &x);

    friend std::ostream &operator<<(std::ostream &output, Coada &x);

    void adauga(Complex &valoare, int pozitie) override;

    Complex sterge(int pozitie) override;

    int getFirst() { return first; }

    int getLast() { return last; }

    Complex *getVector() { return v; }
};


#endif //PROIECT2_COADA_H
