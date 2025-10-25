/*Ejercicio 6
Un supermercado ingresa las ventas de los últimos 6 meses, realizadas en los 8 departamentos de venta que posee. Por cada venta se 
ingresa mes, departamento e importe. Las ventas no traen ningún orden particular. Realizar un programa en C, que a través de funciones 
permita:*/

#include <stdio.h>

#define F 8
#define C 6

void cereo(int t[F][C]) {
	int i, j;
	for (i = 0; i < F; i++) {
		for (j = 0; j < C; j++) {
			t[i][j] = 0;
		}
	}
	return;
}

//1. Almacenar la información en una tabla que posea por cada mes, el importe total de ventas de cada departamento.
void carga(int t[F][C]) {
	int mes, depto;
	float importe;
	
	printf("Ingrese numero de mes (0 para finalizar): \n");
	scanf("%d", &mes);
	
	while(mes != 0) {
		printf("Ingrese numero de departamento: \n");
		scanf("%d", &depto);
		
		printf("Ingrese importe de venta: \n");
		scanf("%f", &importe);
		
		t[depto - 1][mes - 1] += importe;
		
		printf("Ingrese numero de mes (0 para finalizar): \n");
		scanf("%d", &mes);
	}
	return;
}

//2. Mostrar en el programa principal el departamento que tuvo menor importe de venta (suponer único).
int menor_importe(int t[F][C], float m) {
	int i, j;
	float min = 999999999999999999999999999;
	
	for (i = 0; i < F; i++) {
		for (j = 0; j < C; j++) {
			if (t[i][j] < m) {
				min = t[i][j];
				m = i;
			}
		}
	}
	
	return m;
}

//3. Mostrar importe promedio de venta del supermercado.
float promedio(int t[F][C]) {
	int i, j, acum = 0;
	
	for (i = 0; i < F; i++) {
		for (j = 0; j < C; j++) {
			acum += t[i][j];
		}
	}
	
	return acum / F;
}

//4. Mostrar el/los departamento/s que supera/n la venta promedio, indicando el importe total vendido a lo largo del semestre.
void superan_promedio(int t[F][C]) {
	int i, j, p;
	float acum;
	
	p = promedio(t);
	
	for (i = 0; i < F; i++) {
		acum = 0;
		for (j = 0; j < C; j++) {
			acum += t[i][j];
		}
		if (acum > p) {
			printf("Departamento/s que supera/n la venta promedio: %d", i + 1);
			printf("Importe total vendido a lo largo del semestre: %2.f", acum);
		}
	}
}

int main() {
	int T[F][C], min;
	
	cereo(T);
	carga(T);
	min = menor_importe(T, min);
	printf("Departamento con menor importe de venta: %d", min + 1);
	printf("Importe promedio de venta del supermercado: %2.f", promedio(T));
	superan_promedio(T);
}
