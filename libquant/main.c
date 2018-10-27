//
//  main.c
//  libquant
//
//  Created by Munawar Hasan on 26/10/18.
//  Copyright © 2018 Munawar Hasan. All rights reserved.
//

#include <stdio.h>
#include "quantum/operation.h"

int main(int argc, const char * argv[]) {
    
    //create some qubit
    qubit *q = create_qubit(ZERO);
    qubit *p = create_qubit(ONE);
    
    pipe_out(1, q);
    
    hadamard(q);
    pipe_out(1, q);
    
    hadamard(q);
    pipe_out(1, q);
    
    clean(2, p, q);
    
    //double *kp = test_KP();
    
    return 0;
}
