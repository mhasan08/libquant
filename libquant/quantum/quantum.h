//
//  quantum.h
//  libquant
//
//  Created by Munawar Hasan on 26/10/18.
//  Copyright © 2018 Munawar Hasan. All rights reserved.
//

#ifndef quantum_h
#define quantum_h

#define THRESHOLD 0.99

enum QUBIT_STATE{
    ZERO,
    ONE,
    SUPERIMPOSED
};

typedef struct complex_number{
    double real;
    double img;
}complex;

typedef struct qubit{
    complex alpha;
    complex beta;
}qubit;

typedef struct zero{
    
}zero;

#endif /* quantum_h */
