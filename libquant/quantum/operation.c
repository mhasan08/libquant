//
//  operation.c
//  libquant
//
//  Created by Munawar Hasan on 26/10/18.
//  Copyright © 2018 Munawar Hasan. All rights reserved.
//

#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include "operation.h"
#include "quantum.h"
#include "math.h"

void zero_basis(qubit *q){
    complex c1, c2;
    c1.real = 1;
    c1.img = 0;
    c2.real = c2.img = 0;
    q->alpha = c1;
    q->beta = c2;
}

void one_basis(qubit *q){
    complex c1, c2;
    c1.real = c1.img = 0;
    c2.real = 1;
    c2.img = 0;
    q->alpha = c1;
    q->beta = c2;
}

double mag(complex c){
    return get_complex_magnitude(c);
}

double *getHadamard(){
    int row = 2;
    int col = 2;
    double *h = (double *)calloc(row * col, sizeof(double));
    for (int i =0; i < (row * col); i++)
        h[i] = 1 / sqrt(2);
    h[3] = -1 * h[3];
    return h;
}

qubit *create_qubit(enum QUBIT_STATE state){
    qubit *q = (qubit *)malloc(sizeof(qubit));
    switch (state) {
        case ZERO:
            zero_basis(q);
            break;
        case ONE:
            one_basis(q);
            break;
        case SUPERIMPOSED:
            printf("later ....");
            break;
        default:
            break;
    }
    return q;
}

enum QUBIT_STATE resolve_qubit_state(qubit *q){
    if(mag(q->alpha) >= THRESHOLD)
        return ZERO;
    if(mag(q->beta) >= THRESHOLD)
        return ONE;
    else
        return SUPERIMPOSED;
}


void hadamard(qubit *q){
    double *h = getHadamard();
    
    complex alpha, beta;
    
    alpha = add(scalar_multiply(h[0], q->alpha), scalar_multiply(h[1], q->beta));
    beta = add(scalar_multiply(h[2], q->alpha), scalar_multiply(h[3], q->beta));
    
    q->alpha = alpha;
    q->beta = beta;
    
    free(h);
}

void pipe_out(int count, ...){
    va_list valist;
    va_start(valist, count);
    
    for (int i = 0; i < count; i++) {
        qubit *q = va_arg(valist, qubit *);
        printf("[%lf i%lf; %lf i%lf]\n", q->alpha.real, q->alpha.img, q->beta.real, q->beta.img);
    }
}


void clean(int count, ...){
    va_list valist;
    va_start(valist, count);
    
    for (int i = 0; i < count; i++)
        free(va_arg(valist, qubit *));
    
    va_end(valist);
}


//unit tests
double *test_KP(){
    double *h1 = getHadamard();
    double *h2 = getHadamard();
    
    double *kp = kronecker_product(h1, 2, 2, h2, 2, 2);
    
    double *kp2 = kronecker_product(kp, 4, 4, h1, 2, 2);
    //kronecker_product(h1, 2, 2, kp, 4, 4);
    
    double *kp3 = kronecker_product(kp2, 8, 8, kp2, 8, 8);
    
    //kronecker_product(kp3, 16, 16, h1, 2, 2);
    
    return kp;
}

