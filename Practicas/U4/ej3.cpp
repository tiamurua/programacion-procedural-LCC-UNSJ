/*Ejercicio 3
Dada una tabla de N x M números enteros hacer en forma 
recursiva:*/
#include <stdio.h>

#define N 3
#define M 3

//a) Cargar la información ordenada por columnas.
void carga(int a[N][M], int i, int j) {
	if (j < M) {
		if (i < N) {
			printf("Ingrese numero entero:\n");
			scanf("%d", &a[i][j]);
			carga(a, i + 1, j);
		} else {
			carga(a, 0, j + 1);
		}
	}
	return;
}

/*b) Mostrar el contenido de la tabla con formato de 
reales.*/
void mostrar(int t[N][M], int i, int j) {
	if (i < N) {
		if (j < M) {
			printf("%.2f, ", (float)t[i][j]);
			mostrar(t, i, j + 1);
		} else {
			mostrar(t, i + 1, 0);
		}
	}
	return;
}

int main() {
	int A[N][M];
	
	carga(A, 0, 0);
	mostrar(A, 0, 0);
}
