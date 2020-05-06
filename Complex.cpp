//
// Created by Expert on 4/9/2020.
//
#include <iostream>
#include "Complex.h"

Complex::Complex(float real, float imaginar) {
    re = real;
    im = imaginar;
}

std::istream &operator>>(std::istream &input, Complex &x) {
    input >> x.re >> x.im;
    return input;
}

std::ostream &operator<<(std::ostream &output, Complex &x) {
    if (x.re == 0)
        output << x.im << "i";
    else {
        output << x.re;
        if (x.im >= 0) output << "+";
        output << x.im << "i";
    }
    return output;
}