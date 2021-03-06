//
//  math.h
//  libquant
//
//  Created by Munawar Hasan on 26/10/18.
//  Copyright © 2018 Munawar Hasan. All rights reserved.
//

#ifndef math_h
#define math_h

#include <stdio.h>
#include "quantum.h"

#define PI 3.142857

void swap_qubit_basis(qubit *);
void no_swap_basis(qubit *);
double get_complex_magnitude(complex);
complex add(complex, complex);
complex scalar_multiply(double, complex);
complex multiply(complex, complex);

double *kronecker_product(double *, uint8_t, uint8_t, double *, uint8_t, uint8_t);

#endif /* math_h */
