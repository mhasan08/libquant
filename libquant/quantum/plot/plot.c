//
//  plot.c
//  libquant
//
//  Created by Munawar Hasan on 28/10/18.
//  Copyright © 2018 Munawar Hasan. All rights reserved.
//

#include <stdlib.h>

#include "plot.h"

void plot_qubits(){
    int status = system("gnuplot --persist qubit.p");
    if (status < 0) {
        perror("some error occured in plotting the graph");
    }
}
