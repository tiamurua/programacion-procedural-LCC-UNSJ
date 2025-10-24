//Ejercicio 7
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 5
#define N 4

//Cargar aleatoriamente una tabla de 5x4 con números enteros y:
void carga_tabla(int a[M][N]) {
	int i, j;
	
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			a[i][j] = rand()%201;
		}
	}
	return;
}

void mostrar_tabla(int a[M][N]) {
	int i, j;
	
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf("[ %d ]", a[i][j]);
		}
		printf("\n");
	}
	return;
}

//a) Mostrar la suma de cada una de las filas.
void suma_filas(int a[M][N]) {
	int i, j, acum;
	
	for (i = 0; i < M; i++) {
		acum = 0;
		for (j = 0; j < N; j++) {
			acum += a[i][j];
		}
		
		printf("Suma de la fila %d: %d\n", i + 1, acum);
	}
	return;
}

//b) Calcular el promedio de la tercera columna.
void promedio(int a[M][N]) {
	int i, j, acum = 0;
	float p;
	
	for (i = 0; i < M; i++) {
		acum += a[i][2];
	}
	
	p = acum / M;
	
	printf("El promedio de la tercer columna es: %.2f\n", p);
	return;
}

//c) Decir cuántos números mayores a 100 se ingresaron.
void mayores(int a[M][N]) {
	int i, j, cont = 0;
	
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (a[i][j] > 100) {
				cont++;
			}
		}
	}
	
	printf("Cantidad de numeros mayores a 100: %d\n", cont);
	return;
}
int main () {
	int A[M][N];
	srand(time(NULL));
	
	carga_tabla(A);
	mostrar_tabla(A);
	suma_filas(A);
	promedio(A);
	mayores(A);
}
