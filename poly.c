#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "poly_library.h"

void acha_p(int * max_p, char** argv, int i, int k, int potencias[]){ 
    int j=0,p;
    char pot[15];
    for( ; argv[1][i]!='+' && argv[1][i]!='-' && argv[1][i]!='\0'; i++,j++){
        pot[j] = argv[1][i];
    }
    pot[j] = '\0';
    p = atoi(pot);
    potencias[k] = p;
    if(*max_p<p) *max_p = p;
}

void acha_coef(Poly* polinomio, char** argv, int potencias[]){
    int i,j=0,k=0, l;
    char coef[15];
    for(i=0;argv[1][i]!='\0';i++){
        if(i==0 || argv[1][i]=='+' || argv[1][i]=='-'){
            for(l=i, j=0; argv[1][l]!='x' && argv[1][l]!='\0'; l++, j++){
                coef[j] = argv[1][l];
            }
            coef[j] = '\0';
            polinomio->coef[potencias[k]] = atof(coef);
            k++;
        }
    }
}

