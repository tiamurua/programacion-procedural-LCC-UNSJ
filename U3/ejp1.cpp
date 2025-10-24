/*Ejercicio 1
Codificar en C un programa que tenga:*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 10

/*1. Un menú de opciones, una de las cuales debe 
ser secreta. 

Propuesta:
	1. Opción 1
	2. Opción 2
	3. Opción 3
	99. Opción Secreta

2. Crear una función que reciba tres valores 
enteros ingresados por el usuario, y que calcule 
el cuadrado de cada número.

El pasaje de los parámetros debe ser por valor, 
por referencia y por dirección. 

Mostrar los valores de las variables antes del 
llamado a la función, dentro de la misma y al 
salir. 

Esta función debe ser la Opción 1 del menú.*/
int funcion_uno(int xn1, int *xn2, int &xn3)
{
	printf("Valor del primer numero ingresado: %d\n", xn1);
	printf("Valor del segundo numero ingresado: %d\n", *xn2);
	printf("Valor del tercer numero ingresado: %d\n", xn3);
	xn1 = xn1 * xn1;
	*xn2 = (*xn2) * (*xn2);
	xn3 = xn3 * xn3;
	return xn1;
}

/*4. Crear una función que genere una tabla de 
NxM componentes enteras, y lo llene con números 
aleatorios entre 100 y 199. (Opción 2)*/
void generar_tabla(int t[N][M])
{
	int i, j;
	srand(time(NULL));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			t[i][j] = rand()% 100 + 100;
		}
	}
}

/*5. Crear dos funciones que procese la tabla 
anterior. Una, que busque el máximo de la fila 0 
(enviar sólo la fila a procesar); y la otra, que 
cuente todas las componentes de la columna M. 
(Opción 3).*/
void maximo(int &m, int t[N])
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (t[i] > m)
		{
			m = t[i];
		}
	}
	return;
}

void suma(int colum, int t[N][M])
{
	int i, acum = 0;
	for (i = 0; i < N; i++)
	{
		acum += t[i][colum - 1];
	}
	printf("La suma de las componentes de la columna %d es: %d", colum, acum);
	return;
}

int main()
{
	int n1, n2, n3, cuadradoN1, opcion, T[N][M] = {{0}}, max = 0, columna;
	
	printf("\nMenu\n");
	printf("1. Cuadrado de tres numeros.\n");
	printf("2. Matriz de NxM con numeros aleatorios entre 100 y 199.\n");
	printf("3. Procesar la tabla de la opcion 2.\n");
	printf("4. Salir\n");
	printf("Ingrese numero de opcion:\n");
	scanf("%d", &opcion);
	
	switch (opcion)
	{
		case 1:
			printf("Ingrese tres numeros enteros:\n");
			scanf("%d %d %d", &n1, &n2, &n3);
			cuadradoN1 = funcion_uno(n1, &n2, n3);
			printf("Cuadrado del primer numero ingresado: %d\n", cuadradoN1);
			printf("Cuadrado del segundo numero ingresado: %d\n", n2);
			printf("Cuadrado del tercer numero ingresado: %d\n", n3);
			break;
		case 2:
			generar_tabla(T);
			printf("Matriz generada correctamente.\n");
			break;
		case 3:
			if (T[0][0] != 0)
			{
				maximo(max, T[0]);
				printf("El maximo de la fila 0 es: %d", max);
				printf("Ingrese un numero de columna:\n");
				scanf("%d", &columna);
				suma(columna, T);
			}
			else
			{
				printf("No puede ejecutarse esta opcion sin antes ejecutar la opcion 2.\n");
			}
			break;
		case 4:
			printf("Acaba de salir del programa.");
			break;
	}
}

