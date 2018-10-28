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
void hadamard(qubit *);

void pipe_out(int, ...);
void clean(int, ...);

void plot_qubit();
double *test_KP(void);

#endif /* operation_h */
