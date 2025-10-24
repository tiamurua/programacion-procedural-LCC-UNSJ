/*El instituto Provincial de la Vivienda ha 
implementado un sistema que consta de 5 planes de pago 
distintos, con el fin de que los adjudicatarios de sus
viviendas puedan cancelar sus deudas.

Por cada uno de los 5 planes, se ingresa en forma
ordenada la cantidad de adjudicatarios adheridos y por
cada uno de ellos el monto adeudado.

Se necesita realizar un programa, que utilizando de
manera optima funciones, informe:
Para cada plan:
a) Monto total adeudado por los adjudicatarios adheridos al mismo
b) Monto promedio adeudado
c) Cantidad de ususarios cuyo monto adeudado es superior al promedio calculado
d) el o los numeros de planes con mayor cantidad de adjudicatarios*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 5

void carga(float *t, int xcu) {
	int i;
	t = (float *) malloc (cu * sizeof(float)); /*Solicita espacio para almacenar la deuda de los adjudicat. de un plan*/
	printf("\nIngrese la deuda de los %3d Usuarios ", xcu);
	for (i = 0; i < xcu; i++) {
		scanf("%f", &t[i]);
	}
	return;
}

float total(float *t, int cu) {
	float prom = 0;
	int i;
	
	for (i = 0; i < cu; i++) {
		prom += t[i];
	}
	printf("\nTotal adeudado %5.2f ", prom);
	prom = prom / cu;
	return prom;
}

int cantidad(float *t, int cu, float prom) {
	int c = 0, i;
	
	for (i = 0; i < cu; i++) {
		if (t[i] > prom) {
			c++;
		}
	}
	return c;
}

void maximo(int *tot, int N) {
	int i, max = 0;
	for (i = 0; i < N; i++) {
		if (tot[i] > max) {
			max = tot[i];
		}
	} 
	printf("\nPlanes con mayor cantidad de adjudicatarios");
	for (i = 0; i < N; i++) {
		if (tot[i] == max) {
			printf("\n %3d ", i + 1);
		}
	}
	return;
}


void main(void) {
	int i, cu, totu[5];
	float *monto, prom;
	
	for (i = 0; i < N; i++) {
		printf("\nIngrese cantidad de adjudicatarios del plan %3d ", i + 1);
		scanf("%d", &cu);
		totu[i] = cu;
		
		carga(monto, cu);
		prom = total(monto, cu);
		printf("\nPromedio adeudado por Adjudicatarios del plan %3d es %5.2f ", i + 1, prom);
		printf("\nTotal adjudic. con monto superior a promedio %4d", cantidad(monto, cu, prom));
		free(monto);//Libera el espacio asignado a un plan, cuando no se necesita
	}
	maximo(totu, 5);
}
