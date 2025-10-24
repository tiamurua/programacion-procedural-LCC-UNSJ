/*Ejercicio 3
Se tienen los datos relacionados a un censo de 
pacientes de un hospital. Por cada paciente se ingresa 
número de paciente, edad y peso. El ingreso finaliza 
cuando se lee un peso negativo o cuando la cantidad de 
pacientes supere los 400.
Realizar un programa en C, que permita:*/

#include <stdio.h>

#define N 400

typedef struct {
	int numero;
	int edad;
	float peso;
} paciente;

int carga_datos(paciente p[N], int c) {
	float xpeso;
	
	printf("Ingrese peso del paciente:\n");
	scanf("%f", &xpeso);
	while (xpeso > 0 && c <= N) {
		printf("Ingrese edad del paciente:\n");
		scanf("%d", &p[c].edad);
		printf("Ingrese numero de paciente:\n");
		scanf("%d", &p[c].numero);
		p[c-1].peso = xpeso;
		c++;
		
		printf("Ingrese peso del paciente:\n");
		scanf("%f", &xpeso);
	}
	return c;
}

/*1. Calcular la cantidad de pacientes cuya edad este 
comprendida entre 7 y 11 años inclusive.*/
void calculo_edad(paciente p[N], int c) {
	int i, cont = 0;
	for (i = 0; i < c; i++) {
		if (p[i].edad >= 7 && p[i].edad <= 11) {
			cont++;
		}
	}
	
	printf("Cantidad de pacientes cuya edad esta comprendida entre 7 y 11 años inclusive: %d", cont);
	return;
}

/*2. Determinar el porcentaje de pacientes mayores de 
11 años cuyo peso no supera los 50kg.*/
void porcentaje(paciente p[N], int c) {
	int i, cont = 0;
	for (i = 0; i < c; i++) {
		if (p[i].edad > 11 && p[i].peso <= 50) {
			cont++;
		}
	}
	
	printf("Porcentaje de pacientes mayores de 11 años cuyo peso no supera los 50kg: %.2f", (cont * 100) / c);
	return;
}

/*3. Imprimir el número de paciente y edad con menor 
peso.*/
void menor_peso(paciente p[N], int c) {
	int i, indice = 0;
	float min = 99999;
	for (i = 0; i < c; i++) {
		if (p[i].peso < min) {
			min = p[i].peso;
			indice = i;
		}
	}
	
	printf("Paciente con menor peso:\n");
	printf("Numero: %d\n", p[indice].numero);
	printf("Edad: %d\n", p[indice].edad);
	return;
}

int main() {
	paciente P[N];
	int cantidad = 0;
	
	cantidad = carga_datos(P, cantidad);
	calculo_edad(P, cantidad);
	porcentaje(P, cantidad);
	menor_peso(P, cantidad);
}
