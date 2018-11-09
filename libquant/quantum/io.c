//
//  io.c
//  libquant
//
//  Created by Munawar Hasan on 09/11/18.
//  Copyright © 2018 Munawar Hasan. All rights reserved.
//

#include "io.h"

#include "math.h"

#define IOPATH ../plot

void write_to_file(double array[], int size){
    FILE *fp = fopen("./qubit.dat", "w");
    
    for (int i = 0; i < size; i=i+2) {
        double real = array[i];
        double img = array[i + 1];
        
        fputs("0 0", fp);
        fputs("\n", fp);
        fprintf(fp, "%lf %lf", real, img);
        
        if(size - 1 > i)
            fputs("\n \n", fp);
        
    }
    fclose(fp);
}
