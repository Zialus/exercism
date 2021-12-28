#include "complex_numbers.h"
#include <math.h>

complex_t c_add(complex_t a, complex_t b) {
    complex_t solution = {.real = a.real + b.real, .imag = a.imag + b.imag};

    return solution;
}

complex_t c_sub(complex_t a, complex_t b) {
    complex_t solution = {.real = a.real - b.real, .imag = a.imag - b.imag};

    return solution;
}

complex_t c_mul(complex_t a, complex_t b) {
    complex_t solution = {.real = a.real * b.real - a.imag * b.imag,
                          .imag = a.imag * b.real + a.real * b.imag};

    return solution;
}

complex_t c_div(complex_t a, complex_t b) {
    //(a * c + b * d)/(c^2 + d^2) + (b * c - a * d)/(c^2 + d^2) * i.
    double c_square_d_square = b.real * b.real + b.imag * b.imag;

    complex_t solution = {
        .real = (a.real * b.real + a.imag * b.imag) / c_square_d_square,
        .imag = (a.imag * b.real - a.real * b.imag) / c_square_d_square};

    return solution;
}

double c_abs(complex_t x) {
    double a = x.real;
    double b = x.imag;
    double solution = sqrt(a * a + b * b);

    return solution;
}

complex_t c_conjugate(complex_t x) {
    complex_t solution = {.real = x.real, .imag = - x.imag};

    return solution;
}

double c_real(complex_t x) {
    return x.real;
}

double c_imag(complex_t x) {
    return x.imag;
}

complex_t c_exp(complex_t x) {
    double a = x.real;
    double b = x.imag;

    complex_t solution = {.real = exp(a) * cos(b), .imag = sin(b)};

    return solution;
}
