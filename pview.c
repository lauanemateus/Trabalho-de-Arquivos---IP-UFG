#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "poly_library.h"

int main(int argc, char** argv){
    int i;
    FILE * arq = NULL;
    Poly polinomio;

    arq = fopen(argv[1], "rb");
    if(!arq){
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    fread((void*)&polinomio.code, sizeof(char), ID_SIZE, arq);
    fread((void*)&polinomio.p, sizeof(int), 1, arq);
    polinomio.coef = (double*)calloc(polinomio.p+1, sizeof(double));
    fread((void*)polinomio.coef, sizeof(double), polinomio.p+1, arq);

    for(i=0;i<=polinomio.p;i++){
        if(polinomio.coef[i]==(double)(0)) continue;
        if(polinomio.coef[i]>0 && i!=0) printf("+");
        if(polinomio.coef[i]==1.0) printf("x^%d", i);
        else if(polinomio.coef[i]==-1.0) printf("-x^%d", i);
        else if(polinomio.coef[i]-(int)polinomio.coef[i] == 0.0){
            if(i==0) printf("%d", (int)polinomio.coef[i]);
            else if(polinomio.coef[i]==1) printf("x^%d", i);
            else if (polinomio.coef[i]==-1) printf("-x^%d", i);
            else printf("%dx^%d", (int)polinomio.coef[i],i);
        }
        else{
            if(i==0) printf("%.2lf", polinomio.coef[i]);
            else if(polinomio.coef[i]==1.0) printf("x^%d", i);
            else if (polinomio.coef[i]==-1.0) printf("-x^%d", i);
            else printf("%.2lfx^%d", polinomio.coef[i],i);
        }
    }
    printf("\n"); 

    fclose(arq);
    free(polinomio.coef);
    return 0;
}