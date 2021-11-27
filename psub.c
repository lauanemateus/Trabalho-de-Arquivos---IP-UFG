#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "poly_library.h"

int main(int argc, char** argv){
    int i,j;
    FILE * arq1 = NULL, *arq2 = NULL;
    Poly polinomio1, polinomio2, answer;

    arq1 = fopen(argv[1], "rb");
    if(!arq1){
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
    
    fread((void*)&polinomio1.code, sizeof(char), ID_SIZE, arq1);
    fread((void*)&polinomio1.p, sizeof(int), 1, arq1);
    polinomio1.coef = (double*)calloc(polinomio1.p+1, sizeof(double));
    fread((void*)polinomio1.coef, sizeof(double), polinomio1.p+1, arq1);

    arq2 = fopen(argv[2], "rb");
    if(!arq2){
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
    
    fread((void*)&polinomio2.code, sizeof(char), ID_SIZE, arq2);
    fread((void*)&polinomio2.p, sizeof(int), 1, arq2);
    polinomio2.coef = (double*)calloc(polinomio2.p+1, sizeof(double));
    fread((void*)polinomio2.coef, sizeof(double), polinomio2.p+1, arq2);

    answer.p = polinomio1.p;
    if(answer.p<polinomio2.p) answer.p = polinomio2.p;
    answer.coef = (double*)calloc(answer.p+1, sizeof(double));

    for(i=0;i<=answer.p;i++){
        if(i<=polinomio1.p) answer.coef[i] += polinomio1.coef[i];
        if(i<=polinomio2.p) answer.coef[i] -= polinomio2.coef[i];
    }

    fclose(arq1), fclose(arq2);
    
    arq1 = fopen(argv[3], "wb");
    strncpy(answer.code,"poly", sizeof(answer.code));
    fwrite((void*)&answer.code, sizeof(char), ID_SIZE, arq1);
    fwrite((void*)&answer.p, sizeof(int), 1, arq1);
    fwrite((void*)answer.coef, sizeof(double), answer.p+1, arq1);

    fclose(arq1);
    free(polinomio1.coef), free(polinomio2.coef), free(answer.coef);
    return 0;
}