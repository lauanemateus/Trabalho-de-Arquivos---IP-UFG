#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "poly_library.h"

int main(int argc, char** argv){
    
    FILE * arq = NULL;
    int i,j, max_p=-1, potencias[QTD_POT];

    arq = fopen(argv[2], "wb");
    Poly polinomio;
    strncpy(polinomio.code,"poly", sizeof(polinomio.code));

    j=0;
    for(i=0; i<argv[1][i] != '\0'; i++){
        if(argv[1][i]=='^'){
            acha_p(&max_p, argv, i+1, j, potencias);
            j++;
        }
    }
    
    polinomio.p = max_p;
    polinomio.coef = (double*)calloc(polinomio.p+1, sizeof(double));
    acha_coef(&polinomio, argv, potencias);

    fwrite((void*)&polinomio.code, sizeof(char), ID_SIZE, arq);
    fwrite((void*)&polinomio.p, sizeof(int), 1, arq);
    fwrite((void*)polinomio.coef, sizeof(double), polinomio.p+1, arq);

    fclose(arq);
    free(polinomio.coef);
    return 0;
}