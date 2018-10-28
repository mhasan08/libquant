//
//  test.c
//  libquant
//
//  Created by Munawar Hasan on 28/10/18.
//  Copyright © 2018 Munawar Hasan. All rights reserved.
//

#include "test.h"

#include "../quantum/operation.h"

void perform_all_tests(){
    double *kp = test_KP();
    
    plot_qubit();
}
