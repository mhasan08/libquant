//
//  test.c
//  libquant
//
//  Created by Munawar Hasan on 28/10/18.
//  Copyright © 2018 Munawar Hasan. All rights reserved.
//

#include "test.h"

#include "../quantum/operation.h"
#include "../quantum/gates/gate.h"

#define PI 3.14159265

void check_register(){
    quantum_register *qreg = create_quantum_register(4, ZERO);
    int x = num_of_qubits(qreg);
    //printf("qubits: %d\n", x);
    hadamard_n(qreg);
    
    plot_n(qreg);
    
    clean_n(qreg);
}

void perform_all_tests(){
    double *kp = test_KP();
    
    qubit *q = create_qubit(ONE);
    phase_shift(q, PI/64);
    
    printf("values: %lf, %lf, %lf, %lf\n", q->alpha.real, q->alpha.img, q->beta.real, q->beta.img);
    
    qubit *q1 = create_qubit(ZERO);
    hadamard(q1);
    //plot(1, q1);
    
    check_register();
}


