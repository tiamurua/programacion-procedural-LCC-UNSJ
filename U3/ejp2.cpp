/*Ejercicio 2
Realizar un programa en C que permita:*/

#include <stdio.h>

#define N 1000

/*1. Leer datos enteros hasta que se llegue a 1000 
datos o hasta que el dato ingresado sea igual a –50.*/
int carga(int a[N], int c) {
	int dato, i = 0;
	
	printf("Ingrese un dato entero:\n");
	scanf("%d", &dato);
	while (dato < 1000 || dato != -50) {
		a[i] = dato;
		i++;
		c++;
		
		printf("Ingrese un dato entero:\n");
		scanf("%d", &dato);
	}
	return c;
}

//2. Imprimir cantidad de elementos ingresados.
void imprimir(int a[N], int c) {
	int i;
	printf("Cantidad de componentes ingresados: %d", c);
	printf("Componentes:\n");
	for (i = 0; i < c; i++) {
		printf("%d, ", a[i]);
	}
	return;
}

//3. Imprimir porcentaje de datos pares leídos.
void porcentaje_pares(int a[N], int c) {
	int i, p = 0;
	for (i = 0; i < c; i++) {
		if (a[i] % 2 == 0) {
			p++;
		}
	}
	
	printf("Porcentaje de datos pares leidos: %.2f", (c * 100) / p);
	return;
}

/*4. Calcular e imprimir promedio de todos los datos 
ingresados.*/
void promedio (int a[N], int c) {
	int i, acum = 0;
	for (i = 0; i < c; i++) {
		acum += a[i];
	}
	
	printf("Promedio de todos los datos ingresados: %.2f", acum / c);
	return;
}

int main() {
	int A[N], componentes = 0;
	
	componentes = carga(A, componentes);
	imprimir(A, componentes);
	porcentaje_pares(A, componentes);
	promedio(A, componentes);
}
