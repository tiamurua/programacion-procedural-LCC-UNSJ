/*Ejercicio 10
Un laboratorio abastece a 30 farmacias de la provincia (las 
farmacias están codificadas con números entre 1 y 30). Dicho 
laboratorio comercializa 80 medicamentos (con código desde 
100 hasta 179).

En forma ordenada por las farmacias se ingresan las ventas 
realizadas. Por cada venta se ingresa: código de medicamento 
y cantidad de unidades, finalizando con código de 
medicamento igual a 0 (cero), como lo muestra el siguiente 
ejemplo:

			Código Medicamento	Cantidad Unidades
Farmacia 1	23					12
			32					20
			41					6
			0
Farmacia 2	43					10
			25					24
			0
			
Codificar un programa en C, que utilizando funciones 
permita:*/

#include <stdio.h>
#include <string.h>

#define F 30
#define C 80

void cereo(int t[F][C]) {
	int i, j;
	for (i = 0; i < F; i++) {
		for (j = 0; j < C; j++) {
			t[i][j] = 0;
		}
	}
	return;
}
//a) Realizar la carga de la tabla.
void carga(int t[F][C]) {
	int cod, unidades, i;
	
	for (i = 0; i < F; i++) {
		printf("Ingrese codigo del medicamento (0 para finalizar): \n");
		scanf("%d", &cod);
		
		while (cod != 0) {
			printf("Ingrese cantidad de unidades vendidas: \n");
			scanf("%d", &unidades);
			
			t[i][cod - 100] += unidades;
			
			printf("Ingrese codigo del medicamento (0 para finalizar): \n");
			scanf("%d", &cod);
		}
	}
	return;
}

//b) Calcular y mostrar el total de unidades vendidas de cada uno de los medicamentos.
void total_unidades(int t[F][C]) {
	int i, j, acum = 0;
	
	printf("Total de unidades vendidas por medicamento: \n");
	
	for (j = 0; j < C; j++) {
		for (i = 0; i < F; i++) {
			if (t[i][j] != 0) {
				acum += t[i][j];
			}
		}
		printf("Medicamento %d: %d unidades totales vendidas.\n", j + 100, acum);
	}
	return;
}

//c) Dado el código de una farmacia, indicar el código del medicamento más vendido.
void medicamento_mas_vendido(int t[F][C], int cFarmacia) {
	int i, max = -1, cod;
	for (i = 0; i < C; i++) {
		if (t[cFarmacia - 1][i] > max) {
			max = t[cFarmacia - 1][i];
			cod = i + 100;
		}
	}
	
	printf("El codigo del medicamento mas vendido es: %d", cod);
	return;
}
int main() {
	int T[F][C], cod;
	
	cereo(T);
	carga(T);
	total_unidades(T);
	
	printf("Ingrese codigo de una farmacia, para indicar el codigo del medicamento mas vendido: \n");
	scanf("%d", &cod);
	medicamento_mas_vendido(T, cod);
}
