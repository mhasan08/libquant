//
//  gate.c
//  libquant
//
//  Created by Munawar Hasan on 28/10/18.
//  Copyright © 2018 Munawar Hasan. All rights reserved.
//

#include <math.h>

#include "gate.h"
#include "../quantum.h"
#include "../math.h"
#include "../operation.h"

qubit *and(qubit *p, qubit *q){
    qubit *res = NULL;
    if (get_complex_magnitude(p->alpha) >= THRESHOLD) {
        if (get_complex_magnitude(q->alpha) >= THRESHOLD) {
            res = create_qubit(ZERO);
        }else if (get_complex_magnitude(q->beta) >= THRESHOLD){
            res = create_qubit(ZERO);
        }else
            perror("superimposed xor is unstable and not supported yet!");
    }else if (get_complex_magnitude(p->beta) >= THRESHOLD){
        if (get_complex_magnitude(q->alpha) >= THRESHOLD) {
            res = create_qubit(ZERO);
        }else if (get_complex_magnitude(q->beta) >= THRESHOLD){
            res = create_qubit(ONE);
        }else
            perror("superimposed xor is unstable and not supported yet!");
    }else
        perror("superimposed xor is unstable and not supported yet!");
    if (res == NULL) {
        perror("and operation on qubit failed!");
    }
    return res;
}

//top => p
//bottom => q
void cnot(qubit *p, qubit *q){
    if (get_complex_magnitude(p->alpha) >= THRESHOLD) {
        if (get_complex_magnitude(q->alpha) >= THRESHOLD || get_complex_magnitude(q->beta)) {
            swap_qubit_basis(q);
        }else
            perror("superimposed xor is unstable and not supported yet!");
    } else if(get_complex_magnitude(p->beta) >= THRESHOLD){
        if (get_complex_magnitude(q->alpha) >= THRESHOLD || get_complex_magnitude(q->beta)) {
            no_swap_basis(q);
        }else
            perror("superimposed xor is unstable and not supported yet!");
    }else{
        perror("superimposed xor is unstable and not supported yet!");
    }
}

//top => p
//middle => q
//bottom => r
void toffoli(qubit *p, qubit *q, qubit *r){
    qubit *res = and(p, q);
    cnot(r, res);
    clean(1, res);
}

void phase_shift(qubit *q, double angle){
    complex c1;
    c1.real = cos(angle);
    c1.img = sin(angle);
    q->beta = multiply(q->beta, c1);
}
