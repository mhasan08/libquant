//
//  operation.h
//  libquant
//
//  Created by Munawar Hasan on 26/10/18.
//  Copyright © 2018 Munawar Hasan. All rights reserved.
//

#ifndef operation_h
#define operation_h

#include <stdio.h>
#include "quantum.h"

#define UNIT_TEST 1

double mag(complex);
qubit *create_qubit(enum QUBIT_STATE);
quantum_register *create_quantum_register(int, enum QUBIT_STATE);
int num_of_qubits(quantum_register *);
void hadamard_n(quantum_register *);
void hadamard(qubit *);

void pipe_out(int, ...);
void clean_n(quantum_register *);
void clean(int, ...);

void plot_n(quantum_register *);
void plot(int, ...);
double *test_KP(void);

#endif /* operation_h */
