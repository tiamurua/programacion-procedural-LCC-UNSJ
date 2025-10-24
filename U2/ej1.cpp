#include <stdio.h>

#define N 20

void carga_num_aleatorios (int a[N]) {
	int i;
	for (i = 0; i < N; i++) {
		printf("Ingrese un numero: ");
		scanf("%d", &a[i]);
	}
}

int esCero(int a[N], int e) {
	int i = 0;
	
	while (i < N && e != a[i]) {
		i++;
	}
	
	return i;
}

void pares(int a[N]) {
	int i;
	printf("Numeros en las posiciones pares: \n");
	for (i = 0; i < N; i++) {
		if ((i % 2) == 0) {
			printf("%d\n", a[i]);
		}
	}
	
}

void cuantos_pares (int a[N]) {
	int i, cont = 0;
	
	for (i = 0; i < N; i++) {
		if (a[i] % 2 == 0) {
			cont++;
		}
	}
	
	printf("Cantidad de numeros pares en el arreglo: %d", cont);
	return;
}
int main () {
	int A[N], elemento = 0, p;
	
	carga_num_aleatorios (A);
	p = esCero(A, elemento);
	if (p < N) {
		printf("Alguno de los numeros es cero.");
	} else {
		printf("Ningun valor es cero.");
	}
	pares(A);
	cuantos_pares(A);
}
