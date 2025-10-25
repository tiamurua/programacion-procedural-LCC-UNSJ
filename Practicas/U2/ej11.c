/*Ejercicio 11
Un supermercado ingresa las ventas de los últimos 6 meses, 
realizadas en los 8 departamentos de venta que posee.
 
Por cada venta se ingresa mes (1 ... 12), número de 
departamento (1 ... 8) e importe. Las ventas no traen ningún 
orden particular. 

Realizar un programa en C, que a través de funciones 
permita:*/

#include <stdio.h>

#define F 8
#define C 12

/*a) Almacenar la información en una tabla que posea por cada 
mes, el importe total de ventas de cada departamento. La 
carga finaliza con mes igual a cero.*/
void cereo(int t[F][C]) {
	int i, j;
	
	for (i = 0; i < F; i++) {
		for (j = 0; j < C; j++) {
			t[i][j] = 0;
		}
	}
	return;
}

void carga(int t[F][C]) {
	int mes, depto;
	float importe;
	
	printf("Ingrese departamento: \n");
	scanf("%d", &depto);
	while (depto != 0) {
		printf("Ingrese mes e importe: \n");
		scanf("%d %f", &mes, &importe);
		
		t[depto - 1][mes - 1] += importe;
		
		printf("Ingrese departamento: \n");
		scanf("%d", &depto);
	}
}

//b) Dado un mes, mostrar en el programa principal el departamento que menos vendió (suponer único).
int minimo(int t[F][C], int m) {
	int i, min = 9999999999999999999, mes;
	for (i = 0; i < F; i++) {
		if (t[i][mes - 1] < min) {
			min = t[i][mes - 1];
			mes = i;
		}
	}
	return mes;
}

//c) Mostrar el importe promedio de venta del supermercado.
float promedio(int t[F][C]) {
	int i;
	float acum = 0, p;
	
	for (i = 0; i < F; i++) {
		for (j = 0; j < C; j++) {
			acum += t[i][j];
		}
	}
	
	p = acum / 8;
	
	return p;
}

//d) Dado un mes y un departamento, indicar si supera el importe promedio del ítem anterior.
void supera(int t[F][C], int m, int d, int p) {
	
	if (t[d - 1][m - 1] > p) {
		printf("El importe del departamento %d en el mes %d, supera el importe promedio vendido por el supermercado.", d, m);
	} else {
		printf("El importe del departamento %d en el mes %d, no supera el importe promedio vendido por el supermercado.", d, m)
	}
	return;
}

int main() {
	int T[F][C], mes, departamento, indice;
	float prom;
	
	cereo(T);
	carga(T);
	
	printf("Ingrese un mes, para saber el departamento que menos vendio: \n");
	scanf("%d", &mes);
	indice = minimo(T, mes);
	printf("Departamento que menos vendio: %d", indice + 1);
	
	prom = promedio(T);
	printf("Importe promedio de venta del supermercado: %2.f", prom);
	
	printf("Ingrese un mes y un departamento: \n");
	scanf("%d %d", &mes, &departamento);
	supera(T, mes, departamento, prom);
}




