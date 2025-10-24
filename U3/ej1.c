/*Ejercicio 1
Crear un arreglo de 50 numeros enteros y cargarlo 
generando cada numero de manera aleatoria.
Codificar un programa en C que permita: */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 50

void carga(int a[N]) {
	int i;
	srand(time(NULL));
	
	for (i = 0; i < N; i++) {
		a[i] = rand() % 201 - 100;
	}
	
	return;
}

/*1. Indicar en el main si cantidad de n�meros mayores 
a cero es mayor o igual a la cantidad de n�meros 
menores a cero.*/
int positivosNegativos(int a[N], int *positivos, int *negativos) {
	int i;
	*positivos = 0;
	*negativos = 0;
	for (i = 0; i < N; i++) {
		if (a[i] > 0) {
			(*positivos)++;
		} else if (a[i] < 0) {
			(*negativos)++;
		}
	}
}

/*2. Indicar en el main, la sumatoria de las 
componentes que se encuentren en las posiciones pares y 
la sumatoria de las que est� en posiciones impares.*/
void sumar_pares_impares(int a[N], int *pares, int *impares) {
	int i;
	*pares = 0;
	*impares = 0;
	for (i = 0; i < N; i++) {
		if (i % 2 == 0) {
			*pares += a[i];
		} else {
			*impares += a[i];
		}
	}
}

/*3. Leer un n�mero e indicar si se encuentra en el 
arreglo indicar su posici�n (puede estar repetido).*/
void buscar_numero(int a[N], int num) {
	int i, encontrado = 0;
	for (i = 0; i < N; i++) {
		if (a[i] == num) {
			encontrado = 1;
			printf("Numero encontrado en la posicion %d. \n", i);
		}
	}
	if (!encontrado) {
		printf("Numero no encontrado en el arreglo.\n");
	}
}
int main() {
	int A[N], positivos, negativos, pares, impares, numero;
	
	carga(A);
	
	positivosNegativos(A, &positivos, &negativos);
	if (positivos >= negativos) {
		printf("La cantidad de numeros mayores a 0 es igual a la cantidad de numeros menores a 0.\n");
	} else {
		printf("La cantidad de numeros mayores a 0 no es igual a la cantidad de numeros menores a 0.\n");
	}
	
	sumar_pares_impares(A, &pares, &impares);
	printf("Sumatoria de las componentes que se encuentran en posiciones pares: %d\n", pares);
	printf("Sumatoria de las componentes que se encuentran en posiciones impares: %d\n", impares);
	
	printf("Ingrese un numero para buscarlo en el arreglo: \n");
	scanf("%d", &numero);
	buscar_numero(A, numero);
}
