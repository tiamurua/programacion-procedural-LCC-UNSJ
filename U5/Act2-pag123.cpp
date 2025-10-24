#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct {
	int dni;
	float monto;
} adjudicatario;

typedef struct {
	int cAdj;
	adjudicatario *A;
} plan;

//1. Realice la carga de la información
void carga(plan p[N]) {
	int i, c, j;
	
	for (i = 0; i < N; i++) {
		printf("Ingrese la cantidad de adjudicatarios del plan %d.\n", i + 1);
		scanf("%d", &p[i].cAdj);
		
		p[i].A = (adjudicatario *) malloc (p[i].cAdj * sizeof(adjudicatario));
		
		for (j = 0; j < p[i].cAdj; j++) {
			printf("Ingrese DNI del adjudicatario\n");
			scanf("%d", &p[i].A[j].dni);
			printf("Ingrese monto del adjudicatario\n");
			scanf("%f", &p[i].A[j].monto);
		}
	}
	return;
}

/*2. Para un adjudicatario cuyo DNI se ingresa por teclado, indicar el número de plan al cual se adhirió y el monto 
adeudado.*/
void busqueda(plan p[N], int xdni) {
	int i = 0, j;
	
	while (i < N) {
		j = 0;
		while (j < p[i].cAdj) {
			if (p[i].A[j].dni == xdni) {
				printf("Numero de plan al que se adhirio el adjudicatario de dni %d es el plan: %d\n", xdni, i + 1);
				printf("Monto adeudado del adjudicatario de dni %d: %f", xdni, p[i].A[j].monto);
			}
			j++;
		}
		i++;
	}
	return;
}

int main(){
	plan P[N];
	int dni;
	
	carga(P);
	
	printf("Ingrese un DNI:\n");
	scanf("%d", &dni);
	busqueda(P, dni);
}
