/*Ejercicio 1
Escribir un programa en lenguaje C que usando funciones 
permita:*/
#include <stdlib.h>
#include <stdio.h>

/*a) Crear y cargar 2 arreglos dinámicos de 
componentes enteras MxM (mismo tamaño) ingresada por 
teclado.*/
void carga(int xa[], int m, int i) {
	if (i < M) {
		printf("Ingrese un numero entero:\n");
		scanf("%d", &xa[i]);
		carga(xa, m, i + 1);
	}
}

/*b) Calcular el producto escalar.

El producto escalar es una operación donde al 
multiplicar dos arreglos se obtiene un único valor.
A * B = A[0] * B[0] + A[1] * B[1] +…+ A[N-1] * B[N-1]*/
void producto_escalar(int a[], int b[], int m) {
	int i, acum = 0;
	
	for (i = 0; i < m; i++) {
		acum += a[i] * b[i];
	}
	
	printf("El producto escalar entre A y B es de: %d", acum);
	return;
}

/*c) Generar una nueva estructura con los valores 
pares contenidos en uno de los arreglos (realizar un 
subprograma que solicite memoria para la nueva 
estructura y la devuelva cargada).*/
void carga_subarreglo(int a[], int &sa, int m) {
	int *pares, i, c = 0;
	
	sa = (int *)malloc(m * sizeof(int));
	
	for (i = 0; i < m; i++) {
		if (a[i] % 2 == 0) {
			pares[c] = a[i];
			c++;
		}
	}
	
	sa = realloc(pares, c * sizeof(int));
	return;
}

int main() {
	int *A, *B, M, *SA, tamano;
	
	//a)
	printf("Ingrese el tamaño de los arreglos:\n");
	scanf("%d", &M);
	A = (int *) malloc (M * sizeof(int));
	B = (int *) malloc (M * sizeof(int));
	carga(A, M, 0);
	carga(B, M, 0);
	
	//b)
	producto_escalar(A, B, M);
	
	//c)
	carga_subarreglo(A, SA, M);
	
	free(A);
	free(B);
	free(SA);
}
