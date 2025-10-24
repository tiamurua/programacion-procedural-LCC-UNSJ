/*Ejercicio 6
Realizar un programa en C, que permita:*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 5

/*1. Cargar una matriz de n x m, con elementos enteros 
desde el 1 al 100.*/
void carga_matriz(int m[N][M]) {
	int i, j;
	
	srand(time(NULL));
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			m[i][j] = rand() % 100 + 1;
		}
	}
}

void mostrar_matriz(int m[N][M]) {
	int i, j;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf("[ %d ]", m[i][j]);
		}
		printf("\n");
	}
}

/*2. Buscar los números primos que contenga la matriz 
e indicar la posición en la que se encuentra cada uno 
de ellos.*/
int es_primo(int num) {
	int i;
	
	for (i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return 0; //si es divisible por algun numero no es primo.
		}
	}
	
	return 1; //es primo
}

void buscar_primos(int m[N][M]) {
	int i, j, indice;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (es_primo(m[i][j])) {
				printf("Número primo: %d en posicion [Fila: %d, Columna: %d]\n", m[i][j], i + 1, j + 1);
			}
		}
	}
	return;
}

int main() {
	int matriz[N][M];
	
	carga_matriz(matriz);
	mostrar_matriz(matriz);
	
	buscar_primos(matriz);
}

