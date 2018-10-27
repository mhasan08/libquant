//
//  math.c
//  libquant
//
//  Created by Munawar Hasan on 26/10/18.
//  Copyright © 2018 Munawar Hasan. All rights reserved.
//

#include "math.h"
#include "quantum.h"
#include <math.h>
#include <stdlib.h>

double get_complex_magnitude(complex c){
    return sqrt(pow(c.real, 2) + pow(c.img, 2));
}

complex add(complex c1, complex c2){
    complex res;
    res.real = c1.real + c2.real;
    res.img = c2.img + c2.img;
    return res;
}

complex scalar_multiply(double scalar, complex c){
    complex res;
    res.real = scalar * c.real;
    res.img = scalar * c.img;
    
    return res;
}

void printMat(double *ptr, int r, int c){
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%lf\t",ptr[i * r + j]);
        }
        printf("\n");
    }
    
    printf("\n");
}

double *kronecker_product(double *m1, uint8_t r1, uint8_t c1, double *m2, uint8_t r2, uint8_t c2){
    double *kr = (double *)calloc((r1*r2) * (c1*c2), sizeof(double));
    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            for (int k = 0; k < r2; k++) {
                for (int l = 0; l < c2; l++) {
                    kr[(i*r1*r2*c2) + ((c1*k*r2) + l) + j*c2] = m1[i * r1 + j] * m2[k * r2 + l];
                }
            }
        }
    }
    
    printMat(kr, (r1*r2), (c1*c2));
    
    return kr;
}
