/*Ejercicio 2
Dado un arreglo de N componentes enteras hacer en 
forma recursiva:*/

#include <stdio.h>

#define N 3

//a) Cargar el arreglo.
void carga(int a[N], int indice) {
	
	if (indice < N) {
		printf("Ingrese un numero: \n");
		scanf("%d", &a[indice]);
		carga(a, indice + 1);
	}
}

//b) Mostrar el arreglo en forma invertida.
void mostrar(int a[N], int n) {
	
	if (n != -1) {
		printf("[ %d ]", a[n]);
		mostrar(a, n - 1);
	}
}

/*c) Decir cuántas componentes son positivas y cuantas 
negativas. (hacer una función que devuelva ambos 
resultados).

Nota: Hacer mapa de memoria para un subprograma*/
int positivas_negativas(int a[N], int *cp, int *cn, int indice) {
	
	if(indice < N) {
		if (a[indice] > 0) {
			(*cp)++;
		} else if (a[indice] < 0) {
			(*cn)++;
		}
		positivas_negativas(a, cp, cn, indice + 1);
	}
}
int main() {
	int A[N], i = 0, contP = 0, contN = 0;
	
	carga(A, i);
	mostrar(A, N - 1);
	positivas_negativas(A, &contP, &contN, i);
	printf("Componentes Positivas: %d\nComponentes Negativas: %d", contP, contN);
}
