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

double mag(complex);
qubit *create_qubit(enum QUBIT_STATE);
void hadamard(qubit *);

void pipe_out(int, ...);
void clean(int, ...);


double *test_KP(void);

#endif /* operation_h */
