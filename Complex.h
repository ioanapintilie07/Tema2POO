//
// Created by Expert on 4/9/2020.
//

#ifndef PROIECT2_COMPLEX_H
#define PROIECT2_COMPLEX_H

#include <iostream>

class Complex {
    float re, im;
public:
    explicit Complex(float real = 0, float imaginar = 0);

    Complex(const Complex &x);

    ~Complex();

    friend std::istream &operator>>(std::istream &input, Complex &x);

    friend std::ostream &operator<<(std::ostream &output, Complex &x);

    Complex &operator=(const Complex &x);

    friend class Vector;

    friend class Stiva;

    friend class Coada;
};


#endif //PROIECT2_COMPLEX_H
