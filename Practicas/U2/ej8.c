//Ejercicio 8
//Realizar un programa en lenguaje C, que usando funciones óptimas realice lo siguiente:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 3
#define N 4

//a) Generar y cargar un arreglo bidimensional de enteros de 3x4.
void carga_tabla(int a[M][N]) {
	int i, j;
	
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			a[i][j] = rand()%201;
		}
	}
	return;
}

//b) Mostrar en el main la suma de los elementos con valor impar.
int elementos_impares(int a[M][N]) {
	int i, j, acum = 0;
	
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if ((a[i][j] % 2) != 0) {
				acum += a[i][j];
			} 
		}
	}
	
	return acum;
}

// c) Ingresar un número de fila y mostrar en el main la cantidad de elementos mayores a 10 (realice una función que 
//devuelva la cantidad al main).
int acumular_por_fila(int a[M][N], int f) {
	int i, acum = 0;
	
	for (i = 0; i < N; i++) {
		if (a[f - 1][i] > 10) {
			acum += a[f - 1][N];
		}
	}
	
	return acum;
}
int main() {
	int A[M][N], fila, cantidad;
	srand(time(NULL));
	
	carga_tabla(A);
	printf("Resultado de la suma de los elementos con valor impar: %d\n", elementos_impares(A));
	
	printf("Ingrese un numero de fila: \n");
	scanf("%d", &fila);
	cantidad = acumular_por_fila(A, fila);
}
