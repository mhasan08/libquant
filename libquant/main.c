//
//  main.c
//  libquant
//
//  Created by Munawar Hasan on 26/10/18.
//  Copyright © 2018 Munawar Hasan. All rights reserved.
//

#include <stdio.h>
#include "quantum/operation.h"

#ifdef UNIT_TEST

#include "unit_tests/test.h"

#endif

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
    
#ifdef UNIT_TEST
    perform_all_tests();
#endif
    
    return 0;
}
