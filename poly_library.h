#define ID_SIZE 4
#define QTD_POT 10000

typedef struct {
	char code[ID_SIZE]; // "poly"
	int p;
	double* coef;
} Poly;

void acha_p(int * max_p, char** argv, int i, int k, int potencias[]);

void acha_coef(Poly* polinomio, char** argv, int potencias[]);