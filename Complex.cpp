//
// Created by Expert on 4/9/2020.
//
#include <iostream>
#include "Complex.h"

Complex::Complex(float real, float imaginar) {
    re = real;
    im = imaginar;
}

Complex::Complex(const Complex &x) {
    re = x.re;
    im = x.im;
}

Complex::~Complex() {
    re = 0;
    im = 0;
}

Complex &Complex::operator=(const Complex &x) {
    re = x.re;
    im = x.im;
}

std::istream &operator>>(std::istream &input, Complex &x) {
    input >> x.re >> x.im;
    return input;
}

std::ostream &operator<<(std::ostream &output, Complex &x) {
    if (x.re == 0) {
        if (x.im == 0)
            output << 0;
        else output << "i*" << x.im;
    } else if (x.im == 0) output << x.re;
    else output << x.re << " + i*" << x.im;
    return output;
}